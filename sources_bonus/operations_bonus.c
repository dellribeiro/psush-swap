/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:06:03 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:14:31 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	bonus_swap(t_bonus *stack)
{
	int	aux;

	aux = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = aux;
}

void	bonus_push(t_bonus *stack_src, t_bonus *stack_dest)
{
	int	top_src;

	top_src = ft_pop(stack_src);
	ft_push(stack_dest, top_src);
}

void	bonus_rotate(t_bonus *stack)
{
	int	aux;
	int	i;

	i = stack->top;
	aux = stack->data[stack->top];
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = aux;
}

void	bonus_reverse_rotate(t_bonus *stack)
{
	int	aux;
	int	i;

	aux = stack->data[0];
	i = 0;
	while (i < stack->top)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->top] = aux;
}
