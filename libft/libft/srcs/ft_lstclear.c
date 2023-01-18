/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:29:45 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:35:30 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Deletes and frees the given element and every successor of that element, 
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
*/

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{	
	t_list	*temp;
	t_list	*temp_free;

	if (!(*lst) || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		temp_free = temp->next;
		ft_lstdelone(temp, del);
		temp = temp_free;
	}
	*lst = NULL;
}
