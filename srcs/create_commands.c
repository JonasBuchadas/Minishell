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
	ms()->last_fd_in = STDIN_FILENO;
	ms()->last_fd_out = STDOUT_FILENO;
	while (current)
	{
		token = (t_token *)current->content;
		if (token->parse_code != METACHAR)
			command = join_token(command, token->text);
		else
			command = add_metachar(command, token->text);
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

static char *add_metachar(char *cmd, char *meta_str)
{
	// char	*meta;
	char	*new_cmd;

	if (ft_strequal(meta_str, "|"))
		add_command(cmd, true, ms()->last_fd_in, ms()->last_fd_out);
	if (ft_strequal(meta_str, "<"))
		ms()->last_fd_in = // FD of next token (Open next token)
	if (ft_strequal(meta_str, ">"))
		ms()->last_fd_out = // FD of next token (Open next token)
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
	command->in_fd = in_fd;
	command->out_fd = out_fd;
	if (create_pipe)
	{
		if (pipe(command->pipe) == ERROR)
			program_errors("OPENING PIPES", true, true);
		command->out_fd = command->pipe[1];
		ms()->last_fd_in = command->pipe[0];
	}
	if (!ms()->commands)
		ms()->commands = ft_lstnew((void *)command);
	else
		ft_lstadd_back(&ms()->commands, ft_lstnew((void *)command));
}
