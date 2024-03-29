/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:16:35 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/18 18:20:50 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bt_sort_swap(char ***envp, int c1, int c2, int *c)
{
	char	*temp;

	temp = (*envp)[c1];
	(*envp)[c1] = (*envp)[c2];
	(*envp)[c2] = temp;
	*c -= 2;
	if (*c < 0)
		*c = 0;
}

char	**bt_export_sort(char **envp)
{
	size_t	len;
	int		c;
	char	*s1;
	char	*s2;

	len = 0;
	c = 0;
	while (envp[len])
		len++;
	while (c < ((int)len -1))
	{
		s1 = get_env_name(envp[c]);
		s2 = get_env_name(envp[c + 1]);
		if (ft_strcmp(s1, s2) > 0)
			bt_sort_swap(&envp, c, c + 1, &c);
		free(s1);
		free(s2);
		c++;
	}
	return (envp);
}

void	bt_export_print(void)
{
	char	**list;
	int		c;
	char	*name;

	list = init_env(ms()->envp, 0);
	list = bt_export_sort(list);
	c = 0;
	while (list[c])
	{
		ft_putstr_fd("declare -x ", 1);
		name = get_env_name(list[c]);
		ft_putstr_fd(name, 1);
		if (get_env(name)[0])
		{
			write(1, "=\"", 2);
			ft_putstr_fd(get_env(name), 1);
			write(1, "\"", 1);
		}
		write(1, "\n", 1);
		free(name);
		c++;
	}
	ft_strarray_clear(&list);
}

void	bt_add_export(t_command *cmd, int i)
{
	char	*name;
	char	*temp;

	if (cmd->command[i])
	{
		if (!ft_strchr(cmd->command[i], '='))
			name = ft_strdup(cmd->command[i]);
		else
			name = get_env_name(cmd->command[i]);
		if (name[ft_strlen(name) - 1] != '=')
		{
			temp = name;
			name = ft_strjoin(name, "=");
			free(temp);
		}
		set_env(name, &cmd->command[i][ft_strlen(name)]);
		free(name);
	}
}

void	bt_export(t_command *cmd)
{
	int	i;

	i = 0;
	if (!cmd->command[1])
		bt_export_print();
	else
		while (cmd->command[i++])
			bt_add_export(cmd, i);
}
