/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:53:22 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 14:36:00 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include "structs.h"
# include "constants.h"
# include "utils_mem.h"
# include "utils_others.h"
# include "utils_graph.h"
# include "utils_rays.h"
# include "lib.h"

void	ft_bridge(t_viewport *view_port, t_listt *list);
void	render_game(t_env *game);

#endif
