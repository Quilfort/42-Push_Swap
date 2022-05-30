/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/14 12:40:22 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/30 14:55:41 by qfrederi      ########   odam.nl         */
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
				ft_putstr_fd("Error\n", 2);
				exit(1);
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
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	min_max(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_atoi_long(argv[i]) > (long)INT_MAX || \
		ft_atoi_long(argv[i]) < (long)INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
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
