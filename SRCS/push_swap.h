/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diosanto <diosanto@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:27:55 by diosanto          #+#    #+#             */
/*   Updated: 2023/04/20 16:03:35 by diosanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define FALSE 0
# define TRUE 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef struct node_t
{
	int				number;
	struct node_t	*next;
}				t_node;

//CHUNKS
int		ft_chunk_counter(t_node **stack_a, t_node **stack_b);
int		ft_arr_size(int *arr);

//ARRAYS
int		*sorted_array(t_node **stack_a, int *sorted_arr);
int		*sort_array(int sorted_arr[]);
int		check_sorted_array(int sorted_array[]);

//CHECKS
int		check_if_sorted(t_node **stack);
int		ft_isdigit(int c);
int		input_checker(int ac, char **av);
int		check_sorted(t_node **stack);
int		check_chars(char *str);
int		check_for_repeats(int ac, char **av);
int		arg_checker(char *str);

//PRINTS
void	print_stack(t_node *head, char a_or_b);

//SORTS
void	sort_smallest(t_node **stack_a);
void	sort_small(t_node **stack_a, t_node **stack_b);
void	sort_big(t_node **stack_a, t_node **stack_b);
void	sort_biggest(t_node **stack_a, t_node **stack_b);
void	sep_2(t_node **stack_a, int valor_2, int valor_3);
void	sep_1(t_node **stack_a, int valor_1, int valor_3);

//OPERATIONS
void	move_to_b(int n, t_node **stack_a, t_node **stack_b);
void	put_numebr_to_top(t_node **stack, int i);
void	put_nbr_to_top_a(t_node **stack, int number_to_move);
void	put_nbr_to_top_b(t_node **stack, int number_to_move);
void	ft_max_to_top_b(t_node **stack_b);
void	ft_sa(t_node **stack_a);
void	ft_sb(t_node **stack_b);
void	ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);
void	ft_ra(t_node **stack_a);
void	ft_rb(t_node **stack_b);
void	ft_rr(t_node **stack_a, t_node **stack_b);
void	ft_rra(t_node **stack_a);
void	ft_rrb(t_node **stack_b);
void	ft_rrr(t_node **stack_a, t_node **stack_b);

//FINDS
int		ft_move_cost(int n, t_node **stack_a, t_node **stack_b);
int		find_max_big(t_node **stack);
int		find_min_big(t_node **stack);
int		find_n_before(t_node **stack_b, int number);
int		a_cost(t_node **stack_a, int n);
int		b_cost(t_node **stack_b, int n);
int		signal_checker(int ac, char **av);
int		check_int_minmax(int ac, char **av);
int		digit_checker(int ac, char **av);
long long	ft_atoi(const char *nptr);

//LISTS
t_node	*ft_lstnew_ps(int content);
t_node	*lstlast_node_ps(t_node *lst);
t_node	*ft_lstadd_back_ps(t_node **lst, t_node *new_last);
void	ft_lstadd_front_ps(t_node **lst, t_node *new);
void	ft_lstclear(t_node **lst);
int		ft_lstsize(t_node *lst);
void	ft_clean_lst(t_node **stack);

#endif
