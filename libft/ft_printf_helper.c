/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 21:29:30 by whendrix          #+#    #+#             */
/*   Updated: 2022/10/27 03:34:55 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_pf_putstr(char *str)
{
	int	i;	

	i = 0;
	if (!str)
	{
		ft_pf_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		ft_pf_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_nb_base(size_t nb, int base)
{
	int	i;

	i = 0;
	if (!nb)
		return (1);
	while (nb > 0)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char	*ft_utoa(unsigned int n)
{
	int				len;
	char			*str;
	unsigned int	nb;

	nb = n;
	len = ft_nb_base(nb, 10);
	str = malloc ((len) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
