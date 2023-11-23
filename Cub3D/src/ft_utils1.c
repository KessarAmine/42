/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:54:53 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = 0;
		i++;
	}
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		j;

	if (!src || ft_strlen(src) == 0)
		return (NULL);
	j = ft_strlen(src);
	p = (char *)malloc(sizeof(char) * (j + 1));
	j = 0;
	if (p == 0)
		return (0);
	while (src[j])
	{
		p[j] = src[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_callocc(size_t count, size_t size)
{
	char	*p;

	p = (char *)malloc(sizeof(char) * (count * size));
	if (p == 0)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}
