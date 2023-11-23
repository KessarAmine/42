/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:53:55 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"
#include "../lib/libft/libft.h"

void	check_0_around(t_listt *list)
{
	int	i;
	int	j;

	j = 1;
	while (list->dup_map[j])
	{
		i = 0;
		while (list->dup_map[j][i])
		{
			if (list->dup_map[j][i] == '0'
			&& (list->dup_map[j][i + 1] == '\0'
			|| list->dup_map[j - 1][i] == '-'
			|| list->dup_map[j - 1][i] == '_'
			|| list->dup_map[j + 1][i] == '_'
			|| list->dup_map[j + 1][i] == '-'))
				exit(printf("Error: Invalid 0 around at (%d,%d)\n", j, i));
			i++;
		}
		j++;
	}
}

void	check_colorr(char *str)
{
	int	i;

	i = 0;
	if (str[i] < '0' || str[i] > '9')
		exit(printf("Error: RGB structure Invalid.\n"));
	while (str[i])
	{
		if ((str[i] != ',' && str[i] > '9' && str[i] < '0')
			|| (str[i] == ',' && str[i + 1] == ',')
			|| (str[i] == ',' && !str[i + 1]))
			exit(printf("Error: RGB structure Invalid\n"));
		i++;
	}
}

void	check_tokens(t_listt *list)
{
	int	i;
	int	j;
	int	length;

	j = 0;
	list->high_map = 0;
	while (list->map[j])
	{
		i = 0;
		length = find_f_space(list->map[j]);
		while (list->map[j][i] == ' ')
				i++;
		while (list->map[j][i])
		{
			if (list->map[j][i] != 'N' && list->map[j][i] != 'S'
			&& list->map[j][i] != 'E' && list->map[j][i] != 'W'
			&& list->map[j][i] != '0' && list->map[j][i] != '1'
			&& i < length && list->map[j][i] != ' ')
				exit(printf("Error:There Are Invalides Tokens in Map. -> |%c|\n",
						list->map[j][i]));
		i++;
		}
	j++;
	}
	list->high_map = j;
}

void	check_text_extension(char *str)
{
	int	length;

	length = ft_strlen(str);
	if (str[length] == '\0' && str[length - 1] == 'm'
		&& str[length - 2] == 'p'
		&& str[length - 3] == 'x'
		&& str[length - 4] == '.')
		return ;
	exit (printf("Error : Extension Invalid ! -> Use Extension '.xpm'\n"));
}
