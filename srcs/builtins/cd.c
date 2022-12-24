/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:49:19 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/24 16:12:27 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bt_cd_error(char **cmd)
{
	char	*error;

	if (cmd[1] && ft_strcmp(cmd[1], "-") != 0)
		error = ft_strdup(strerror(errno));
	else if (cmd[1] && ft_strcmp(cmd[1], "-") == 0)
		error = ft_strdup("OLDPWD is not set\n");
	else
		error = ft_strdup("HOME is not set\n");
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(error, 2);
	if (cmd[1] && ft_strcmp(cmd[1], "-") != 0)
		write(2, "\n", 1);
	free(error);
	return (EXIT_FAILURE);
}

int	bt_setpwd(int old)
{
	char	cwd[PATH_MAX];

	getcwd(cwd, PATH_MAX);
	if (cwd == NULL)
		return (0);
	if (old)
		set_env("OLDPWD=", cwd);
	else
		set_env("PWD=", cwd);
	return (1);
}

int	bt_cd(t_command	*cmd)
{
	char	*dir;
	int		cd;

	dir = NULL;
	cd = 0;
	if (cmd->command[1] && ft_strcmp(cmd->command[1], "-") != 0)
		dir = cmd->command[1];
	else if (cmd->command[1] && ft_strcmp(cmd->command[1], "-") == 0)
		dir = get_env("OLDPWD=");
	else
		dir = get_env("HOME=");
	if (!dir)
		return (bt_cd_error(cmd->command));
	else
	{
		bt_setpwd(1);
		cd = chdir(dir);
		if (cd == 0)
			bt_setpwd(0);
		else
			return (bt_cd_error(cmd->command));
	}
	return (EXIT_SUCCESS);
}
