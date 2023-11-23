/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:22:35 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/22 01:33:01 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"

void	raycaster_v(t_ray *ray, t_map *map, t_player *player)
{
	ray->side = 'V';
	if (!is_west(ray->angle))
		raycaster_v_east(ray, map, player);
	else
		raycaster_v_west(ray, map, player);
}

void	raycaster_v_west(t_ray *ray, t_map *map, t_player *player)
{
	t_coord	destination;
	t_coord	step;
	double	ray_section;

	destination.x = floor(player->x);
	step.x = player->x - destination.x;
	step.y = step.x * tan(ray->angle);
	destination.y = player->y - step.y;
	ray->size += get_eucledian_distance(step.x, step.y);
	if (is_wall(map, destination.x - 1, destination.y, ray))
		return ;
	step.x = -1;
	step.y = step.x * tan(ray->angle);
	ray_section = get_eucledian_distance(step.x, step.y);
	while (!is_wall(map, destination.x - 1, destination.y, ray))
	{
		destination.x += step.x;
		destination.y += step.y;
		ray->size += ray_section;
	}
}

void	raycaster_v_east(t_ray *ray, t_map *map, t_player *player)
{
	t_coord	destination;
	t_coord	step;
	double	ray_section;

	destination.x = ceil(player->x);
	step.x = destination.x - player->x;
	step.y = step.x * tan(ray->angle);
	destination.y = player->y + step.y;
	ray->size += get_eucledian_distance(step.x, step.y);
	if (is_wall(map, destination.x, destination.y, ray))
		return ;
	step.x = 1;
	step.y = step.x * tan(ray->angle);
	ray_section = get_eucledian_distance(step.x, step.y);
	while (!is_wall(map, destination.x, destination.y, ray))
	{
		destination.x += step.x;
		destination.y += step.y;
		ray->size += ray_section;
	}
}
