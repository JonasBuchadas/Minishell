/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:34:37 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:50:40 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
Outputs the integer ’n’ to the given file descriptor.
*/

#include <unistd.h>

static int	find_digits(int n);
static void	print_digits(unsigned int n, int digits, int fd);
static int	power_10(int exp);

void	ft_putnbr_fd(int n, int fd)
{
	int				digits;
	unsigned int	un;

	un = n;
	digits = find_digits(n);
	if (n < 0)
	{
		write(fd, "-", 1);
		un *= -1;
	}
	print_digits(un, digits, fd);
}

static int	find_digits(int n)
{
	int	digits;

	digits = 1;
	while (n / 10 != 0)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

static void	print_digits(unsigned int n, int digits, int fd)
{
	int	digit;
	int	power;

	while (digits >= 1)
	{
		power = power_10(digits);
		digit = n / power;
		digit = digit + 48;
		write(fd, &digit, 1);
		digits--;
		n %= power;
	}
}

static int	power_10(int exp)
{
	int	result;

	result = 1;
	while (exp > 1)
	{
		result *= 10;
		exp--;
	}
	return (result);
}	
