/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_events.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:32 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 14:36:00 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_EVENTS_H
# define READY_GAME_EVENTS_H

# include "cub3d.h"

int	key_pressed(int keycode, t_env *game);
int	key_released(int keycode, t_env *game);
int	close_window_cross(int keycode, t_env *game);

#endif
