/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:25:43 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 04:53:34 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push(t_stack *stack, int x)
{
	stack->top++;
	stack->data[stack->top] = x;
}

int	ft_pop(t_stack *stack)
{
	int	top;

	if (stack->top == -1)
	{
		write(1, "Error: empty\n", 14);
		return (-1);
	}
	top = stack->data[stack->top];
	stack->data[stack->top] = 0;
	stack->top--;
	return (top);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 1)
	{
		if (stack->data[i] > stack->data[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->data);
	free(stack_b->data);
}

int	get_condition(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	mid_a;
	int	mid_b;

	mid_a = stack_a->top / 2;
	mid_b = stack_b->top / 2;
	if (idx_a >= mid_a && idx_b >= mid_b)
		return (BOTH_UP);
	if (idx_a < mid_a && idx_b < mid_b)
		return (BOTH_DOWN);
	if (idx_a >= mid_a && idx_b < mid_b)
		return (TOP_UP_NUM_DOWN);
	if (idx_a < mid_a && idx_b >= mid_b)
		return (TOP_DOWN_NUM_UP);
	return (-1);
}
