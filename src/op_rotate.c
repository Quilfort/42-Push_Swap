/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_rotate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/07 10:49:12 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/07 16:16:19 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_node **stack_a, t_vars *vars)
{
	t_node	*temp;
	t_node	*temp2;

	if ((*stack_a)->next == NULL)
	{
		return ;
	}
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp2 = *stack_a;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
	temp->next = NULL;
	if (vars->check_print != 1)
		write(1, "ra\n", 3);
	vars->check_print = 0;
}

void	rotate_b(t_node **stack_b, t_vars *vars)
{
	t_node	*temp;
	t_node	*temp2;

	if ((*stack_b)->next == NULL)
	{
		return ;
	}
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp2 = *stack_b;
	while (temp2->next != NULL)
	{
		temp2 = temp2->next;
	}
	temp2->next = temp;
	temp->next = NULL;
	if (vars->check_print != 1)
		write(1, "rb\n", 3);
	vars->check_print = 0;
}

void	rotate_both(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	vars->check_print = 1;
	rotate_a(stack_a, vars);
	vars->check_print = 1;
	rotate_b(stack_b, vars);
	write(1, "rr\n", 3);
}

// void	rotate(t_node **stack)
// {
// 	struct s_node	*temp;
// 	int				number;

// 	if (stack == NULL || *stack == NULL)
// 		return ;
// 	number = (*stack)->content;
// 	temp = *stack;
// 	*stack = (*stack)->next;
// 	free(temp);
// 	lstadd_back(stack, number);
// }
