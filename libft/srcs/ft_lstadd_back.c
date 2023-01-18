/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:42:34 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:32:02 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Adds the element ’new’ at the end of the list.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{	
	t_list	*temp;

	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}	
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
