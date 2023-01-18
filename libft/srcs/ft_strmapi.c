/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:36:37 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 15:22:41 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Applies the function ’f’ to each character ofthe string ’s’, and passing its 
index as first argument to create a new string (with malloc(3)) resulting from 
successive applications of ’f’.
*/

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str || !f)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = f(i, s[i]);
	str[i] = 0;
	return (str);
}
