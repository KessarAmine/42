/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:27:48 by kmohamed          #+#    #+#             */
/*   Updated: 2023/01/23 13:52:23 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printfLib.h"

void	ft_putcharacter_length(char character, int *length)
{
	write(1, &character, 1);
	(*length)++;
}

void	ft_string(char *args, int *length)
{
	size_t	i;

	i = 0;
	if (!args)
	{
		write(1, "(null)", 6);
		(*length) += 6;
		return ;
	}
	while (args[i] != '\0')
	{
		ft_putcharacter_length(args[i], length);
		i++;
	}
}

int	has_nonenumeric(char *par1)
{
	while (*par1)
	{
		if (*par1 < '0' || *par1 > '9')
			return (0);
		par1++;
	}
	return (1);
}
