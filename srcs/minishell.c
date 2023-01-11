/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:11:18 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/02 00:20:20 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_minishell(char **envp);
static void	run_ms(void);
static void	run_input(void);

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	init_minishell(envp);
	sg_init();
	run_ms();
	clear_data(true);
	ft_strarray_clear(&ms()->envp);
	return (EXIT_SUCCESS);
}

static void	run_ms(void)
{
	while (1)
	{
		ms()->on_read = 1;
		ms()->input = readline(PROMPT);
		ms()->on_read = 0;
		if (!(ms()->input))
			exit(1);
		if (ms()->input && *ms()->input)
			add_history(ms()->input);
		if (ft_strequal(ms()->input, "clear"))
			rl_clear_history();
		else
			run_input();
		while (wait(&ms()->status) > 0)
			;
		if (WIFEXITED(ms()->status))
			ms()->status = WEXITSTATUS(ms()->status);
		ms()->exit = 0;
		ms()->lstatus = ms()->status;
		ms()->toplvl = 1;
		clear_data(false);
	}
}

static void	run_input(void)
{
	create_tokens();
	expand_tokens();
	create_commands();
	exec_input();
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
}

char	**command_paths(void)
{
	int			i;

	i = -1;
	while (ms()->envp[++i])
	{
		if (!ft_strncmp(ms()->envp[i], "PATH=", 5))
			break ;
	}
	if (!ms()->envp[i])
		return (NULL);
	else
		return (ft_split(ms()->envp[i] + 5, ':'));
}
