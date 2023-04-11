/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:01:44 by kmohamed          #+#    #+#             */
/*   Updated: 2023/03/04 13:07:45 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include <limits.h>
# include <unistd.h>
# include <stdio.h>

void	ft_putnbr_hexlower_fd(unsigned long long nbr, int fd, int *count);
void	ft_putnbr_hexupper_fd(unsigned long long nbr, int fd, int *count);
void	ft_putptr(void *p, int *count);
void	ft_putchar_fd(char c, int fd, int *count);
void	get_conversion(va_list args, char signe, int *count);
void	ft_putnbr_unsigned_fd(unsigned int nb, int fd, int *count);
void	ft_putnbr_fd(int nb, int fd, int *count);
int		ft_printf(const char *str, ...);
void	ft_putstr_fd(char *str, int fd, int *count);

#endif