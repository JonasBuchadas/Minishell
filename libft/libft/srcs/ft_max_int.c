/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:00:31 by jocaetan          #+#    #+#             */
/*   Updated: 2022/04/28 10:00:32 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_int(int n, ...)
{
	int		max;
	int		i;
	int		temp;
	va_list	ptr;

	va_start(ptr, n);
	i = 0;
	max = va_arg(ptr, int);
	while (++i < n)
	{
		temp = va_arg(ptr, int);
		if (temp > max)
			max = temp;
	}
	va_end(ptr);
	return (max);
}
