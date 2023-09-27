/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 22:41:00 by whendrix          #+#    #+#             */
/*   Updated: 2022/07/02 01:42:02 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	find;

	find = c;
	while (*str != find)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

/*
Description
The function strchr searches for the first occurrence of the character c 
(an unsigned char) in the string pointed to by the argument str.

Return Value
This returns a pointer to the first occurrence of the character c 
in the string str, or NULL if the character is not found.
*/