/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:56:11 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:08:09 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/update.h"

void	update(t_env *game)
{
	update_player_position(&game->player, game->view_port.map.grid);
	update_player_orientation(&game->player);
	update_rays(game);
}

void	update_player_position(t_player *player, char **grid)
{
	double	move_step;
	double	rotation;

	if (player->walk_direction == 0)
		return ;
	move_step = player->player_config.move_speed;
	rotation = player->player_config.rotation_angle;
	if (player->walk_direction == 's' || player->walk_direction == 'a')
		move_step = (-1) * player->player_config.move_speed;
	if (player->walk_direction == 'a')
		rotation = player->player_config.rotation_angle + deg_to_rad(90);
	else if (player->walk_direction == 'd')
		rotation = player->player_config.rotation_angle + deg_to_rad(90);
	player->x += cos(rotation) * move_step;
	player->y += sin(rotation) * move_step;
	if (ft_strchr("1", grid[(int)player->y][(int)player->x])
		|| ft_strchr("1", grid[(int)floor(player->y -
			(sin(rotation) * move_step))][(int)player->x])
		|| ft_strchr("1", grid[(int)player->y][(int)floor(player->x
			- (cos(rotation) * move_step))]))
	{
		player->x -= cos(rotation) * move_step;
		player->y -= sin(rotation) * move_step;
	}
}

void	update_player_orientation(t_player *player)
{
	double	rotation;

	if (player->turn_direction == 0)
		return ;
	rotation = player->turn_direction * player->player_config.rotation_speed;
	player->player_config.rotation_angle += rotation;
}

void	update_rays(t_env *game)
{
	double	ray_angle;
	int		i;

	ray_angle = game->player.player_config.rotation_angle
		- game->player.player_config.view_angle / 2;
	i = -1;
	while (++i < game->view_port.width)
	{
		game->rays.arr[i].angle = ray_angle;
		raycaster(&game->rays.arr[i], &game->view_port.map, &game->player);
		ray_angle += game->player.player_config.view_angle
			/ game->view_port.width;
	}
}
