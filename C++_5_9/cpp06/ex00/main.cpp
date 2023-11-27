/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 00:27:34 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 00:30:01 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <string>
#include <sstream>

int main(int ac, char **av)
{
	try{
	if (ac != 2)
	{
		std::cerr << "Error Input!" << std::endl;
		return 0;
	}
	ScalarConverter::convert(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error : Wrong Input! -->"  << e.what() <<  std::endl;
	}
	return 0;
}

