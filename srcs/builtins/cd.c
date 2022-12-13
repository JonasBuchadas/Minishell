/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:49:19 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/12 23:54:17 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bt_cd(t_command	*cmd)
{
	int	a;

	a = 0;
	printf("Got cd %s\n", cmd->command[0]);
	while (ms()->envp[a])
	{
		printf("ENVP %d: %s\n", a, ms()->envp[a]);
		a++;
	}
}