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

void	ft_cdlstclear(t_dlist **lst, void (*del)(void *))
{	
	t_dlist	*temp;
	t_dlist	*temp_free;

	if (!(*lst) || !del)
		return ;
	temp = *lst;
	while (temp->next != *lst)
	{
		temp_free = temp->next;
		ft_cdlstdelone(temp, del);
		temp = temp_free;
	}
	ft_cdlstdelone(temp, del);
	*lst = NULL;
}
