/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:04:21 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:11:52 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
				write(STDERR_FILENO, INT_ERROR, ft_strlen(INT_ERROR));
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
			write(STDERR_FILENO, RANGE_ERROR, ft_strlen(RANGE_ERROR));
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
				write(STDERR_FILENO, DUP_ERROR, ft_strlen(DUP_ERROR));
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	arg_checker_bonus(char **argv)
{
	if (is_int(argv) && is_args_in_range(argv) && is_duplicate(argv))
		return (0);
	exit (0);
}
