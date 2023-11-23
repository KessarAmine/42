/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 15:32:17 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 21:50:44 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/render_walls.h"
/*function takes a rectangle structure (t_rect)
representing a wall strip, along with the game's
image buffer, resolution, and the corresponding ray.
It maps the wall texture onto the wall strip
by calculating texture positions and offsets
and assigns the corresponding texture color
to each pixel in the wall strip within the image buffer*/

/* explanation:
variables:
y_tex and x_tex(offset) : corridantes to map the correct textel to to pixel.
step_img_start = [step, start_position]
1- The step is calculated to how much we move vertically (in  texture)
for each step along the wall's height. This step ensures that the
texture is appropriately scaled to fit the height of the wall strip.

2- the tex_pox wich represent the current position on the texture on the 
view_port
aka ((double)rect->y - (view_port->height - rect->height) / 2):
This part calculates the relative position of the current
pixel within the entire view_port and centers the wall strip
vertically on the screen. It subtracts half of the difference
between the view_port height and the strip height from the y-coordinate.
By dividing this difference by 2 and subtracting it from the y-coordinate,
the strip is centered vertically on the screen.

3- based on the ray's side we get the tex_offset
4- we iterate pixel by pixel through the height of the wall strip
an edge case the view_port height will be less then the wall strip if
the player is touching the wall strip so we have the stop candition
(y < rect->height && y < view_port->height)
5- y_tex has the remainder of the current position in the texture and the 
texture height fmod(modulo) ensures that the value wraps around if 
it exceeds the height of the texture.
6- map the corresponding texel from the texture 
onto the current pixel of the wall strip.
7- update the current position in the texture b y the step
8- move to the next pixel
*/

// Calculate the starting position in the img array
// Access the texel data and apply it directly to the img array
// Move to the next row in the img array
void	render_wall_strip(t_rect *rect, int *img,
		t_viewport *view_port, t_ray *ray)
{
	int		y;
	int		y_tex;
	int		tex_offset;
	double	step_img_start[2];
	double	tex_pox;

	step_img_start[0] = (float)rect->tex.dim.height / rect->dimension.height;
	tex_pox = ((double)rect->cmp_cords.y
			- (view_port->height - rect->dimension.height) / 2)
		* step_img_start[0];
	tex_offset = get_offset(ray, rect->tex.dim.width);
	step_img_start[1] = (rect->cmp_cords.y
			* view_port->width) + rect->cmp_cords.x;
	y = 0;
	while (y < rect->dimension.height && y < view_port->height)
	{
		y_tex = (int)fmod(tex_pox, rect->tex.dim.height);
		img[(int) step_img_start[1]]
			= rect->tex.img.data[y_tex * rect->tex.dim.width + tex_offset];
		tex_pox += step_img_start[0];
		step_img_start[1] += view_port->width;
		y++;
	}
}

/* calculates the x-coordinate offset for texture 
mapping based on the ray's side 
and the width of the wall texture.*/

/*
double remainder: 
This variable will store the fractional part of the ray's x-coordinate 
or y-coordinate, depending on the ray's side (horizontal or vertical).
int offset:
This variable will represent the calculated x-coordinate offset 
for texture mapping.*/

/* execution explanation:
If the ray's side (ray->side == 'H'), 
it means it intersects the wall along the x-axis. 
so the remainder is fractional part of (ray->x).
If  (ray->side == 'V'), it means the remainder is fmod(ray->y).
and then to get the offset :
we do width * fractional_part
example : ray is hitting a horizontal wall aka ray->side = H
Ray's x-coordinate: 2.75
fmod(ray->x, 1.0) aka remainder : 0.75
Offset in the texture: 75 (if width = 100)
*/
int	get_offset(t_ray *ray, int width)
{
	double	remainder;
	int		offset;

	if (ray->side == 'H')
		remainder = fmod(ray->cords.x, 1.0);
	else
		remainder = fmod(ray->cords.y, 1.0);
	offset = width * remainder;
	return (offset);
}
