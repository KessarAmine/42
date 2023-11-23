/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:19:12 by anoury            #+#    #+#             */
/*   Updated: 2023/07/22 01:49:04 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_rays.h"
/*checks if a given position in the map grid is a wall 
and updates the ray structure accordingly*/
int	is_wall(t_map *map, double x, double y, t_ray *ray)
{
	ray->cords.x = x;
	ray->cords.y = y;
	if ((int)x < 0 || map->dim.width < (int)x
		|| (int)y < 0 || map->dim.height < (int)y)
	{
		ray->size = INT_MAX;
		return (1);
	}
	if (map->dim.height == (int)y)
	{
		ray->obstacle = '1';
		ray->orientation = 'N';
		return (1);
	}
	ray->obstacle = map->grid[(int)y][(int)x];
	if (ray->obstacle == '1')
	{
		ray->orientation = get_wall_orientation(map, (int)x, (int)y, ray);
		return (1);
	}
	return (0);
}

/*determines the orientation of a wall based on its position 
and the ray structure's side and angle*/
char	get_wall_orientation(t_map *map, int x, int y, t_ray *ray)
{
	if (x == 0)
		return ('E');
	else if (x == map->dim.width)
		return ('W');
	else if (y == 0)
		return ('S');
	else if (y == map->dim.height - 1)
		return ('N');
	if (map->grid[y - 1][x] != '1'
		&& (ray->angle >= 0 && ray->angle < M_PI) && ray->side == 'H')
		return ('N');
	if (map->grid[y + 1][x] != '1'
		&& !(ray->angle >= 0 && ray->angle < M_PI) && ray->side == 'H')
		return ('S');
	if (map->grid[y][x - 1] != '1'
		&& !(ray->angle >= M_PI / 2 && ray->angle < M_PI * 1.5)
		&& ray->side == 'V')
		return ('W');
	if (map->grid[y][x + 1] != '1'
		&& (ray->angle >= M_PI / 2 && ray->angle < M_PI * 1.5)
		&& ray->side == 'V')
		return ('E');
	return (0);
}

// player is on top of the PI cercle or below
int	is_south(double angle)
{
	if (angle >= 0 && angle < M_PI)
		return (1);
	else
		return (0);
}

// player is on left of the PI cercle or right
int	is_west(double angle)
{
	if (angle >= M_PI / 2 && angle < M_PI * 1.5)
		return (1);
	else
		return (0);
}

double	get_eucledian_distance(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}
