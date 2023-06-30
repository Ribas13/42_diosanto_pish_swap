/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:59:53 by diosanto          #+#    #+#             */
/*   Updated: 2023/03/30 14:24:49 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew_ps(int content)
{
	t_node	*link;

	/*if (!content)
		return (NULL);*/
	link = malloc(sizeof(t_node));
	if (!link)
		return (NULL);
	link->number = content;
	link->next = NULL;
	return (link);
}

t_node	*lstlast_node_ps(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_node	*ft_lstadd_back_ps(t_node **lst, t_node *new_last)
{
	t_node	*last_node;

	if (!new_last || !lst)
		return (NULL);
	if (!*lst)
	{
		*lst = new_last;
		return (new_last);
	}
	last_node = lstlast_node_ps(*lst);
	last_node->next = new_last;
	return (new_last);
}

void	ft_lstadd_front_ps(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_node *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}