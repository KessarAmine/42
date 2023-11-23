/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:32:45 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 22:24:57 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_WALLS_H
# define RENDER_WALLS_H

# include "cub3d.h"

t_texture	get_wall_texture(t_viewport *view_port, char orientation);
void		render_wall_strip(t_rect *rect, int *img,
				t_viewport *view_port, t_ray *ray);
int			get_offset(t_ray *ray, int width);
int			get_wall(t_env *game, t_ray *ray, t_rect *rect);
double		adjust_fisheye(t_env *game, t_ray *ray);
#endif
