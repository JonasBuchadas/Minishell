/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <jocaetan@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:50:50 by jocaetan          #+#    #+#             */
/*   Updated: 2023/01/17 22:46:07 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The atoi() function converts the initial portion of the string pointed to by str
to int representation
*/

#include "libft.h"

static long	readnumbers(const char *str, long i, long signal);
static long	check_overflow(const char *str, long i, long signal);
static long	check_signal(char c);
static long	ft_isspace(int c);

long	ft_atol(const char *str)
{
	long	i;
	long	signal;
	long	result;

	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	signal = check_signal(str[i]);
	if (signal < 0)
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		result = readnumbers(str, i, signal);
	return (result);
}

static long	readnumbers(const char *str, long i, long signal)
{
	long	result;

	result = check_overflow(str, i, signal);
	if (result != 0)
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * signal);
}

static long	check_signal(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (-1);
	return (1);
}

static long	check_overflow(const char *str, long i, long signal)
{
	int		len;
	int		index;
	char	*max;
	char	*min;

	len = 0;
	index = i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		len++;
		i++;
	}
	i = index;
	max = "9223372036854775807";
	min = "9223372036854775808";
	if (len < 19)
		return (0);
	else if (len > 19)
		return (1);
	else if (len == 19 && signal >= 0 && ft_strncmp(&str[i], max, 19) > 0)
		return (1);
	else if (len == 19 && signal < 0 && ft_strncmp(&str[i], min, 19) > 0)
		return (1);
	return (0);
}

static long	ft_isspace(int c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	else
		return (0);
}
