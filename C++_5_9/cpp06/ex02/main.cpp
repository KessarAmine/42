/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:43:15 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 03:32:09 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	// we need to seed rand to make in generage different rand numbers
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Base* inst1 = generate();
	Base* inst2 = generate();
	Base* inst3 = generate();
std::cout<< "----------------------" <<std::endl;
	identify(inst1);
std::cout<< "----------------------" <<std::endl;
	identify(*inst2);
std::cout<< "----------------------" <<std::endl;
	identify(inst3);
std::cout<< "----------------------" <<std::endl;
	delete (inst2);
	delete (inst3);
	delete (inst1);
	return (0);
}
