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

# define WRITE_END 1
# define READ_END 0
# define NO_INPUT_FILE 0
# define CHILD_PROCESS 0
# define ERROR -1
# define PIPE 2
# define HERE_DOC 3

# define PROMPT "minishell: "

typedef struct s_minishell
{
	int		argc;
	char	**argv;
	char	**envp;
}			t_minishell;

#endif

t_minishell *ms(void);
