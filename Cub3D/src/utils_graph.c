/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:28:42 by anoury            #+#    #+#             */
/*   Updated: 2023/07/22 00:39:42 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_graph.h"
/*used to draw a rectangle on an image buffer
it  takes a rectangle structure (t_rect), 
an image buffer (img), and the width of the image (res_width) 
as inputs. It iterates over the pixels within the rectangle 
and assigns the appropriate color values to each pixel 
in the image buffer to draw the rectangle, 
considering the border and fill colors specified in the t_rect structure.*/

void	put_component(t_rect *rect, int *img, int res_width)
{
	int	i;
	int	j;
	int	tmp_x;
	int	tmp_y;

	rect->border_width--;
	i = -1;
	while (++i < rect->dimension.height)
	{
		j = -1;
		while (++j < rect->dimension.width)
		{
			tmp_x = rect->cmp_cords.x + j;
			tmp_y = rect->cmp_cords.y + i;
			if (i <= rect->border_width || j <= rect->border_width
				|| i >= rect->dimension.height - 1 - rect->border_width
				|| j >= rect->dimension.width - 1 - rect->border_width)
				img[tmp_y * res_width + tmp_x] = rect->border_color;
			else
				img[tmp_y * res_width + tmp_x] = rect->fill_color;
		}
	}
}
