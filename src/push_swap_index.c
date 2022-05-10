/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 16:08:13 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/10 17:08:00 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_node **stack_a, t_vars *vars)
{
	t_node	**temp;
	int		i;
	int		arg_count;
	int		swap;

	arg_count = 0;
	while (arg_count <= vars->arguments)
	{
		temp = stack_a;
		swap = 0;
		i = 0;
		while (i < vars->arguments - arg_count - 1)
		{
			if (check_nodes(*temp, (*temp)->next) == 1)
			{
				vars->check_print = 1;
				swap_a(temp, vars);
				swap = 1;
			}
			temp = &(*temp)->next;
			i++;
		}
		arg_count++;
		if (swap == 0)
			break ;
	}
}
