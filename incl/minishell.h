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

typedef struct s_minishell
{
	pid_t	pid_cmd;
	char		**cmd_args;
	char		*cmd;
	char		**envp;
	char		**env_paths;
	char		*input;
	t_list		*tokens;
	unsigned int	last_i;
}			t_minishell;




#endif

t_minishell *ms(void);

void	command_errors(char *errname, bool stop);
void	program_errors(char *errname, bool stop);
void	create_tokens(void);
void	del_token(void *token);
void	print_token(void *token);
