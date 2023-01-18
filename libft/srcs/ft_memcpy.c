/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:32:51 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/28 12:15:17 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The ft_memcpy() function copies n bytes from memory area src to memory area dst.
The memory areas must not overlap.
RETURN VALUE
The ft_memcpy() function returns a pointer to dst.
*/

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	i = -1;
	while (++i < n)
		*(unsigned char *)(dst + i) = *(const unsigned char *)(src + i);
	return (dst);
}
