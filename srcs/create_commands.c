#include "minishell.h"

static char *join_token(char *cmd, char *str);
static char *add_metachar(char *cmd, char *meta_str);
static void add_command(char *cmd);

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
		else
			command = add_metachar(command, token->text);
		current = current->next;
	}
	add_command(command);
	ft_strdel(&command);
	ft_lstiter(ms()->commands, print_command);
}

static char	*join_token(char *cmd, char *str)
{
	char	*temp;

	temp = ft_strjoin(cmd, str);
		ft_strdel(&cmd);
	return temp;
}

static char *add_metachar(char *cmd, char *meta_str)
{
	char	*meta;
	char	*new_cmd;

	if (!ft_strequal(cmd, ""))
		add_command(cmd);
	ft_strdel(&cmd);
	meta = (char *)ft_calloc(1, 1);
	if (!meta)
		program_errors("MALLOC", true, true);
	meta = join_token(meta, meta_str);
	add_command(meta);
	ft_strdel(&meta);
	new_cmd = (char *)ft_calloc(1, 1);
	if (!new_cmd)
		program_errors("MALLOC", true, true);
	return (new_cmd);
}

static void add_command(char *cmd)
{
	t_command	*command;

	command = ft_calloc(1, sizeof(t_command));
	if (!command)
		program_errors("MALLOC", true, true);
	command->command = ft_split(cmd, ' ');
	if (!ms()->commands)
		ms()->commands = ft_lstnew((void *)command);
	else
		ft_lstadd_back(&ms()->commands, ft_lstnew((void *)command));
}
