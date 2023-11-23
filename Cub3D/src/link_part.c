/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:13 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 23:13:18 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/link_part.h"
#include "../lib/libft/libft.h"

void	ft_bridge(t_viewport *view_port, t_listt *list)
{
	ft_memset(view_port, 0, sizeof(t_viewport));
	ft_memset(&view_port->view_port_text.ceilling_color, -1, sizeof(int));
	ft_memset(&view_port->view_port_text.floor_color, -1, sizeof(int));
	view_port->height = SCREEN_HEIGHT;
	view_port->width = SCREEN_WIDTH;
	get_texture(view_port, list);
	get_color(view_port, list);
	get_map(&view_port->map, list);
}

void	get_texture(t_viewport *view_port, t_listt *list)
{
	view_port->view_port_text.north.path = list->north_path;
	view_port->view_port_text.south.path = list->south_path;
	view_port->view_port_text.west.path = list->west_path;
	view_port->view_port_text.east.path = list->east_path;
}

void	get_color(t_viewport *view_port, t_listt *list)
{	
	view_port->view_port_text.floor_color
		= create_argb(0, list->floor_color->red,
			list->floor_color->green, list->floor_color->blue);
	view_port->view_port_text.ceilling_color
		= create_argb(0, list->cieling_color->red,
			list->cieling_color->green, list->cieling_color->blue);
}

void	get_map(t_map *map, t_listt *list)
{
	map->grid = list->map;
	map->dim.height = list->high_map;
	map->dim.width = list->long_line;
}
