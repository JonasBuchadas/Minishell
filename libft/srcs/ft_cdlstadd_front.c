/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cdlstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:42:34 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:32:02 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Adds the element ’new’ at the beggining of the list.
*/

#include "libft.h"

void	ft_cdlstadd_front(t_dlist **lst, t_dlist *new)
{	
	t_dlist	*temp;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	temp = *lst;
	new->next = temp;
	new->prev = temp->prev;
	temp->prev = new;
	temp = new->prev;
	temp->next = new;
	*lst = new;
}
