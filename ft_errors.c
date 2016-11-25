/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:59:31 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 22:59:34 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_putstr_fd(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

int		ft_error(const char *str)
{
	ft_putstr_fd(2, "[\x1b[31m");
	ft_putstr_fd(2, "FATAL ERROR\x1b[0m] --> ");
	ft_putstr_fd(2, str);
	ft_putstr_fd(2, "\n");
	return (0);
}

void	ft_fatal(const char *str)
{
	ft_error(str);
	exit(1);
}
