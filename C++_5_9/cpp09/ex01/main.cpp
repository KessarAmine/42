/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:15:07 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/29 18:28:59 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error : bad arguments" << std::endl;
		return(-1);
	}
	RPN calc;
	try
	{
		 calc.processing(argv[1]);
	}
	catch(const RPN::Exception& e)
	{
		std::cout << e.message() << std::endl;
	}
	return(0);
}
