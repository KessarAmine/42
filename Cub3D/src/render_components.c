/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_components.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:32:06 by anoury            #+#    #+#             */
/*   Updated: 2023/07/22 00:39:42 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render_components.h"
/*drawing the entire game view_port, 
including the ceiling, floor, and walls*/
/*handle drawing the ceiling and floor areas respectively, 
by initializing and configuring rectangle structures 
and calling the put_component function to draw 
the rectangles onto the game's image buffer.*/
void	render_components(t_env *game)
{
	t_rect	rect_roof;
	t_rect	rect_floor;

	init_rect(&rect_roof, game);
	init_rect(&rect_floor, game);
	rect_roof.fill_color = game->view_port.view_port_text.ceilling_color;
	rect_floor.fill_color = game->view_port.view_port_text.floor_color;
	rect_floor.cmp_cords.y = game->view_port.height / 2;
	put_component(&rect_roof, game->mlx.img.data, game->view_port.width);
	put_component(&rect_floor, game->mlx.img.data, game->view_port.width);
	render_walls(game);
}

void	init_rect(t_rect *rect, t_env *game)
{
	ft_memset(rect, 0, sizeof(t_rect));
	rect->dimension.width = game->view_port.width;
	rect->dimension.height = game->view_port.height / 2;
}
