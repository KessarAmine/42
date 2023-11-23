/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:22:53 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:21:06 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/raycaster.h"

void	raycaster(t_ray *ray, t_map *map, t_player *player)
{
	t_ray	ray_h;
	t_ray	ray_v;

	ray_startup(ray, &ray_h);
	ray_startup(ray, &ray_v);
	raycaster_v(&ray_v, map, player);
	*ray = ray_v;
	raycaster_h(&ray_h, map, player);
	if (ray_h.size < ray_v.size)
		*ray = ray_h;
}
