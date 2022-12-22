#include "minishell.h"

static void	init_minishell(char **envp);
static void command_paths(void);

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;

	init_minishell(envp);
	sg_init();
	while (1)
	{
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
			ft_lstiter(ms()->tokens, print_token);
			expand_tokens();
			ft_lstiter(ms()->tokens, print_token);
			create_commands();
			exec_input();
		}
		waitpid(-1, &ms()->status, 0);
		if (!ms()->toplvl)
			ms()->status = WEXITSTATUS(ms()->status);
		clear_data(false);
	}
	clear_data(true);
	ft_strarray_clear(&ms()->envp);
	return (EXIT_SUCCESS);
}

static void	init_minishell(char **envp)
{
	ms()->envp = init_env(envp, 0);
	ms()->exit = 0;
	ms()->file_input = STDIN_FILENO;
	ms()->file_output = STDOUT_FILENO;
	ms()->last_fd_in = STDIN_FILENO;
	ms()->last_fd_out = STDOUT_FILENO;
	ms()->toplvl = 1;
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
