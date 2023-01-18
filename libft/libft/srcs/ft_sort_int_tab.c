/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:01:31 by jocaetan          #+#    #+#             */
/*   Updated: 2022/04/28 10:01:34 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	rep;
	int	swap;
	int	temp;

	rep = 0;
	swap = 0;
	while (rep < size - 1)
	{
		while (swap < size - rep - 1)
		{
			if (*(tab + swap) > *(tab + swap + 1))
			{
				temp = *(tab + swap);
				*(tab + swap) = *(tab + swap + 1);
				*(tab + swap + 1) = temp;
			}
			swap++;
		}
		swap = 0;
		rep++;
	}
}
