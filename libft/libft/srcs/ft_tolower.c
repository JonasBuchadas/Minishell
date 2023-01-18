/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:37:15 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/22 15:29:52 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The tolower() function converts an upper-case letter to the corresponding 
lower-case letter. The argument must be representable as an unsigned char or 
the value of EOF.
*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
