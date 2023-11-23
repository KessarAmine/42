/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:56:15 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:15:53 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_H
# define UPDATE_H

# include "cub3d.h"

void	update_player_position(t_player *player, char **grid);
void	update_player_orientation(t_player *player);
void	update_rays(t_env *game);
void	raycaster(t_ray *ray, t_map *map, t_player *player);

#endif
