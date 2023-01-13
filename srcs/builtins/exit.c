/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:45:07 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/13 15:57:46 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bt_exit_error(char *str, int ex)
{
	ft_putendl_fd(str, 2);
	if (ex >= 0)
		exit(ex);
	else
		return ((ex * -1));
}

int	bt_exit(t_command *cmd)
{
	int	ec;
	int	c;

	c = 0;
	if (cmd->command[1] && cmd->command[2])
		return (bt_exit_error("exit: too many arguments", -1));
	if (cmd->command[1])
	{
		c = -1;
		while (cmd->command[1][++c])
			if (!ft_isdigit(cmd->command[1][c]))
				bt_exit_error("exit: numeric argument required", 2);
		ec = ft_atoi(cmd->command[1]);
		if (ec > 255)
			ec = ec % 256;
		exit (ec);
	}
	else
	{
		ft_putendl_fd("exit", 0);
		exit(0);
	}
}
