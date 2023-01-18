/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:38:13 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 15:28:00 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Allocates (with malloc(3)) and returns a copy of’s1’ with the characters 
specified in ’set’ removed from the beginning and the end of the string.
*/

#include <stddef.h>
#include "libft.h"

static int	check_set(const char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*strtrim;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && (check_set(s1[start], set) == 1))
		start++;
	end = ft_strlen(s1);
	while ((check_set(s1[end - 1], set) == 1) && end > start)
		end--;
	strtrim = ft_substr(s1, start, end - start);
	return (strtrim);
}

static int	check_set(const char c, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}
