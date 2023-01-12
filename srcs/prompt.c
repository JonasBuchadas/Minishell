/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:29:02 by tpereira          #+#    #+#             */
/*   Updated: 2023/01/12 15:15:29 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
