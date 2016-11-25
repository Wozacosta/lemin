/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srabah-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 22:59:38 by srabah-m          #+#    #+#             */
/*   Updated: 2014/02/23 23:38:59 by srabah-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void ft_reverse(char *str);

char		*ft_strcpy(char *s1, const char *s2)
{
	char	*ptr;

	ptr = s1;
	while (*s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (ptr);
}

char		*ft_itoa(int n)
{
	char	*str;
	char	*ptr;

	if (!(str = (char *) malloc(sizeof(char) * 12)))
		return (NULL);
	ptr = str;
	if (n <= 0)
	{
		if (n == -2147483648)
			return (ft_strcpy(ptr, "-2147483648"));
		if (n == 0)
			return (ft_strcpy(ptr, "0"));
		*ptr++ = '-';
		n *= -1;
	}
	while (n >= 1)
	{
		*ptr++ = n % 10 + '0';
		n = n / 10;
	}
	*ptr = '\0';
	ft_reverse(str);
	return (str);
}

void		ft_reverse(char *str)
{
	char	*ptr;
	char	tmp;

	if (*str == '-')
		str++;
	ptr = str;
	while (*ptr)
		ptr++;
	--ptr;
	while (ptr > str)
	{
		tmp = *str;
		*str++ = *ptr;
		*ptr-- = tmp;
	}
}
