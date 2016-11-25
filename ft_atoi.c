/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:59:18 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 22:59:27 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	is_atoi_ignored(char c)
{
	return (c == '\n' || c == '\v' || c == '\t' || c == '\r'
		|| c == '\f' || c == ' ');
}

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long long	result;
	int					is_neg;
	int					i;

	while (is_atoi_ignored(*str))
		str++;
	result = 0;
	is_neg = str && *str == '-';
	i = str && (*str == '-' || *str == '+');
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - '0');
	if (is_neg)
		return (-result);
	return (result);
}
