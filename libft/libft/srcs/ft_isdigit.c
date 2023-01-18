/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:41:25 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/28 11:44:30 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The isdigit() function tests for a decimal digit character.  Regardless of 
locale, this includes the following characters only:

     ``0''         ``1''         ``2''         ``3''         ``4''
     ``5''         ``6''         ``7''         ``8''         ``9''
*/

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
