/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:04:42 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/02 00:17:22 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_env(char **env, int ra)
{
	size_t	len;
	char	**envp;

	len = 0;
	while (env[len])
		len++;
	envp = (char **)malloc(sizeof(char *) * (len + 1 + ra));
	if (!envp)
		return (NULL);
	len = -1;
	while (env[++len])
		envp[len] = ft_strdup(env[len]);
	envp[len] = '\0';
	if (ra)
		envp[len + ra] = '\0';
	return (envp);
}

char	*get_env(char	*str)
{
	int		c;
	size_t	len;

	c = 0;
	while (ms()->envp[c])
	{
		len = ft_strlen(str);
		if (ft_strncmp(ms()->envp[c], str, len) == 0)
		{
			if (ms()->envp[c][len] == '=')
				len++;
			return (&ms()->envp[c][len]);
		}
		c++;
	}
	return (NULL);
}

void	set_env(char *env, char *value)
{
	int			c;
	int			f;
	char		**temp;
	t_minishell	*mini;

	c = 0;
	f = 0;
	mini = ms();
	while (mini->envp[c])
	{
		if (ft_strncmp(mini->envp[c], env, ft_strlen(env)) == 0)
		{
			free(mini->envp[c]);
			f = 1;
			mini->envp[c] = ft_strjoin(env, value);
		}
		c++;
	}
	if (!f)
	{
		temp = ms()->envp;
		mini->envp = init_env(mini->envp, 1);
		ft_strarray_clear(&temp);
		mini->envp[c] = ft_strjoin(env, value);
	}
}

char	*get_env_name(char	*str)
{
	size_t	c;
	char	*ret;

	c = 0;
	while (str[c] && str[c] != '=')
		c++;
	if (str[c] == '=')
		c++;
	ret = malloc(sizeof(char) * c + 1);
	if (!ret)
		return (NULL);
	ft_bzero(ret, c);
	ft_strlcpy(ret, str, c);
	return (ret);
}
