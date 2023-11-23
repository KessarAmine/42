/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:47 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 22:19:39 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ready_game_player.h"

void	ready_game_player(t_env *game)
{
	game->player.walk_direction = 0;
	game->player.player_config.move_speed = 0.15;
	game->player.turn_direction = 0;
	game->player.player_config.rotation_speed = deg_to_rad(4);
	get_starting_position(&game->player, game->view_port.map.grid);
}

void	get_starting_position(t_player *player, char **grid)
{
	int	i;
	int	j;

	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (ft_strchr("NSEW", grid[i][j]))
			{
				player->x = j + 0.5;
				player->y = i + 0.5;
				player->player_config.rotation_angle
					= get_starting_orientation(grid[i][j]);
				player->player_config.rotation_cos
					= cos(player->player_config.rotation_angle);
				player->player_config.rotation_sin
					= sin(player->player_config.rotation_angle);
				grid[i][j] = '0';
			}
		}
	}
}

double	get_starting_orientation(char orientation)
{
	double	radian;

	radian = 0;
	if (orientation == 'N')
		radian = deg_to_rad(270);
	else if (orientation == 'S')
		radian = deg_to_rad(90);
	else if (orientation == 'E')
		radian = deg_to_rad(360);
	else if (orientation == 'W')
		radian = deg_to_rad(180);
	return (radian);
}
