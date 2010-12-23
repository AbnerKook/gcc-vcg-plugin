/* <one line to give the program's name and a bief idea of what it does.>
 *
 * Copyright (C) 2010 Mingjie Xing, mingjie.xing@gmail.com.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include <config.h>

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "gcc-plugin.h"
#include "plugin.h"
#include "plugin-version.h"

#include "vcg-plugin.h"
#include "gdl.h"

static const char *function_name;
static char buf[32]; /* Should be enough.  */
static char **bb_graph_title;
static char **bb_graph_label;
static char **bb_node_title;

/* Initialize all of the names.  */
static void
init_names (const char *func_name, int bb_num)
{
  int i;
  
  bb_graph_title = (char **) xmalloc (bb_num * sizeof (char *));
  bb_graph_label = (char **) xmalloc (bb_num * sizeof (char *));
  bb_node_title = (char **) xmalloc (bb_num * sizeof (char *));

  for (i = 0; i < bb_num; i++)
    {
      sprintf (buf, "%d", i);

      /* format: func_name.bb_index */
      bb_graph_title[i] = concat (func_name, ".", buf, NULL);

      /* format: ENTRY | EXIT | bb bb_index */
      if (i == 0)
        bb_graph_label[i] = "ENTRY";
      else if (i == 1)
        bb_graph_label[i] = "EXIT";
      else
        bb_graph_label[i] = concat ("bb ", buf, NULL);

      /* format: ENTRY | EXIT | bb.bb_index */
      if (i == 0)
        bb_node_title[i] = "ENTRY";
      else if (i == 1)
        bb_node_title[i] = "EXIT";
      else
        bb_node_title[i] = concat ("bb.", buf, NULL);
    }
}

/* Create a graph from the basic block bb. */

static gdl_graph *
create_bb_graph (basic_block bb, int flags)
{
  gdl_graph *g;
  gdl_node *n;
  gimple_stmt_iterator gsi;
  gimple stmt;

  g = gdl_new_graph (bb_graph_title[bb->index]);
  gdl_set_graph_label (g, bb_graph_label[bb->index]);
  n = gdl_new_node (bb_node_title[bb->index]);

/*
  for (gsi = gsi_start_bb (bb); !gsi_end_p (gsi); gsi_next (&gsi))
    {
      stmt = gsi_stmt (gsi);
      init_print_file ();
      print_gimple_stmt (print_file, stmt, 2, flag);
    }
*/
  return g;
}

/* Create a graph from the function fn. */

static gdl_graph *
create_function_graph (tree fn, int flags)
{
  basic_block bb;
  edge e;
  edge_iterator ei;

  gdl_graph *graph, *bb_graph;
  gdl_edge *v_edge;

  /* Get the function's name. */
  function_name = lang_hooks.decl_printable_name (fn, 2);

  graph = gdl_new_graph (function_name);

  /* Switch CFUN to point to FN. */
  push_cfun (DECL_STRUCT_FUNCTION (fn));

  init_names (function_name, n_basic_blocks);

  FOR_ALL_BB (bb)
    {
      bb_graph = create_bb_graph (bb, flags);
      gdl_add_subgraph (graph, bb_graph);

      FOR_EACH_EDGE (e, ei, bb->succs)
        {
          v_edge = gdl_new_edge (bb_graph_title[e->src->index],
                                 bb_graph_title[e->dest->index]);
          gdl_add_edge (graph, v_edge);
        }
    }

  return graph;
}

static void
exit_if_invalid (tree fn)
{
}

void
vcg_plugin_dump_function (tree fn, int flags)
{
  gdl_graph *g;

  exit_if_invalid (fn);

  g = create_function_graph (fn, flags);

  vcg_plugin_common.dump (g);
}

void
vcg_plugin_view_function (tree fn, int flags)
{
  gdl_graph *g;

  exit_if_invalid (fn);

  g = create_function_graph (fn, flags);

  vcg_plugin_common.show (g);
}

