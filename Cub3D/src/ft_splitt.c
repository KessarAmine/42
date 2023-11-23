/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:54:46 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static int	ft_cw(const char *s1, char to_find)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s1[i] == to_find)
		i++;
	while (s1[i])
	{
		if (s1[i] == to_find && s1[i + 1] != to_find && s1[i + 1])
			count ++;
		i++;
	}
	return (count + 1);
}

void	ft_khwi(int j, char **p)
{
	int	d;

	d = 0;
	while (j >= 0)
	{
		free(p[d]);
		d++;
		j--;
	}
	free(p);
	return ;
}

static void	alloc(const char *s1, char to_find, char **p, int i)
{
	int	j;
	int	k;
	int	end;

	i = 0;
	j = -1;
	while (s1[i])
	{
		if (s1[i] != to_find && s1[i])
		{
			end = i;
			while (s1[end] != to_find && s1[end])
				end++;
			p[++j] = (char *)ft_callocc(sizeof(char) * (end - i) + 1, 1);
			if (!p[j])
				return (ft_khwi(j, p));
			k = 0;
			while (i < end)
				p[j][k++] = s1[i++];
		}
		if (s1[i])
			i++;
	}
}

char	**ft_splitt(const char *s1, char c)
{
	char	**p;
	int		o;

	o = 0;
	if (!s1)
		return (0);
	p = (char **)ft_callocc(sizeof(char *) * (ft_cw(s1, c) + 1), 1);
	if (!p)
		return (0);
	alloc(s1, c, p, o);
	return (p);
}
