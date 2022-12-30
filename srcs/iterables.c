/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:45:07 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/24 16:12:37 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_tokens(void)
{
	t_list	*tokens;

	if (!ms()->tokens)
		return ;
	tokens = ft_lstmap(ms()->tokens, &expand_token, &del_token);
	if (!tokens)
		program_errors("MALLOC", true, true);
	ft_lstclear(&ms()->tokens, del_token_list);
	ms()->tokens = tokens;
}

void	del_token(void *elem)
{
	t_token	*token;

	token = (t_token *)elem;
	ft_strdel(&token->text);
	ft_memdel(&elem);
}

void	del_token_list(void *elem)
{
	ft_memdel(&elem);
}

void	del_command(void *elem)
{
	t_command	*command;

	command = (t_command *)elem;
	ft_strarray_clear(&command->command);
	ft_memdel(&elem);
}

void	close_fd(void *elem)
{
	t_command	*command;

	command = (t_command *)elem;
	if (!(command->in_fd == -1 || command->in_fd == STDIN_FILENO))
		close(command->in_fd);
	if (!(command->out_fd == -1 || command->out_fd == STDOUT_FILENO))
		close(command->out_fd);
}
