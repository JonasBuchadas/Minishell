/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:49:19 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/15 10:04:17 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bt_cd_error(char **cmd)
{
	if (cmd[1])
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
	}
	else
		ft_putstr_fd("minishell: cd: HOME is not set\n", 2);
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

void	bt_cd(t_command	*cmd)
{
	char	*dir;
	int		cd;

	dir = NULL;
	cd = 0;
	if (cmd->command[1])
		dir = cmd->command[1];
	else
		dir = get_env("HOME=");
	if (!dir)
		bt_cd_error(cmd->command);
	else
	{
		bt_setpwd(1);
		cd = chdir(dir);
		if (cd == 0)
			bt_setpwd(0);
		else
			bt_cd_error(cmd->command);
	}
	exit(EXIT_SUCCESS);
}
