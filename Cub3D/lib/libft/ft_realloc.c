/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:46:10 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:46:12 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t orig_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = 0;
	if (new_size == 0)
		free(ptr);
	else if (!ptr)
	{
		new_ptr = malloc(new_size);
		if (!(new_ptr))
			return (0);
	}
	else if (new_size <= orig_size)
		return (ptr);
	else if (ptr && new_size > orig_size)
	{
		new_ptr = malloc(new_size);
		if (!(new_ptr))
			return (0);
		ft_memcpy(new_ptr, ptr, orig_size);
		free(ptr);
	}
	return (new_ptr);
}
