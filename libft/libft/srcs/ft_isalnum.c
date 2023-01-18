/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:37:33 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 14:23:24 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The isalnum() function tests for any character for which isalpha(3) or 
isdigit(3) is true. The value of the argument must be representable as an 
unsigned char or the value of EOF.
*/

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}
