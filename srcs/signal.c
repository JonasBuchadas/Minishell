/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:52:37 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/30 09:07:18 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sg_int(int sghandler)
{
	(void)sghandler;
	ms()->status = EXIT_SIGINT;
	ms()->exit = EXIT_SIGINT;
	if (ms()->on_read)
		ms()->lstatus = EXIT_SIGINT;
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	if (ms()->on_read)
		rl_redisplay();
}

void	sg_quit(int sghandler)
{
	(void)sghandler;
}

void	sg_init(void)
{
	signal(SIGINT, &sg_int);
	signal(SIGQUIT, &sg_quit);
}
