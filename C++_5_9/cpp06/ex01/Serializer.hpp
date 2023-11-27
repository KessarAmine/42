/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:57:34 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 01:00:14 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		const Serializer &operator=(const Serializer& src);
		~Serializer();
	public :
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
#endif