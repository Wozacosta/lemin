/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:02:23 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 23:11:08 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		g_nb_ants;
int		g_nb_nodes;
int		g_start_set;
int		g_end_set;
int		g_nb_start;
int		g_nb_end;
t_node	g_nodes[NB_NODES_MAX];
t_graph	*g_graph;

int		main(void)
{
	g_nb_nodes = 2;
	g_graph = create_graph(NB_NODES_MAX);
	get_nb_ants();
	get_anthill();
	display_anthill(g_graph);
	bfs();
	move();
	queue_destroy(g_queue);
	return (0);
}
