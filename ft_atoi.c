/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 01:05:25 by rbicanic          #+#    #+#             */
/*   Updated: 2021/12/02 23:09:59 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int	is_over_max_long(const char *nptr, int sign)
{
	if (ft_len(nptr) > 20)
		return (sign);
	else if (ft_len(nptr) > 18
		&& ft_strncmp("9223372036854775807", nptr, ft_len(nptr)) < 0)
		return (sign);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	int			nbr;
	int			sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && (nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	if (is_over_max_long(&nptr[i], sign) == 1)
		return (-1);
	else if (is_over_max_long(&nptr[i], sign) == -1)
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = nbr * 10 + nptr[i] - 48;
		i++;
	}
	return (nbr * sign);
}
