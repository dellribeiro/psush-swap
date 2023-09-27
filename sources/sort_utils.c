/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:20:10 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 04:52:11 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

	min = stack->data[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] < min)
			min = stack->data[i];
		i++;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int	max;
	int	i;

	max = stack->data[0];
	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] > max)
			max = stack->data[i];
		i++;
	}
	return (max);
}

void	sort_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	while (!is_sorted(stack_a))
	{
		if ((stack_a->data[stack_a->top] < stack_a->data[stack_a->top - 1]
				&& stack_a->data[stack_a->top] > stack_a->data[0])
			|| stack_a->data[stack_a->top] == min
			|| stack_a->data[stack_a->top] == max)
			rotate(stack_a, 1);
		else
			push(stack_a, stack_b);
	}
}

int	get_position(t_stack *stack_a, int num_moves, int target_value)
{
	int	position;

	position = 1;
	if (num_moves == 1)
		return (stack_a->top);
	while (position <= stack_a->top)
	{
		if (target_value < stack_a->data[position - 1]
			&& target_value > stack_a->data[position])
			return (position - 1);
		position++;
	}
	return (position - 1);
}

int	get_moves(t_stack *stack, int value)
{
	int	num_moves;
	int	half;
	int	top;

	num_moves = 0;
	half = stack->top / 2;
	top = stack->top;
	if (value < stack->data[top] && value > stack->data[0])
		return (1);
	while (top >= half)
	{
		num_moves++;
		if (value < stack->data[top] && value > stack->data[top + 1])
			break ;
		top--;
	}
	while (top < half)
	{
		if (value < stack->data[top] && value > stack->data[top + 1])
			break ;
		num_moves--;
		top--;
	}
	return (num_moves + 1);
}
