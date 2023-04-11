/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfLib.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:27:40 by kmohamed          #+#    #+#             */
/*   Updated: 2023/01/23 13:52:27 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTFLIB_H
# define FT_PRINTFLIB_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putcharacter_length(char character, int *length);
void	ft_string(char *args, int *length);
void	ft_number(int number, int *length);
void	ft_hexadecimal(unsigned int x, int *length, char x_or_x);
void	ft_unsigned_int(unsigned int u, int *length);
void	ft_pointer(size_t pointer, int *length);
int		ft_printf(const char *string, ...);
int		has_nonenumeric(char *par1);

#endif
