/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:05:00 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:14:12 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	add_numbers_in_stack_bonus(t_bonus *stack, char **argv)
{
	int	i;

	i = stack->max_size;
	while (i > 0)
	{
		ft_push(stack, ft_atoi(argv[i]));
		i--;
	}
}

void	init_stack_bonus(t_bonus	*stack, int max_size, char id)
{
	stack->max_size = max_size;
	stack->top = -1;
	stack->data = malloc(max_size * sizeof(int));
	stack->id = id;
}
