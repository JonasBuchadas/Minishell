/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:03:04 by jocaetan          #+#    #+#             */
/*   Updated: 2022/04/28 10:03:09 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_strequal(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	if (ft_strncmp(s1, s2, ft_strlen(s1)) == 0)
		return (true);
	return (false);
}
