/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 03:54:59 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/21 21:05:17 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lib.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] || nb > 255)
		exit(printf("Error : Number RGB Invalide\n"));
	return (nb);
}

char	*read_file(t_listt *list)
{
	char	str[1000000];
	char	*a;
	int		sz;
	int		i;

	sz = 1;
	i = 0;
	while (1)
	{
		sz = read(list->fd_map, &str[i++], 1);
		if (!*str)
			exit (write(1, "Error : Map is Empty !!\n", 24));
		if (sz == -1)
			exit (write(1, "Error\n", 6));
		if (sz == 0)
			break ;
	}
	a = str;
	return (a);
}

void	fil_globales(t_listt *list)
{
	char	*s1;

	list->fd_map = open(list->map_name, O_RDONLY);
	if (list->fd_map < 0)
		exit(printf("Error 404 !!\n"));
	s1 = read_file(list);
	list->before = s1;
	list->global = ft_splitt(s1, '\n');
	close(list->fd_map);
}
