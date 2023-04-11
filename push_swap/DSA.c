/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DSA.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:42:54 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/02 13:41:12 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (newnode == NULL)
		return (NULL);
	newnode->value = value;
	newnode->next = newnode;
	newnode->prev = newnode;
	return (newnode);
}

void	look_towards(t_node *head)
{
	t_node	*temp;
	
	temp = head;
	if (temp == NULL)
	{
		printf("EMPTY\n");
		return ;
	}
	while (temp->next != head)
	{
		printf("%d - >", temp->value);
		temp = temp->next;
	}
	if (temp != NULL)
		printf("%d\n", temp->value);
}

void	look_backwards(t_node *head)
{
	t_node	*temp;
	
	temp = head;
	while (temp->prev != head)
	{
		printf("%d - >", temp->value);
		temp = temp->prev;
	}
	if (temp != NULL)
		printf("%d\n", temp->value);
}

void	add_back(t_node	**head, t_node	*newnode)
{
	t_node	*last;
	if ((*head) == NULL)
	{
		(*head) = newnode;
		return ;
	}
	last = (*head);
	while (last->next != (*head))
		last = last->next;
	last->next = newnode;
	newnode->prev = last;
	newnode->next = (*head);
	(*head)->prev = newnode;
}

void	add_front(t_node	**head, t_node	*newnode)
{
	if ((*head) == NULL)
	{
		(*head) = newnode;
		return ;
	}
	newnode->next = (*head);
	newnode->prev = (*head)->prev;
	(*head)->prev->next = newnode;
	(*head)->prev = newnode;
	(*head)  = newnode;
}

int		get_size(t_node *head)
{
	int		count;
	t_node	*temp;

	temp = head;
	if (temp == NULL)
		return (0);
	count = 0;
	while (temp->next != head)
	{
		count++;
		temp = temp->next;
	}
	if (count >= 0)
		count++;
	return (count);
}

void	pa(t_node **head_a, t_node **head_b)
{
	t_node *hb;

	hb = *head_b;
	write(1, "pa\n", 3);
	if (get_size(hb) >= 1)
	{
		add_front(head_a, create_node(hb->value));
		if (get_size(hb) == 1)
			(*head_b) = NULL;
		else
		{
			(*head_b)->next->prev = (*head_b)->prev;
			(*head_b)->prev->next = (*head_b)->next;
			(*head_b) = (*head_b)->next;
		}
		free(hb);
	}
}
void	pb(t_node **head_a, t_node **head_b)
{
	t_node *ha;

	ha = *head_a;
	write(1, "pb\n", 3);
	if (get_size(ha) >= 1)
	{
		add_front(head_b, create_node(ha->value));
		if (get_size(ha) == 1)
			(*head_a) = NULL;
		else
		{
			(*head_a)->next->prev = (*head_a)->prev;
			(*head_a)->prev->next = (*head_a)->next;
			(*head_a) = (*head_a)->next;
		}
		free(ha);
	}
}

void	sa(t_node **head_a_1, t_node **head_a_2)
{
	int		temp;

	write(1, "sa\n", 3);
	if (get_size((*head_a_1)) >= 2)
	{
		temp = (*head_a_1)->value;
		(*head_a_1)->value = (*head_a_2)->value;
		(*head_a_2)->value = temp;
	}
}

void	sb(t_node *head_b)
{
	t_node	*temp_b;
	int		temp;

	write(1, "sb\n", 3);
	temp_b  = head_b->prev;
	if (get_size(head_b) > 2)
	{
		temp = temp_b->value;
		temp_b->value = temp_b->prev->value;
		temp_b->prev->value = temp;
	}
}

// void	ss(t_node *head_a, t_node *head_b)
// {
// 	sa(&head_a, &head_a->next);
// 	sb(head_b);
// }

void	rb(t_node *head_b)
{
	t_node	*head;
	int		temp;

	write(1, "rb\n", 3);
	head = head_b;
	while (head->next != head_b)
	{
		temp = head->value;
		head->value = head->next->value;
		head->next->value = temp;
	}
}

// void	rr(t_node *head_a, t_node *head_b)
// {
// 	ra(&head_a);
// 	rb(head_b);
// }
void	rra(t_node **head_a)
{
	t_node	*head;
	int		temp;
	int		temp_s;

	write(1, "rra\n", 4);
	head = *head_a;
	temp = head->value;
	while (head->next != (*head_a))
	{
		temp_s = temp;
		temp = head->next->value;
		head->next->value = temp_s;
		head = head->next;
	}
	(*head_a)->value = temp;
}

void	ra(t_node **head_a)
{
	t_node	*head;
	int		temp;
	int		temp_s;

	write(1, "ra\n", 3);
	head = *head_a;
	temp = head->value;
	while (head->prev != (*head_a))
	{
		temp_s = temp;
		temp = head->prev->value;
		head->prev->value = temp_s;
		head = head->prev;
	}
	(*head_a)->value = temp;
}

void	rrb(t_node *head_b)
{
	t_node	*head;
	int		temp;

	write(1, "rrb\n", 4);
	head = head_b;
	while (head->next != head_b)
	{
		temp = head->value;
		head->value = head->prev->value;
		head->prev->value = temp;
	}
}

// void	rrr(t_node *head_a, t_node *head_b)
// {
// 	rra(head_a);
// 	rrb(head_b);
// }

int	init_stack_a(t_node_inputs *inputs_head, t_node **stack_a)
{
	t_node_inputs	*inputs_temp;
	int size;

	size = 0;
	inputs_temp = inputs_head;
	while (inputs_temp != NULL)
	{
		add_back(stack_a, create_node(inputs_temp->value));
		size++;
		inputs_temp = inputs_temp->next;
	}
	return (size);
}

int is_sorted(t_node *head_a)
{
	t_node *temp;

	if (head_a == NULL)
		return (1);
	temp = head_a;
	while (temp->next != head_a)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

// void	solve(t_node **head_stack_a, t_node *head_stack_b)
// {
// 	t_node	*temp_a;
// 	t_node	*next_track;
// 	t_node	*prev_track;

// 	prev_track = (*head_stack_a)->prev;
// 	// while (!is_empty((*head_stack_a)))
// 	{
// 		temp_a = (*head_stack_a);
// 		while (temp_a->next != (*head_stack_a))
// 		{
// 			if ((temp_a->value > temp_a->next->value) && temp_a == (*head_stack_a))
// 				sa(&temp_a, &temp_a->next);
// 			else if ((temp_a->value > temp_a->next->value) && temp_a != (*head_stack_a))
// 			{
// 				while ((*head_stack_a) != temp_a)
// 				{
// 					next_track = (*head_stack_a)->next;
// 					prev_track = (*head_stack_a)->prev;
// 					pb((*head_stack_a), &head_stack_b);
// 					(*head_stack_a)->prev->next = next_track;
// 					(*head_stack_a)->next->prev = prev_track;
// 					free((*head_stack_a));
// 					(*head_stack_a) = next_track;
// 				}
// 				sa(&temp_a, &temp_a->next);
// 				while (get_size(head_stack_b) > 1)
// 				{
// 					pa(head_stack_a, head_stack_b);
// 					head_stack_b->prev->prev->next = head_stack_b;
// 					prev_track = head_stack_b->prev->prev;
// 					head_stack_b->prev = head_stack_b->prev->prev;
// 				}
// 				if (get_size(head_stack_b) == 1)
// 					pa(head_stack_a, head_stack_b);
// 			}
// 			temp_a = temp_a->next;
// 		}
// 		if ((*head_stack_a)->value > (*head_stack_a)->next->value) 
// 			sa(&(*head_stack_a), &(*head_stack_a)->next);
// 	}
// }

t_return get_min(t_node *head)
{
	t_return min;
	t_node *temp;
	int		index;

	index = 0;
	min.value = head->value;
	temp = head;
	while (temp->next != head)
	{
		if (min.value > temp->value)
		{
			min.value = temp->value;
			min.index = index;
		}
		index++;
		temp = temp->next;
	}
	if (temp->value < min.value)
	{
		min.value = temp->value;
		min.index = index + 1;
	}
	return (min);
}

// void	solve2(t_node **head_stack_a, t_node *head_stack_b, int size_a)
// {
// 	t_node	*temp;
// 	t_node	*min_track;
// 	t_node	*prev_track;
// 	t_return min;
	
// 	temp = *head_stack_a;
// 	while (!is_sorted(*head_stack_a))
// 	{
// 		while (get_size((*head_stack_a)) > 1)
// 		{
// 			min = get_min((*head_stack_a));
// 			// while head.value != min / move all (up/down)
// 			while (temp->value != min.value && min.index < size_a / 2)
// 			{
// 				ra(head_stack_a);
// 				temp = *head_stack_a;
// 			}
// 			while (temp->value != min.value && min.index > size_a / 2)
// 			{
// 				rra(head_stack_a);
// 				temp = *head_stack_a;
// 			}
// 			// if head.value == min / put head in b
// 			if (temp->value == min.value)
// 				pb(temp, &head_stack_b);
// 			// repaet untill the stack is empty
// 		}
// 	}
// }

// // void	setinputs_newnode(t_node_inputs	**inputs)
// {
// 	add_back_inputs(inputs, create_node_input(2));
// 	add_back_inputs(inputs, create_node_input(1));
// 	add_back_inputs(inputs, create_node_input(3));
// 	add_back_inputs(inputs, create_node_input(6));
// 	add_back_inputs(inputs, create_node_input(5));
// 	add_back_inputs(inputs, create_node_input(8));
// }

void setinputs_newnode(t_node	**inputs)
{
	int i;

	i = -1;
	while (++i < 10)
		add_back(inputs, create_node(rand()));
	// add_back(inputs, create_node(3));
	// add_back(inputs, create_node(1));
	// add_back(inputs, create_node(6));
	// add_back(inputs, create_node(5));
	// add_back(inputs, create_node(2));
}

// int main(int arc, char **argv)
// {
// 	t_node			*stack_a;
// 	t_node			*stack_b;
// 	t_node_inputs	*inputs;
	
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	inputs = NULL;
// 	setinputs_newnode(&inputs);
// 	init_stack_a(inputs, &stack_a);
// 	printf("beforee sorting=========\n");
// 	look_towards(stack_a);
// 	printf("steps=========\n");
// 	solve(&stack_a, stack_b);
// 	printf("result=========\n");
// 	look_towards(stack_a);
// 	// printf("stack_b=========\n");
// 	// look_towards(stack_b);
// }

void	move_min_tohead_push_b(t_node **head_a, t_node **head_b)
{
	t_node *temp_node = (*head_a);
	int size_a = get_size((temp_node));
	t_return min = get_min(temp_node);
	// while head.value != min / move all (up/down)
	while (temp_node->value != min.value && min.index + 1 <= size_a / 2)
	{
		ra(head_a);
		temp_node = (*head_a);
	}
	while (temp_node->value != min.value && min.index + 1 > size_a / 2)
	{
		rra(head_a);
		temp_node = (*head_a);
	}
	pb(head_a, head_b);
}

void	solve_3args(t_node **head_stack_a)
{
	if ((*head_stack_a)->value < (*head_stack_a)->next->value && (*head_stack_a)->next->value > (*head_stack_a)->prev->value && (*head_stack_a)->prev->value < (*head_stack_a)->next->value && (*head_stack_a)->value > (*head_stack_a)->prev->value)
		rra(head_stack_a);
	else if ((*head_stack_a)->value > (*head_stack_a)->next->value && (*head_stack_a)->next->value < (*head_stack_a)->prev->value && (*head_stack_a)->value < (*head_stack_a)->prev->value)
		sa(head_stack_a, &(*head_stack_a)->next);
	else if ((*head_stack_a)->value > (*head_stack_a)->next->value && (*head_stack_a)->next->value > (*head_stack_a)->prev->value)
	{
		sa(head_stack_a, &(*head_stack_a)->next);
		rra(head_stack_a);
	}
	else if ((*head_stack_a)->value > (*head_stack_a)->next->value && (*head_stack_a)->next->value < (*head_stack_a)->prev->value && (*head_stack_a)->value > (*head_stack_a)->prev->value)
		ra(head_stack_a);
	else if ((*head_stack_a)->value < (*head_stack_a)->next->value && (*head_stack_a)->next->value > (*head_stack_a)->prev->value)
	{
		sa(head_stack_a, &(*head_stack_a)->next);
		ra(head_stack_a);
	}
}

int main()
{
	t_node		*head_stack_a;
	t_node		*head_stack_b;
	t_node		*temp_node;
	t_return	min;
	int			size_a;

	head_stack_a = NULL;
	setinputs_newnode(&head_stack_a);
	if (show_logs)
	{
		printf("\tThe list :\n");
		look_towards(head_stack_a);
	}
	while (get_size((head_stack_a)) > 0)
	{
		if (show_logs)
			printf("\t=================newstep=================\n");
		if (is_sorted(head_stack_a))
		{
			while (get_size((head_stack_b)) > 0 && get_size(head_stack_b) > 0)
				pa(&head_stack_a, &head_stack_b);
			exit (0);
		}
		if (get_size((head_stack_a)) > 5)
		{
			k_sort(&head_stack_a, &head)
			exit (0);
		}
		if (get_size((head_stack_a)) == 5)
		{
			move_min_tohead_push_b(&head_stack_a, &head_stack_b);
			move_min_tohead_push_b(&head_stack_a, &head_stack_b);
			solve_3args(&head_stack_a);
			pa(&head_stack_a, &head_stack_b);
			pa(&head_stack_a, &head_stack_b);
			if (show_logs)
			{
				printf("\t/*the results teteteraaa teteteterraaa*\\\n");
				printf("a is : ========\n");
				look_towards(head_stack_a);
				printf("b is : ========\n");
				look_towards(head_stack_b);
				printf("size is : %d\n", get_size((head_stack_a)));
			}
			exit (0);
		}
		if (get_size((head_stack_a)) == 3)
		{
			solve_3args(&head_stack_a);
			if (show_logs)
			{
				printf("\t/*the results teteteraaa teteteterraaa*\\\n");
				printf("a is : ========\n");
				look_towards(head_stack_a);
				printf("b is : ========\n");
				look_towards(head_stack_b);
				printf("size is : %d\n", get_size((head_stack_a)));
			}
			exit (0);
		}
		if (get_size((head_stack_a)) == 2 && !is_sorted(head_stack_a))
		{
			sa(&head_stack_a, &head_stack_a->next);
			exit (0);
		}
		// else
		if (head_stack_a->value > head_stack_a->next->value)
			sa(&head_stack_a, &head_stack_a->next);
		temp_node = head_stack_a;
		size_a = get_size((head_stack_a));
		min = get_min(head_stack_a);
		if (show_logs)
			printf("\tmin is : %d at %d position\n", min.value, min.index + 1);
		// while head.value != min / move all (up/down)
		while (temp_node->value != min.value && min.index + 1 <= size_a / 2)
		{
			ra(&head_stack_a);
			temp_node = head_stack_a;
		}
		while (temp_node->value != min.value && min.index + 1 > size_a / 2)
		{
			rra(&head_stack_a);
			temp_node = head_stack_a;
		}
		// if head.value == min / put head in b
		if (temp_node->value == min.value)
			pb(&head_stack_a, &head_stack_b);
	}
	while (get_size((head_stack_b)) > 0)
		pa(&head_stack_a, &head_stack_b);
	if (show_logs)
	{
		printf("\tthe results teteteraaa teteteterraaa\n");
		printf("a is : ========\n");
		look_towards(head_stack_a);
		printf("b is : ========\n");
		look_towards(head_stack_b);
		printf("size is : %d\n", get_size((head_stack_a)));
	}
}