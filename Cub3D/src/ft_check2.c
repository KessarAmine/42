/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:53:49 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:08:48 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

static void	part2(char *str)
{
	int	i;

	i = 0;
	if (!str)
		exit(printf("Error : Something Wrong in map.\n"));
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			if (str[i] == '\n')
				exit(printf("Error : empty line in map\n"));
		}
		i++;
	}
}

void	check_ligne_map(t_listt *list)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	while (list->before[i])
	{
		if (list->before[i] == '\n')
		{
			i++;
			while (list->before[i] == ' ' || list->before[i] == '\n')
				i++;
			if (list->before[i] == '1')
			{
				list->before += i;
				str = list->before;
				break ;
			}
		}
		i++;
	}
	part2(str);
}

void	check_text_path(t_listt *list)
{
	check_text_extension(list->north_path);
	check_text_extension(list->west_path);
	check_text_extension(list->east_path);
	check_text_extension(list->south_path);
	if (access(list->north_path, F_OK) != 0)
		exit(printf("Error: Some of Textures not found.\n"));
	if (access(list->south_path, F_OK) != 0)
		exit(printf("Error: Some of Textures not found.\n"));
	if (access(list->east_path, F_OK) != 0)
		exit(printf("Error: Some of Textures not found.\n"));
	if (access(list->west_path, F_OK) != 0)
		exit(printf("Error: Some of Textures not found.\n"));
}

static void	part_2(t_listt *list, int i, int j)
{
	if ((list->dup_map[j][i] == '-' && j == 0)
		&& (list->dup_map[j][i + 1] == '0' || list->dup_map[j][i - 1] == '0'
		|| list->dup_map[j + 1][i] == '0'
		|| list->dup_map[j][i + 1] == list->direction
		|| list->dup_map[j][i - 1] == list->direction
		|| list->dup_map[j + 1][i] == list->direction))
		exit(printf("Error: Invalid space found at (%d,%d)\n", j, i));
	if ((list->dup_map[j][i] == '-' && j == list->high_map - 1)
		&& (list->dup_map[j][i + 1] == '0' || list->dup_map[j][i - 1] == '0'
		|| list->dup_map[j - 1][i] == '0'
		|| list->dup_map[j][i + 1] == list->direction
		|| list->dup_map[j][i - 1] == list->direction
		|| list->dup_map[j - 1][i] == list->direction))
		exit(printf("Error: Invalid space found at (%d,%d)\n", j, i));
	if ((list->dup_map[j][i] == list->direction
		&& j < list->high_map - 1 && j != 0)
		&& (list->dup_map[j - 1][i] == '-' || list->dup_map[j + 1][i] == '-'
		|| list->dup_map[j - 1][i] == '_'
		|| list->dup_map[j + 1][i] == '_'))
		exit(printf("Error: Invalid Player Position !!\n"));
}

void	check_space_inside(t_listt *list)
{
	int	i;
	int	j;

	j = 0;
	while (list->dup_map[j])
	{
		i = 1;
		while (list->dup_map[j][i])
		{
			if ((list->dup_map[j][i] == '-' && j < list->high_map - 1 && j != 0)
			&& (list->dup_map[j][i + 1] == '0' || list->dup_map[j][i - 1] == '0'
			|| list->dup_map[j - 1][i] == '0' || list->dup_map[j + 1][i] == '0'
			|| list->dup_map[j][i + 1] == list->direction
			|| list->dup_map[j][i - 1] == list->direction
			|| list->dup_map[j - 1][i] == list->direction
			|| list->dup_map[j + 1][i] == list->direction))
				exit(printf("Error: Invalid space found attt (%d,%d)\n", j, i));
			part_2(list, i, j);
		i++;
		}
		j++;
	}
}
