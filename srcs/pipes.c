#include "minishell.h"

void	create_pipes(void)
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
