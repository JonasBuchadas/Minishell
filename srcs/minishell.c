#include "minishell.h"

static void	init_minishell(int argc, char **argv, char **envp);

int	main(int argc, char **argv, char **envp)
{
	init_minishell(argc, argv, envp);
	return (0);
}

static void	init_minishell(int argc, char **argv, char **envp)
{
	ms()->argc = argc;
	ms()->argv = argv;
	ms()->envp = envp;
}
