/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:52:37 by fvarela           #+#    #+#             */
/*   Updated: 2023/01/12 09:52:00 by tpereira         ###   ########.fr       */
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
	int			 	rc;
	struct termios	mytermios;

	rc = tcgetattr(0, &mytermios);
	mytermios.c_cc[VINTR] = CTRL_C;
	mytermios.c_lflag &= ~ECHOCTL;
	rc = tcsetattr(0, TCSANOW, &mytermios);
	signal(SIGINT, &sg_int);
	signal(SIGQUIT, &sg_quit);
}
