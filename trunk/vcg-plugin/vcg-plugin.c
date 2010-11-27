/* vcg plugin

   Copyright (C) 2009, 2010 Mingjie Xing, mingjie.xing@gmail.com. 

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include <config.h>

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "gcc-plugin.h"
#include "plugin.h"
#include "plugin-version.h"

#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "toplev.h"
#include "gimple.h"
#include "tree-pass.h"
#include "intl.h"
#include "langhooks.h"
#include "cfghooks.h"

#include "vcg-plugin.h"
#include "gdl.h"

/* plugin license check */
int plugin_is_GPL_compatible;

/* plugin initialization */
int
plugin_init (struct plugin_name_args *plugin_info,
             struct plugin_gcc_version *version)
{
  int i;
  int argc = plugin_info->argc;
  struct plugin_argument *argv = plugin_info->argv;

  if (!plugin_default_version_check (version, &gcc_version))
    return 1;

  /* Initialize the vcg plugin */
  return vcg.init (argc, argv);
}

/* vcg viewer tool, default is vcgview */
char *vcg_viewer = "vcgview";

static void
vcg_init (int argc, char *argv[])
{
  for (i = 0; i < argc; i++)
    {
      printf ("key: %s\n", argv[i].key);
      printf ("value: %s\n", argv[i].value);
      /* Get the vcg viewer tool, default is "vcgview". */
      if (strcmp (argv[i].key, "viewer") == 0)
        {
          vcg_viewer = argv[i].value;
        }
    }
}

static void
vcg_add_graph ()
{
}

static void
vcg_dump_node (FILE *fout, struct gdl_node *node)
{
  char *str;
  int val;
  int i;

  fputs ("node: {\n", fout);

  /* title */
  str = gdl_get_node_title (node);
  if (str != NULL)
    fprintf (fout, "title: \"%s\"\n", str);
  
  /* label */
  str = gdl_get_node_label (node);
  if (str != NULL)
    {
      fprintf (fout, "label: \"", str);
      for (i = 0; i < strlen (str); i++)
        {
          if (str[i] == '"')
            fprintf (fout,  "\\");
          fprintf (fout, "%c", str[i]);
        }
      fprintf (fout, "\"\n");
    }
  
  /* vertical_order */
  val = gdl_get_node_vertical_order (node);
  if (val != -1)
    fprintf (fout, "vertical_order: %d\n", val);

  /* shape */
  str = gdl_get_node_shape_s (node);
  if (str != NULL)
    fprintf (fout, "shape: %s\n", str); 

  /* color */
  str = gdl_get_node_color_s (node);
  if (str != NULL)
    fprintf (fout, "color: %s\n", str); 

  fputs ("}\n", fout);
}

static void
vcg_dump_edge (FILE *fout, struct gdl_edge *edge)
{
  char *str;
  int val;
  int i;

  fputs ("edge: {\n", fout);

  /* sourcename */
  str = gdl_get_edge_source (edge);
  if (str != NULL)
    fprintf (fout, "sourcename: \"%s\"\n", str);
  
  /* targetname */
  str = gdl_get_edge_target (edge);
  if (str != NULL)
    fprintf (fout, "targetname: \"%s\"\n", str);
  
  /* label */
  str = gdl_get_edge_label (edge);
  if (str != NULL)
    {
      fprintf (fout, "label: \"", str);
      for (i = 0; i < strlen (str); i++)
        {
          if (str[i] == '"')
            fprintf (fout,  "\\");
          fprintf (fout, "%c", str[i]);
        }
      fprintf (fout, "\"\n");
    }
  
  /* linestyle */
  str = gdl_get_edge_linestyle_s (edge);
  if (str != NULL)
    fprintf (fout, "linestyle: %s\n", str);

  fputs ("}\n", fout);
}

static void
vcg_dump_graph_attributes (FILE *fout, struct gdl_graph *graph)
{
  char *str;
  int val;
  int i;

  /* title */
  str = gdl_get_graph_title (graph);
  if (str != NULL)
    fprintf (fout, "title: \"%s\"\n", str);

  /* label */
  str = gdl_get_graph_label (graph);
  if (str != NULL)
    {
      fprintf (fout, "label: \"", str);
      for (i = 0; i < strlen (str); i++)
        {
          if (str[i] == '"')
            fprintf (fout,  "\\");
          fprintf (fout, "%c", str[i]);
        }
      fprintf (fout, "\"\n");
    }

  /* color */
  str = gdl_get_graph_color_s (graph);
  if (str != NULL)
    fprintf (fout, "color: %s\n", str);

  /* node.color */
  str = gdl_get_graph_node_color_s (graph);
  if (str != NULL)
    fprintf (fout, "node.color: %s\n", str);

  /* node.borderwidth */
  val = gdl_get_graph_node_borderwidth (graph);
  if (val != -1)
    fprintf (fout, "node.borderwidth: %d\n", val);

  /* node.margin */
  //val = gdl_get_graph_node_margin (graph);
  //if (val != -1)
  //  fprintf (fout, "node.margin: %d\n", val);

  /* edge.thickness */
  val = gdl_get_graph_edge_thickness (graph);
  if (val != -1)
    fprintf (fout, "edge.thickness: %d\n", val);

  /* folding */
  val = gdl_get_graph_folding (graph);
  if (val != -1)
    fprintf (fout, "folding: %d\n", val);

  /* vertical order */
  val = gdl_get_graph_vertical_order (graph);
  if (val != -1)
    fprintf (fout, "vertical_order: %d\n", val);

  /* splines */
  str = gdl_get_graph_splines (graph);
  if (str != NULL)
    fprintf (fout, "splines: %s\n", str);

  /* shape */
  str = gdl_get_graph_shape_s (graph);
  if (str != NULL)
    fprintf (fout, "shape: %s\n", str);

  /* layoutalgorithm */
  //str = gdl_get_graph_layout_algorithm_s (graph);
  //if (str != NULL)
  //  fprintf (fout, "layoutalgorithm: %s\n", str);

  /* near_edges */
  val = gdl_get_graph_near_edges (graph);
  if (val != -1)
    fprintf (fout, "near_edges: %s\n", val ? "yes" : "no");

  /* port_sharing */
  val = gdl_get_graph_port_sharing (graph);
  if (val != -1)
    fprintf (fout, "port_sharing: %s\n", val ? "yes" : "no");
}
static void
vcg_dump_graph (FILE *fout, struct gdl_graph *graph)
{
  struct gdl_node *nodes, *node;
  struct gdl_edge *edges, *edge;
  struct gdl_graph *subgraphs, *subgraph;

  fputs ("graph: {\n", fout);

  /* general graph attributes */
  output_graph_attributes (fout, graph);

  /* list of nodes or subgraphs */
  nodes = gdl_get_graph_node (graph);
  for (node = nodes; node != NULL; node = node->next)
    output_node (fout, node);

  subgraphs = gdl_get_graph_subgraph (graph);
  for (subgraph = subgraphs; subgraph != NULL; subgraph = subgraph->next)
    output_graph (fout, subgraph);

  /* list of edges */
  edges = gdl_get_graph_edge (graph);
  for (edge = edges; edge != NULL; edge = edge->next)
    output_edge (fout, edge);

  fputs ("}\n", fout);
}

static void
vcg_dump (void)
{
  vcg_dump_graph (fout, vcg_plugin_top_graph);
}

static void
vcg_show ()
{
  char *cmd;
  pid_t pid;

  cmd = concat (vcg_viewer, " ", filename, NULL);
  pid = fork ();
  if (pid == 0)
    {
      system (cmd);
      exit (0);
    }
}

struct vcg_plugin vcg =
{
  "vcg_plugin",
  "0.1",
  "vcgview",
  vcg_init,
  vcg_dump,
  vcg_show
};
