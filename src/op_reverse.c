/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_reverse.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 13:44:45 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/07 16:15:30 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_node **stack_a, t_vars *vars)
{
	t_node	*temp;
	t_node	*temp2;

	if ((*stack_a)->next == NULL)
	{
		return ;
	}
	temp = *stack_a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp2->next = *stack_a;
	*stack_a = temp2;
	temp->next = NULL;
	if (vars->check_print != 1)
		write(1, "rra\n", 4);
	vars->check_print = 0;
}

void	reverse_b(t_node **stack_b, t_vars *vars)
{
	t_node	*temp;
	t_node	*temp2;

	if ((*stack_b)->next == NULL)
	{
		return ;
	}
	temp = *stack_b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp2->next = *stack_b;
	*stack_b = temp2;
	temp->next = NULL;
	if (vars->check_print != 1)
		write(1, "rrb\n", 4);
	vars->check_print = 0;
}

void	reverse_both(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	vars->check_print = 1;
	reverse_a(stack_a, vars);
	vars->check_print = 1;
	reverse_b(stack_b, vars);
	write(1, "rrr\n", 4);
}
