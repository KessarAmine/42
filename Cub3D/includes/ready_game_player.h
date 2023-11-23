/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_player.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:51 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/20 03:55:51 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_PLAYER_H
# define READY_GAME_PLAYER_H

# include "cub3d.h"

void		get_starting_position(t_player *player, char **grid);
double		get_starting_orientation(char orientation);

#endif
