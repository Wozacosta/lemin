/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:04:57 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 23:05:21 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		parse_anthill_room(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == 'L' || str[i] == '#')
			return (ft_error("Bad room names, no L and # allowed"));
		i++;
	}
	if (i == 0)
		return (0);
	g_nodes[g_nb_nodes].name = ft_strndup(str, i);
	g_nodes[g_nb_nodes].dist = INFINITY;
	g_nodes[g_nb_nodes].visited = 0;
	g_nodes[g_nb_nodes++].ant = 0;
	parse_anthill_coord(str + i, g_nb_nodes - 1);
	return (1);
}

int		parse_anthill(char *str)
{
	if (ft_strncmp(str, "##", 2) == 0)
		return (parse_cmd(str));
	else if ((ft_strchr(str, '-')) && (!ft_strchr(str, ' ')))
		return (add_link(str));
	else if (ft_strncmp(str, "#", 1) != 0)
		return (parse_anthill_room(str));
	return (1);
}

void	get_anthill(void)
{
	char	*line;
	int		ret;
	int		ret_parse;

	ret_parse = 1;
	while ((ret_parse != 0) && ((ret = (get_next_line(0, &line))) >= 0))
		ret_parse = parse_anthill(line);
	if (ret < 0)
		ft_fatal("Couldn't read the input :(");
	if (!g_end_set || !g_start_set)
		ft_fatal("Bad input, end/start not set properly :s");
}
