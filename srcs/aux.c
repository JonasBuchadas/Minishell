#include "minishell.h"

bool is_metachar(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '|' || c == '&' || c == ';' || c == '(' || c == ')' || c == '<' || c == '>')
		return true;
	return false;
}

void *protected_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		program_errors("MALLOC", true, true);
	return ptr;
}

void dup2_util(int read_end, int write_end)
{
	if (dup2(read_end, STDIN_FILENO) == ERROR)
		program_errors("DUP2", true, true);
	if (dup2(write_end, STDOUT_FILENO) == ERROR)
		program_errors("DUP2", true, true);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_resetfds(void)
{
	t_list	*cmds;
	t_command	*cmd;

	cmds = ms()->commands;
	while (cmds)
	{
		cmd = (t_command *)cmds->content;
		if (cmd->in_fd > 0)
			close(cmd->in_fd);
		if (cmd->out_fd > 0)
			close(cmd->out_fd);
		cmds = cmds->next;
	}
	dup2(ms()->in, 0);
	dup2(ms()->out, 1);
	close(ms()->in);
	close(ms()->out);
}
