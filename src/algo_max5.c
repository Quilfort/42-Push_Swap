/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algo_max5.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/07 12:58:14 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/25 14:06:35 by qfrederi      ########   odam.nl         */
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

void	arg_4(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	int	pos;

	pos = smallest_num(stack_a);
	if (pos == 2)
		swap_a(stack_a, vars);
	else if (pos == 3)
	{
		reverse_a(stack_a, vars);
		reverse_a(stack_a, vars);
	}
	else if (pos == 4)
	{
		reverse_a(stack_a, vars);
	}
	if (is_sorted(stack_a) != 0)
	{
		push_to_b(stack_a, stack_b, vars);
		arg_3(stack_a, vars);
		push_to_a(stack_b, stack_a, vars);
	}
}

static void	arg_5_2(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	if (is_sorted(stack_a) != 0)
	{
		push_to_b(stack_a, stack_b, vars);
		arg_4(stack_a, stack_b, vars);
		push_to_a(stack_b, stack_a, vars);
	}
}

void	arg_5(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	int	pos;

	pos = smallest_num(stack_a);
	if (pos == 2)
		swap_a(stack_a, vars);
	else if (pos == 3)
	{
		rotate_a(stack_a, vars);
		rotate_a(stack_a, vars);
	}
	else if (pos == 4)
	{
		reverse_a(stack_a, vars);
		reverse_a(stack_a, vars);
	}
	else if (pos == 5)
	{
		reverse_a(stack_a, vars);
	}
	arg_5_2(stack_a, stack_b, vars);
}
