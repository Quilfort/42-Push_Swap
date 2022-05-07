/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_max3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/07 12:58:14 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/07 16:20:31 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	arg_2(t_node **stack_a, t_vars *vars)
{
	int	first;
	int	second;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	if (first > second)
	{
		swap_a(stack_a, vars);
	}
	else
		return ;
}

void	arg_3(t_node **stack_a, t_vars *vars)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && second > third)
	{
		swap_a(stack_a, vars);
		reverse_a(stack_a, vars);
	}
	else if (first > second && third < first)
		rotate_a(stack_a, vars);
	else if (first > second && second < third)
		swap_a(stack_a, vars);
	else if (first < second && third < first)
		reverse_a(stack_a, vars);
	else if (first < second && third > first && second > third)
	{
		reverse_a(stack_a, vars);
		swap_a(stack_a, vars);
	}
	else
		return ;
}
