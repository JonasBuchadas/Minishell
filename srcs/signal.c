/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:52:37 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/17 07:00:28 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sg_int(int sghandler)
{
	/* CTRL+C handler. Should stop execution & return a new line */
	(void)sghandler;
	ms()->exit = 3;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	if (ms()->on_read)
		rl_redisplay();
}

void	sg_quit(int sghandler)
{
	/* CTRL+\ handler. Should do NOTHING */
	(void)sghandler;
	ft_putstr_fd("SIGQUIT received\n", 2);
}

void	sg_init(void)
{
	signal(SIGINT, &sg_int);
	signal(SIGQUIT, &sg_quit);
}