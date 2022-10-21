#include "minishell.h"

static int	handle_double_quotes(int i);
static int	handle_single_quotes(int i);
static int	handle_space(int i);
static void add_token(unsigned int start, int len, int parse_code);

// Will travel the input and create tokens within "", '' or [space]
void create_tokens(void)
{
	int			i;

	ms()->last_i = 0;
	i = -1;
	while (ms()->input[++i])
	{
		if (ms()->input[i] == '\"')
			i = handle_double_quotes(i);
		else if (ms()->input[i] == '\'')
			i = handle_single_quotes(i);
		else if (ms()->input[i] == ' ')
			i = handle_space(i);
	}
	handle_space(i);
}

static int	handle_double_quotes(int i)
{
	size_t	len;
	int		start;

	len = 0;
	start = i + 1;
	while (ms()->input[++i])
	{
		if (ms()->input[i] == '\"')
		{
			add_token(start, len, DOUBLE_QUOTES);
			ms()->last_i = ++i;
			return i;
		}
		len++;
	}
	return start;
}

static int	handle_single_quotes(int i)
{
	size_t	len;
	int		start;

	len = 0;
	start = i + 1;
	while (ms()->input[++i])
	{
		if (ms()->input[i] == '\'')
		{
			add_token(start, len, SINGLE_QUOTES);
			ms()->last_i = ++i;
			return i;
		}
		len++;
	}
	return start;
}

//Handle space has to create a token with the lenght of last token index and the current index
static int	handle_space(int i)
{
	size_t			len;
	// unsigned int	space_len;

	len = i - ms()->last_i;
	if (len > 0)
	// {
	// 	while (input[ms()->last_i] == ' ')
	// 		ms()->last_i++;
	// 	while (input[ms()->last_i + len] && input[ms()->last_i + len] != ' ')
	// 		len++;
	// 	if (len != 0)
	// 		add_token(ms()->last_i, len, NORMAL);
	// 	ms()->last_i += (int)len;
	// }
	{
		// space_len = 0;
		// while (ms()->input[ms()->last_i + space_len] == ' ')
		// 	space_len++;
		add_token(ms()->last_i, len, NORMAL);
		ms()->last_i += len + 1;
	}
	else
		ms()->last_i++;
	return i;
}

static void add_token(unsigned int start, int len, int parse_code)
{
	t_token *token;

	token = ft_calloc(1, sizeof(t_token));
	// TODO: Malloc protection
	token->parse_code = parse_code;
	token->text = ft_substr(ms()->input, start, len);
	if (!ms()->tokens)
		ms()->tokens = ft_lstnew((void *)token);
	else
		ft_lstadd_back(&ms()->tokens, ft_lstnew((void *)token));
}
