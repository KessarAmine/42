/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:35:31 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 21:41:04 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_GAME_H
# define RENDER_GAME_H

# include "cub3d.h"

void	ready_game(t_env *game);
void	update(t_env *game);
void	render_components(t_env *game);
void	render_game(t_env *game);
int		render_next_frame(void *my_struct);

#endif
