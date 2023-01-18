/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:33:03 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/28 12:19:49 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The ft_memmove() function copies len bytes from memory area src to memory area
dst. The memory areas may overlap.
RETURN VALUE
The ft_memmove() function returns a pointer to dst.
*/

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL && len != 0)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			*(unsigned char *)(dst + i) = *(const unsigned char *)(src + i);
	}
	else
	{
		i = -1;
		while (++i < len)
			*(unsigned char *)(dst + i) = *(const unsigned char *)(src + i);
	}
	return (dst);
}
