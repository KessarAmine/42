/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:49:41 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 16:01:55 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

template<typename T>
void iter(T *adresse_array, size_t size_array, void(*f)(T&))
{
	std::for_each(adresse_array, adresse_array + size_array, f);
}
