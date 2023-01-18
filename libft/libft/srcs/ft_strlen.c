/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:22 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/18 17:27:48 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The ft_strlen() function calculates the length of the string pointed to by s, 
excluding the terminating null byte ('\0').
RETURN VALUE
The ft_strlen() function returns the number of bytes in the string pointed
to by s.
*/

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
