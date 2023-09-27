/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 22:44:10 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/23 04:01:41 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(dest) + ft_strlen(src);
	j = ft_strlen(dest);
	i = 0;
	if (n < j)
		return (ft_strlen(src) + n);
	while (src[i] && (j + 1) < n)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (len);
}

/*
Description 
The function concatenate strings. 
They are designed to be safer, more consistent,
and less error prone replacements for strncat(3).

Return Value 
strlcat functions return the total length of
the string they tried to create.
*/