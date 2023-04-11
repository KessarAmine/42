/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:41:16 by kmohamed          #+#    #+#             */
/*   Updated: 2022/10/15 16:42:52 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

static int	ft_search(char *str, char *to_find, size_t i, size_t len)
{
	int	j;
	int	found;

	found = 1;
	j = 0 ;
	while (to_find[j] != '\0' && i < len)
	{
		if (to_find[j] != str[i])
			found = 0;
		j++;
		i++;
	}
	if (to_find[j] != '\0')
		found = 0;
	return (found);
}

char	*ft_strnstr(const char *strsrc, const char *to_find, size_t len)
{
	size_t	i;
	size_t	current;
	char	*needle;
	char	*str;

	if ((!strsrc || !to_find) && len == 0)
		return (0);
	str = (char *) strsrc;
	needle = (char *)to_find;
	current = 0;
	i = 0;
	if (*needle == '\0')
		return (str);
	while (str[i] != '\0' && current < len)
	{
		if (str[i] == needle[0])
		{
			if (ft_search(str, needle, i, len))
				return (&str[i]);
		}
		current++;
		i++;
	}
	return (NULL);
}
