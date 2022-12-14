/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:07:04 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/24 16:07:05 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		expand_token_text(t_token *token);
static void		expand_env(t_token *token, int i, int len);
static char		*expand_env_var(t_token *token, int i, int env_len);
static t_token	*create_token(char *text, int code);

void	*expand_token(void *elem)
{
	t_token	*token;

	if (!elem)
		program_errors("MALLOC", true, true);
	token = (t_token *)elem;
	if (token->parse_code == SINGLE_QUOTES)
		return ((void *)create_token(token->text, token->parse_code));
	expand_token_text(token);
	return ((void *)create_token(token->text, token->parse_code));
}

static void	expand_token_text(t_token *token)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (token->text[++i])
	{
		if (token->text[i] == '$')
		{
			len = 0;
			j = i;
			while (token->text[++j] && token->text[j] != ' '
				&& token->text[j] != '$' && token->text[j] != '=')
				len++;
			if (token->text[i + 1] == '?')
				expand_env(token, i, 1);
			else
				expand_env(token, i, len);
			i--;
			if (!token->text[0])
				break ;
		}
	}
}

static void	expand_env(t_token *token, int i, int env_len)
{
	unsigned int	start;
	char			*temp1;
	char			*temp2;
	char			*env;

	env = expand_env_var(token, i, env_len);
	if (!env)
		env = (char *)protected_calloc(1, 1);
	start = (unsigned int)i++;
	temp1 = ft_substr(token->text, 0, start);
	temp2 = ft_strjoin(temp1, env);
	ft_strdel(&temp1);
	i += env_len;
	if (token->text[start + 1] == '?')
	{
		i -= ft_strlen(env) - 1;
		free(env);
	}
	temp1 = ft_substr(token->text, (unsigned int) i, \
		(size_t)strlen(token->text) - i);
	ft_strdel(&token->text);
	token->text = ft_strjoin(temp2, temp1);
	ft_strdel(&temp1);
	ft_strdel(&temp2);
}

static char	*expand_env_var(t_token *token, int i, int len)
{
	unsigned int	start;
	char			*temp1;
	char			*env;

	start = (unsigned int)i + 1;
	temp1 = ft_substr(token->text, start, len);
	if (ft_strequal(temp1, "?") || temp1[0] == '?')
		env = ft_itoa(ms()->status);
	else
		env = get_env(temp1);
	ft_strdel(&temp1);
	return (env);
}

static t_token	*create_token(char *text, int code)
{
	t_token	*token;

	token = protected_calloc(1, sizeof(t_token));
	token->text = text;
	token->parse_code = code;
	return (token);
}
