/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_graph.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:07:55 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 23:08:33 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph		*create_graph(int n)
{
	int		i;
	t_graph	*new_graph;

	new_graph = (t_graph *)malloc(sizeof(t_graph));
	new_graph->nb_vertices = n;
	new_graph->adj_list_array = (t_adj_list *)malloc(n * (sizeof(t_adj_list)));
	i = -1;
	while (++i < n)
		new_graph->adj_list_array[i] = NULL;
	return (new_graph);
}

t_adj_node	*create_adj_node(int id)
{
	t_adj_node	*new;

	new = (t_adj_node *)malloc(sizeof(t_adj_node));
	new->id = id;
	new->displayed = 0;
	new->next = NULL;
	return (new);
}

void		add_next(int tail, int head)
{
	t_adj_node	*new_node;
	t_adj_list	next_list;

	new_node = create_adj_node(head);
	next_list = g_nodes[tail].bfs_next;
	if (next_list == NULL)
		g_nodes[tail].bfs_next = new_node;
	else
	{
		while (next_list->next)
			next_list = next_list->next;
		next_list->next = new_node;
	}
}

void		add_edge_directed(t_graph *graph, int a, int b)
{
	t_adj_node	*new_node;

	new_node = create_adj_node(b);
	new_node->next = graph->adj_list_array[a];
	graph->adj_list_array[a] = new_node;
}

void		add_edge(t_graph *graph, int a, int b)
{
	add_edge_directed(graph, a, b);
	add_edge_directed(graph, b, a);
}

