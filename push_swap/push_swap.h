/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:43:10 by kmohamed          #+#    #+#             */
/*   Updated: 2022/11/07 17:07:40 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#ifndef show_logs
 # define show_logs 0
#endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef	struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef	struct s_node_inputs
{
	long					value;
	struct s_node_inputs	*next;
}t_node_inputs;

typedef struct s_return
{
	int value;
	int index;
}t_return;

int 			ft_isdigit(char c);
int 			check_current_param(char *param);
t_node_inputs	*create_node_input(int value);
void			add_back_inputs(t_node_inputs	**head, t_node_inputs	*newnode);
int				ft_atoi(char *str);
void 			look_towards_inputs(t_node_inputs *head);
int 			inputs_constraints(t_node_inputs *inputs);
int				inputs_checker(int argc, char **argv, t_node_inputs	**inputs);
void			look_towards(t_node *head);
void			look_backwards(t_node *head);
void			add_back(t_node	**head, t_node	*newnode);
void			add_front(t_node	**head, t_node	*newnode);
int				get_size(t_node *head);
void			pa(t_node **head_a, t_node **head_b);
void			pb(t_node **head_a, t_node **head_b);
void			sa(t_node **head_a_1, t_node **head_a_2);
void			sb(t_node *head_b);
void			ss(t_node *head_a, t_node *head_b);
void			ra(t_node **head_a);
void			rb(t_node *head_b);
void			rr(t_node *head_a, t_node *head_b);
void			rra(t_node **head_a);
void			rrb(t_node *head_b);
void			rrr(t_node *head_a, t_node *head_b);
int				init_stack_a(t_node_inputs *inputs_head, t_node **stack_a);
void			solve(t_node **head_stack_a, t_node *head_stack_b);
void			solve2(t_node **head_stack_a, t_node *head_stack_b, int size_a);
t_node			*create_node(int value);
void			ft_lstdelone(t_node **Head, void (*del)(void *));
#endif