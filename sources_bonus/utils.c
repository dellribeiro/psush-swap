/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:15:27 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:15:11 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_push(t_bonus *stack, int x)
{
	stack->top++;
	stack->data[stack->top] = x;
}

int	ft_pop(t_bonus *stack)
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

int	is_sorted(t_bonus *stack)
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

void	free_stacks(t_bonus *stack_a, t_bonus *stack_b)
{
	free(stack_a->data);
	free(stack_b->data);
}

void	program_finished(t_bonus *stack_a, t_bonus *stack_b)
{
	if (is_sorted(stack_a) && stack_b->top == -1)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	free_stacks(stack_a, stack_b);
}
