/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:26:51 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/07 16:33:45 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	**stack_a;
	t_node	**stack_b;
	t_vars	vars;

	stack_a = malloc(sizeof(t_node));
	stack_b = malloc(sizeof(t_node));
	*stack_a = create_list(argc, argv);
	*stack_b = NULL;
	vars.check_print = 0;
	if (argc == 3)
		arg_2(stack_a, &vars);
	else if (argc == 4)
		arg_3(stack_a, &vars);
	else
	{
		push_to_b(stack_a, stack_b, &vars);
		push_to_b(stack_a, stack_b, &vars);
		swap_a(stack_a, &vars);
		swap_b(stack_a, &vars);
		swap_both(stack_a, stack_b, &vars);
	}
	write(1, "\n", 1);
	list_print(*stack_a);
	write(1, "\n", 1);
	list_print(*stack_b);
	return (0);
}
