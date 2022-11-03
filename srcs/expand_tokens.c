#include "minishell.h"

static void		expand_env(t_token *token, int i);
static char		*expand_env_var(t_token *token, int i);
static t_token	*create_token(char *text, int code);

void	expand_tokens(void)
{
	t_list *tokens;

	tokens = ft_lstmap(ms()->tokens, &expand_token, &del_token);
	//TODO: Return error and exit minishell
	if (!tokens)
		return ;
	ft_lstclear(&ms()->tokens, del_token_list);
	ms()->tokens = tokens;
}

void	*expand_token(void *elem)
{
	t_token	*token;
	int		i;

	if (!elem)
	//TODO: Return error and exit minishell
		return ((void *)elem);
	token = (t_token *)elem;
	if (token->parse_code == SINGLE_QUOTES)
		return ((void *)create_token(token->text, token->parse_code));
	i = -1;
	while (token->text[++i])
	{
		if (token->text[i] == '$')
		{
			expand_env(token, i);
			i--;
		}
	}
	return ((void *)create_token(token->text, token->parse_code));
}

static void	expand_env(t_token *token, int i)
{
	size_t			len;
	unsigned int	start;
	char			*temp1;
	char			*temp2;
	char			*env;

	env = expand_env_var(token, i);
	if (!env)
	{
		ft_strdel(&token->text);
		// TODO: Return error and exit minishell
		token->text = (char *)calloc(1, 1);
		return ;
	}
	start = (unsigned int)i++;
	temp1 = ft_substr(token->text, 0, start);
	temp2 = ft_strjoin(temp1, env);
	ft_strdel(&temp1);
	i = ft_strlen(temp2);
	len = ft_strlen(token->text);
	temp1 = ft_substr(token->text, (unsigned int) i, (size_t)len - i);
	ft_strdel(&token->text);
	token->text = ft_strjoin(temp2, temp1);
	ft_strdel(&temp1);
	ft_strdel(&temp2);
}

static char	*expand_env_var(t_token *token, int i)
{
	size_t			len;
	unsigned int	start;
	char			*temp1;
	char			*env;

	len = 0;
	while (token->text[len] && token->text[len] != ' ')
		len++;
	start = (unsigned int)i + 1;
	temp1 = ft_substr(token->text, start, len);
	env = getenv(temp1);
	ft_strdel(&temp1);
	return (env);
}

static t_token	*create_token(char *text, int code)
{
	t_token	*token;

	token = calloc(1, sizeof(t_token));
	// TODO: Return error and exit minishell
	// if (!new)
	// 	error();
	token->text = text;
	token->parse_code = code;
	return (token);
}