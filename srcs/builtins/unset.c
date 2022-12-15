/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:26:40 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/15 10:10:03 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bt_swap_envp(char *t)
{
	int		tr;
	size_t	len;

	len = -1;
	while (ms()->envp[++len])
	{
		if (ft_strncmp(t, ms()->envp[len], ft_strlen(t)) == 0)
			tr = (int)len;
	}
	free(ms()->envp[tr]);
	ms()->envp[tr] = ms()->envp[len - 1];
	ms()->envp[len - 1] = NULL;
}

int	bt_unset(t_command *cmd)
{
	char	*t;
	size_t	len;
	char	*f;

	len = ft_strlen(cmd->command[1]);
	if (cmd->command[1][len - 1] != '=')
		t = ft_strjoin(cmd->command[1], "=");
	else
		t = ft_strdup(cmd->command[1]);
	f = get_env(t);
	if (f)
		bt_swap_envp(t);
	free(t);
	if (f)
		return (0);
	else
		return (1);
}
