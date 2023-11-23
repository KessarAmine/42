/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_others1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:39:42 by anoury            #+#    #+#             */
/*   Updated: 2023/07/21 21:21:57 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils_others.h"
/*takes an angle in radian as input to be converted to deg 
multiplied by 180 and devided of the value of mpi*/
double	rad_to_deg(double rad)
{
	return (rad * 180.0 / M_PI);
}

/*takes an angle in deg as input to be converted to rad
multiplied by 180 and devided of the value of mpi*/
double	deg_to_rad(double deg)
{
	return (deg * M_PI / 180.0);
}

/*normalizes an angle in radians to a value
between 0 and 2π (or 0 and 360 degrees). 
It first calculates the value of a full circle in radians by 
calling deg_to_rad(360). 
Then, it uses the fmod function to calculate the remainder 
of radian divided 
by the value of full_circle. If the resulting remainder is negative, 
it adds the value of full_circle to make it positive. 
The function returns the normalized radian value.*/
void	ray_startup(t_ray *ray, t_ray *sub_ray)
{
	double	full_circle;

	sub_ray->size = 0;
	if (ray->angle == deg_to_rad(180) || ray->angle == deg_to_rad(360))
	{
		sub_ray->size = INT_MAX;
		return ;
	}
	full_circle = deg_to_rad(360);
	sub_ray->angle = fmod(ray->angle, full_circle);
	if (sub_ray->angle < 0)
		sub_ray->angle += full_circle;
}

/*creating ARGB color values.*/
int	create_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}
