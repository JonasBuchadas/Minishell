#include "minishell.h"

static char		*join_token(char *cmd, char *str);
static t_list	*redirect_io(t_list *tokens, char *redirect);
static char		*add_command(char *cmd, bool pipe);

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
		else if (ft_strequal(token->text, "|"))
			command = add_command(command, true);
		else
			current = redirect_io(current, token->text);
		current = current->next;
	}
	command = add_command(command, false);
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

static t_list *redirect_io(t_list *tokens, char *redirect)
{
	t_list	*next;
	t_token	*token;
	char	*filename;

	if (!tokens->next)
		unexpected_token_error("newline");
	next = tokens->next;
	token = (t_token *)next->content;
	filename = ft_strtrim(token->text, " ");
	if (token->parse_code == METACHAR)
		unexpected_token_error(token->text);
	if (ft_strequal(redirect, "<"))
		ms()->file_input = read_file(filename);
	if (ft_strequal(redirect, ">"))
		ms()->file_output = write_file(filename);
	if (ft_strequal(redirect, "<<"))
		ms()->file_input = here_doc(filename);
	if (ft_strequal(redirect, ">>"))
		ms()->file_output = append_file(filename);
	ft_strdel(&filename);
	return (next);
}

static char *add_command(char *cmd, bool create_pipe)
{
	t_command	*command;

	command = protected_calloc(1, sizeof(t_command));
	command->command = ft_split(cmd, ' ');
	command->in_fd = ms()->file_input;
	command->out_fd = ms()->last_fd_out;
	command->pipe = false;
	if (create_pipe)
		command->pipe = true;
	if (!ms()->commands)
		ms()->commands = ft_lstnew((void *)command);
	else
		ft_lstadd_back(&ms()->commands, ft_lstnew((void *)command));
	ms()->file_input = STDIN_FILENO;
	ms()->file_output = STDOUT_FILENO;
	ft_strdel(&cmd);
	return (char *)protected_calloc(1, 1);
}
		// if (pipe(command->pipe) == ERROR)
		// 	program_errors("OPENING PIPES", true, true);
		// if (command->out_fd != STDOUT_FILENO)
		// 	command->out_fd = ms()->file_output;
		// else
		// 	command->out_fd = command->pipe[1];
		// ms()->last_fd_in = command->pipe[0];
