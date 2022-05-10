/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:28:03 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/10 17:02:21 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <limits.h>

typedef struct s_vars {
	int		check_print;
	int		arguments;
}				t_vars;

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}	t_node;

t_node	*create_list(int argc, char *argv[]);
t_node	*lstnew(int number);
void	lstadd_back(t_node **lst, int number);

// operations
void	swap_a(t_node **stack_a, t_vars *vars);
void	swap_b(t_node **stack_b, t_vars *vars);
void	swap_both(t_node **stack_a, t_node **stack_b, t_vars *vars);
void	push_to_b(t_node **stack_a, t_node **stack_b, t_vars *vars);
void	push_to_a(t_node **stack_b, t_node **stack_a, t_vars *vars);

void	rotate_a(t_node **stack_a, t_vars *vars);
void	rotate_b(t_node **stack_b, t_vars *vars);
void	rotate_both(t_node **stack_a, t_node **stack_b, t_vars *vars);

void	reverse_a(t_node **stack_a, t_vars *vars);
void	reverse_b(t_node **stack_b, t_vars *vars);
void	reverse_both(t_node **stack_a, t_node **stack_b, t_vars *vars);

//
void	list_print(t_node *stack_a);
int		list_size(t_node *list);

//
void	bubble_sort(t_node **stack_a, t_vars *vars);

//
int		is_sorted(t_node **stack_a);
int		check_nodes(t_node *first, t_node *second);
int		smallest_num(t_node **stack_a);

// algo test
void	arg_2(t_node **stack_a, t_vars *vars);
void	arg_3(t_node **stack_a, t_vars *vars);
void	arg_4(t_node **stack_a, t_node **stack_b, t_vars *vars);
void	arg_5(t_node **stack_a, t_node **stack_b, t_vars *vars);
void	arg_5_2(t_node **stack_a, t_node **stack_b, t_vars *vars);

int		smallest_num(t_node **stack_a);
#endif