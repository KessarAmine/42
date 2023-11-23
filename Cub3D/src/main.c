/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:53:16 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/lib.h"

int	main(int argc, char *argv[])
{
	t_env	game;
	t_listt	list;

	if (argc == 2)
	{
		list.map_name = argv[1];
		game.map_name = list.map_name;
		parsing_part(&list);
		ft_bridge(&game.view_port, &list);
		render_game(&game);
	}
	else
		printf("Arguments Invalides\n");
	return (0);
}
