/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:03:56 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 04:50:37 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_numbers(t_stack *stack)
{
	while (!is_sorted(stack))
	{
		if ((stack->data[stack->top] > stack->data[stack->top - 1])
			&& (stack->data[stack->top - 1] > stack->data[stack->top - 2]))
		{
			rotate(stack, 1);
			swap(stack, 1);
		}
		else if ((stack->data[stack->top] < stack->data[stack->top - 1])
			&& (stack->data[stack->top] < stack->data[stack->top - 2]))
		{
			swap(stack, 1);
			rotate(stack, 1);
		}
		else if ((stack->data[stack->top] < stack->data[stack->top - 1])
			&& (stack->data[stack->top] > stack->data[stack->top - 2]))
			reverse_rotate(stack, 1);
		else if ((stack->data[stack->top] > stack->data[stack->top - 1])
			&& (stack->data[stack->top] > stack->data[stack->top - 2]))
			rotate(stack, 1);
		else
			swap(stack, 1);
	}
}

static void	sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	small;

	while (stack_a->top >= 3)
	{
		small = find_min(stack_a);
		if (stack_a->data[stack_a->top - 1] == small)
			swap(stack_a, 1);
		else if (stack_a->data[stack_a->top - 2] == small)
		{
			rotate(stack_a, 1);
			rotate(stack_a, 1);
		}
		else if (stack_a->data[1] == small)
		{
			reverse_rotate(stack_a, 1);
			reverse_rotate(stack_a, 1);
		}
		else if (stack_a->data[0] == small)
			reverse_rotate(stack_a, 1);
		push(stack_a, stack_b);
	}
	sort_three_numbers(stack_a);
	push(stack_b, stack_a);
	if (stack_a->max_size == 5)
		push(stack_b, stack_a);
}

static void	sort_ten_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 5)
	{
		min = find_min(stack_a);
		while (stack_a->data[stack_a->top] != min)
		{
			if (stack_a->data[0] == min)
				reverse_rotate(stack_a, 1);
			else
				rotate(stack_a, 1);
		}
		push(stack_a, stack_b);
		i++;
	}
	sort_five_numbers(stack_a, stack_b);
	while (stack_b->top > 0)
	{
		while (stack_a->data[stack_a->top] < stack_b->data[stack_b->top])
			rotate(stack_a, 1);
		push(stack_b, stack_a);
	}
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->max_size == 2)
		swap(stack_a, 1);
	else if (stack_a->max_size == 3)
		sort_three_numbers(stack_a);
	else if (stack_a->max_size <= 5)
		sort_five_numbers(stack_a, stack_b);
	else
		sort_ten_numbers(stack_a, stack_b);
	while (stack_b->top >= 0)
		push(stack_b, stack_a);
}
