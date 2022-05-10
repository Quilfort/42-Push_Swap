/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/07 12:24:39 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/10 10:09:15 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_swap(t_node *swap1, t_node *swap2)
{
	t_node	*temp;
	t_node	*temp2;

	temp = swap1;
	swap1 = swap2;
	temp2 = swap2;
	swap2 = temp;
}

void	bubble_sort(t_node **stack_a)
{
	t_node	*temp;
	t_node	*temp2;

	if ((*stack_a) == NULL || (*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	temp2 = *stack_a;
	while (temp2->next != NULL)
	{
		if (temp > temp->next)
		{
			bubble_swap(temp, temp->next);
		}
		temp2 = temp;
		temp = temp->next;
	}
}
