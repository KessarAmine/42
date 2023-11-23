/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:39:35 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_mem.h"

/* function frees the memory allocated for the game 
and its associated resources, including 
the view_port and an array of rays.*/
void	free_game(t_env *game)
{
	free_view_port(&game->view_port);
	free(game->rays.arr);
}

/*function specifically frees the memory 
allocated for the view_port's textures' paths.*/
void	free_view_port(t_viewport *view_port)
{
	free(view_port->view_port_text.north.path);
	free(view_port->view_port_text.south.path);
	free(view_port->view_port_text.west.path);
	free(view_port->view_port_text.east.path);
}
