/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:35:21 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 15:47:33 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_

#include <iostream>

template<typename T>

void swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T& min(T &a, T &b)
{
	if (a > b) return b;
		return a;
}

template<typename T>
T& max(T &a, T &b)
{
	if (a > b) return a;
		return b;
}
#endif
