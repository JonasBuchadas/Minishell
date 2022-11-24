#include "minishell.h"

static char *join_token(char *cmd, char *str);
static char *add_metachar(char *cmd, char *meta_str);
static void add_command(char *cmd, bool pipe, int in_fd, int out_fd);

void create_commands()
{
	char	*command;
	t_list	*current;
	t_token	*token;

	command = (char *)protected_calloc(1, 1);
	current = ms()->tokens;
	while (current)
	{
	ms()->last_fd_out = STDOUT_FILENO;
		token = (t_token *)current->content;
		if (token->parse_code != METACHAR)
			command = join_token(command, token->text);
		else
		{
			current = add_metachar(command, current, token->text);

		}
		current = current->next;
	}
	add_command(command,false, ms()->last_fd_in, ms()->last_fd_out);
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

static char *add_metachar(char *cmd, t_list *tokens, char *meta_str)
{
	// char	*meta;
	char	*new_cmd;

	if (ft_strequal(meta_str, "|"))
		add_command(cmd, true);
	if (ft_strequal(meta_str, "<"))
		ms()->file_input = // FD of next token (Open next token)
	if (ft_strequal(meta_str, ">"))
		ms()->file_output = // FD of next token (Open next token)
			// if (!ft_strequal(cmd, ""))
			// 	add_command(cmd);
			// ft_strdel(&cmd);
			// meta = (char *)protected_calloc(1, 1);
			// meta = join_token(meta, meta_str);
			// add_command(meta);
			// ft_strdel(&meta);
			new_cmd = (char *)protected_calloc(1, 1);
	return (new_cmd);
}

static void add_command(char *cmd, bool create_pipe, int in_fd, int out_fd)
{
	t_command	*command;

	command = protected_calloc(1, sizeof(t_command));
	command->command = ft_split(cmd, ' ');
	if (ms()->file_input != STDIN_FILENO)
		command->in_fd = ms()->file_input;
	else
		command->in_fd = ms()->last_fd_in;
	command->out_fd = ms()->last_fd_out;
	if (create_pipe)
	{
		if (pipe(command->pipe) == ERROR)
			program_errors("OPENING PIPES", true, true);
		if (command->out_fd != STDOUT_FILENO)
			command->out_fd = ms()->file_output;
		else
			command->out_fd = command->pipe[1];
		ms()->last_fd_in = command->pipe[0];
	}
	if (!ms()->commands)
		ms()->commands = ft_lstnew((void *)command);
	else
		ft_lstadd_back(&ms()->commands, ft_lstnew((void *)command));
	ms()->last_fd_out = STDOUT_FILENO;
}
