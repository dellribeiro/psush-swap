/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:49:10 by whendrix          #+#    #+#             */
/*   Updated: 2023/02/23 21:33:24 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack, int id)
{
	int	aux;

	aux = stack->data[stack->top];
	stack->data[stack->top] = stack->data[stack->top - 1];
	stack->data[stack->top - 1] = aux;
	if (id == 1)
		ft_printf("s%c\n", stack->id);
}

void	push(t_stack *stack_src, t_stack *stack_dest)
{
	int	top_src;

	top_src = ft_pop(stack_src);
	ft_push(stack_dest, top_src);
	ft_printf("p%c\n", stack_dest->id);
}

void	rotate(t_stack *stack, int id)
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
	if (id == 1)
		ft_printf("r%c\n", stack->id);
}

void	reverse_rotate(t_stack *stack, int id)
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
	if (id == 1)
		ft_printf("rr%c\n", stack->id);
}
