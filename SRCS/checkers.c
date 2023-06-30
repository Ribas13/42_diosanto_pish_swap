/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:47:12 by diosanto          #+#    #+#             */
/*   Updated: 2023/04/20 16:04:47 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
		return (0);
}

//check for signals
int	signal_checker(int ac, char **av)
{
	int	i;
	int	j;
	int	c;

	i = 1;
	j = 1;
	while (i < ac)
	{
		c = 0;
		if (av[j][c] == '-')
		{
			c += 1;
			if (!(av[j][c] >= '0' && av[j][c] <= '9'))
				return (FALSE);
		}
		j++;
		i++;
	}
	return (TRUE);
}

//check for digits
int	digit_checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-')
		{
			if (av[i][1] == '\0' || !ft_isdigit(av[i][1]))
				return (FALSE);
			j = 2;
		}
		else
			j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			sig;
	long long	res;

	i = 0;
	sig = 1;
	res = 0;
	while ((nptr[i] == 32) || (nptr[i] == '\n') || (nptr[i] == '\t') || \
			(nptr[i] == '\v') || (nptr[i] == '\f') || (nptr[i] == '\r'))
			i++;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			sig = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (res * sig);
}

//check for int max and min
int	check_int_minmax(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) > 2147483647)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
