/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:32:54 by tpereira          #+#    #+#             */
/*   Updated: 2023/01/16 16:21:59 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_codes(t_command *cmd, int code)
{
	char	*err;

	err = ft_strjoin("minishell: ", cmd->command[0]);
	ms()->status = code;
	perror(err);
	free(err);
}
