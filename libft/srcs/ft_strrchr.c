/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:37:59 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 15:26:43 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The strrchr() function is identical to strchr(), except it locates the last 
occurrence of c.
*/

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == ch)
		return ((char *)s + i);
	return (NULL);
}
