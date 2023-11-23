/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:29:09 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 14:36:00 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MEM_H
# define UTILS_MEM_H

# include "cub3d.h"

void	free_game(t_env *game);
void	free_view_port(t_viewport *view_port);

#endif
