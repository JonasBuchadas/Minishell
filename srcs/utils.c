/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 15:30:06 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/02 00:20:00 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_metachar(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '|' || \
	c == '&' || c == ';' || c == '(' || c == ')' || c == '<' || c == '>')
		return (true);
	return (false);
}

void	*protected_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(count, size);
	if (!ptr)
		program_errors("MALLOC", true, true);
	return (ptr);
}

void	dup2_util(int read_end, int write_end)
{
	if (dup2(read_end, STDIN_FILENO) == ERROR)
		program_errors("DUP2", true, true);
	if (dup2(write_end, STDOUT_FILENO) == ERROR)
		program_errors("DUP2", true, true);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	close_pipes(void)
{
	int	i;

	if (!ms()->pipes)
		return ;
	i = -1;
	while (++i < ms()->n_pipes)
	{
		close(ms()->pipes[i]);
		ms()->pipes[i] = -1;
	}
	free(ms()->pipes);
	ms()->pipes = NULL;
}
