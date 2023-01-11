/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:22:26 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/02 00:36:45 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	is_n_flag(t_command *cmd, bool *n_flag);

int	bt_echo(t_command *cmd)
{
	bool	n_flag;
	char	*echo;

	n_flag = false;
	is_n_flag(cmd, &n_flag);
	if (!n_flag)
	{
		echo = ft_strnstr(cmd->raw_command, "echo ", 6);
		echo = echo + 5;
		ft_putendl_fd(echo, 1);
	}
	else
	{
		echo = ft_strnstr(cmd->raw_command, "-n ", 10);
		echo = echo + 3;
		ft_putstr_fd(echo, 1);
	}
	return (0);
}

static void	is_n_flag(t_command *cmd, bool *n_flag)
{
	int	argc;

	argc = 1;
	while (cmd->command[argc] && cmd->command[argc][0] == '-')
	{
		if (ft_strequal(cmd->command[argc], "-n"))
			*n_flag = true;
		else
			break ;
		argc++;
	}
}
