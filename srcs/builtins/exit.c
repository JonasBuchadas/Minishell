/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:45:07 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/16 22:51:41 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bt_exit_error(char *str, int ex)
{
	ft_putendl_fd("exit", 2);
	ft_putendl_fd(str, 2);
	if (ex >= 0)
		exit(ex);
	else
		return ((ex * -1));
}

int	bt_exit(t_command *cmd)
{
	long	ec;
	int		c;

	if (cmd->command[1] && cmd->command[2])
		return (bt_exit_error("exit: too many arguments", -1));
	if (cmd->command[1])
	{
		ec = ft_atol(cmd->command[1]);
		if (ec < 0)
			c = 0;
		else
			c = -1;
		while (cmd->command[1][++c])
			if (!ft_isdigit(cmd->command[1][c])
				|| (ec == 0 && !ft_strequal(cmd->command[1], "0")))
				bt_exit_error("exit: numeric argument required", 2);
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
