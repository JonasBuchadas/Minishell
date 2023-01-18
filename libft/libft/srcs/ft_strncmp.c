/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:49 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/28 12:55:54 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The strncmp() function compares not more than n characters. 
Because strncmp() is designed for comparing strings rather than binary data, 
characters that appear after a `\0' character are not compared.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			maxlen;
	unsigned char	c1;
	unsigned char	c2;

	if (ft_strlen(s1) > ft_strlen(s2))
		maxlen = ft_strlen(s1);
	else
		maxlen = ft_strlen(s2);
	i = -1;
	while (++i < n && i < maxlen)
	{
		c1 = s1[i];
		c2 = s2[i];
		if ((c1 != c2))
			return (c1 - c2);
	}
	return (0);
}
