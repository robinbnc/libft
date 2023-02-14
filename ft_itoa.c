/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:08:55 by rbicanic          #+#    #+#             */
/*   Updated: 2021/11/28 17:00:08 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		nbr_len;

	nbr_len = nb_len(n);
	nbr = malloc(sizeof(char) * (nbr_len + 1));
	if (nbr == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(nbr, "-2147483648", 12);
		return (nbr);
	}
	nbr[nbr_len] = '\0';
	if (n < 0)
	{
		n = -n;
		nbr[0] = '-';
	}
	while (n > 9)
	{
		nbr[--nbr_len] = n % 10 + 48;
		n /= 10;
	}
	nbr[--nbr_len] = n % 10 + 48;
	return (nbr);
}
