/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instruc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 22:07:57 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:13:39 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	exec_instruc(t_bonus *stack_a, t_bonus *stack_b, char *line)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		bonus_swap(stack_a);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		bonus_swap(stack_a);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		bonus_push(stack_b, stack_a);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		bonus_push(stack_a, stack_b);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		bonus_rotate(stack_a);
	else if (ft_strncmp(line, "rb\n", 3) == 0)
		bonus_rotate(stack_b);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		bonus_reverse_rotate(stack_a);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		bonus_reverse_rotate(stack_b);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		bonus_swap_double(stack_a, stack_b);
	else if (ft_strncmp(line, "rr\n", 3) == 0)
		bonus_rotate_double(stack_a, stack_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		bonus_reverse_rotate_double(stack_a, stack_b);
	else
		exit(write(STDERR_FILENO, ERROR, ft_strlen(ERROR)));
}
