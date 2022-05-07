/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: qfrederi <qfrederi@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/13 12:08:58 by qfrederi      #+#    #+#                 */
/*   Updated: 2022/05/05 09:39:36 by qfrederi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_head(char *argv[])
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (head == NULL)
		return (head);
	head->content = ft_atoi(argv[1]);
	head->next = NULL;
	return (head);
}

t_node	*lstlast(t_node *lst)
{
	while (lst)
	{
		if (!(lst->next))
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_node	*lstnew(int number)
{
	t_node	*newcontent;

	newcontent = (t_node *)malloc(sizeof(t_node));
	if (!newcontent)
		return (NULL);
	newcontent->content = number;
	newcontent->next = NULL;
	return (newcontent);
}

void	lstadd_back(t_node **lst, int number)
{
	t_node	*temp;
	t_node	*new;

	new = lstnew(number);
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	else
	{
		temp = lstlast(*lst);
		temp->next = new;
	}
}

t_node	*create_list(int argc, char *argv[])
{
	t_node	*list;
	int		arguments;
	int		argv_index;

	arguments = argc - 2;
	argv_index = 2;
	list = create_head(argv);
	while (arguments)
	{
		lstadd_back(&list, ft_atoi(argv[argv_index]));
		argv_index++;
		arguments--;
	}
	return (list);
}
