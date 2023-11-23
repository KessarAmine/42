/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_components.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:31:54 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 21:51:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_COMPONENTS_H
# define RENDER_COMPONENTS_H

# include "cub3d.h"

void	render_walls(t_env *game);
void	init_rect(t_rect *rect, t_env *game);

#endif
