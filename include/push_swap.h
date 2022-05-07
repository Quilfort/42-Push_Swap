/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:28:03 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/07 16:04:04 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <libft.h>

typedef struct s_vars {
	int		check_print;
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


// algo test
void	arg_2(t_node **stack_a, t_vars *vars);
void	arg_3(t_node **stack_a, t_vars *vars);




#endif