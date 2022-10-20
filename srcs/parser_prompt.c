#include "minishell.h"

// Will travel the input and create tokens within "", '' or [space]
void parse_tokens(void)
{
	int			i;
	t_token		*token;

	ms()->last_index = 0;
	if (!ms()->tokens)
		ms()->tokens = ft_calloc(1, sizeof(t_list*));
	//TODO: Malloc protection
	// if (!ms()->tokens)
	// 	program_errors();
	i = -1;
	token = ft_calloc(1, sizeof(t_token));
	// TODO: Malloc protection
	while (ms()->input[++i])
	{
		// if (ms()->input[i] == '\"')
		// 	i = handle_double_quotes(&tokens, i);
		// else if (ms()->input[i] == '\'')
			// i = handle_single_quotes(&tokens, i);
		// else if (ms()->input[i] == ' ')
			// i = handle_space(&tokens, i);
	}
	//TODO: token->text is a sub string of input until space
	token->text = ft_strdup(ms()->input);
	token->double_quotes = true;
	ft_lstadd_front(&ms()->tokens, ft_lstnew((void*)token));
	printf("%s\n", ((t_token*)ms()->tokens->content)->text);
}

static int	handle_double_quotes(t_list **tokens, int i)
{
	t_token	*token;
	size_t	len;
	int		start;

	len = 0;
	start = i + 1;
	while (ms()->input[++i])
	{
		if (ms()->input[i] == '\"')
		{
			token = ft_calloc(1, sizeof(t_token));
			// TODO: Malloc protection
			token->double_quotes = true;
			token->text = ft_substr(ms()->input, (unsigned int)start, len);
			//TODO Malloc Protection ???
			ft_lstadd_back(tokens, ft_lstnew((void*)token));
			ms()->last_index = ++i;
			return i;
		}
		len++;
	}
	return start;
}

static int	handle_single_quotes(t_list **tokens, int i)
{
	t_token	*token;
	size_t	len;
	int		start;

	len = 0;
	start = i + 1;
	while (ms()->input[++i])
	{
		if (ms()->input[i] == '\'')
		{
			token = ft_calloc(1, sizeof(t_token));
			// TODO: Malloc protection
			token->single_quotes = true;
			token->text = ft_substr(ms()->input, (unsigned int)start, len);
			// TODO Malloc Protection ???
			ft_lstadd_back(tokens, ft_lstnew((void *)token));
			ms()->last_index = ++i;
			return i;
		}
		len++;
	}
	return start;
}

//Handle space has to create a token with the lenght of last token index and the current index
static int	handle_space(t_list **tokens, int i)
{
	t_token	*token;
	unsigned int start;

	start = ms()->last_index;
	token = ft_calloc(1, sizeof(t_token));
	// TODO: Malloc protection
	token->double_quotes = false;
	token->single_quotes = false;
	token->text = ft_substr(ms()->input, start, start - (unsigned int)i);
	// TODO Malloc Protection ???
	ft_lstadd_back(tokens, ft_lstnew((void *)token));
	return ++i;
}
