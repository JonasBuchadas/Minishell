/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:11:18 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/30 15:48:30 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_minishell(char **envp);
static void	command_paths(void);

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	init_minishell(envp);
	sg_init();
	while (1)
	{
		// add_history("echo \"lol\" | grep \"lol\" | askdjhaskd | asdjkhaskd");
		ms()->on_read = 1;
		ms()->input = readline(PROMPT);
		ms()->on_read = 0;
		if (!(ms()->input))
			exit(1);
		if (ft_strequal(ms()->input, "exit"))
			break ;
		if (ms()->input && *ms()->input)
			add_history(ms()->input);
		if (ft_strequal(ms()->input, "clear"))
			rl_clear_history();
		else
		{
			create_tokens();
			expand_tokens();
			create_commands();
			exec_input();
		}
		/* dprintf(2, "WAITING\n"); */
		while (wait(&ms()->status) > 0)
			;
		/* dprintf(2, "NOT WAITING\n"); */
		if (WIFEXITED(ms()->status))
			ms()->status = WEXITSTATUS(ms()->status);
		ms()->exit = 0;
		ms()->lstatus = ms()->status;
		// ms()->status = 0;
		ms()->toplvl = 1;
		clear_data(false);
	}
	clear_data(true);
	ft_strarray_clear(&ms()->envp);
	return (EXIT_SUCCESS);
}

static void	init_minishell(char **envp)
{
	t_minishell	*mini;

	mini = ms();
	mini->envp = init_env(envp, 0);
	mini->exit = 0;
	mini->file_input = STDIN_FILENO;
	mini->file_output = STDOUT_FILENO;
	mini->d_in = dup(STDIN_FILENO);
	mini->d_out = dup(STDOUT_FILENO);
	mini->toplvl = 1;
	mini->status = 0;
	command_paths();
}

static void	command_paths(void)
{
	int			i;
	t_minishell	*mini;

	i = -1;
	mini = ms();
	while (ms()->envp[++i])
	{
		if (!ft_strncmp(ms()->envp[i], "PATH=", 5))
			break ;
	}
	mini->env_paths = ft_split(ms()->envp[i] + 5, ':');
}
