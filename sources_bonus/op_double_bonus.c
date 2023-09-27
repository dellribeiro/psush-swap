/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_double_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:06:59 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:14:22 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	bonus_swap_double(t_bonus *stack_a, t_bonus *stack_b)
{
	bonus_swap(stack_a);
	bonus_swap(stack_b);
}

void	bonus_rotate_double(t_bonus *stack_a, t_bonus *stack_b)
{
	bonus_rotate(stack_a);
	bonus_rotate(stack_b);
}

void	bonus_reverse_rotate_double(t_bonus *stack_a, t_bonus *stack_b)
{
	bonus_reverse_rotate(stack_a);
	bonus_reverse_rotate(stack_b);
}
