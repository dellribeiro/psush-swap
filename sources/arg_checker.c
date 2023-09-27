/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 03:01:29 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/14 20:15:45 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_int(char **argv)
{
	int	y;
	int	i;

	y = 0;
	while (argv[++y])
	{
		i = -1;
		while (argv[y][++i])
		{
			if (argv[y][i] == '-')
				i++;
			if (!ft_isdigit(argv[y][i]))
			{
				write(STDERR_FILENO, ERROR, ft_strlen(ERROR));
				return (0);
			}
		}
	}
	return (1);
}

static int	is_args_in_range(char **argv)
{
	int	y;

	y = 0;
	while (argv[++y])
	{
		if (ft_atol(argv[y]) > INT_MAX || ft_atol(argv[y]) < INT_MIN)
		{
			write(STDERR_FILENO, ERROR, ft_strlen(ERROR));
			return (0);
		}
	}
	return (1);
}

static int	is_duplicate(char **argv)
{
	int	holder;
	int	y;
	int	i;

	y = 0;
	while (argv[++y])
	{
		i = y + 1;
		holder = ft_atoi(argv[y]);
		while (argv[i])
		{
			if (holder == ft_atoi(argv[i]))
			{
				write(STDERR_FILENO, ERROR, ft_strlen(ERROR));
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	arg_checker(char **argv)
{
	if (is_int(argv) && is_args_in_range(argv) && is_duplicate(argv))
		return (0);
	exit (0);
}
