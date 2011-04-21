/* Graph description languange.

   Copyright (C) 2009, 2010, 2011 Mingjie Xing, mingjie.xing@gmail.com. 

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <error.h>
#include <libiberty.h>

#include "gdl.h"

/* Functions to get the attributes.  */

char *
gdl_get_node_bordercolor (gdl_node *node)
{
  return node->bordercolor;
}

int
gdl_get_node_borderwidth (gdl_node *node)
{
  return node->borderwidth;
}

char *
gdl_get_node_color (gdl_node *node)
{
  return node->color;
}

char *
gdl_get_node_label (gdl_node *node)
{
  return node->label;
}

char *
gdl_get_node_title (gdl_node *node)
{
  return node->title;
}

int
gdl_get_node_vertical_order (gdl_node *node)
{
  return node->vertical_order;
}

char *
gdl_get_edge_label (gdl_edge *edge)
{
  return edge->label;
}

char *
gdl_get_edge_linestyle (gdl_edge *edge)
{
  return edge->linestyle;
}

char *
gdl_get_edge_sourcename (gdl_edge *edge)
{
  return edge->sourcename;
}

char *
gdl_get_edge_targetname (gdl_edge *edge)
{
  return edge->targetname;
}

int
gdl_get_edge_thickness (gdl_edge *edge)
{
  return edge->thickness;
}

char *
gdl_get_graph_color (gdl_graph *graph)
{
  return graph->color;
}

int
gdl_get_graph_folding (gdl_graph *graph)
{
  return graph->folding;
}

char *
gdl_get_graph_label (gdl_graph *graph)
{
  return graph->label;
}

char *
gdl_get_graph_layout_algorithm (gdl_graph *graph)
{
  return graph->layout_algorithm;
}

char *
gdl_get_graph_near_edges (gdl_graph *graph)
{
  return graph->near_edges;
}

char *
gdl_get_graph_orientation (gdl_graph *graph)
{
  return graph->orientation;
}

char *
gdl_get_graph_port_sharing (gdl_graph *graph)
{
  return graph->port_sharing;
}

char *
gdl_get_graph_shape (gdl_graph *graph)
{
  return graph->shape;
}

char *
gdl_get_graph_splines (gdl_graph *graph)
{
  return graph->splines;
}

char *
gdl_get_graph_title (gdl_graph *graph)
{
  return graph->title;
}

int
gdl_get_graph_vertical_order (gdl_graph *graph)
{
  return graph->vertical_order;
}

int
gdl_get_graph_xspace (gdl_graph *graph)
{
  return graph->xspace;
}

int
gdl_get_graph_yspace (gdl_graph *graph)
{
  return graph->yspace;
}

int
gdl_get_graph_node_borderwidth (gdl_graph *graph)
{
  return graph->node_borderwidth;
}

char *
gdl_get_graph_node_color (gdl_graph *graph)
{
  return graph->node_color;
}

char *
gdl_get_graph_node_shape (gdl_graph *graph)
{
  return graph->node_shape;
}

char *
gdl_get_graph_edge_color (gdl_graph *graph)
{
  return graph->edge_color;
}

int
gdl_get_graph_edge_thickness (gdl_graph *graph)
{
  return graph->edge_thickness;
}

/* Functions to set the attributes.  */

void
gdl_set_node_bordercolor (gdl_node *node, char *value)
{
  node->set_p[GDL_NODE_ATTR_bordercolor] = 1;
  node->bordercolor = value;
}

void
gdl_set_node_borderwidth (gdl_node *node, int value)
{
  node->set_p[GDL_NODE_ATTR_borderwidth] = 1;
  node->borderwidth = value;
}

void
gdl_set_node_color (gdl_node *node, char *value)
{
  node->set_p[GDL_NODE_ATTR_color] = 1;
  node->color = value;
}

void
gdl_set_node_label (gdl_node *node, char *value)
{
  node->set_p[GDL_NODE_ATTR_label] = 1;
  node->label = value;
}

void
gdl_set_node_title (gdl_node *node, char *value)
{
  node->set_p[GDL_NODE_ATTR_title] = 1;
  node->title = value;
}

void
gdl_set_node_vertical_order (gdl_node *node, int value)
{
  node->set_p[GDL_NODE_ATTR_vertical_order] = 1;
  node->vertical_order = value;
}

void
gdl_set_edge_label (gdl_edge *edge, char *value)
{
  edge->set_p[GDL_EDGE_ATTR_label] = 1;
  edge->label = value;
}

void
gdl_set_edge_linestyle (gdl_edge *edge, char *value)
{
  edge->set_p[GDL_EDGE_ATTR_linestyle] = 1;
  edge->linestyle = value;
}

void
gdl_set_edge_sourcename (gdl_edge *edge, char *value)
{
  edge->set_p[GDL_EDGE_ATTR_sourcename] = 1;
  edge->sourcename = value;
}

void
gdl_set_edge_targetname (gdl_edge *edge, char *value)
{
  edge->set_p[GDL_EDGE_ATTR_targetname] = 1;
  edge->targetname = value;
}

void
gdl_set_edge_thickness (gdl_edge *edge, int value)
{
  edge->set_p[GDL_EDGE_ATTR_thickness] = 1;
  edge->thickness = value;
}

void
gdl_set_graph_color (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_color] = 1;
  graph->color = value;
}

void
gdl_set_graph_folding (gdl_graph *graph, int value)
{
  graph->set_p[GDL_GRAPH_ATTR_folding] = 1;
  graph->folding = value;
}

void
gdl_set_graph_label (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_label] = 1;
  graph->label = value;
}

void
gdl_set_graph_layout_algorithm (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_layout_algorithm] = 1;
  graph->layout_algorithm = value;
}

void
gdl_set_graph_near_edges (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_near_edges] = 1;
  graph->near_edges = value;
}

void
gdl_set_graph_orientation (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_orientation] = 1;
  graph->orientation = value;
}

void
gdl_set_graph_port_sharing (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_port_sharing] = 1;
  graph->port_sharing = value;
}

void
gdl_set_graph_shape (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_shape] = 1;
  graph->shape = value;
}

void
gdl_set_graph_splines (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_splines] = 1;
  graph->splines = value;
}

void
gdl_set_graph_title (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_title] = 1;
  graph->title = value;
}

void
gdl_set_graph_vertical_order (gdl_graph *graph, int value)
{
  graph->set_p[GDL_GRAPH_ATTR_vertical_order] = 1;
  graph->vertical_order = value;
}

void
gdl_set_graph_xspace (gdl_graph *graph, int value)
{
  graph->set_p[GDL_GRAPH_ATTR_xspace] = 1;
  graph->xspace = value;
}

void
gdl_set_graph_yspace (gdl_graph *graph, int value)
{
  graph->set_p[GDL_GRAPH_ATTR_yspace] = 1;
  graph->yspace = value;
}

void
gdl_set_graph_node_borderwidth (gdl_graph *graph, int value)
{
  graph->set_p[GDL_GRAPH_ATTR_node_borderwidth] = 1;
  graph->node_borderwidth = value;
}

void
gdl_set_graph_node_color (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_node_color] = 1;
  graph->node_color = value;
}

void
gdl_set_graph_node_shape (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_node_shape] = 1;
  graph->node_shape = value;
}

void
gdl_set_graph_edge_color (gdl_graph *graph, char *value)
{
  graph->set_p[GDL_GRAPH_ATTR_edge_color] = 1;
  graph->edge_color = value;
}

void
gdl_set_graph_edge_thickness (gdl_graph *graph, int value)
{
  graph->set_p[GDL_GRAPH_ATTR_edge_thickness] = 1;
  graph->edge_thickness = value;
}

/* Other functions to access structure fields.  */

gdl_node *
gdl_get_graph_node (gdl_graph *graph)
{
  return graph->node;
}

gdl_edge *
gdl_get_graph_edge (gdl_graph *graph)
{
  return graph->edge;
}

gdl_graph *
gdl_get_graph_subgraph (gdl_graph *graph)
{
  return graph->subgraph;
}

gdl_graph *
gdl_get_graph_parent (gdl_graph *graph)
{
  return graph->parent;
}

gdl_graph *
gdl_get_node_parent (gdl_node *node)
{
  return node->parent;
}

gdl_edge_type 
gdl_get_edge_type (gdl_edge *edge)
{
  return edge->type;
}

void
gdl_set_edge_type (gdl_edge *edge, gdl_edge_type type)
{
  edge->type = type;
}

/* Create a node for a given TITLE.  */

gdl_node *
gdl_new_node (const char *title)
{
  gdl_node *node;

  node = XNEW (gdl_node);
  memset (node->set_p, 0, GDL_NODE_ATTR_MAX * sizeof (int));

  /* Duplicate the string.  */
  gdl_set_node_title (node, strdup (title));

  node->next = NULL;
  node->parent = NULL;
  
  return node;
}

/* Create an edge for a given SOURCE and TARGET.  */

gdl_edge *
gdl_new_edge (const char *source, const char *target)
{
  gdl_edge *edge;

  edge = XNEW (gdl_edge);
  memset (edge->set_p, 0, GDL_EDGE_ATTR_MAX * sizeof (int));

  /* Duplicate the string.  */
  gdl_set_edge_sourcename (edge, strdup (source));
  gdl_set_edge_targetname (edge, strdup (target));

  edge->type = GDL_EDGE;
  edge->next = NULL;
  
  return edge;
}

/* Create a graph for a given TITLE.  */

gdl_graph *
gdl_new_graph (const char *title)
{
  gdl_graph *graph;

  graph = XNEW (gdl_graph);
  memset (graph->set_p, 0, GDL_GRAPH_ATTR_MAX * sizeof (int));

  /* Duplicate the string.  */
  gdl_set_graph_title (graph, strdup (title));

  graph->node = NULL;
  graph->last_node = NULL;
  graph->subgraph = NULL;
  graph->last_subgraph = NULL;
  graph->edge = NULL;
  graph->last_edge = NULL;
  graph->next = NULL;
  graph->parent = NULL;

  return graph;
}

/* Free the NODE.  */

void
gdl_free_node (gdl_node *node)
{
  free (node->title);
  free (node);
}

/* Free the EDGE.  */

void
gdl_free_edge (gdl_edge *edge)
{
  free (edge->sourcename);
  free (edge->targetname);
  free (edge);
}

/* Free the GRAPH.  */

void
gdl_free_graph (gdl_graph *graph)
{
  gdl_graph *subgraphs, *subgraph, *next_subgraph;
  gdl_node *nodes, *node, *next_node;
  gdl_edge *edges, *edge, *next_edge;

  /* Free the nodes.  */
  nodes = gdl_get_graph_node (graph);
  for (node = nodes; node != NULL;)
    {
      next_node = node->next;
      gdl_free_node (node);
      node = next_node;
    }

  /* Free the edges.  */
  edges = gdl_get_graph_edge (graph);
  for (edge = edges; edge != NULL;)
    {
      next_edge = edge->next;
      gdl_free_edge (edge);
      edge = next_edge;
    }

  /* Free the subgraphs.  */
  subgraphs = gdl_get_graph_subgraph (graph);
  for (subgraph = subgraphs; subgraph != NULL;)
    {
      next_subgraph = subgraph->next;
      gdl_free_graph (subgraph);
      subgraph = next_subgraph;
    }

  /* Free the graph.  */
  free (graph->title);
  free (graph);
}

/* Add NODE into GRAPH.  */

void 
gdl_add_node (gdl_graph *graph, gdl_node *node)
{
  if (graph->node == NULL)
    {
      graph->node = node;
      graph->last_node = node;
    }
  else
    {
      graph->last_node->next = node;
      graph->last_node = node;
    }
  node->parent = graph;
}

/* Add EDGE into GRAPH.  */

void 
gdl_add_edge (gdl_graph *graph, gdl_edge *edge)
{
  if (graph->edge == NULL)
    {
      graph->edge = edge;
      graph->last_edge = edge;
    }
  else
    {
      graph->last_edge->next = edge;
      graph->last_edge = edge;
    }
}

/* Add SUBGRAPH into GRAPH.  */

void 
gdl_add_subgraph (gdl_graph *graph, gdl_graph *subgraph)
{
  if (graph->subgraph == NULL)
    {
      graph->subgraph = subgraph;
      graph->last_subgraph = subgraph;
    }
  else
    {
      graph->last_subgraph->next = subgraph;
      graph->last_subgraph = subgraph;
    }
  subgraph->parent = graph;
}

/* Find the node in GRAPH for a given TITLE.  */

gdl_node *
gdl_find_node (gdl_graph *graph, char *title)
{
  gdl_node *nodes, *node;

  nodes = gdl_get_graph_node (graph); 
  for (node = nodes; node; node = node->next)
    if (!strcmp (gdl_get_node_title (node), title))
      return node;

  return NULL;
}

/* Find the edge in GRAPH for a given SOURCE and TARGET.  */

gdl_edge *
gdl_find_edge (gdl_graph *graph, char *source, char *target)
{
  gdl_edge *edges, *edge;
  char *srcname, *destname;

  edges = gdl_get_graph_edge (graph); 
  for (edge = edges; edge; edge = edge->next)
    {
      srcname = gdl_get_edge_sourcename (edge);
      destname = gdl_get_edge_targetname (edge);
      if (!strcmp (srcname, source) && !strcmp (destname, target))
        return edge;
    }

  return NULL;
}

/* Find the subgraph in GRAPH for a given TITLE.  */

gdl_graph *
gdl_find_subgraph (gdl_graph *graph, char *title)
{
  gdl_graph *subgraphs, *subgraph;
  
  subgraphs = gdl_get_graph_subgraph (graph);
  for (subgraph = subgraphs; subgraph; subgraph = subgraph->next)
    if (!strcmp (gdl_get_graph_title (subgraph), title))
      return subgraph;

  return NULL;
}

/* Print the string into the file and add a '\' before each '"'.  */

static inline void
print_string (FILE *fout, const char *str)
{
  int i;

  for (i = 0; i < strlen (str); i++)
    {
      if (str[i] == '"')
        fprintf (fout,  "\\");
      fprintf (fout, "%c", str[i]);
    }
}

/* Dump NODE into the file.  */

void
gdl_dump_node (FILE *fout, gdl_node *node)
{
  fputs ("node: {\n", fout);

  /* Dump the attributes.  */

  if (node->set_p[GDL_NODE_ATTR_bordercolor])
    {
      fprintf (fout, "bordercolor: %s\n", node->bordercolor);
    }

  if (node->set_p[GDL_NODE_ATTR_borderwidth])
    {
      fprintf (fout, "borderwidth: %d\n", node->borderwidth);
    }

  if (node->set_p[GDL_NODE_ATTR_color])
    {
      fprintf (fout, "color: %s\n", node->color);
    }

  if (node->set_p[GDL_NODE_ATTR_label])
    {
      fprintf (fout, "label: \"");
      print_string (fout, node->label);
      fprintf (fout, "\"\n");
    }

  if (node->set_p[GDL_NODE_ATTR_title])
    {
      fprintf (fout, "title: \"");
      print_string (fout, node->title);
      fprintf (fout, "\"\n");
    }

  if (node->set_p[GDL_NODE_ATTR_vertical_order])
    {
      fprintf (fout, "vertical_order: %d\n", node->vertical_order);
    }

  fputs ("}\n", fout);
}

/* Dump EDGE into the file.  */

void
gdl_dump_edge (FILE *fout, gdl_edge *edge)
{
  switch (edge->type)
    {
    case GDL_EDGE:
      fputs ("edge: {\n", fout);
      break;
    case GDL_BACKEDGE:
      fputs ("backedge: {\n", fout);
      break;
    case GDL_NEAREDGE:
      fputs ("nearedge: {\n", fout);
      break;
    case GDL_LEFTNEAREDGE:
      fputs ("leftnearedge: {\n", fout);
      break;
    case GDL_RIGHTNEAREDGE:
      fputs ("rightnearedge: {\n", fout);
      break;
    case GDL_BENTNEAREDGE:
      fputs ("bentnearedge: {\n", fout);
      break;
    case GDL_LEFTBENTNEAREDGE:
      fputs ("leftbentnearedge: {\n", fout);
      break;
    case GDL_RIGHTBENTNEAREDGE:
      fputs ("rightbentnearedge: {\n", fout);
      break;
    default:
      abort ();
    }

  /* Dump the attributes.  */

  if (edge->set_p[GDL_EDGE_ATTR_label])
    {
      fprintf (fout, "label: \"");
      print_string (fout, edge->label);
      fprintf (fout, "\"\n");
    }

  if (edge->set_p[GDL_EDGE_ATTR_linestyle])
    {
      fprintf (fout, "linestyle: %s\n", edge->linestyle);
    }

  if (edge->set_p[GDL_EDGE_ATTR_sourcename])
    {
      fprintf (fout, "sourcename: \"");
      print_string (fout, edge->sourcename);
      fprintf (fout, "\"\n");
    }

  if (edge->set_p[GDL_EDGE_ATTR_targetname])
    {
      fprintf (fout, "targetname: \"");
      print_string (fout, edge->targetname);
      fprintf (fout, "\"\n");
    }

  if (edge->set_p[GDL_EDGE_ATTR_thickness])
    {
      fprintf (fout, "thickness: %d\n", edge->thickness);
    }

  fputs ("}\n", fout);
}

/* Dump GRAPH into the file.  */

void
gdl_dump_graph (FILE *fout, gdl_graph *graph)
{
  gdl_node *nodes, *node;
  gdl_edge *edges, *edge;
  gdl_graph *subgraphs, *subgraph;

  fputs ("graph: {\n", fout);

  /* Dump the attributes.  */

  if (graph->set_p[GDL_GRAPH_ATTR_color])
    {
      fprintf (fout, "color: %s\n", graph->color);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_folding])
    {
      fprintf (fout, "folding: %d\n", graph->folding);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_label])
    {
      fprintf (fout, "label: \"");
      print_string (fout, graph->label);
      fprintf (fout, "\"\n");
    }

  if (graph->set_p[GDL_GRAPH_ATTR_layout_algorithm])
    {
      fprintf (fout, "layout_algorithm: %s\n", graph->layout_algorithm);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_near_edges])
    {
      fprintf (fout, "near_edges: %s\n", graph->near_edges);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_orientation])
    {
      fprintf (fout, "orientation: %s\n", graph->orientation);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_port_sharing])
    {
      fprintf (fout, "port_sharing: %s\n", graph->port_sharing);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_shape])
    {
      fprintf (fout, "shape: %s\n", graph->shape);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_title])
    {
      fprintf (fout, "title: \"");
      print_string (fout, graph->title);
      fprintf (fout, "\"\n");
    }

  if (graph->set_p[GDL_GRAPH_ATTR_vertical_order])
    {
      fprintf (fout, "vertical_order: %d\n", graph->vertical_order);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_xspace])
    {
      fprintf (fout, "xspace: %d\n", graph->xspace);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_yspace])
    {
      fprintf (fout, "yspace: %d\n", graph->yspace);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_node_borderwidth])
    {
      fprintf (fout, "node.borderwidth: %d\n", graph->node_borderwidth);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_node_color])
    {
      fprintf (fout, "node.color: %s\n", graph->node_color);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_node_shape])
    {
      fprintf (fout, "node.shape: %s\n", graph->node_shape);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_edge_color])
    {
      fprintf (fout, "edge.color: %s\n", graph->edge_color);
    }

  if (graph->set_p[GDL_GRAPH_ATTR_edge_thickness])
    {
      fprintf (fout, "edge.thickness: %d\n", graph->edge_thickness);
    }

  /* Dump the nodes.  */
  nodes = gdl_get_graph_node (graph);
  for (node = nodes; node != NULL; node = node->next)
    gdl_dump_node (fout, node);

  /* Dump the subgraphs.  */
  subgraphs = gdl_get_graph_subgraph (graph);
  for (subgraph = subgraphs; subgraph != NULL; subgraph = subgraph->next)
    gdl_dump_graph (fout, subgraph);

  /* Dump the edges.  */
  edges = gdl_get_graph_edge (graph);
  for (edge = edges; edge != NULL; edge = edge->next)
    gdl_dump_edge (fout, edge);

  fputs ("}\n", fout);
}

