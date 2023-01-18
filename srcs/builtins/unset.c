/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:26:40 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/18 17:37:54 by tpereira         ###   ########.fr       */
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

void	bt_remove_unset(t_command *cmd, int i)
{
	char	*t;
	size_t	len;
	char	*f;

	if (cmd->command[i])
	{
		len = ft_strlen(cmd->command[i]);
		printf("len= %zu\n", len);
		if (cmd->command[i][len - 1] != '=')
			t = ft_strjoin(cmd->command[i], "=");
		else
			t = ft_strdup(cmd->command[i]);
		f = get_env(t);
		if (f)
			bt_swap_envp(t);
		free(t);
	}
}

void	bt_unset(t_command *cmd)
{
	int	i;

	i = 0;
	if (!cmd->command[1])
		printf("unset: not enough arguments\n");
	else
		while (cmd->command[i++])
			bt_remove_unset(cmd, i);
}
