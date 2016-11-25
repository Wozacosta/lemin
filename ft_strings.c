/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:59:46 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 22:59:48 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

size_t	ft_strlen(const char *str)
{
	const char	*istr;

	istr = str;
	while (*istr)
		++istr;
	return (istr - str);
}

void	ft_putstr(char *str)
{
	write(1, str, (int)ft_strlen(str));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putendl(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}
