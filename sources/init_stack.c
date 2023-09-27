/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:24:40 by whendrix          #+#    #+#             */
/*   Updated: 2023/02/16 00:52:28 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_numbers_in_stack(t_stack *stack, char **argv)
{
	int	i;

	i = stack->max_size;
	while (i > 0)
	{
		ft_push(stack, ft_atoi(argv[i]));
		i--;
	}
}

void	init_stack(t_stack	*stack, int max_size, char id)
{
	stack->max_size = max_size;
	stack->top = -1;
	stack->data = malloc(max_size * sizeof(int));
	stack->id = id;
}
