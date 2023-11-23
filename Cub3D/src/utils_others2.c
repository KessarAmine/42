/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:15:50 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_others.h"

/*verifies if a map file name has the expected ".cub" extension. 
If the extension is valid, it returns without any action. 
Otherwise, it prints an error message and terminates the program.*/
void	check_valid_map(t_env *game)
{
	int	length;

	length = ft_strlen(game->map_name);
	if (game->map_name[length] == '\0' && game->map_name[length - 1] == 'b'
		&& game->map_name[length - 2] == 'u'
		&& game->map_name[length - 3] == 'c'
		&& game->map_name[length - 4] == '.')
		return ;
	else
		exit (printf("Error : Extension Invalid ! -> Use Extension '.cub'\n"));
}
