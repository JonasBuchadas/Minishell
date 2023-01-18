/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaetan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 13:38:54 by jocaetan          #+#    #+#             */
/*   Updated: 2021/10/28 19:41:32 by jocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
The strnstr() function locates the first occurrence of the null-terminated 
string needle in the string haystack, where not more than len characters are 
searched.
Characters that appear after a `\0' character are not searched.  
Since the strnstr() function is a FreeBSD specific API, it should only be used 
when portability is not a concern.
*/

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			j;

	if (!*needle)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((i + j) < len && needle[j] && haystack[i + j]
				&& needle[j] == haystack[i + j])
				j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
	}
	return (0);
}
