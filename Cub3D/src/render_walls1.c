/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:32:28 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 22:41:43 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render_walls.h"

/* iterates over the game's resolution width 
and uses the other functions to calculate wall 
height, position, and texture for each column*/
void	render_walls(t_env *game)
{
	int		i;
	t_rect	rect;
	t_ray	*ray;

	i = -1;
	while (++i < game->view_port.width)
	{
		ray = &game->rays.arr[i];
		rect.cmp_cords.x = i;
		rect.cmp_cords.y = get_wall(game, ray, &rect);
		rect.tex = get_wall_texture(&game->view_port, ray->orientation);
		render_wall_strip(&rect, game->mlx.img.data, &game->view_port, ray);
	}
}

/*provide the necessary calculations 
and retrieve relevant information 
to facilitate the drawing of wall strips.*/
t_texture	get_wall_texture(t_viewport *view_port, char orientation)
{
	if (orientation == 'N')
		return (view_port->view_port_text.north);
	else if (orientation == 'S')
		return (view_port->view_port_text.south);
	else if (orientation == 'E')
		return (view_port->view_port_text.east);
	else
		return (view_port->view_port_text.west);
}

// Calculate the x-component of the adjusted ray angle
// fisheye_adjustment we have readjust the angle by getting
//half pixel by half and apply cos cuz it is the rays relative to the center
int	get_wall(t_env *game, t_ray *ray, t_rect *rect)
{
	double	wall_height;
	double	scaled_distance;
	double	fisheye_adjustment;
	double	center_screen;
	double	center_wall;

	fisheye_adjustment = cos(ray->angle
			- game->player.player_config.rotation_angle
			+ (1.0 / game->view_port.width) * 0.5);
	scaled_distance = ray->size * SCALE * fisheye_adjustment;
	wall_height = (SCALE / (scaled_distance)) * game->rays.eucledian_dist;
	rect->dimension.height = wall_height;
	center_screen = game->view_port.height / 2;
	center_wall = wall_height / 2;
	if (center_screen - center_wall < 0)
		return (0);
	return (center_screen - center_wall);
}

// Calculate the y-component of the adjusted ray angle
// Calculate the fisheye_adjustment using the adjusted ray angle
double	adjust_fisheye(t_env *game, t_ray *ray)
{
	double	adjusted_ray_x;
	double	adjusted_ray_y;

	adjusted_ray_x = cos(ray->angle) * game->player.player_config.rotation_cos
		- sin(ray->angle) * game->player.player_config.rotation_sin;
	adjusted_ray_y = sin(ray->angle) * game->player.player_config.rotation_cos
		+ cos(ray->angle) * game->player.player_config.rotation_sin;
	return (cos(atan2(adjusted_ray_y, adjusted_ray_x)
			- game->player.player_config.rotation_angle));
}
