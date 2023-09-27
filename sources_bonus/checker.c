/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:43:01 by whendrix          #+#    #+#             */
/*   Updated: 2023/03/01 05:12:55 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	t_bonus	stack_a;
	t_bonus	stack_b;
	char	*line;

	if (argc <= 2)
		exit(0);
	line = NULL;
	arg_checker_bonus(argv);
	init_stack_bonus(&stack_a, argc - 1, 'a');
	init_stack_bonus(&stack_b, argc - 1, 'b');
	add_numbers_in_stack_bonus(&stack_a, argv);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		exec_instruc(&stack_a, &stack_b, line);
		free(line);
	}
	free(line);
	program_finished(&stack_a, &stack_b);
	return (0);
}
