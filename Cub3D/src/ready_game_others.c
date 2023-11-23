/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_game_others.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:36 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ready_game_others.h"

void	ready_game_others(t_env *game)
{
	set_rays(game);
	load_texture(game->mlx.mlx_ptr, &game->view_port.view_port_text.north);
	load_texture(game->mlx.mlx_ptr, &game->view_port.view_port_text.south);
	load_texture(game->mlx.mlx_ptr, &game->view_port.view_port_text.west);
	load_texture(game->mlx.mlx_ptr, &game->view_port.view_port_text.east);
}

void	set_rays(t_env *game)
{
	game->rays.arr = malloc(game->view_port.width * sizeof(t_ray));
	if (!game->rays.arr)
		exit(EXIT_SUCCESS);
	game->player.player_config.view_angle = deg_to_rad(VIEW_ANGLE);
	game->rays.eucledian_dist = (game->view_port.width / 2)
		/ tan(game->player.player_config.view_angle / 2);
}

void	load_texture(void *mlx, t_texture *texture)
{
	if (mlx_xpm_file_to_image(mlx, texture->path,
			&texture->dim.width, &texture->dim.height) == 0)
		exit(printf("Error : Texture -> \"%s\" Is Invalid!\n", texture->path));
	texture->img.img_ptr = mlx_xpm_file_to_image(mlx, texture->path,
			&texture->dim.width, &texture->dim.height);
	texture->img.data = (int *)mlx_get_data_addr(texture->img.img_ptr,
			&texture->img.bpp,
			&texture->img.size_l,
			&texture->img.endian);
}
