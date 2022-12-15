/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvarela <fvarela@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 07:52:37 by fvarela           #+#    #+#             */
/*   Updated: 2022/12/15 08:04:05 by fvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sg_int(int sghandler)
{
	/* CTRL+C handler. Should stop execution & return a new line */
	(void)sghandler;
	ft_putstr_fd("SIGINT received\n", 2);
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