/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:18:59 by whendrix          #+#    #+#             */
/*   Updated: 2023/02/07 23:59:33 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
	{
		free_stacks(stack_a, stack_b);
		exit(0);
	}
	else if (stack_a->max_size <= 10)
		simple_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
}
