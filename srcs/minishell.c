#include "minishell.h"

static void	init_minishell(int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	char	*input;

	init_minishell(argc, argv, envp);
	while (1)
	{
		input = readline(PROMPT);
		if (ft_strequal(input, "exit"))
			break ;
		if (input && *input)
			add_history(input);
		if (ft_strequal(input, "clear"))
			rl_clear_history();
		else
			printf("Input is: %s\n", input);
	}
	return (0);
}

static void	init_minishell(int argc, char **argv, char **envp)
{
	ms()->argc = argc;
	ms()->argv = argv;
	ms()->envp = envp;
}
