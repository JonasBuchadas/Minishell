#include "minishell.h"

static char *join_token(char *cmd, char *str);

void create_commands()
{
	char	*command;
	t_list	*current;
	t_token	*token;

	command = (char *)ft_calloc(1, 1);
	current = ms()->tokens;
	while (current)
	{
		token = (t_token *)current->content;
		if (token->parse_code != METACHAR)
			command = join_token(command, token->text);
		// else
		// 	command = join_token(command, token->text);
		current = current->next;
	}
	printf("%s\n", command);
}

static char	*join_token(char *cmd, char *str)
{
	char	*temp;

	temp = ft_strjoin(cmd, str);
		ft_strdel(&cmd);
	return temp;
}
