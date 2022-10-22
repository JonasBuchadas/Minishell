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
	ft_lstclear(&ms()->tokens, &del_token);
	if (stop)
		exit(EXIT_FAILURE);
}

void	program_errors(char *errname, bool stop)
{
	perror(errname);
	if (stop)
		exit(EXIT_FAILURE);
}

void	del_token(void *elem)
{
	t_token	*token;

	token = (t_token *)elem;
	ft_strdel(&token->text);
	ft_memdel(&elem);
}

void	print_token(void *elem)
{
	t_token	*token;

	if (!elem)
		return ;
	token = (t_token *)elem;
	printf("Token :%s\n", token->text);
}
