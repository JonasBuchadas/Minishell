/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:01:19 by jocaetan          #+#    #+#             */
/*   Updated: 2022/04/28 10:01:21 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min_int(int n, ...)
{
	int		min;
	int		i;
	int		temp;
	va_list	ptr;

	va_start(ptr, n);
	i = 0;
	min = va_arg(ptr, int);
	while (++i < n)
	{
		temp = va_arg(ptr, int);
		if (temp < min)
			min = temp;
	}
	va_end(ptr);
	return (min);
}
