/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:40:22 by kmohamed          #+#    #+#             */
/*   Updated: 2022/10/13 16:43:54 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *str, size_t n)
{
	unsigned int	i;
	unsigned int	lsrc;
	char			*src;

	src = (char *) str;
	lsrc = 0;
	while (src[lsrc] != '\0')
		lsrc++;
	if (n > 0)
	{
		i = 0;
		while (i < n - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (lsrc);
}
