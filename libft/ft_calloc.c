/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:53:37 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/23 04:41:10 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t n)
{
	void	*pont;

	if (nb == SIZE_MAX || n == SIZE_MAX)
		return (NULL);
	pont = malloc(nb * n);
	if (!pont)
		return (NULL);
	ft_bzero (pont, (nb * n));
	return (pont);
}

/*
Description 
The function calloc allocates the requested memory
and returns a pointer to it.
Calloc sets allocated memory to zero.

Return Value 
This function returns a pointer to the allocated
memory, or NULL if the request fails.
*/