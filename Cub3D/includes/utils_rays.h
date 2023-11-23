/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rays.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:30:32 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 15:46:10 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RAYS_H
# define UTILS_RAYS_H

# include "cub3d.h"

int		is_wall(t_map *map, double x, double y, t_ray *ray);
char	get_wall_orientation(t_map *map, int x, int y, t_ray *ray);
int		is_south(double angle);
int		is_west(double angle);
#endif
