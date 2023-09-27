/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 06:25:28 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/14 19:15:32 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define INT_ERROR "Some arguments aren’t integers\n"
# define RANGE_ERROR "Some arguments are greater or less than an integer size\n"
# define DUP_ERROR "There are duplicate arguments\n"
# define ERROR "\033[31mError\033[m\n"

# define BOTH_UP 1
# define BOTH_DOWN 2
# define TOP_UP_NUM_DOWN 3
# define TOP_DOWN_NUM_UP 4

typedef struct stack{
	int		max_size;
	int		top;
	char	id;
	int		*data;
}t_stack;

int		arg_checker(char **argv);
void	init_stack(t_stack	*stack, int max_size, char id);
void	add_numbers_in_stack(t_stack *stack, char **argv);
void	ft_push(t_stack *stack, int x);
int		ft_pop(t_stack *stack);
int		is_sorted(t_stack *stack);
void	swap(t_stack *stack, int id);
void	push(t_stack *stack_src, t_stack *stack_dest);
void	rotate(t_stack *stack, int id);
void	reverse_rotate(t_stack *stack, int id);
void	swap_double(t_stack *stack_a, t_stack *stack_b);
void	rotate_double(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_double(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);
void	simple_sort(t_stack *stack_a, t_stack *stack_b);
void	complex_sort(t_stack *stack_a, t_stack *stack_b);
int		get_position(t_stack *stack_a, int moves, int value);
int		get_moves(t_stack *stack, int value);
void	moves_one(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_two(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_three(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_four(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	moves_five(t_stack *stack_a);
int		operation_count(t_stack *stack_a, t_stack *stack_b);
void	sort_stack_a(t_stack *stack_a, t_stack *stack_b);
int		get_condition(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

#endif