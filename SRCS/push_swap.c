/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:41:26 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/29 23:14:42 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_node *head, char a_or_b)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = head;
	printf("%c STACK:\n", a_or_b);
	while (temp->next != NULL)
	{
		printf("%i: ", i);
		/*if (temp->number > temp->next->number)
			printf("\nHERE ----> ");*/
		printf("%i\n", temp->number);
		temp = temp->next;
		i++;
	}
	printf("%i: ", i);
	printf("%i\n\n\n", temp->number);
	return ;
}

t_node	*insert_stack_a(char **av)
{
	t_node	**stack_a;
	t_node	*temp;
	t_node	*head;
	int		i;
	int		number;

	i = 0;
	while (av[++i])
	{
		number = ft_atoi(av[i]);
		if (i == 1)
			head = ft_lstnew_ps(number);
		else
		{
			temp = ft_lstnew_ps(number);
			ft_lstadd_back_ps(stack_a, temp);
		}
		stack_a = &head;
	}
	return (head);
}

int	main(int ac, char **av)
{
	t_node	**stack_a;
	t_node	**stack_b;
	t_node	*head_a;
	t_node	*head_b;

	if (ac == 1)
		return (0);
	if (input_checker(ac, av) == FALSE)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	head_a = insert_stack_a(av);
	stack_a = &head_a;
	stack_b = &head_b;
	head_b = NULL;
	if (check_if_sorted(stack_a) == TRUE)
	{
		ft_clean_lst(stack_a);
		return (0);
	}
	if (ac <= 4)
		sort_smallest(stack_a);
	else if (ac > 4 && ac <= 6)
		sort_small(stack_a, stack_b);
	else if (ac > 6 && ac <= 501)
		sort_big(stack_a, stack_b);
	//print_stack((*stack_a), 'A');
	ft_clean_lst(stack_a);
	ft_clean_lst(stack_b);
	return (0);
}
