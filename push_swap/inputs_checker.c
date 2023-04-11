/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:42:54 by kmohamed          #+#    #+#             */
/*   Updated: 2022/11/12 11:06:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char c)
{
	if ((c <= '9' && c >= '0') || c == '+' || c == '-')
		return (1);
	return (0);
}

int check_current_param(char *param)
{
	int i;

	i = 0;
	while (param[i])
	{
		if (!ft_isdigit(param[i]))
			return (0);
		i++;
	}
	if (param[i - 1] == '-' || param[i - 1] == '+')
		return (0);
	return (1);
}

t_node_inputs	*create_node_input(int value)
{
	t_node_inputs	*newnode;

	newnode = malloc(sizeof(t_node_inputs));
	if (newnode == NULL)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

void	add_back_inputs(t_node_inputs	**head, t_node_inputs	*newnode)
{
	t_node_inputs	*last;
	if ((*head) == NULL)
	{
		(*head) = newnode;
		return ;
	}
	last = (*head);
	while (last->next != NULL)
		last = last->next;
	last->next = newnode;
}

int	ft_atoi(char *str)
{
	size_t				i;
	int					signe;
	unsigned long int	result;

	i = 0;
	signe = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe *= -1;
	while (ft_isdigit(str[i]) && str[i])
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	if (result == 2147483648 && signe == 1)
	{		
		write(2, "Error\n", 6);
		exit (0);
	} 
	else if (result > 2147483648)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	return (result * signe);
}

// void look_towards_inputs(t_node_inputs *head)
// {
// 	t_node_inputs	*temp;

// 	temp = head;
// 	if (temp == NULL)
// 		return ;
// 	while (temp != NULL)
// 	{
// 		printf("%ld - >", temp->value);
// 		temp = temp->next;
// 	}
// }

int inputs_constraints(t_node_inputs *inputs)
{
	t_node_inputs	*temp;
	t_node_inputs	*next;

	next = NULL;
	temp = inputs;
	while (temp != NULL)
	{
		next = temp->next;
		while (next != NULL)
		{
			if (temp->value == next->value)
				return (0);
			next = next->next;
		}
		temp = temp->next;
	}
	return (1);
}

int inputs_checker(int argc, char **argv, t_node_inputs	**inputs)
{
	int i;
	t_node_inputs	*next;

	i = 0;
	next = (*inputs);
	//check parameters
	while (++i < argc)
	{
		if (check_current_param(argv[i]))
			add_back_inputs(inputs, create_node_input(ft_atoi(argv[i])));
		else
		{
			write(2, "Error\n", 6);
			exit (0);
		}
	}
	if (!inputs_constraints((*inputs)))
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	return (1);
}

// //test
// int main(int argc, char **argv)
// {
// 	t_node_inputs	*inputs;
// 	t_node			*stack_a;
// 	t_node			*stack_b;
// 	int				size;

// 	stack_a = NULL;
// 	stack_b = NULL;
// 	inputs = NULL;
// 	if (argc < 2)
// 		exit (0);
// 	inputs_checker(argc, argv, &inputs);
// 	size = init_stack_a(inputs, &stack_a);
// 	solve2(&stack_a, stack_b, size);
// 	exit (0);
// }

// int main(int argc, char **argv)
// {
// 	t_node_inputs	*inputs;
// 	t_node			*stack_a;
// 	t_node			*stack_b;
		
// 	stack_a = NULL;
// 	stack_b = NULL;
// 	inputs = NULL;
// 	if (argc < 2)
// 		return (0);
// 	if (!inputs_checker(argc, argv, &inputs))
// 		return (0);
// 	init_stack_a(inputs, &stack_a);
// 	solve(&stack_a, stack_b);
// 	return (1);
// }