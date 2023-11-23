/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:54:19 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"
#include "../lib/libft/libft.h"

void	find_text(t_listt *list, int j)
{
	char	**p;
	char	*s_1;

	while (list->global[j] && j < 6)
	{
		p = ft_splitt(list->global[j], ' ');
		if (!p[0])
			exit(printf("Error : something Wrong in file.cub\n"));
		s_1 = remove_space(p[0]);
		if (!ft_strcmp(s_1, "NO"))
			list->north_path = ft_strdup(p[1]);
		else if (!ft_strcmp(s_1, "SO"))
			list->south_path = ft_strdup(p[1]);
		else if (!ft_strcmp(s_1, "WE"))
			list->west_path = ft_strdup(p[1]);
		else if (!ft_strcmp(s_1, "EA"))
			list->east_path = ft_strdup(p[1]);
		j++;
		free(s_1);
		ft_khwi(2, p);
	}
	if (!list->south_path || !list->north_path || !list->east_path
		|| !list->west_path)
		exit(printf("Error : some texture Missing !!\n"));
}

void	find_map(t_listt *list)
{
	list->map = &list->global[6];
}

char	*remove_space(char *str)
{
	char	*new;

	new = ft_strdup(str);
	while (*new == ' ')
		new++;
	return (new);
}

void	find_color(t_listt *list )
{
	int		j;
	char	**p;
	char	**s;
	char	*s_1;

	j = 0;
	s = NULL;
	list->floor_color = malloc(sizeof(t_colorr));
	list->cieling_color = malloc(sizeof(t_colorr));
	while (list->global[j] && j < 6)
	{
		p = ft_splitt(list->global[j], ' ');
		if (!p[0])
			exit(printf("Error : something Wrong in file.cub\n%s",
					list->global[j]));
		s_1 = remove_space(p[0]);
		compare_color(s_1, s, p, list);
		j++;
		ft_khwi(2, p);
		free(s_1);
	}
}

void	compare_color(char *s_1, char **s, char **p, t_listt *list)
{
	if (!ft_strcmp(s_1, "F") || !ft_strcmp(s_1, "C"))
	{
		check_colorr(p[1]);
		s = ft_splitt(p[1], ',');
		if (!s[0] || !s[1] || !s[2] || s[3])
			exit(printf("Colors Invalides\n"));
		if (!ft_strcmp(s_1, "F"))
		{
			list->floor_color->red = ft_atoi(s[0]);
			list->floor_color->green = ft_atoi(s[1]);
			list->floor_color->blue = ft_atoi(s[2]);
		}
		else
		{
			list->cieling_color->red = ft_atoi(s[0]);
			list->cieling_color->green = ft_atoi(s[1]);
			list->cieling_color->blue = ft_atoi(s[2]);
		}
		ft_khwi(3, s);
	}
}
