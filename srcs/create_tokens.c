#include "minishell.h"

static int	handle_double_quotes(int i);
static int	handle_single_quotes(int i);
static int	handle_metachar(int i);
static void add_token(unsigned int start, int len, int parse_code);

// Will travel the input and create tokens within "", '' or [space]
void create_tokens(void)
{
	int			i;

	ms()->last_i = 0;
	i = 0;
	while (ms()->input[i])
	{
		if (ms()->input[i] == '\"')
			i = handle_double_quotes(i);
		if (ms()->input[i] == '\'')
			i = handle_single_quotes(i);
		if (is_metachar(ms()->input[i]))
			i = handle_metachar(i);
		if (!(ms()->input[i] == '\"' || ms()->input[i] == '\'') && ms()->input[i])
			i++;
	}
	handle_metachar(i);
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
			if (len > 0)
				add_token(start, len, DOUBLE_QUOTES);
			if (ms()->input[i + 1] && ms()->input[i + 1] != ' ')
				ms()->last_i = ++i;
			else
				ms()->last_i = ++i + 1;
			return (i);
		}
		len++;
	}
	return (start);
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
			if (len > 0)
				add_token(start, len, SINGLE_QUOTES);
			if (ms()->input[i + 1] && ms()->input[i + 1] != ' ')
				ms()->last_i = ++i;
			else
				ms()->last_i = ++i + 1;
			return (i);
		}
		len++;
	}
	return (start);
}

//Handle space has to create a token with the lenght
//of last token index and the current index
static int handle_metachar(int i)
{
	int len;

	len = i - ms()->last_i;
	if (len > 0)
	{
		add_token(ms()->last_i, len, NORMAL);
		ms()->last_i += len;
	}
	if ((ms()->input[i] == '<' && ms()->input[i + 1] == '<')
		|| (ms()->input[i] == '>' && ms()->input[i + 1] == '>'))
	{
		add_token(ms()->last_i, 2, METACHAR);
		ms()->last_i = ms()->last_i + 2;
		return (++i);
	}
	if (ms()->input[i] && ms()->input[i] != ' ')
	{
		add_token(ms()->last_i, 1, METACHAR);
		ms()->last_i++;
	}
	return (i);
}

static void add_token(unsigned int start, int len, int parse_code)
{
	t_token *token;
	char *text;
	char *temp;

	text = ft_substr(ms()->input, start, len);
	if (parse_code == SINGLE_QUOTES || parse_code == DOUBLE_QUOTES)
	{
		temp = text;
		text = ft_strjoin(" ", temp);
		ft_strdel(&temp);
	}
	if (ft_strequal(text, " "))
	{
		ft_strdel(&text);
		return ;
	}
	token = protected_calloc(1, sizeof(t_token));
	token->parse_code = parse_code;
	token->text = text;
	if (!ms()->tokens)
		ms()->tokens = ft_lstnew((void *)token);
	else
		ft_lstadd_back(&ms()->tokens, ft_lstnew((void *)token));
}