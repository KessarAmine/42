/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:54:00 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"
#include "../lib/libft/libft.h"

int	find_f_space(char *str)
{
	int	end;

	end = ft_strlen(str) - 1;
	while (str[end] == ' ')
	end--;
	return (end);
}

void	get_long_line(t_listt *list)
{
	int	i;
	int	len;

	i = 0;
	list->long_line = 0;
	while (list->map[i])
	{
		len = ft_strlen(list->map[i]);
		if (len > list->long_line)
			list->long_line = len;
		i++;
	}
}

static void	part2(char **lines, int i, int num_lines, int j)
{
	free(lines[i]);
	j = i;
	while (j < num_lines - 1)
	{
		lines[j] = lines[j + 1];
		j++;
	}
}

static void	part3(char **lines, int a, int i)
{
	while (lines[a])
	{
		lines[i] = lines[a];
		i++;
		a++;
	}
	lines[i] = NULL;
}

void	remove_empty_lines(char **lines, int num_lines, t_listt *list, int i)
{
	int	j;
	int	len;
	int	count_spaces;

	while (i < num_lines)
	{
		len = ft_strlen(lines[i]);
		count_spaces = 0;
		j = 0;
		while (j < len)
		{
			if (lines[i][j] == ' ')
				count_spaces++;
			j++;
		}
		if (count_spaces == len)
		{
			part2(lines, i, num_lines, j);
			num_lines--;
			i--;
		}
	i++;
	}
	part3(lines, list->first_map + 1, i);
}
