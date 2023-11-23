/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:49:52 by anoury            #+#    #+#             */
/*   Updated: 2023/07/19 16:49:55 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRTRIM_H
# define FT_STRTRIM_H

# include "libft.h"

static size_t	get_length(char const *s1, char const *set);
static void		trim(char *new_str,
					size_t size_new_str,
					char const *s1,
					char const *set);

#endif
