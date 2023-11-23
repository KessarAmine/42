/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:56 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ready_game.h"

void	ready_game(t_env *game)
{
	ready_game_player(game);
	ready_game_events(game);
	ready_game_others(game);
}
