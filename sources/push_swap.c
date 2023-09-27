/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:27:19 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/14 20:15:00 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc <= 2)
		exit(0);
	arg_checker(argv);
	init_stack(&stack_a, argc - 1, 'a');
	init_stack(&stack_b, argc - 1, 'b');
	add_numbers_in_stack(&stack_a, argv);
	sort(&stack_a, &stack_b);
	free_stacks(&stack_a, &stack_b);
	return (0);
}
