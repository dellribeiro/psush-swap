/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:33:49 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/27 21:11:34 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	char	find;
	int		len;
	char	*result;

	find = (char)c;
	result = 0;
	len = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + len);
	while (*s)
	{
		if (*s == find)
			result = (char *) s;
		s++;
	}
	return (result);
}

/*
Description 
The C library function strrchr searches for the last
occurrence of the character c in the string pointed to,
by the argument s.

Return Value 
This function returns a pointer to the last occurrence
of character in str. If the value is not found,
the function returns a null pointer.
*/