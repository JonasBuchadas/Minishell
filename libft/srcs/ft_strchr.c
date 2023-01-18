/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:35:27 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 15:05:15 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The strchr() function locates the first occurrence of c (converted to a char) 
in the string pointed to by s. 
The terminating null character is considered to be part of the string; therefore
if c is `\0', the functions locate the terminating `\0'.
The strrchr() function is identical to strchr(), except it locates the 
last occurrence of c.

RETURN VALUES
The functions strchr() and strrchr() return a pointer to the located character, 
or NULL if the character does not appear in the string.
*/

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	if (!s)
		return (NULL);
	i = -1;
	ch = c;
	while (s[++i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
	}
	if (s[i] == ch)
		return ((char *)s + i);
	return (NULL);
}
