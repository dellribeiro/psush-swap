/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:31:03 by whendrix          #+#    #+#             */
/*   Updated: 2022/06/22 18:23:45 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
Description
The function isascii tests if a given character,in the current
locale,can be represented as a valid 7–bit US-ASCII character.

Return Value
This function returns non-zero value if c in the current locale, 
can be represented as a character in the 7–bit US-ASCII character 
set, else it returns 0.
*/