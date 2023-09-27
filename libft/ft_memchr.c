/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:35:56 by whendrix          #+#    #+#             */
/*   Updated: 2022/07/07 03:37:51 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	str = NULL;
	return (str);
}

/*
Description
The function memchr searches for the first occurrence of the character c
(an unsigned char) in the first n bytes of the string pointed to, 
by the argument s.

Return Value
This function returns a pointer to the matching byte or NULL if the character
does not occur in the given memory area.
*/