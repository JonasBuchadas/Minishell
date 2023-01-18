/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:31:21 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/28 15:11:32 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Iterates the list ’lst’ and applies the function ’f’ to the content of each 
element. Creates a newlist resulting of the successive applications of the 
function ’f’. The ’del’ function is used to delete the content of an element 
if needed.
*/

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{	
	t_list	*new;
	t_list	*temp;
	t_list	*last;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	temp = lst;
	while (temp)
	{
		last = ft_lstnew(f(temp->content));
		if (!last)
		{
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, last);
		temp = temp->next;
	}
	return (new);
}
