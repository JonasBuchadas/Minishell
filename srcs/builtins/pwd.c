/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:56:42 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/02 00:17:07 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bt_pwd(void)
{
//	char	cwd[PATH_MAX];

	if (ms()->cwd)
	{
		ft_putstr_fd(ms()->cwd, 1);
		write(1, "\n", 1);
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
}
