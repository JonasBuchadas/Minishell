/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:29:02 by tpereira          #+#    #+#             */
/*   Updated: 2023/01/13 10:55:23 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    add_cwd_to_prompt(t_minishell *mini)
{
	char	*temp;

	temp = ft_strjoin(GREEN, mini->path);
	ft_strdel(&mini->path);
	mini->path = ft_strjoin(temp, YELLOW);
	ft_strdel(&temp);
	temp = ft_strjoin(mini->path, " ~ ");
	ft_strdel(&mini->path);
	mini->path = ft_strjoin(temp, RESET);
	ft_strdel(&temp);
}

char    *ft_relative_path(char *cwd)
{
	char    **tmp;
	char    *path;
	int     i;

	i = 0;
	tmp = ft_split(cwd, '/');
	while (tmp[i])
		i++;
	path = ft_strdup(tmp[i - 1]);
	ft_strarray_clear(&tmp);
	return (path);
}
