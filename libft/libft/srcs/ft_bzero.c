/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:36:09 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:03:22 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The ft_bzero() function erases the data in the n bytes of the memory starting
at the location pointed to by s, by writing zeros (bytes containing '\0')
to that area.
*/

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		*(unsigned char *)(s + i++) = '\0';
}
