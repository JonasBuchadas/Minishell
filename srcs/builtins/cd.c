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

static char	*bt_get_dir(t_command *cmd, bool *old);

int	bt_cd_error(char **cmd)
{
	char	*error;

	if (cmd[1] && !ft_strequal(cmd[1], "-"))
		error = ft_strdup(strerror(errno));
	else if (cmd[1] && ft_strequal(cmd[1], "-"))
		error = ft_strdup("OLDPWD is not set\n");
	else
		error = ft_strdup("HOME is not set\n");
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(error, 2);
	if (cmd[1] && !ft_strequal(cmd[1], "-"))
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
	bool	old;

	dir = NULL;
	old = false;
	cd = 0;
	dir = bt_get_dir(cmd, &old);
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
		if (old)
			ft_putendl_fd(dir, 1);
		ft_strdel(&dir);
	}
	return (EXIT_SUCCESS);
}

static char	*bt_get_dir(t_command *cmd, bool *old)
{
	char	*dir;

	if (cmd->command[1] && !ft_strequal(cmd->command[1], "-"))
		dir = cmd->command[1];
	else if (cmd->command[1] && ft_strequal(cmd->command[1], "-"))
	{
		dir = ft_strdup(get_env("OLDPWD"));
		*old = true;
	}
	else
		dir = ft_strdup(get_env("HOME"));
	return (dir);
}
