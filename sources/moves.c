/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:10:34 by whendrix          #+#    #+#             */
/*   Updated: 2023/02/23 21:33:46 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	moves_one(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->data[idx_a];
	value_top_b = stack_b->data[idx_b];
	while (stack_a->data[stack_a->top] != value_top_a
		&& stack_b->data[stack_b->top] != value_top_b)
		rotate_double(stack_a, stack_b);
	while (stack_a->data[stack_a->top] != value_top_a)
		rotate(stack_a, 1);
	while (stack_b->data[stack_b->top] != value_top_b)
		rotate(stack_b, 1);
	push(stack_b, stack_a);
}

void	moves_two(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->data[idx_a];
	value_top_b = stack_b->data[idx_b];
	while (stack_a->data[stack_a->top] != value_top_a
		&& stack_b->data[stack_b->top] != value_top_b)
		reverse_rotate_double(stack_a, stack_b);
	while (stack_a->data[stack_a->top] != value_top_a)
		reverse_rotate(stack_a, 1);
	while (stack_b->data[stack_b->top] != value_top_b)
		reverse_rotate(stack_b, 1);
	push(stack_b, stack_a);
}

void	moves_three(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->data[idx_a];
	value_top_b = stack_b->data[idx_b];
	while (stack_a->data[stack_a->top] != value_top_a)
		rotate(stack_a, 1);
	while (stack_b->data[stack_b->top] != value_top_b)
		reverse_rotate(stack_b, 1);
	push(stack_b, stack_a);
}

void	moves_four(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	value_top_a;
	int	value_top_b;

	value_top_a = stack_a->data[idx_a];
	value_top_b = stack_b->data[idx_b];
	while (stack_a->data[stack_a->top] != value_top_a)
		reverse_rotate(stack_a, 1);
	while (stack_b->data[stack_b->top] != value_top_b)
		rotate(stack_b, 1);
	push(stack_b, stack_a);
}

void	moves_five(t_stack *stack_a)
{
	int	higher;
	int	i;

	higher = find_max(stack_a);
	i = 0;
	while (i <= stack_a->top)
	{
		if (stack_a->data[i] == higher)
			break ;
		i++;
	}
	if (i >= stack_a->top / 2)
		rotate(stack_a, 1);
	else
		reverse_rotate(stack_a, 1);
}
