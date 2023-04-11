/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memory_tracker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:46:57 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/18 14:26:12 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/resources.h"

void	*my_malloc(size_t size, t_memoryblock *memory_list)
{
	void			*address;
	t_memoryblock	*block;

	address = malloc(size);
	if (!address)
		return (NULL);
	block = malloc(sizeof(t_memoryblock));
	block->address = address;
	block->size = size;
	block->next = memory_list;
	memory_list = block;
	return (address);
}

void	my_free(void *address, t_memoryblock *memory_list)
{
	t_memoryblock	*prev;
	t_memoryblock	*curr;

	prev = NULL;
	curr = memory_list;
	while (curr != NULL)
	{
		if (curr->address == address)
		{
			if (prev == NULL)
				memory_list = curr->next;
			else
				prev->next = curr->next;
			free(address);
			free(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	free_all_memory(t_memoryblock *memory_list)
{
	t_memoryblock	*curr;
	t_memoryblock	*temp;

	curr = memory_list;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp->address);
		free(temp);
	}
	memory_list = NULL;
}
