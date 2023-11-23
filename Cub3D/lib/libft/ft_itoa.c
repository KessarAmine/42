/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:44:22 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:44:24 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(long long n)
{
	char	*str;
	size_t	size_nbr;

	size_nbr = get_len_int(n);
	str = ft_calloc(size_nbr + 1, sizeof(char));
	if (!(str))
		return (0);
	str += size_nbr - 1;
	while (size_nbr--)
	{
		if (n == LONG_MIN)
			*str-- = '8';
		else
			*str-- = ft_abs(n) % 10 + ASCII_OFFSET_NUM;
		if (-10 < n && n < 0)
		{
			*str-- = '-';
			break ;
		}
		n /= 10;
	}
	return (++str);
}
