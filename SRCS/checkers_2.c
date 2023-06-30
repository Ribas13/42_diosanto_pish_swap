/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:30:10 by diosanto          #+#    #+#             */
/*   Updated: 2023/04/20 15:49:20 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sorted(t_node **stack)
{
	t_node	*temp;

	temp = (*stack);
	while (temp->next != NULL)
	{
		if (temp->number > temp->next->number)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}

int	check_for_repeats(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*This function tests for invalid inputs*/
int	input_checker(int ac, char **av)
{
	/*if (ac == 1)
		return (FALSE);*/
	if (digit_checker(ac, av) == FALSE)
		return (FALSE);
	if (check_for_repeats(ac, av) == FALSE)
		return (FALSE);
	else if (check_int_minmax(ac, av) == FALSE)
		return (FALSE);
	else if (signal_checker(ac, av) == FALSE)
		return (FALSE);
	return (TRUE);
}
