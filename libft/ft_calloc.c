/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:28:05 by kmohamed          #+#    #+#             */
/*   Updated: 2022/10/25 15:41:25 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	bytessize;
	void	*p;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	bytessize = count * size;
	p = malloc(bytessize);
	if (p == NULL)
		return (NULL);
	else
		ft_memset(p, 0, bytessize);
	return (p);
}
	// if(count * size >= SIZE_MAX)
	// 	return (NULL);