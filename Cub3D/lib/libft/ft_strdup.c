/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:31 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:47:33 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*cpy;

	if (!s)
	{
		cpy = malloc(1);
		if (!(cpy))
			return (0);
		*cpy = 0;
		return (cpy);
	}
	s_len = ft_strlen(s) + 1;
	cpy = malloc(s_len * sizeof(char));
	if (!(cpy))
		return (0);
	ft_strcpy(cpy, s);
	return (cpy);
}
