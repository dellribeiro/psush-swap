/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:41:39 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/20 22:00:05 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*memory;

	i = 0;
	memory = (unsigned char *)s;
	while (n > i)
	{
		memory[i] = c;
		i++;
	}
	return (memory);
}

/*
Description
The function memset copies the character c to the first 
n characters of the string pointed to, by the argument s.

Return Value
This function returns a pointer to the memory area s.
*/