/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:00:42 by kmohamed          #+#    #+#             */
/*   Updated: 2022/10/20 12:02:06 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *Head, void (*del)(void *))
{
	t_list	*temp;

	if (!Head || !del)
		return ;
	temp = Head;
	Head = Head->next;
	if (temp->content != NULL)
		(*del)(temp->content);
	free(temp);
}
