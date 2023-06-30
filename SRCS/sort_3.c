/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:02:08 by diosanto          #+#    #+#             */
/*   Updated: 2023/04/20 21:09:15 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	sort_2(t_node **stack_a)
{
	int	valor_1;
	int	valor_2;

	valor_1 = (*stack_a)->number;
	valor_2 = (*stack_a)->next->number;
	if (valor_1 > valor_2)
		ft_sa(stack_a);
	return ;
}

void	sep_1(t_node **stack_a, int valor_1, int valor_3)
{
	if (valor_1 > valor_3)
		ft_rra(stack_a);
	else
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

void	sep_2(t_node **stack_a, int valor_2, int valor_3)
{
	if (valor_2 < valor_3)
		ft_ra(stack_a);
	else
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
}

void	sort_smallest(t_node **stack_a)
{
	int	valor_1;
	int	valor_2;
	int	valor_3;

	if (ft_lstsize((*stack_a)) < 3)
	{
		sort_2(stack_a);
		return ;
	}
	valor_1 = (*stack_a)->number;
	valor_2 = (*stack_a)->next->number;
	valor_3 = (*stack_a)->next->next->number;
	if (check_if_sorted(stack_a) == TRUE)
		return ;
	if (valor_1 < valor_2)
	{
		sep_1(stack_a, valor_1, valor_3);
	}
	else if (valor_1 > valor_2 && valor_1 > valor_3)
	{
		sep_2(stack_a, valor_2, valor_3);
	}
	else
		ft_sa(stack_a);
}
