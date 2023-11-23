/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:50 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:47:52 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*sav_d;
	const char	*sav_s;
	int			n;
	int			length_dst;

	sav_d = dst;
	sav_s = src;
	n = size;
	while (n-- != 0 && *sav_d != '\0')
		sav_d++;
	length_dst = sav_d - dst;
	n = size - length_dst;
	if (n == 0)
		return (length_dst + ft_strlen(sav_s));
	while (*sav_s != '\0')
	{
		if (n != 1)
		{
			*sav_d++ = *sav_s;
			n--;
		}
		sav_s++;
	}
	*sav_d = '\0';
	return (length_dst + sav_s - src);
}
