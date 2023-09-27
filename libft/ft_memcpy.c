/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:57:17 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/20 21:45:37 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_pont;
	unsigned char	*src_pont;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest_pont = (unsigned char *)dest;
	src_pont = (unsigned char *)src;
	while (n > i)
	{
		dest_pont[i] = src_pont[i];
		i++;
	}
	return (dest);
}

/*
Description
The function memcpy copies n characters from memory area 
src to memory area dest.

Return Value
This function returns a pointer to destination.
*/