/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 10:28:03 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/30 13:22:22 by qfrederi      ########   odam.nl         */
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
	int				pos_org;
	int				bubble_index;
	struct s_node	*next;
}	t_node;

// create list
t_node	*create_list(int argc, char *argv[]);
t_node	*lstnew(int number);

//
void	list_print(t_node *stack, int argc);
int		list_size(t_node *list);
void	duplicate(char *argv[], int argc);
void	only_numbers(char *argv[], int argc);
void	min_max(char *argv[]);

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

//index
void	original_position(t_node *stack_a, int argc);
void	bubble_index(t_node **stack_a, t_vars *vars, int argc);
void	bubble_org_pos(t_node **stack_a, t_vars *vars);

//
int		is_sorted(t_node **stack_a);
int		check_nodes(t_node *first, t_node *second);
int		smallest_num(t_node **stack_a);

// algo test
void	arg_2(t_node **stack_a, t_vars *vars);
void	arg_3(t_node **stack_a, t_vars *vars);
void	arg_4(t_node **stack_a, t_node **stack_b, t_vars *vars);
void	arg_5(t_node **stack_a, t_node **stack_b, t_vars *vars);

void	sort_stack(t_node **stack_a, t_node **stack_b, t_vars *vars);
void	radix_stack(t_node **stack_a, t_node **stack_b, \
		t_vars *vars, int max_bits);

int		smallest_num(t_node **stack_a);

#endif