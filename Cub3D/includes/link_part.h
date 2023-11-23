/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_part.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:17 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 14:33:58 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINK_PART_H
# define LINK_PART_H

# include "cub3d.h"
# include "lib.h"

void	get_texture(t_viewport *view_port, t_listt *list);
void	get_color(t_viewport *view_port, t_listt *list);
void	get_map(t_map *map, t_listt *list);

#endif
