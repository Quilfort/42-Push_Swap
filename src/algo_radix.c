/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_radix.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 14:16:07 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/30 14:53:08 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_stack(t_node **stack_a, t_node **stack_b, \
	t_vars *vars, int max_bits)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = list_size(*stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->bubble_index >> i) & 1) == 1)
				rotate_a(stack_a, vars);
			else
				push_to_b(stack_a, stack_b, vars);
			j++;
		}
		while (*stack_b != NULL)
			push_to_a(stack_b, stack_a, vars);
		i++;
	}
}

void	sort_stack(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	int	size;
	int	max_num;
	int	max_bits;

	max_bits = 0;
	size = list_size(*stack_a);
	max_num = size - 1;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	radix_stack(stack_a, stack_b, vars, max_bits);
}
