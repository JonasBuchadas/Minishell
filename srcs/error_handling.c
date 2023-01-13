/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:55:02 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/13 11:53:48 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_errors(char *errname, bool clear, bool stop)
{
	char	*prompt_line;
	char	*full_line;

	prompt_line = ft_strjoin("minishell: ", errname);
	prompt_line = ft_strjoin(prompt_line, ": ");
	full_line = ft_strjoin(prompt_line, "command not found");
	ft_putendl_fd(full_line, 2);
	ft_strdel(&prompt_line);
	ft_strdel(&full_line);
	ms()->status = EXIT_COMMAND;
	ms()->exit = EXIT_COMMAND;
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
	ft_strdel(&ms()->cwd);
	ft_strdel(&ms()->path);
	ft_strdel(&ms()->limiter);
	ft_strdel(&ms()->err_message);
	ft_strdel(&ms()->cmd);
	close_pipes();
	ft_lstclear(&ms()->tokens, &del_token);
	ft_lstclear(&ms()->commands, &del_command);
	if (access(".inputstream.txt", F_OK) != -1)
	{
		if (unlink(".inputstream.txt") == ERROR)
			program_errors("UNLINKING INPUTSTREAM", false, true);
	}
}
