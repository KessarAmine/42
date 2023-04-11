/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:00:42 by kmohamed          #+#    #+#             */
/*   Updated: 2022/10/13 22:51:03 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *Head)
{
	t_list	*temp;
	int		count;

	count = 0;
	temp = Head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
