/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:28:37 by diosanto          #+#    #+#             */
/*   Updated: 2023/04/20 21:10:05 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	best_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	int		cost;
	int		number_to_move;

	temp = (*stack_a);
	cost = INT_MAX;
	while (temp->next != NULL)
	{
		if (ft_move_cost(temp->number, stack_a, stack_b) < cost)
		{
			cost = ft_move_cost(temp->number, stack_a, stack_b);
			number_to_move = temp->number;
		}
		temp = temp->next;
	}
	if (ft_move_cost(temp->number, stack_a, stack_b) < cost)
	{
		cost = ft_move_cost(temp->number, stack_a, stack_b);
		number_to_move = temp->number;
	}
	put_nbr_to_top_b(stack_b, find_n_before(stack_b, number_to_move));
	move_to_b(number_to_move, stack_a, stack_b);
}

int	find_n_after(t_node **stack, int n)
{
	t_node	*temp;
	int		target;

	temp = (*stack);
	target = find_max_big(stack);
	while (temp->next != NULL)
	{
		if (temp->number > n && temp->number < target)
			target = temp->number;
		temp = temp->next;
	}
	if (temp->number > n && temp->number < target)
			target = temp->number;
	return (target);
}

void	push_back_to_a(t_node **stack_a, t_node **stack_b)
{
	int		nbr_to_top;
	int		min;

	while (ft_lstsize((*stack_b)) > 0)
	{
		if ((*stack_b)->number > find_max_big(stack_a))
		{
			nbr_to_top = find_min_big(stack_a);
			put_nbr_to_top_a(stack_a, nbr_to_top);
		}
		else
		{
			nbr_to_top = find_n_after(stack_a, (*stack_b)->number);
			put_nbr_to_top_a(stack_a, nbr_to_top);
		}
		ft_pa(stack_a, stack_b);
	}
	min = find_min_big(stack_a);
	put_nbr_to_top_a(stack_a, min);
}

void	sort_to_b(t_node **stack_a, t_node **stack_b, int max)
{
	int	min;

	min = find_min_big(stack_b);
	while (ft_lstsize((*stack_a)) > 3)
	{
		if ((*stack_a)->number > max)
		{
			max = (*stack_a)->number;
			ft_pb(stack_a, stack_b);
		}
		else if ((*stack_a)->number < min)
		{
			min = (*stack_a)->number;
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
		}
		else
			best_move(stack_a, stack_b);
	}
	sort_smallest(stack_a);
	push_back_to_a(stack_a, stack_b);
}

void	sort_big(t_node **stack_a, t_node **stack_b)
{
	int	max;

	ft_pb(stack_a, stack_b);
	ft_pb(stack_a, stack_b);
	max = find_max_big(stack_b);
	if ((*stack_b)->number != max)
		ft_sb(stack_b);
	sort_to_b(stack_a, stack_b, max);
	return ;
}
