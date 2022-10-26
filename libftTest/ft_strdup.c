/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:39:57 by kmohamed          #+#    #+#             */
/*   Updated: 2022/10/13 22:42:33 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		i;
	int		l;
	size_t	memo_alloc;

	l = ft_strlen(str);
	memo_alloc = (l + 1) * sizeof(char);
	newstr = (char *) malloc(memo_alloc);
	if (newstr == NULL)
		return (NULL);
	i = -1;
	while (++i < l)
		newstr[i] = str[i];
	newstr[i] = '\0';
	return (newstr);
}
