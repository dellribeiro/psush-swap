/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:07:35 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:14:51 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define INT_ERROR "Some arguments aren’t integers\n"
# define RANGE_ERROR "Some arguments are bigger than an integer\n"
# define DUP_ERROR "There are duplicate arguments\n"
# define ERROR "\033[31mError\033[m\n"

typedef struct stack{
	int		max_size;
	int		top;
	char	id;
	int		*data;
}t_bonus;

int		arg_checker_bonus(char **argv);
void	exec_instruc(t_bonus *stack_a, t_bonus *stack_b, char *line);
void	add_numbers_in_stack_bonus(t_bonus *stack, char **argv);
void	init_stack_bonus(t_bonus	*stack, int max_size, char id);
void	bonus_swap_double(t_bonus *stack_a, t_bonus *stack_b);
void	bonus_rotate_double(t_bonus *stack_a, t_bonus *stack_b);
void	bonus_reverse_rotate_double(t_bonus *stack_a, t_bonus *stack_b);
void	bonus_swap(t_bonus *stack);
void	bonus_push(t_bonus *stack_src, t_bonus *stack_dest);
void	bonus_rotate(t_bonus *stack);
void	bonus_reverse_rotate(t_bonus *stack);
void	ft_push(t_bonus *stack, int x);
int		ft_pop(t_bonus *stack);
int		is_sorted(t_bonus *stack);
void	free_stacks(t_bonus *stack_a, t_bonus *stack_b);
void	program_finished(t_bonus *stack_a, t_bonus *stack_b);

#endif