/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <marvin@42.fr>                           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:04:11 by jocaetan          #+#    #+#             */
/*   Updated: 2022/04/29 15:19:14 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

// Parse Codes
# define NORMAL 0
# define SINGLE_QUOTES 1
# define DOUBLE_QUOTES 2
# define METACHAR 3

# define WRITE_END 1
# define READ_END 0
# define NO_INPUT_FILE 0
# define CHILD_PROCESS 0
# define ERROR -1
# define PIPE 2
# define HERE_DOC 3

# define PROMPT "minishell: "

typedef struct s_token
{
	int			parse_code;
	char		*text;
}	t_token;

typedef struct s_command
{
	char	**command;
	int		in_fd;
	int		out_fd;
	int		*pipe;
}	t_command;

typedef struct s_minishell
{
	pid_t	pid_cmd;
	int		fd_input;
	int		fd_output;
	char		**cmd_args;
	char		*cmd;
	char		**envp;
	char		**env_paths;
	char		*input;
	t_list		*tokens;
	t_list		*commands;
	int			last_fd_in;
	int			last_fd_out;
	int		last_error_cd;
	unsigned int	last_i;
}			t_minishell;

t_minishell *ms(void);

void command_errors(char *errname, bool clear, bool stop);
void program_errors(char *errname, bool clear, bool stop);
void file_error(char *error, char *filename, bool stop);
void check_malloc(void *ptr);
void create_tokens(void);
void expand_tokens(void);
// void redirect_io();
void clear_data(bool clear_history);
void del_token(void *token);
void del_token_list(void *elem);
void del_command(void *elem);
void print_token(void *token);
void print_command(void *elem);
void *expand_token(void *elem);
void create_commands();
bool is_metachar(char c);
void *protected_calloc(size_t count, size_t size);
int read_file(char *filename)

#endif
