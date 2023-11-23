/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:55:04 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/20 18:51:13 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct color
{
	int	red;
	int	green;
	int	blue;
}	t_colorr;

typedef struct s_listt
{
	char		**global;
	char		**map;
	char		**dup_map;
	char		*map_name;
	char		*before;
	char		*south_path;
	char		*north_path;
	char		*west_path;
	char		*east_path;
	char		direction;
	int			high_file;
	int			long_line;
	int			fd_map;
	int			high_map;
	int			first_map;
	t_colorr	*floor_color;
	t_colorr	*cieling_color;
}	t_listt;

void	parsing_part(t_listt *list);
void	check_valid_maps(t_listt *list);
void	check_wall(t_listt *list);
void	check_direction(t_listt *list);
void	fil_globales(t_listt *list);
void	check_tokens(t_listt *list);
char	*remove_space(char *str);
void	find_map(t_listt *list);
void	find_color(t_listt *list);
void	find_text(t_listt *list, int j);
void	check_wall2(char *str, int length);
void	check_ligne_map(t_listt *list);
void	check_space_inside(t_listt *list);
void	check_0_around(t_listt *list);
void	check_colorr(char *str);
void	copy_map(t_listt *list);
void	get_long_line(t_listt *list);
void	check_text_path(t_listt *list);
void	check_text_extension(char *str);
void	get_high_file(t_listt *list);
void	compare_color(char *s_1, char **s, char **p, t_listt *list);
int		find_f_space(char *str);
char	*ft_callocc(size_t count, size_t size);
char	**ft_splitt(const char *s1, char c);
void	ft_khwi(int j, char **p);
void	remove_empty_lines(char **lines, int num_lines, t_listt *list, int i);
#endif
