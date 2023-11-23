/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:30:53 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 23:13:34 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render_game.h"
/* initializing the game window and starting the rendering loop.*/
void	render_game(t_env *game)
{
	game->mlx.mlx_ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx_ptr,
			game->view_port.width,
			game->view_port.height,
			"Cub3d");
	ready_game(game);
	mlx_loop_hook(game->mlx.mlx_ptr, render_next_frame, game);
	mlx_loop(game->mlx.mlx_ptr);
}

/*the callback function that is repeatedly called by 
the MLX loop in the rendering process*
-it creates images */
int	render_next_frame(void *my_struct)
{
	t_env	*game;

	game = my_struct;
	game->mlx.img.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
			game->view_port.width,
			game->view_port.height);
	game->mlx.img.data = (int *)mlx_get_data_addr(game->mlx.img.img_ptr,
			&game->mlx.img.bpp,
			&game->mlx.img.size_l,
			&game->mlx.img.endian);
	update(game);
	render_components(game);
	mlx_put_image_to_window(game->mlx.mlx_ptr,
		game->mlx.win, game->mlx.img.img_ptr, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->mlx.img.img_ptr);
	return (1);
}
