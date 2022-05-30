/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_index.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 16:08:13 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/25 15:56:03 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_bubble(t_node **stack_a)
{
	t_node	*top;
	t_node	*second;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	top = *stack_a;
	*stack_a = (*stack_a)->next;
	second = (*stack_a)->next;
	(*stack_a)->next = top;
	(*stack_a)->next->next = second;
}

static void	bubble_sort(t_node **stack_a, t_vars *vars)
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
				swap_bubble(temp);
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

void	original_position(t_node *stack_a, int argc)
{
	int	pos;
	int	total_arg;

	pos = 0;
	total_arg = argc - 1;
	while (total_arg)
	{
		(stack_a)->pos_org = pos;
		(stack_a) = (stack_a)->next;
		pos++;
		total_arg--;
	}
}

void	bubble_org_pos(t_node **stack_a, t_vars *vars)
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
			if ((*temp)->pos_org > (*temp)->next->pos_org)
			{
				swap_bubble(temp);
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

void	bubble_index(t_node **stack_a, t_vars *vars, int argc)
{
	int		index;
	int		total_arg;
	t_node	**temp;

	index = 0;
	total_arg = argc - 1;
	bubble_sort(stack_a, vars);
	temp = stack_a;
	while (total_arg)
	{
		(*temp)->bubble_index = index;
		temp = &(*temp)->next;
		index++;
		total_arg--;
	}
}
