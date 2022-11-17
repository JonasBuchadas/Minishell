#include "minishell.h"

void	command_errors(char *errname,bool clear, bool stop)
{
	char	*prompt_line;
	char	*full_line;

	prompt_line = ft_strjoin(PROMPT, "command not found: ");
	full_line = ft_strjoin(prompt_line, errname);
	ft_putendl_fd(full_line, 2);
	ft_strdel(&prompt_line);
	ft_strdel(&full_line);
	if (clear)
		clear_data(true);
	if (stop)
		exit(EXIT_FAILURE);
}

void	program_errors(char *errname, bool clear, bool stop)
{
	perror(errname);
	if (clear)
		clear_data(true);
	if (stop)
		exit(EXIT_FAILURE);
}

void	clear_data(bool clear_history)
{
	if (clear_history)
		rl_clear_history();
	ft_strdel(&ms()->input);
	ft_lstclear(&ms()->tokens, &del_token);
	ft_lstclear(&ms()->commands, &del_command);
}

void	del_token(void *elem)
{
	t_token	*token;

	token = (t_token *)elem;
	ft_strdel(&token->text);
	ft_memdel(&elem);
}

void del_token_list(void *elem)
{
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

void print_command(void *elem)
{
	t_command	*command_elem;
	char		**command;

	if (!elem)
		return;
	command_elem = (t_command *)elem;
	command = command_elem->command;
	while (*command)
	{
		printf("%s,", *command);
		command++;
	}
	printf("\n");
}

void del_command(void *elem)
{
	t_command *command;

	command = (t_command *)elem;
	ft_strarray_clear(&command->command);
	ft_memdel(&elem);
}

void check_malloc(void *ptr)
{
	if (!ptr)
		program_errors("MALLOC", true, true);
}
