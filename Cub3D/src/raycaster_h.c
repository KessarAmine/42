/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_h_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:27:30 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 18:06:19 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"

// we first make sure that the 
// backwards rays do not get in the intersections (180/360)
// horizon we check the angle if it is facing north or south
void	raycaster_h(t_ray *ray, t_map *map, t_player *player)
{
	ray->side = 'H';
	if (!is_south(ray->angle))
		raycaster_h_north(ray, map, player);
	else
		raycaster_h_south(ray, map, player);
}

// "ceiling" and is used to round a floating-point number up 
// to the nearest integer greater than or equal to the original value.
// 
void	raycaster_h_south(t_ray *ray, t_map *map, t_player *player)
{
	t_coord	destination;
	t_coord	step;
	double	ray_section;

	destination.y = ceil(player->y);
	step.y = destination.y - player->y;
	step.x = step.y / tan(ray->angle);
	destination.x = player->x + step.x;
	ray->size += get_eucledian_distance(step.x, step.y);
	if (is_wall(map, destination.x, destination.y, ray))
		return ;
	step.y = 1;
	step.x = step.y / tan(ray->angle);
	ray_section = get_eucledian_distance(step.x, step.y);
	while (!is_wall(map, destination.x, destination.y, ray))
	{
		destination.x += step.x;
		destination.y += step.y;
		ray->size += ray_section;
	}
}

// destination.y is the current H destination at that position
// destination_x is the current V destination at that position
void	raycaster_h_north(t_ray *ray, t_map *map, t_player *player)
{
	t_coord	destination;
	t_coord	step;
	double	ray_section;

	destination.y = floor(player->y);
	step.y = player->y - destination.y;
	step.x = step.y / tan(ray->angle);
	destination.x = player->x - step.x;
	ray->size += get_eucledian_distance(step.x, step.y);
	if (is_wall(map, destination.x, destination.y - 1, ray))
		return ;
	step.y = -1;
	step.x = +step.y / tan(ray->angle);
	ray_section = get_eucledian_distance(step.x, step.y);
	while (!is_wall(map, destination.x, destination.y - 1, ray))
	{
		destination.x += step.x;
		destination.y += step.y;
		ray->size += ray_section;
	}
}
