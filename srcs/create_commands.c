/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:32:34 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/02 00:17:16 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*join_token(char *cmd, char *str);
static t_list	*redirect_io(t_list *tokens, char *redirect);
static char		*add_command(char *cmd, bool pipe);

void	create_commands(void)
{
	char	*command;
	t_list	*current;
	t_token	*token;

	command = (char *)protected_calloc(1, 1);
	current = ms()->tokens;
	while (current)
	{
		token = (t_token *)current->content;
		if (token->parse_code != METACHAR)
			command = join_token(command, token->text);
		else if (ft_strequal(token->text, "|"))
			command = add_command(command, true);
		else
			current = redirect_io(current, token->text);
		current = current->next;
	}
	command = add_command(command, false);
	ft_strdel(&command);
}

static char	*join_token(char *cmd, char *str)
{
	char	*temp;

	temp = ft_strjoin(cmd, str);
	ft_strdel(&cmd);
	return (temp);
}

static t_list	*redirect_io(t_list *tokens, char *redirect)
{
	t_list	*next;
	t_token	*token;
	char	*filename;

	if (!tokens->next)
		unexpected_token_error("newline");
	next = tokens->next;
	token = (t_token *)next->content;
	filename = ft_strtrim(token->text, " ");
	if (token->parse_code == METACHAR)
		unexpected_token_error(token->text);
	if (ft_strequal(redirect, "<"))
		ms()->file_input = read_file(filename);
	if (ft_strequal(redirect, ">"))
		ms()->file_output = write_file(filename);
	if (ft_strequal(redirect, "<<"))
		ms()->file_input = here_doc(filename);
	if (ft_strequal(redirect, ">>"))
		ms()->file_output = append_file(filename);
	ft_strdel(&filename);
	return (next);
}

static char	*add_command(char *cmd, bool create_pipe)
{
	t_command	*command;

	command = protected_calloc(1, sizeof(t_command));
	command->raw_command = cmd;
	command->command = ft_split(cmd, ' ');
	command->in_fd = ms()->file_input;
	command->out_fd = ms()->file_output;
	command->pipe = false;
	if (create_pipe)
		command->pipe = true;
	if (!ms()->commands)
	{
		command->cmd_nu = 0;
		ms()->commands = ft_lstnew((void *)command);
	}
	else
	{
		command->cmd_nu = ft_lstsize(ms()->commands);
		ft_lstadd_back(&ms()->commands, ft_lstnew((void *)command));
	}
	ms()->file_input = STDIN_FILENO;
	ms()->file_output = STDOUT_FILENO;
	return ((char *)protected_calloc(1, 1));
}
