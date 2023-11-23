/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:45:39 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:45:42 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_to_char(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb + ASCII_OFFSET_NUM);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	n_to_print;
	int		remainder;

	if (0 <= n && n < 10)
	{
		n_to_print = convert_to_char(n);
		write(fd, &n_to_print, 1);
		return ;
	}
	else if (-10 < n && n < 0)
	{
		write(fd, "-", 1);
		n_to_print = convert_to_char(n);
		write(fd, &n_to_print, 1);
		return ;
	}
	remainder = n % 10;
	ft_putnbr_fd(n / 10, fd);
	n_to_print = convert_to_char(remainder);
	write(fd, &n_to_print, 1);
	return ;
}
