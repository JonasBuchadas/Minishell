#include "minishell.h"

static void create_pipes(void);
static char *find_command(char *cmd, char **paths);
static void redirect_io(t_command *command);

void	ft_execbin(t_command *command)
{
	ms()->pid_cmd = fork();
	if (ms()->pid_cmd == ERROR)
		program_errors("FORK", true, true);
	if (ms()->pid_cmd == CHILD_PROCESS)
	{
		ms()->toplvl = 0;
		redirect_io(command);
		close_pipes();
		if (access(command->command[0], F_OK) != ERROR)
			execve(command->command[0], command->command, ms()->envp);
		ms()->cmd = find_command(command->command[0], ms()->env_paths);
		if ((!ms()->cmd || access(ms()->cmd, F_OK) == ERROR) && !ft_isbt(command))
			command_errors(command->command[0], true, true);
		if (ft_isbt(command))
			ft_execbt(command);
		else
			execve(ms()->cmd, command->command, ms()->envp);
	}
}

void exec_input(void)
{
	t_command	*command;
	t_list		*current;

	create_pipes();
	current = ms()->commands;
	while (current)
	{
		command = (t_command *)current->content;
		if (ft_isbt(command) && ms()->n_pipes <= 0)
			ft_execbt(command);
		else
			ft_execbin(command);
		current = current->next;
	}
}

static void redirect_io(t_command *command)
{
	int nu_cmds;
	int cmd_nu;

	nu_cmds = ft_lstsize(ms()->commands);
	cmd_nu = command->cmd_nu;
	if (cmd_nu == 0 && command->pipe)
		dup2_util(command->in_fd, ms()->pipes[0 + WRITE_END]);
	else if (cmd_nu == 0 && !command->pipe)
		dup2_util(command->in_fd, command->out_fd);
	else if (cmd_nu == nu_cmds - 1)
		dup2_util(ms()->pipes[2 * cmd_nu - 2], command->out_fd);
	else
		dup2_util(ms()->pipes[2 * cmd_nu - 2], ms()->pipes[2 * cmd_nu + WRITE_END]);
}

static void create_pipes(void)
{
	int		i;
	t_list	*commands;

	commands = ms()->commands;
	ms()->n_pipes = 2 * (ft_lstsize(commands) - 1);
	ms()->pipes = (int *)protected_calloc(ms()->n_pipes, sizeof(int));
	i = -1;
	while (++i < ft_lstsize(ms()->commands) - 1)
	{
		if (pipe(ms()->pipes + 2 * i) == ERROR)
			program_errors("OPENING PIPES", true, true);
	}
}

static char *find_command(char *cmd, char **paths)
{
	/* If it's not a file and it's not a binary in PATH,
	paths gets freed without being reinitialzed,
	thus throwing an error on consecutive commands*/
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
			/* ft_strarray_clear(&paths); */
			return (path);
		}
		else
			ft_strdel(&path);
		i++;
	}
	/* ft_strarray_clear(&paths); */
	return (NULL);
}
