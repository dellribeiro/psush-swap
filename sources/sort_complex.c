/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:10:23 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 04:48:32 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_movements(t_stack *stack_a, t_stack *stack_b,
						int idx_a, int idx_b)
{
	int	next_top;
	int	condition;

	next_top = stack_b->top - 1;
	while (stack_b->top != next_top)
	{
		condition = get_condition(stack_a, stack_b, idx_a, idx_b);
		if (condition == BOTH_UP)
			moves_one(stack_a, stack_b, idx_a, idx_b);
		else if (condition == BOTH_DOWN)
			moves_two(stack_a, stack_b, idx_a, idx_b);
		else if (condition == TOP_UP_NUM_DOWN)
			moves_three(stack_a, stack_b, idx_a, idx_b);
		else if (condition == TOP_DOWN_NUM_UP)
			moves_four(stack_a, stack_b, idx_a, idx_b);
	}
}

static int	get_best_index_b(t_stack *stack_a, t_stack *stack_b, int *num_moves)
{
	int	current_index_b;
	int	best_index_b;
	int	moves;

	*num_moves = stack_a->max_size * 2;
	current_index_b = stack_b->top + 1;
	best_index_b = stack_b->top;
	while (--current_index_b >= 0)
	{
		if (current_index_b >= stack_b->top / 2)
			moves = get_moves(stack_a, stack_b->data[current_index_b])
				+ (stack_b->top - current_index_b);
		else
			moves = get_moves(stack_a, stack_b->data[current_index_b])
				+ (current_index_b + 1);
		if (moves < *num_moves)
		{
			best_index_b = current_index_b;
			*num_moves = moves;
		}
	}
	return (best_index_b);
}

static void	insert_back_on_a(t_stack *stack_a, t_stack *stack_b)
{
	int	num_moves;
	int	best_index_b;
	int	current_index_b;

	best_index_b = get_best_index_b(stack_a, stack_b, &num_moves);
	current_index_b = get_position(stack_a, num_moves,
			stack_b->data[best_index_b]);
	do_movements(stack_a, stack_b, current_index_b, best_index_b);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	sort_stack_a(stack_a, stack_b);
	while (stack_b->top >= 0)
		insert_back_on_a(stack_a, stack_b);
	while (!is_sorted(stack_a))
		moves_five(stack_a);
}
