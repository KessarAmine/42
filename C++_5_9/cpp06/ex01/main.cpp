/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:57:29 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 01:29:40 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdint.h>
#include "Serializer.hpp"

void	Display(char *str)
{
	if (str)
		std::cout << "Data: " << str << std::endl;
	else
		std::cout << "Data is null." << std::endl;
}

int	main()
{
	Data		data, *new_data;
	uintptr_t	ptr;

	// Set some data
	std::memcpy(data.str, "some random_input", 18);
	data.next = nullptr;

	// Display original data
	// content of the str member.
	std::cout << "Original Data:" << std::endl;
	Display(data.str);
	std::cout << "----------------------------------" << std::endl;
	// Serialize and display
	ptr = Serializer::serialize(&data);
	std::cout << "After Serializing Data and reinterpreting the Serialed data as string:" << std::endl;
	Display(reinterpret_cast<char*>(ptr));
	std::cout << "----------------------------------" << std::endl;
	// Deserialize and display
	new_data = Serializer::deserialize(ptr);
	std::cout << "After Deserializing Data the serialized data:" << std::endl;
	Display(new_data->str);
	std::cout << "----------------------------------" << std::endl;
	// Display deserialized data directly
	std::cout << "Accessing deserialized Data directly:" << std::endl;
	std::cout << new_data->str << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return (0);
}
