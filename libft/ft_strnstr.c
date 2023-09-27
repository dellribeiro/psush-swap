/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:45:46 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/23 04:27:13 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i])
	{
		n = 0;
		while (big[i + n] == little[n] && (i + n) < len)
		{
			if (big[i + n] == '\0' && little[n] == '\0')
				return ((char *)&big[i]);
			n++;
		}
		if (little[n] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}

/*
Description 
The strnstr function locates the first occurrence of
the null-terminated string little in the string big.

Return Value 
If	little is an empty string, big is returned; if little occurs nowhere
in	big, NULL is returned; otherwise a pointer to the first	character of
the first occurrence of little is returned.
*/