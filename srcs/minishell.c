#include "minishell.h"

static void	init_minishell(int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	init_minishell(argc, argv, envp);
	while (true)
	{
		ms()->input = readline(PROMPT);
		if (ft_strequal(ms()->input, "exit"))
			break ;
		if (ms()->input && *ms()->input)
			add_history(ms()->input);
		if (ft_strequal(ms()->input, "clear"))
			rl_clear_history();
		else
			printf("Input is: %s\n", ms()->input);
		ft_strdel(&ms()->input);
	}
	return (EXIT_SUCCESS);
}

static void	init_minishell(int argc, char **argv, char **envp)
{
	ms()->argc = argc;
	ms()->argv = argv;
	ms()->envp = envp;
}
