/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:08:34 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/24 16:08:36 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_here_doc(int file);

int	read_file(char *filename)
{
	int	fd_input;

	if (access(filename, F_OK) == ERROR)
	{
		file_error("NO FILE", filename, false);
		fd_input = NO_INPUT_FILE;
	}
	else if (access(filename, R_OK) == ERROR)
	{
		file_error("NO PERMISSION", filename, false);
		fd_input = NO_INPUT_FILE;
	}
	else
		fd_input = open(filename, O_RDONLY);
	if (fd_input == ERROR)
		program_errors("OPENING INPUT FILE", true, true);
	return (fd_input);
}

int	write_file(char *filename)
{
	int	fd_output;

	fd_output = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_output == ERROR)
		file_error("NO FILE", filename, false);
	return (fd_output);
}

int	append_file(char *filename)
{
	int	fd_output;

	fd_output = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_output == ERROR)
		file_error("NO FILE", filename, false);
	return (fd_output);
}

int	here_doc(char *limiter)
{
	int	file;
	int	fd_input;

	file = open(".inputstream.txt", O_WRONLY | O_CREAT, 0644);
	if (file == ERROR)
		file_error("NO FILE", ".inputstream.txt", false);
	ms()->limiter = ft_strdup(limiter);
	init_here_doc(file);
	close(file);
	fd_input = open(".inputstream.txt", O_RDONLY);
	if (fd_input == ERROR)
		file_error("NO FILE", ".inputstream.txt", false);
	return (fd_input);
}

static void	init_here_doc(int file)
{
	char	*line;
	char	*tmp;

	tmp = ft_strjoin(ms()->limiter, "\n");
	while (1)
	{
		ft_putstr_fd("minishell heredoc> ", 1);
		line = get_next_line(STDIN_FILENO);
		if (line)
		{
			if (ft_strequal(tmp, line))
				break ;
			ft_putstr_fd(line, file);
			ft_strdel(&line);
		}
		else
			ft_putendl_fd("", 1);
	}
	ft_strdel(&tmp);
	ft_strdel(&line);
}
