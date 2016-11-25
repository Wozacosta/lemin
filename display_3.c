/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:06:22 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 23:33:41 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		get_end_name(void)
{
	char	*str;
	int		i;
	int		ret;

	ret = 1;
	if (get_next_line(0, &str) < 0)
		return (ft_error("Bad input (end_name)"));
	while ((str && str[0] == '#') && (ret >= 0))
		ret = get_next_line(0, &str);
	if (ret <= 0)
		return (ft_error("Bad input (end_name)"));
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\r')
		i++;
	if (i == 0)
		return (0);
	g_nodes[1].name = ft_strndup(str, i);
	g_nodes[1].dist = 0;
	g_nodes[1].ant = 0;
	g_nodes[1].visited = 0;
	parse_anthill_coord(str + i, 1);
	g_end_set = 1;
	return (1);
}

int		parse_cmd(char *str)
{
	if ((ft_strcmp(str, "##start") == 0) || (ft_strcmp(str, "##start\r") == 0))
		return (get_start_name());
	else if ((ft_strcmp(str, "##end") == 0) || (ft_strcmp(str, "##end\r") == 0))
		return (get_end_name());
	return (1);
}

int		find_node(char *name)
{
	int	i;

	i = 0;
	while (i < g_nb_nodes)
	{
		if (ft_strcmp(name, g_nodes[i].name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int		add_link_both(char *a, char *b)
{
	int	a_id;
	int	b_id;

	if ((a_id = find_node(a)) == -1)
		return (0);
	if ((b_id = find_node(b)) == -1)
		return (0);
	add_edge(g_graph, a_id, b_id);
	return (1);
}

int		add_link(char *str)
{
	char	*room_a;
	char	*room_b;
	int		i;

	i = 0;
	while (str[i] && str[i] != '-')
		i++;
	if ((i == 0) || (!g_end_set || !g_start_set))
		return (0);
	room_a = ft_strndup(str, i++);
	str += i;
	i = 0;
	while (str[i] != '\0' && str[i] != '\r')
		i++;
	if (i == 0)
		return (0);
	room_b = ft_strndup(str, i);
	return (add_link_both(room_a, room_b));
}
