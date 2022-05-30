/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:26:51 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/30 15:04:40 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	more_than_5(t_node **stack_a, t_node **stack_b, \
	t_vars *vars, int argc)
{
	original_position(*stack_a, argc);
	bubble_index(stack_a, vars, argc);
	bubble_org_pos(stack_a, vars);
	sort_stack(stack_a, stack_b, vars);
}

static	void	max_5_arguments(t_node **stack_a, t_node **stack_b, \
	t_vars *vars, int argc)
{
	if (argc == 3)
		arg_2(stack_a, vars);
	else if (argc == 4)
		arg_3(stack_a, vars);
	else if (argc == 5)
		arg_4(stack_a, stack_b, vars);
	else if (argc == 6)
		arg_5(stack_a, stack_b, vars);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_vars	vars;

	if (argc < 3)
		return (0);
	duplicate(argv, argc);
	only_numbers(argv, argc);
	min_max(argv);
	vars.arguments = argc - 1;
	vars.check_print = 0;
	stack_a = create_list(argc, argv);
	if (is_sorted(&stack_a) != 0)
	{
		if (argc >= 3 && argc <= 6)
			max_5_arguments(&stack_a, &stack_b, &vars, argc);
		else
			more_than_5(&stack_a, &stack_b, &vars, argc);
	}
	return (0);
}
