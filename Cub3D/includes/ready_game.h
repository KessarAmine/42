/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:56:00 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 14:36:00 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READY_GAME_H
# define READY_GAME_H

# include "cub3d.h"

void	ready_game_player(t_env *game);
void	ready_game_events(t_env *game);
void	ready_game_others(t_env *game);

#endif
