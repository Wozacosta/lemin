/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:03:43 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 23:33:26 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	display_coord_node(int id)
{
	if (id == 0)
		ft_putendl("##start");
	else if (id == 1)
		ft_putendl("##end");
	ft_putstr(g_nodes[id].name);
	ft_putstr(" ");
	ft_putstr(ft_itoa(g_nodes[id].coord[0]));
	ft_putstr(" ");
	ft_putendl(ft_itoa(g_nodes[id].coord[1]));
}

void	set_as_displayed(char *from, char *to)
{
	int			i;
	t_adj_list	adj_list;

	i = -1;
	while (++i < g_nb_nodes)
	{
		if (ft_strcmp(g_nodes[i].name, from) == 0)
		{
			adj_list = g_graph->adj_list_array[i];
			while (adj_list)
			{
				if (ft_strcmp(g_nodes[adj_list->id].name, to) == 0)
					adj_list->displayed = 1;
				adj_list = adj_list->next;
			}
			return ;
		}
	}
}

void	display_anthill(t_graph *graph)
{
	int			i;
	t_adj_list	adj_list;

	ft_putendl(ft_itoa(g_nb_ants));
	i = 0;
	while (i < g_nb_nodes)
		display_coord_node(i++);
	i = -1;
	while (++i < g_nb_nodes)
	{
		adj_list = graph->adj_list_array[i];
		while (adj_list)
		{
			if (!adj_list->displayed)
			{
				ft_putstr(g_nodes[i].name);
				ft_putchar('-');
				ft_putendl(g_nodes[adj_list->id].name);
				adj_list->displayed = 1;
				set_as_displayed(g_nodes[adj_list->id].name, g_nodes[i].name);
				set_as_displayed(g_nodes[i].name, g_nodes[adj_list->id].name);
			}
			adj_list = adj_list->next;
		}
	}
}
