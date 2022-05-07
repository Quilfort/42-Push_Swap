/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_swap_push.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/07 10:18:37 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/07 16:32:24 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **stack_a, t_vars *vars)
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
	if (vars->check_print != 1)
		write(1, "sa\n", 3);
	vars->check_print = 0;
}

void	swap_b(t_node **stack_b, t_vars *vars)
{
	t_node	*top;
	t_node	*second;

	if ((*stack_b) == NULL || (*stack_b)->next == NULL)
		return ;
	top = *stack_b;
	*stack_b = (*stack_b)->next;
	second = (*stack_b)->next;
	(*stack_b)->next = top;
	(*stack_b)->next->next = second;
	if (vars->check_print != 1)
		write(1, "sb\n", 3);
	vars->check_print = 0;
}

void	swap_both(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	vars->check_print = 1;
	swap_a(stack_a, vars);
	vars->check_print = 1;
	swap_b(stack_b, vars);
	write(1, "ss\n", 3);
}

void	push_to_b(t_node **stack_a, t_node **stack_b, t_vars *vars)
{
	t_node	*new;

	new = *stack_a;
	if (new == NULL)
	{
		return ;
	}
	*stack_a = new->next;
	new->next = *stack_b;
	*stack_b = new;
	if (vars->check_print != 1)
		write(1, "pb\n", 3);
	vars->check_print = 0;
}

void	push_to_a(t_node **stack_b, t_node **stack_a, t_vars *vars)
{
	t_node	*new;

	new = *stack_b;
	if (new == NULL)
	{
		return ;
	}
	*stack_b = new->next;
	new->next = *stack_a;
	*stack_a = new;
	if (vars->check_print != 1)
		write(1, "pa\n", 3);
	vars->check_print = 0;
}

// void	swap(t_node *stack)
// {
// 	int	top;
// 	int	second;

// 	top = stack->content;
// 	second = stack->next->content;
// 	stack->content = second;
// 	stack->next->content = top;
// }

// void	push_to_b(struct s_node **stack_a, struct s_node **stack_b)
// {
// 	struct s_node	*temp;

// 	if (stack_a == NULL || *stack_a == NULL)
// 		return ;
// 	lstadd_front(stack_b, (*stack_a)->content);
// 	temp = *stack_a;
// 	*stack_a = (*stack_a)->next;
// 	free(temp);
// }

// void	push_to_a(struct s_node **stack_b, struct s_node **stack_a)
// {
// 	struct s_node	*temp;

// 	if (stack_b == NULL || *stack_b == NULL)
// 		return ;
// 	lstadd_front(stack_a, (*stack_b)->content);
// 	temp = *stack_b;
// 	*stack_b = (*stack_b)->next;
// 	free(temp);
// }