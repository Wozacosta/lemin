/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 23:33:52 by srabah-m          #+#    #+#             */
/*   Updated: 2014/03/08 18:20:09 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	get_nb_ants(void)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	while (line && line[0] == '#')
		get_next_line(0, &line);
	i = 0;
	while (line[i] != '\0' && ft_isdigit(line[i]))
		i++;
	g_nb_ants = ft_atoi(line);
	if ((g_nb_ants <= 0))
		ft_fatal("Incorrect number of ants in input !\n");
}

int		parse_anthill_bis(int j)
{
	if (j != 2)
		return (ft_error("Bad input"));
	return (1);
}

int		parse_anthill_coord(char *str, int id)
{
	int		j;
	int		i;
	int		nb;
	int		neg;

	i = 0;
	j = 0;
	neg = 1;
	while ((str[i] != '\0') && (str[i] != '\r'))
	{
		i++;
		nb = 0;
		if (str[i] == '-')
			neg = -1;
		while (str[i] && str[i] != ' ' && str[i] != '\r')
		{
			if ((!ft_isdigit(str[i])) && (str[i] != '-'))
				return (ft_error("Bad input"));
			nb = nb * 10 + (str[i++] - '0');
		}
		g_nodes[id].coord[j] = nb * neg;
		j++;
	}
	return (parse_anthill_bis(j));
}

int		get_start_name(void)
{
	char	*str;
	int		i;
	int		ret;

	ret = 1;
	if (get_next_line(0, &str) < 0)
		return (ft_error("Bad input (start name)"));
	while ((str && str[0] == '#') && (ret >= 0))
		ret = get_next_line(0, &str);
	if (ret <= 0)
		return (ft_error("Bad input (start name)"));
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\r')
		i++;
	if (i == 0)
		return (0);
	g_nodes[0].name = ft_strndup(str, i);
	g_nodes[0].dist = INFINITY;
	g_nodes[0].ant = 0;
	g_nodes[0].visited = 0;
	parse_anthill_coord(str + i, 0);
	g_start_set = 1;
	return (1);
}
