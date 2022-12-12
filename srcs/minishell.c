#include "minishell.h"

static void	init_minishell(char **envp);
static void command_paths(void);

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;

	init_minishell(envp);
	while (true)
	{
		ms()->input = readline(PROMPT);
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
			ft_lstiter(ms()->tokens, print_token);
			exec_input();
		}
		waitpid(-1, NULL, 0);
		clear_data(false);
	}
	clear_data(true);
	return (EXIT_SUCCESS);
}

static void	init_minishell(char **envp)
{
	ms()->envp = envp;
	ms()->file_input = STDIN_FILENO;
	ms()->file_output = STDOUT_FILENO;
	ms()->last_fd_in = STDIN_FILENO;
	ms()->last_fd_out = STDOUT_FILENO;
	command_paths();
}

static void command_paths(void)
{
	int i;

	i = -1;
	while (ms()->envp[++i])
	{
		if (!ft_strncmp(ms()->envp[i], "PATH=", 5))
			break;
	}
	ms()->env_paths = ft_split(ms()->envp[i] + 5, ':');
}
