/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:23:35 by diosanto          #+#    #+#             */
/*   Updated: 2023/04/06 15:44:19 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_min(t_node **stack)
{
	t_node	*temp;
	t_node	*smallest;
	int		i;

	temp = (*stack);
	smallest = (*stack);
	i = 0;
	while (temp)
	{
		if (smallest->number > temp->number)
			smallest = temp;
		temp = temp->next;
	}
	temp = (*stack);
	while (temp != smallest)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	put_number_to_top(t_node **stack, int i)
{
	t_node	**temp;

	temp = stack;
	if (i <= ft_lstsize(*temp) / 2)
	{
		while (i--)
		{
			ft_ra(temp);
		}
	}
	else
	{
		while (i++ < ft_lstsize((*temp)))
		{
			ft_rra(temp);
		}
	}
	return ;
}

void	sort_small(t_node **stack_a, t_node **stack_b)
{
	int		i;

	while (ft_lstsize(*stack_a) > 3)
	{
		i = find_min(stack_a);
		put_number_to_top(stack_a, i);
		ft_pb(stack_a, stack_b);
	}
	sort_smallest(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	return ;
}
