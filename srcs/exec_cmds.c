/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:59:42 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/28 21:11:49 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	create_pipes(void);
static char	*find_command(char *cmd, char **paths);
static void	redirect_io(t_command *command);

void	ft_execbin(t_list *current)
{
	t_command	*command;

	create_pipes();
	while (current)
	{
		command = (t_command *)current->content;
		ms()->pid_cmd = fork();
		if (ms()->pid_cmd == ERROR)
			program_errors("FORK", true, true);
		if (ms()->pid_cmd == CHILD_PROCESS)
		{
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
		current = current->next;
	}
}

void	exec_input(void)
{
	t_command	*command;
	t_list		*current;

	current = ms()->commands;
	command = (t_command *)current->content;
	if (ft_isbt(command) && !command->pipe)
	{
		redirect_io(command);
		ft_execbt(command);
		dup2(ms()->d_in, 0);
		dup2(ms()->d_out, 1);
	}
	else
	{
		ms()->toplvl = 0;
		ft_execbin(current);
	}
}

static void	redirect_io(t_command *command)
{
	int	nu_cmds;
	int	cmd_nu;

	if (ms()->pid_cmd == CHILD_PROCESS)
	{
		nu_cmds = ft_lstsize(ms()->commands);
		cmd_nu = command->cmd_nu;
		if (cmd_nu == 0 && command->pipe && command->out_fd == STDOUT_FILENO)
			dup2_util(command->in_fd, ms()->pipes[0 + WRITE_END]);
		else if (cmd_nu == 0 && (!command->pipe || command->out_fd != STDOUT_FILENO))
			dup2_util(command->in_fd, command->out_fd);
		else if (cmd_nu == nu_cmds - 1)
			dup2_util(ms()->pipes[2 * cmd_nu - 2], command->out_fd);
		else
			dup2_util(ms()->pipes[2 * cmd_nu - 2], \
			ms()->pipes[2 * cmd_nu + WRITE_END]);
	}
}

static void	create_pipes(void)
{
	int			i;
	t_list		*commands;
	t_minishell	*mini;

	mini = ms();
	commands = mini->commands;
	mini->n_pipes = 2 * (ft_lstsize(commands) - 1);
	mini->pipes = (int *)protected_calloc(mini->n_pipes, sizeof(int));
	i = -1;
	while (++i < ft_lstsize(mini->commands) - 1)
	{
		if (pipe(mini->pipes + 2 * i) == ERROR)
			program_errors("OPENING PIPES", true, true);
	}
}

static char	*find_command(char *cmd, char **paths)
{
	char	*path;
	char	*tmp;
	size_t	i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		ft_strdel(&tmp);
		if (access(path, F_OK) == 0)
			return (path);
		else
			ft_strdel(&path);
		i++;
	}
	return (NULL);
}
