/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 12:40:22 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/25 14:37:34 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				ft_putstr_fd("Error: Duplicate\n", 1);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	only_numbers(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
			j++;
		while (argv[i][j] != '\0')
		{
			if ((argv[i][j] < '0') || (argv[i][j] > '9'))
			{
				ft_putstr_fd("Error: Not A Number\n", 1);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	list_print(t_node *stack, int argc)
{
	if (argc > 6)
	{
		while (stack)
		{
			printf("Note: %d Orginal Position: %d Index: %d \n", stack->content, \
			stack->pos_org, stack->bubble_index);
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			printf("%d ", stack->content);
			stack = stack->next;
		}
	}
}

int	list_size(t_node *lst)
{
	unsigned int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
