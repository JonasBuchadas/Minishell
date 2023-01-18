/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:38:22 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 15:28:55 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPION
Allocates (with malloc(3)) and returns a substring from the string ’s’. 
The substring begins at index ’start’ and is of maximum size ’len’.
*/

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	sublen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		sublen = 0;
	else if (ft_strlen(s) <= len)
		sublen = ft_strlen(s) - start;
	else
		sublen = len;
	substr = (char *)malloc(sizeof(char) * (sublen + 1));
	if (!substr)
		return (NULL);
	i = -1;
	while (++i < sublen)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
