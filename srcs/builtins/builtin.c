/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:59:36 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/17 12:10:37 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbt(t_command	*cmd)
{
	if (ft_strcmp(cmd->command[0], "echo") == 0)
		return (1);
	if (ft_strcmp(cmd->command[0], "cd") == 0)
		return (1);
	if (ft_strcmp(cmd->command[0], "pwd") == 0)
		return (1);
	if (ft_strcmp(cmd->command[0], "export") == 0)
		return (1);
	if (ft_strcmp(cmd->command[0], "unset") == 0)
		return (1);
	if (ft_strcmp(cmd->command[0], "env") == 0)
		return (1);
	if (ft_strcmp(cmd->command[0], "exit") == 0)
		return (1);
	return (0);
}

void	ft_execbt(t_command *cmd)
{
	if (ft_strcmp(cmd->command[0], "echo") == 0)
		bt_echo(cmd);
	if (ft_strcmp(cmd->command[0], "cd") == 0)
		bt_cd(cmd);
	if (ft_strcmp(cmd->command[0], "pwd") == 0)
		bt_pwd();
	if (ft_strcmp(cmd->command[0], "export") == 0)
		bt_export(cmd);
	if (ft_strcmp(cmd->command[0], "unset") == 0)
		bt_unset(cmd);
	if (ft_strcmp(cmd->command[0], "env") == 0)
		bt_env();
	if (ft_strcmp(cmd->command[0], "exit") == 0)
		bt_exit();
	exit(EXIT_SUCCESS);
}
