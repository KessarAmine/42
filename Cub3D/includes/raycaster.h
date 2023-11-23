/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:52:54 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:51:37 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "cub3d.h"

void	raycaster_h(t_ray *ray, t_map *map, t_player *player);
void	raycaster_h_south(t_ray *ray, t_map *map, t_player *player);
void	raycaster_h_north(t_ray *ray, t_map *map, t_player *player);

void	raycaster_v(t_ray *ray, t_map *map, t_player *player);
void	raycaster_v_east(t_ray *ray, t_map *map, t_player *player);
void	raycaster_v_west(t_ray *ray, t_map *map, t_player *player);

#endif
