/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbicanic <rbicanic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 01:12:11 by rbicanic          #+#    #+#             */
/*   Updated: 2021/11/28 12:59:55 by rbicanic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static int	trimmed_len(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(s1[start], set))
		start++;
	while (is_set(s1[end], set))
		end--;
	return (end - start + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	char		*dest;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	if ((!s1[0] && !set[0]) || trimmed_len(s1, set) < 1)
	{
		dest = malloc(sizeof(char) * 1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	dest = malloc(sizeof(char) * (trimmed_len(s1, set) + 1));
	if (dest == NULL)
		return (NULL);
	while (is_set(s1[i], set))
		i++;
	ft_strlcpy(dest, &s1[i], trimmed_len(s1, set) + 1);
	return (dest);
}
