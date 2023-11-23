/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:48:25 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:48:28 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (1)
	{
		if (*s1 != *s2++)
		{
			--s2;
			if (*s1 < 0 || *s2 < 0)
				return ((unsigned char)(*s1 - *s2));
			return (*s1 - *s2);
		}
		if (*s1++ == 0)
			break ;
		if (--n == 0)
			break ;
	}
	return (0);
}
