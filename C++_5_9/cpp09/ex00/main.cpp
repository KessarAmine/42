/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:35:55 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/29 17:57:32 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BTC.hpp"

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout << "Error bad arguments" << std::endl;
		return(0);
	}
	try
	{
		std::cout << argv[1] << std::endl;
		BTC market(argv[1]);
		market.run();
	}
	catch(const BTC::ErrorException& e)
	{
		std::cerr << e.message() << std::endl;
	}
	return(0);
}
