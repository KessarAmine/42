/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:22:21 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 22:18:21 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct s_dim
{
	int			width;
	int			height;
}				t_dim;

typedef struct s_texture
{
	char		*path;
	t_img		img;
	t_dim		dim;
}				t_texture;

typedef struct s_map
{
	char		**grid;
	t_dim		dim;
}				t_map;

typedef struct s_viewport_text
{
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	int			floor_color;
	int			ceilling_color;
}				t_viewport_text;

typedef struct s_viewport
{
	long long		width;
	long long		height;
	t_viewport_text	view_port_text;
	t_map			map;
}				t_viewport;

// to avoid collision we need a radius
typedef struct s_config
{
	double		move_speed;
	double		rotation_angle;
	double		rotation_sin;
	double		rotation_cos;
	double		rotation_speed;
	double		view_angle;
}				t_config;

typedef struct s_player
{
	double		x;
	double		y;
	int			turn_direction;
	char		walk_direction;
	t_config	player_config;
}				t_player;

typedef struct s_ray
{
	t_coord		cords;
	double		size;
	double		angle;
	char		obstacle;
	char		orientation;
	char		side;
}				t_ray;

typedef struct s_rays
{
	t_ray		*arr;
	double		eucledian_dist;
}				t_rays;

typedef struct s_env
{
	char		*map_name;
	int			fd_map;
	t_mlx		mlx;
	t_viewport	view_port;
	t_player	player;
	t_rays		rays;
}				t_env;

typedef struct s_component
{
	t_coord		cmp_cords;
	t_dim		dimension;
	int			fill_color;
}				t_component;

typedef struct s_rect
{
	t_coord		cmp_cords;
	t_dim		dimension;
	int			fill_color;
	int			border_color;
	int			border_width;
	t_texture	tex;
}				t_rect;
#endif