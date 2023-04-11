/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minTalkLib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:39:44 by kmohamed          #+#    #+#             */
/*   Updated: 2023/01/23 13:40:44 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINTALKLIB_H
# define MINTALKLIB_H
# include <signal.h>

typedef struct s_message
{
	char	c;
	size_t	bit_order;
}	t_message;

int		ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif
