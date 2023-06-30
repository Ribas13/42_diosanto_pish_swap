/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_aux2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:28:28 by diosanto          #+#    #+#             */
/*   Updated: 2023/04/20 15:28:31 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_move_cost(int n, t_node **stack_a, t_node **stack_b)
{
	int		i;
	int		j;

	i = a_cost(stack_a, n);
	if (n > find_max_big(stack_b))
		j = 0;
	else if (n < find_min_big(stack_b))
		j = 0;
	else
		j = (2 * b_cost(stack_b, n)) + 1;
	return (1 + i + j);
}

void	move_to_b(int n, t_node **stack_a, t_node **stack_b)
{
	put_nbr_to_top_a(stack_a, n);
	ft_pb(stack_a, stack_b);
}

int	a_cost(t_node **stack_a, int n)
{
	t_node	*temp;
	int		i;

	temp = (*stack_a);
	i = 0;
	while (temp->next != NULL)
	{
		if (temp->number == n)
			break ;
		i++;
		temp = temp->next;
	}
	if (i > (ft_lstsize((*stack_a)) / 2))
		return (ft_lstsize((*stack_a)) - i);
	return (i);
}

int	b_cost(t_node **stack_b, int n)
{
	t_node	*temp;
	int		j;
	int		max;
	int		min;

	temp = (*stack_b);
	j = 0;
	max = find_max_big(stack_b);
	min = find_min_big(stack_b);
	if (n > max)
		return (0);
	else if (n < min)
		return (1);
	while (temp->next != NULL)
	{
		if (temp->number == find_n_before(stack_b, n))
			break ;
		j++;
		temp = temp->next;
	}
	if (temp->number == find_n_before(stack_b, n))
		j++;
	if (j > (ft_lstsize((*stack_b)) / 2))
		return (ft_lstsize((*stack_b)) - j);
	return (j);
}
