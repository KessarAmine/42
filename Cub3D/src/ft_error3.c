/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:54:40 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"
#include "../lib/libft/libft.h"

void	get_high_file(t_listt *list)
{
	int	j;
	int	i;

	j = 0;
	list->high_file = 0;
	list->first_map = 0;
	while (list->global[j])
		j++;
	list->high_file = j;
	j = 0;
	while (list->global[j])
	{
		i = 0;
		while (list->global[j][i] == ' ')
			i++;
		if (list->global[j][i] == '1')
		{
			list->first_map = j;
			return ;
		}		
		j++;
	}
}

void	errors(t_listt *list)
{
	int		j;
	int		count;
	char	**p;
	char	*s_1;

	j = 0;
	count = 0;
	while (list->global[j] && j < 6)
	{
		p = ft_splitt(list->global[j], ' ');
		if (p[2] || !p[1])
			exit(printf("Error: Textures or Colors Invalidess.\n"));
		s_1 = remove_space(p[0]);
		if (ft_strcmp(s_1, "F") && ft_strcmp(s_1, "C") && ft_strcmp(s_1, "NO")
			&& ft_strcmp(s_1, "SO") && ft_strcmp(s_1, "WE")
			&& ft_strcmp(s_1, "EA"))
			exit(printf("Error: Textures or Colors Invalides formats.\n"));
		free(s_1);
		ft_khwi(2, p);
	j++;
	}
}

void	parsing_part(t_listt *list)
{
	check_valid_maps(list);
	fil_globales(list);
	get_high_file(list);
	remove_empty_lines(list->global, list->first_map + 1, list, 0);
	errors(list);
	find_map(list);
	find_text(list, 0);
	find_color(list);
	check_text_path(list);
	check_tokens(list);
	check_direction(list);
	check_wall(list);
	get_long_line(list);
	copy_map(list);
	check_space_inside(list);
	check_ligne_map(list);
	check_0_around(list);
}

void	copy_map(t_listt *list)
{
	int	j;
	int	i;

	list->dup_map = (char **)ft_callocc(sizeof(char *), list->high_map + 1);
	j = 0;
	while (list->map[j])
	{
		list->dup_map[j] = (char *)ft_callocc(list->long_line + 1, 1);
		i = 0;
		while (list->map[j][i])
		{
			if (list->map[j][i] == ' ')
				list->dup_map[j][i] = '-';
			else
				list->dup_map[j][i] = list->map[j][i];
			i++;
		}
		while (i < list->long_line)
		{
			list->dup_map[j][i] = '_';
			i++;
		}
	j++;
	}
}
