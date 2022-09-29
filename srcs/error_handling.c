#include "minishell.h"

void	command_errors(char *errname, bool stop)
{
	char	*prompt_line;
	char	*full_line;

	prompt_line = ft_strjoin(PROMPT, "command not found: ");
	full_line = ft_strjoin(prompt_line, errname);
	ft_putendl_fd(full_line, 2);
	ft_strdel(&prompt_line);
	ft_strdel(&full_line);
	if (stop)
		exit(EXIT_FAILURE);
}

void	program_errors(char *errname, bool stop)
{
	perror(errname);
	if (stop)
		exit(EXIT_FAILURE);
}
