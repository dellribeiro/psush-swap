/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 06:58:09 by whendrix          #+#    #+#             */
/*   Updated: 2022/10/21 02:34:29 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_convert(va_list args, const char *str, int i)
{
	if (str[i] == 'c')
		return (ft_pf_putchar(va_arg(args, int)));
	else if (str[i] == 's')
		return (ft_pf_putstr(va_arg(args, char *)));
	else if (str[i] == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	else if (str[i] == 'd' || str[i] == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (str[i] == 'u')
		return (ft_put_usigned(va_arg(args, unsigned int)));
	else if (str[i] == 'x' || str[i] == 'X')
		return (ft_puthex(va_arg(args, unsigned int), str[i]));
	else
		return (ft_pf_putchar('%'));
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		result;
	va_list	args;

	i = 0;
	result = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			result += ft_convert(args, str, i);
		}
		else
			result += ft_pf_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (result);
}
