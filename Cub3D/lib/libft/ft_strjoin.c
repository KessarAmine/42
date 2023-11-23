/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:47:43 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:47:46 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	new_str_size;
	char	*new_str;

	if (!s1 || !s2)
		return (0);
	new_str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(new_str_size * sizeof(char));
	if (!(new_str))
		return (0);
	ft_strlcpy(new_str, s1, new_str_size);
	ft_strlcat(new_str, s2, new_str_size);
	return (new_str);
}
