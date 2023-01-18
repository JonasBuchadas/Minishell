/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:31:50 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:46:36 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Counts the number of elements in a list.
*/

#include "libft.h"

int	ft_cdlstsize(t_dlist *lst)
{
	int		size;
	t_dlist	*temp;

	if (!lst)
		return (0);
	temp = lst;
	size = 1;
	while (temp->next != lst)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
