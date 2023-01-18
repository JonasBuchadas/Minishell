/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_tilde.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:07:04 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/18 15:51:19 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_tilde(t_token *token)
{
	char	*tilde_exp;
	char	*prefix;
	char	*suffix;
	char	*result;

	if (token->text[1] == '~'
		&& (!token->text[2] || token->text[2] == ' ' || token->text[2] == '/'))
	{
		tilde_exp = get_env("HOME");
		prefix = ft_strjoin(" ", tilde_exp);
		suffix = ft_substr(token->text, 2, ft_strlen(token->text) - 1);
		result = ft_strjoin(prefix, suffix);
		ft_strdel(&prefix);
		ft_strdel(&suffix);
		ft_strdel(&token->text);
		token->text = result;
	}
}
