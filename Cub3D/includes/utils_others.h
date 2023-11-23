/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:29:26 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 17:20:34 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_OTHERS_H
# define UTILS_OTHERS_H

# include "cub3d.h"

double	rad_to_deg(double rad);
double	deg_to_rad(double deg);
void	ray_startup(t_ray *ray, t_ray *sub_ray);
int		create_argb(int a, int r, int g, int b);
void	check_valid_map(t_env *game);
double	get_eucledian_distance(double x, double y);
#endif
