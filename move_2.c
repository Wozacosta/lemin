/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:14:46 by srabah-m          #+#    #+#             */
/*   Updated: 2014/03/23 22:11:58 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_queue		*g_queue;

void	queue_destroy(t_queue *queue)
{
	free(queue->data);
	free(queue);
}

void	bfs(void)
{
	int			id;
	t_adj_list	adj_list;

	g_queue = queue_create(g_nb_nodes * g_nb_nodes);
	queue_enqueue(g_queue, 1);
	g_nodes[1].visited = 1;
	while ((!queue_empty(g_queue)))
	{
		id = queue_dequeue(g_queue);
		adj_list = g_graph->adj_list_array[id];
		while (adj_list)
		{
			add_next(adj_list->id, id);
			if (g_nodes[adj_list->id].visited == 0)
			{
				queue_enqueue(g_queue, adj_list->id);
				g_nodes[adj_list->id].visited = 1;
			}
			adj_list = adj_list->next;
		}
	}
}

void	display_move(int ant_nb, char *head, int i)
{
	static int	i_prec = -1;

	if (i != i_prec)
		ft_putchar('\n');
	else if (i == i_prec)
		ft_putchar(' ');
	i_prec = i;
	ft_putchar('L');
	ft_putstr(ft_itoa(ant_nb));
	ft_putchar('-');
	ft_putstr(head);
}

