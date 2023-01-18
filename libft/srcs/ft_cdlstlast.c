/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:31:07 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:39:55 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Returns the last element of the list.
*/

#include "libft.h"

t_dlist	*ft_cdlstlast(t_dlist *lst)
{
	t_dlist	*temp;

	if (!lst)
		return (NULL);
	temp = lst->prev;
	return (temp);
}
