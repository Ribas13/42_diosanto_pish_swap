/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort100_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribs <ribs@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:39:11 by diosanto          #+#    #+#             */
/*   Updated: 2023/06/29 23:07:53 by ribs             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_big(t_node **stack)
{
	t_node	*temp;
	int		max;

	temp = (*stack);
	max = temp->number;
	while (temp->next != NULL)
	{
		if (temp->number > max)
			max = temp->number;
		temp = temp->next;
	}
	if (temp->number > max)
			max = temp->number;
	return (max);
}

int	find_min_big(t_node **stack)
{
	t_node	*temp;
	int		min;

	temp = (*stack);
	min = temp->number;
	while (temp->next != NULL)
	{
		if (temp->number < min)
			min = temp->number;
		temp = temp->next;
	}
	if (temp->number < min)
			min = temp->number;
	return (min);
}

void	put_nbr_to_top_a(t_node **stack, int number_to_move)
{
	t_node	*temp;
	int		i;

	temp = (*stack);
	i = 0;
	while (temp->number != number_to_move)
	{
		temp = temp->next;
		i++;
	}
	if (i >= ft_lstsize((*stack)) / 2)
	{
		while (i++ < ft_lstsize((*stack)))
			ft_rra(stack);
	}
	else
	{
		while (i-- > 0)
			ft_ra(stack);
	}
}

void	put_nbr_to_top_b(t_node **stack, int number_to_move)
{
	t_node	*temp;
	int		i;

	temp = (*stack);
	i = 0;
	while (temp->number != number_to_move)
	{
		temp = temp->next;
		i++;
	}
	if (i >= ft_lstsize((*stack)) / 2)
	{
		while (i++ < ft_lstsize((*stack)))
			ft_rrb(stack);
	}
	else
	{
		while (i-- > 0)
			ft_rb(stack);
	}
}

int	find_n_before(t_node **stack_b, int number)
{
	t_node	*temp;
	int		target;

	temp = (*stack_b);
	target = find_min_big(stack_b);
	while (temp->next != NULL)
	{
		if (temp->number > target && temp->number < number)
			target = temp->number;
		temp = temp->next;
	}
	if (temp->number > target && temp->number < number)
			target = temp->number;
	return (target);
}
