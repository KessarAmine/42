/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:57:48 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 01:00:31 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer Constructor Called !" << std::endl;

}

Serializer:: Serializer(const Serializer& copy)
{
	if (this != &copy)
		std::cout << "Serializer Copy Constructor Called !" << std::endl;
}

const Serializer& Serializer:: operator=(const Serializer& src)
{
	if (this != &src)
		std::cout << "Serializer Copy Assignment Operator Constructor Called !" << std::endl;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr_data)
{
		return (reinterpret_cast<uintptr_t>(ptr_data));
}
Data* Serializer::deserialize(uintptr_t raw_data)
{
		return (reinterpret_cast<Data*>(raw_data));
}

Serializer::~Serializer()
{
	std::cout << "Serializer Destructor Called !" << std::endl;
}
