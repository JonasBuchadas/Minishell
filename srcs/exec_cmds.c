/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:59:42 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/12 10:58:37 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_command(char *cmd, char **paths);
static void	child_process(t_command *command);
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
			child_process(command);
		current = current->next;
	}
	close_pipes();
}

static void	child_process(t_command *command)
{
	t_minishell	*mini;
	char		**env_paths;

	mini = ms();
	redirect_io(command);
	close_pipes();
	env_paths = command_paths();
	if (access(command->command[0], F_OK) != ERROR)
		execve(command->command[0], command->command, mini->envp);
	mini->cmd = find_command(command->command[0], env_paths);
	ft_strarray_clear(&env_paths);
	if ((!mini->cmd || access(mini->cmd, F_OK) == ERROR)
		&& !ft_isbt(command))
		command_errors(command->command[0], true, true);
	if (ft_isbt(command))
		ft_execbt(command);
	else
		execve(ms()->cmd, command->command, ms()->envp);
}

void	exec_input(void)
{
	t_command	*command;
	t_list		*current;

	current = ms()->commands;
	command = (t_command *)current->content;
	if (is_dir(command))
		return ;
	if (ft_isbt(command) && !command->pipe)
	{
		redirect_io(command);
		close_pipes();
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
		else if (cmd_nu == 0 && (!command->pipe
				|| command->out_fd != STDOUT_FILENO))
			dup2_util(command->in_fd, command->out_fd);
		else if (cmd_nu == nu_cmds - 1)
			dup2_util(ms()->pipes[2 * cmd_nu - 2], command->out_fd);
		else
			dup2_util(ms()->pipes[2 * cmd_nu - 2], \
			ms()->pipes[2 * cmd_nu + WRITE_END]);
	}
}

static char	*find_command(char *cmd, char **paths)
{
	char	*path;
	char	*tmp;
	size_t	i;

	i = 0;
	while (paths && paths[i])
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
