/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:04:11 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/18 17:24:45 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/wait.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <signal.h>
# include <termios.h>
# include <sys/stat.h>

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

# define PROMPT "\e[0;35mminishell: \033[0m"
# define EXIT_COMMAND 127
# define EXIT_SIGINT 130
# define EXIT_SIGQUIT 131

# define CTRL_C 3
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define PURPLE "\x1B[35m"
# define RESET "\x1b[0m"

typedef struct s_token
{
	int			parse_code;
	char		*text;
	bool		empty_exp;
}	t_token;

typedef struct s_command
{
	int		cmd_nu;
	char	*raw_command;
	char	**command;
	int		in_fd;
	int		out_fd;
	bool	pipe;
	bool	redirect;
}	t_command;

typedef struct s_minishell
{
	pid_t			pid_cmd;
	int				n_pipes;
	int				*pipes;
	int				file_input;
	int				d_in;
	int				d_out;
	int				exit;
	int				toplvl;
	int				status;
	int				test_flag;
	int				lstatus;
	int				file_output;
	unsigned int	last_i;
	bool			on_read;
	char			*limiter;
	char			*err_message;
	char			**cmd_args;
	char			*cmd;
	char			**envp;
	char			**env_paths;
	char			*cwd;
	char			*path;
	char			*input;
	t_list			*tokens;
	t_list			*commands;
}			t_minishell;

t_minishell	*ms(void);

void		command_errors(char *errname, bool clear, bool stop);
void		program_errors(char *errname, bool clear, bool stop);
void		unexpected_token_error(char *token);
void		file_error(char *error, char *filename, bool stop);
void		check_malloc(void *ptr);
void		create_tokens(void);
void		expand_tokens(void);
char		**command_paths(void);
// void redirect_io();
void		clear_data(bool clear_history);
void		del_token(void *token);
void		del_token_list(void *elem);
void		del_command(void *elem);
void		close_fd(void *elem);
void		print_token(void *token);
void		print_command(void *elem);
void		*expand_token(void *elem);
void		create_commands(void);
bool		is_metachar(char c);
void		*protected_calloc(size_t count, size_t size);
int			read_file(char *filename);
int			write_file(char *filename);
int			append_file(char *filename);
int			here_doc(char *limiter);
void		exec_input(void);
void		close_pipes(void);
void		dup2_util(int read_end, int write_end);
/* BUILTINS */
int			ft_isbt(t_command *cmd);
void		ft_execbt(t_command *cmd);
int			bt_echo(t_command	*cmd);
int			bt_cd(t_command	*cmd);
int			bt_pwd(void);
void		bt_env(void);
void		bt_export(t_command *cmd);
void		bt_unset(t_command *cmd);
int			bt_exit(t_command *cmd);
/* AUX */
int			ft_strcmp(const char *s1, const char *s2);
void		create_pipes(void);
void		ft_execbin(t_list *current);
int			is_dir(t_command *cmd);
int			is_local_fd(t_command *cmd);
char		*ft_relative_path(char *cwd);
void		add_cwd_to_prompt(t_minishell *cmd);
void		get_input(t_minishell *mini, char **argv);
void		error_codes(t_command *cmd, int code);
/* ENV */
char		**init_env(char **env, int ra);
char		*get_env(char	*str);
char		*get_env_name(char	*str);
void		set_env(char *env, char *value);
void		expand_tilde(t_token *token);
/* SIGNALS */
void		sg_init(void);
#endif
