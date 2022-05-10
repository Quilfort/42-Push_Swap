/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_sorted.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/10 13:03:06 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/10 14:45:09 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nodes(t_node *first, t_node *second)
{
	if (second == NULL || first == NULL)
		return (-1);
	if (first->content > second->content)
		return (1);
	if (first->content < second->content)
		return (0);
	return (-1);
}

int	is_sorted(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (check_nodes(temp, temp->next) == 1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	smallest_num(t_node **stack_a)
{
	int		pos;
	int		small;
	t_node	*temp_small;
	t_node	*temp_pos;

	temp_small = *stack_a;
	temp_pos = *stack_a;
	small = INT_MAX;
	while (temp_small != NULL)
	{
		if (small > temp_small->content)
		{
			small = temp_small->content;
		}
		temp_small = temp_small->next;
	}
	pos = 1;
	while (temp_pos->content != small)
	{
		pos++;
		temp_pos = temp_pos->next;
	}
	return (pos);
}
