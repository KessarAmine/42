/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:22 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 20:06:56 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string>
#include<iostream>

int	main(int argc, char **argv)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "str adresse : " << &str << std::endl;
	std::cout << "stringPTR adresse : " << stringPTR << std::endl;
	std::cout << "stringREF adresse : " << &stringREF << std::endl;

	std::cout << "str value : " << str << std::endl;
	std::cout << "stringPTR value : " << (*stringPTR) << std::endl;
	std::cout << "stringREF value : " << stringREF << std::endl;
}
