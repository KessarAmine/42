/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:50:20 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:50:23 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define UPPERCASE_OFFSET 32

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - UPPERCASE_OFFSET);
	else
		return (c);
}
