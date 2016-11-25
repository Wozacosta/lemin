/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:14:51 by srabah-m          #+#    #+#             */
/*   Updated: 2014/03/23 21:40:42 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ant(int id, int i, t_adj_list next)
{
	int			ant_nb;

	while (next)
	{
		if (g_nodes[next->id].ant == 0)
		{
			if (id == 0)
			{
				ant_nb = g_nb_ants - g_nb_start + 1;
				g_nb_start--;
			}
			else
			{
				ant_nb = g_nodes[id].ant;
				g_nodes[id].ant = 0;
			}
			if (next->id != 1)
				g_nodes[next->id].ant = ant_nb;
			else
				g_nb_end++;
			display_move(ant_nb, g_nodes[next->id].name, i);
			return ;
		}
		next = next->next;
	}
}

void	move_bfs(int i)
{
	int			id;
	t_adj_list	adj_list;

	queue_enqueue(g_queue, 1);
	g_nodes[1].visited = 1;
	while ((!queue_empty(g_queue)))
	{
		id = queue_dequeue(g_queue);
		adj_list = g_graph->adj_list_array[id];
		while (adj_list)
		{
			if ((g_nodes[adj_list->id].visited == 0) || (adj_list->id == 0))
			{
				if (((adj_list->id != 0) && g_nodes[adj_list->id].ant > 0)
					|| (adj_list->id == 0 && g_nb_start > 0))
					move_ant(adj_list->id, i, g_nodes[id].bfs_next);
				if (adj_list->id != 0)
				{
					queue_enqueue(g_queue, adj_list->id);
					g_nodes[adj_list->id].visited = 1;
				}
			}
			adj_list = adj_list->next;
		}
	}
}

void	de_visit(void)
{
	int	i;

	i = -1;
	while (++i < g_nb_nodes)
		g_nodes[i].visited = 0;
}

void	move(void)
{
	int	i;

	g_nb_start = g_nb_ants;
	g_nodes[0].ant = 0;
	g_nb_end = 0;
	i = 0;
	while (g_nb_end != g_nb_ants && i < (g_nb_ants * (g_nb_nodes * g_nb_nodes)))
	{
		de_visit();
		g_queue->front = 0;
		g_queue->rear = 0;
		g_queue->n_values = 0;
		move_bfs(i++);
	}
	ft_putchar('\n');
}
