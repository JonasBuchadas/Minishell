/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:03 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/18 13:36:05 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The ft_strlcat() function appends the NUL-terminated string src to the end of 
dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating 
the result.
RETURN VALUES
The ft_strlcat() return the initial length of dst plus the length of src.
*/

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	n1;
	size_t	n2;

	n1 = 0;
	n2 = 0;
	if (size <= ft_strlen((const char *)dst))
		return (ft_strlen(src) + size);
	while (dst[n1] != '\0' && n1 < size)
		n1++;
	n2 = n1;
	while (src[n1 - n2] != '\0' && n1 < size - 1)
	{
		dst[n1] = src[n1 - n2];
		n1++;
	}
	if (n2 < size)
		dst[n1] = '\0';
	return (n2 + ft_strlen(src));
}
