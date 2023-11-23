/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:50:31 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:50:33 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	char	buf;
	int		i;

	if (read(fd, 0, 0) == -1)
		return (-1);
	*line = malloc(MAX_LINE);
	if (!(line))
		return (-1);
	i = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			(*line)[i] = '\0';
			return (1);
		}
		(*line)[i++] = buf;
	}
	(*line)[i] = '\0';
	return (0);
}
