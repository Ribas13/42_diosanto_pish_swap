/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:07:31 by diosanto          #+#    #+#             */
/*   Updated: 2023/03/27 14:29:52 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast(t_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*>>Shift down all elements of stack a by 1 - last becomes first<<

1. We make the list "temp" the same as stack_a
2. Move to the last node inside the list temp
3. We set the next node after the previous last as the previous first node
4. We make the list "new_last" the same as stack_a
5. while its different than the previous last node, keep iterating
6. once we exit the loop, we set the next pointer as NULL to finish the list
7. Lastly, we make stack_a the same as temp
*/
void	ft_rra(t_node **stack_a)
{
	t_node	*temp;
	t_node	*new_last;

	temp = *stack_a;
	temp = ft_lstlast(temp);
	temp->next = *stack_a;
	new_last = *stack_a;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_a = temp;
	write(1, "rra\n", 4);
}

//Shift down all elements of stack b by 1 - last becomes first
void	ft_rrb(t_node **stack_b)
{
	t_node	*temp;
	t_node	*new_last;

	temp = *stack_b;
	temp = ft_lstlast(temp);
	temp->next = *stack_b;
	new_last = *stack_b;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_b = temp;
	write(1, "rrb\n", 4);
}

//rra and rrb at the same time
void	ft_rrr(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;
	t_node	*new_last;

	temp = *stack_a;
	temp = ft_lstlast(temp);
	temp->next = *stack_a;
	new_last = *stack_a;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_a = temp;
	temp = *stack_b;
	temp = ft_lstlast(temp);
	temp->next = *stack_b;
	new_last = *stack_b;
	while (new_last->next != temp)
		new_last = new_last->next;
	new_last->next = NULL;
	*stack_b = temp;
	write(1, "rrr\n", 4);
}
