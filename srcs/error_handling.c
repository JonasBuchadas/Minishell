/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:55:02 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/24 15:55:04 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_errors(char *errname, bool clear, bool stop)
{
	char	*prompt_line;
	char	*full_line;

	prompt_line = ft_strjoin(PROMPT, "command not found: ");
	full_line = ft_strjoin(prompt_line, errname);
	ft_putendl_fd(full_line, 2);
	ft_strdel(&prompt_line);
	ft_strdel(&full_line);
	ms()->status = EXIT_COMMAND;
	if (clear)
		clear_data(true);
	if (stop)
		exit(EXIT_COMMAND);
}

void	unexpected_token_error(char *token)
{
	char	*error_msg;
	char	*temp;
	char	*msg;

	error_msg = "minishell: syntax error near unexpected token `";
	temp = ft_strjoin(error_msg, token);
	msg = ft_strjoin(temp, "'");
	ft_strdel(&temp);
	ms()->err_message = msg;
	program_errors(ms()->err_message, true, true);
}

void	file_error(char *error, char *filename, bool stop)
{
	char	*line;

	if (ft_strequal(error, "NO FILE"))
		line = ft_strjoin("minishell: no such file or directory: ", filename);
	else
		line = ft_strjoin("minishell: permission denied: ", filename);
	ft_putendl_fd(line, 2);
	ft_strdel(&line);
	if (stop)
	{
		clear_data(false);
		exit(EXIT_FAILURE);
	}
}

void	program_errors(char *errname, bool clear, bool stop)
{
	perror(errname);
	if (clear)
		clear_data(true);
	if (stop)
		exit(EXIT_FAILURE);
}

void	clear_data(bool clear_history)
{
	if (clear_history)
		rl_clear_history();
	ft_strdel(&ms()->input);
	ft_strdel(&ms()->limiter);
	ft_strdel(&ms()->err_message);
	ft_strdel(&ms()->cmd);
	ft_strarray_clear(&ms()->env_paths);
	close_pipes();
	ft_lstclear(&ms()->tokens, &del_token);
	ft_lstclear(&ms()->commands, &del_command);
	if (access(".inputstream.txt", F_OK) != -1)
	{
		if (unlink(".inputstream.txt") == ERROR)
			program_errors("UNLINKING INPUTSTREAM", false, true);
	}
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

void	print_token(void *elem)
{
	t_token	*token;

	if (!elem)
		return ;
	token = (t_token *)elem;
	printf("Token :%s\n", token->text);
}

void	print_command(void *elem)
{
	t_command	*command_elem;
	char		**command;

	if (!elem)
		return ;
	command_elem = (t_command *)elem;
	command = command_elem->command;
	while (*command)
	{
		printf("%s,", *command);
		command++;
	}
	printf("\n");
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

void	close_pipes(void)
{
	int	i;

	if (!ms()->pipes)
		return ;
	i = -1;
	while (++i < ms()->n_pipes)
	{
		close(ms()->pipes[i]);
		ms()->pipes[i] = -1;
	}
	free(ms()->pipes);
	ms()->pipes = NULL;
}
