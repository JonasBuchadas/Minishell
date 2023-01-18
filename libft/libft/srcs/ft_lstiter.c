/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:30:55 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:38:50 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Iterates the list ’lst’ and applies the function ’f’ to the content of each 
element.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{	
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
