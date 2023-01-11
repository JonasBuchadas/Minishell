/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:59:36 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/02 00:16:48 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbt(t_command	*cmd)
{
	if (ft_strequal(cmd->command[0], "echo"))
		return (1);
	if (ft_strequal(cmd->command[0], "cd"))
		return (1);
	if (ft_strequal(cmd->command[0], "pwd"))
		return (1);
	if (ft_strequal(cmd->command[0], "export"))
		return (1);
	if (ft_strequal(cmd->command[0], "unset"))
		return (1);
	if (ft_strequal(cmd->command[0], "env"))
		return (1);
	if (ft_strequal(cmd->command[0], "exit"))
		return (1);
	return (0);
}

void	ft_execbt(t_command *cmd)
{
	if (ft_strequal(cmd->command[0], "echo"))
		ms()->status = bt_echo(cmd);
	if (ft_strequal(cmd->command[0], "cd"))
		ms()->status = bt_cd(cmd);
	if (ft_strequal(cmd->command[0], "pwd"))
		ms()->status = bt_pwd();
	if (ft_strequal(cmd->command[0], "export"))
		bt_export(cmd);
	if (ft_strequal(cmd->command[0], "unset"))
		bt_unset(cmd);
	if (ft_strequal(cmd->command[0], "env"))
		bt_env();
	if (ft_strequal(cmd->command[0], "exit"))
		bt_exit(cmd);
	if (cmd->pipe || ft_lstsize(ms()->commands) > 1)
		exit(ms()->exit);
}
