/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:00:42 by kmohamed          #+#    #+#             */
/*   Updated: 2022/10/14 19:09:53 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *Head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newnode;
	t_list	*head2;
	void	*result;

	temp = Head;
	head2 = NULL;
	while (temp != NULL)
	{
		result = (*f)(temp->content);
		if (result)
		{
			if (ft_lstsize(head2) == 0)
				head2 = ft_lstnew(result);
			else
			{
				newnode = ft_lstnew(result);
				ft_lstadd_back(&head2, newnode);
			}
		}
		else
			(*del)(temp);
		temp = temp->next;
	}
	return (head2);
}
