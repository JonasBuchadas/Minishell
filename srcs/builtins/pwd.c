/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:56:42 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/18 19:51:09 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bt_pwd(void)
{
	if (ms()->cwd)
	{
		ft_putstr_fd(ms()->cwd, 1);
		write(1, "\n", 1);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
