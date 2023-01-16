/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:59:36 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/16 12:48:11 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_local_fd(t_command *cmd)
{
	char	*err;

	if (*cmd->command && cmd->command[0][0] == '.'
		&& cmd->command[0][1] == '/')
	{
		if (!access(cmd->command[0], F_OK))
		{
			if (!access(cmd->command[0], X_OK))
				ft_execbin(ms()->commands);
			else
			{
				err = ft_strjoin("minishell: ", cmd->command[1]);
				perror(err);
				free(err);
			}
		}
		else
		{
			ft_putstr_fd("minishell: ", 2);
			ft_putstr_fd(cmd->command[0], 2);
			ft_putendl_fd(": No such file or directory", 2);
		}
		return (1);
	}
	return (0);
}

int	is_dir(t_command *cmd)
{
	struct stat	sb;

	if (stat(cmd->command[0], &sb) == -1)
		return (0);
	else if (S_ISDIR(sb.st_mode))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(cmd->command[0], 2);
		ft_putendl_fd(": is a directory", 2);
		return (1);
	}
	return (0);
}

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
