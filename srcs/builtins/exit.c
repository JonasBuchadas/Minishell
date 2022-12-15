/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:45:07 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/15 10:05:41 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bt_exit(void)
{
	/* TODO: Doesn't persist to parent, only the children process exits */
	ms()->exit = 1;
	exit(1);
}
