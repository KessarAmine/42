/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:53:36 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"
#include "../lib/libft/libft.h"

void	check_valid_maps(t_listt *list)
{
	int	length;

	length = ft_strlen(list->map_name);
	if (list->map_name[length] == '\0' && list->map_name[length - 1] == 'b'
		&& list->map_name[length - 2] == 'u'
		&& list->map_name[length - 3] == 'c'
		&& list->map_name[length - 4] == '.')
		return ;
	else
		exit (printf("Error : Extension Invalid ! -> Use Extension '.cub'\n"));
}

void	check_direction(t_listt *list)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (list->map[j])
	{
		i = 0;
		while (list->map[j][i])
		{
			if (list->map[j][i] == 'N' || list->map[j][i] == 'S'
			|| list->map[j][i] == 'E' || list->map[j][i] == 'W')
			{
				count++;
				list->direction = list->map[j][i];
			}
		i++;
		}
		j++;
	}
	if (count == 0)
		exit(printf("Error : The string must start with one directions\n"));
	if (count > 1)
		exit(printf("Error : Map have more 1 direction.\n"));
}

static void	part_2(t_listt *list)
{
	int	i;
	int	j;
	int	length;

	j = 0;
	i = 0;
	while (list->map[j])
	{
		length = find_f_space(list->map[j]);
		i = 0;
		while (list->map[j][i] == ' ')
				i++;
		if ((list->map[j][i] != '1' || list->map[j][length] != '1')
		&& list->map[j][i])
			exit(printf("Error : Walls not set correctly.\n"));
		j++;
	}
}

void	check_wall(t_listt *list)
{
	int	i;
	int	j;
	int	length;

	j = 0;
	i = 0;
	while (list->map[j][i])
	{
		length = find_f_space(list->map[j]);
		check_wall2(list->map[j], length);
		if (i == length - 1 && j == 0)
		{
			j = list->high_map - 1;
			i = 0;
		}
		i++;
	}
	part_2(list);
}

void	check_wall2(char *str, int length)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ' && i < length)
			exit(printf ("Error : Sides Walls not set Correctly.\n"));
		i++;
	}
}
