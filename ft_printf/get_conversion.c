/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:28:28 by kmohamed          #+#    #+#             */
/*   Updated: 2022/11/03 15:20:30 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_conversion(va_list args, char signe, int *count)
{
	if (signe == 's')
		ft_putstr_fd(va_arg(args, char *), 1, count);
	else if (signe == 'c')
		ft_putchar_fd(va_arg(args, int), 1, count);
	else if (signe == 'i' || signe == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, count);
	else if (signe == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1, count);
	else if (signe == 'p')
		ft_putptr(va_arg(args, void *), count);
	else if (signe == 'x')
		ft_putnbr_hexlower_fd(va_arg(args, unsigned int), 1, count);
	else if (signe == 'X')
		ft_putnbr_hexupper_fd(va_arg(args, unsigned int), 1, count);
	else if (signe == '%')
		ft_putchar_fd('%', 1, count);
}
