/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:45:00 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:45:02 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*sav_dest;
	void	*sav_src;

	sav_dest = dest;
	sav_src = (void *)src;
	if (dest < src && dest + n >= src)
	{
		while (n--)
			*(char *)sav_dest++ = *(char *)src++;
	}
	else if (src < dest && src + n > dest)
	{
		sav_src += n;
		sav_dest += n;
		while (n--)
			*(char *)--sav_dest = *(char *)--sav_src;
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
