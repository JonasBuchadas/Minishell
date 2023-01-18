/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:30:09 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:37:14 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Takes as a parameter an element and frees thememory of the element’s content 
using the function ’del’ given as a parameter and free the element.
The memory of ’next’ must not be freed.
*/

#include "libft.h"
#include <stdlib.h>

void	ft_cdlstdelone(t_dlist *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
