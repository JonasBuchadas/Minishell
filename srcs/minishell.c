#include "minishell.h"

static void	init_minishell(char **envp);
static void command_paths(void);
static void exec_input(void);
static char *find_command(char *cmd, char **paths);

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
			// printf("%s\n",ms()->tokens);
			ft_lstiter(ms()->tokens, print_token);
			exec_input();
		}
		waitpid(-1, NULL, 0);
		ft_strdel(&ms()->input);
		// ft_lstclear(&ms()->tokens, &del_token);
	}
	ft_strdel(&ms()->input);
	// ft_lstclear(&ms()->tokens, &del_token);
	return (EXIT_SUCCESS);
}

static void	init_minishell(char **envp)
{
	ms()->envp = envp;
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

static void	exec_input(void)
{
	ms()->pid_cmd = fork();
	if (ms()->pid_cmd == ERROR)
		program_errors("FORK", true);
	if (ms()->pid_cmd == CHILD_PROCESS)
	{
		ms()->cmd_args = ft_split(ms()->input, ' ');
		if (access(ms()->cmd_args[0], F_OK) != ERROR)
			execve(ms()->cmd_args[0], ms()->cmd_args, ms()->envp);
		ms()->cmd = find_command(ms()->cmd_args[0], ms()->env_paths);
		if (!ms()->cmd || access(ms()->cmd, F_OK) == ERROR)
			command_errors(ms()->cmd_args[0], true);
		execve(ms()->cmd, ms()->cmd_args, ms()->envp);
	}
}

static char *find_command(char *cmd, char **paths)
{
	char *path;
	char *tmp;
	size_t i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		ft_strdel(&tmp);
		if (access(path, F_OK) == 0)
		{
			ft_strarray_clear(&paths);
			return (path);
		}
		else
			ft_strdel(&path);
		i++;
	}
	ft_strarray_clear(&paths);
	return (NULL);
}
