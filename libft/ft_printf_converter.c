/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 06:59:41 by whendrix          #+#    #+#             */
/*   Updated: 2022/10/21 02:35:55 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	len = ft_pf_putstr(str);
	free(str);
	return (len);
}

int	ft_put_usigned(unsigned int nb)
{
	char	*str;
	int		len;

	str = ft_utoa(nb);
	len = ft_pf_putstr(str);
	free(str);
	return (len);
}

int	ft_puthex(unsigned long nb, char c)
{
	int	i;

	i = ft_nb_base(nb, 16);
	if (nb >= 16)
	{
		ft_puthex(nb / 16, c);
		ft_puthex(nb % 16, c);
	}
	else
	{
		if (nb < 10)
			ft_pf_putchar(nb + 48);
		else if (c == 'x')
			ft_pf_putchar(nb + 87);
		else
			ft_pf_putchar(nb + 55);
	}
	return (i);
}

int	ft_putptr(unsigned long ptr)
{
	int		len;

	if (!ptr)
		return (ft_pf_putstr("(nil)"));
	len = ft_pf_putstr("0x");
	len += ft_puthex(ptr, 'x');
	return (len);
}
