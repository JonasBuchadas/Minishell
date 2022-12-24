/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:22:26 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/22 18:04:52 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bt_echo(t_command	*cmd)
{
	int	argc;
	int	n_flag;

	argc = 1;
	n_flag = 0;
	while (cmd->command[argc] && cmd->command[argc][0] == '-')
	{
		if (ft_strcmp(cmd->command[argc], "-n") == 0)
			n_flag = 1;
		else
			break ;
		argc++;
	}
	while (cmd->command[argc])
	{
		ft_putstr_fd(cmd->command[argc], 1);
		if (cmd->command[argc + 1] && cmd->command[argc][0] != '\0')
			write(1, " ", 1);
		argc++;
	}
	if (!n_flag)
		write(1, "\n", 1);
	return (0);
}
