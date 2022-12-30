#include "minishell.h"

void	expand_tokens(void)
{
	t_list	*tokens;

	if (!ms()->tokens)
		return ;
	tokens = ft_lstmap(ms()->tokens, &expand_token, &del_token);
	if (!tokens)
		program_errors("MALLOC", true, true);
	ft_lstclear(&ms()->tokens, del_token_list);
	ms()->tokens = tokens;
}

void	del_token(void *elem)
{
	t_token	*token;

	token = (t_token *)elem;
	ft_strdel(&token->text);
	ft_memdel(&elem);
}

void	del_token_list(void *elem)
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

void	print_command(void *elem)
{
	t_command	*command_elem;
	char		**command;

	if (!elem)
		return ;
	command_elem = (t_command *)elem;
	command = command_elem->command;
	while (*command)
	{
		printf("%s,", *command);
		command++;
	}
	printf("\n");
}

void	del_command(void *elem)
{
	t_command	*command;

	command = (t_command *)elem;
	ft_strarray_clear(&command->command);
	ft_memdel(&elem);
}

void	close_fd(void *elem)
{
	t_command	*command;

	command = (t_command *)elem;
	if (!(command->in_fd == -1 || command->in_fd == STDIN_FILENO))
		close(command->in_fd);
	if (!(command->out_fd == -1 || command->out_fd == STDOUT_FILENO))
		close(command->out_fd);
}
