/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:39:03 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/28 16:08:09 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

void print(int& a)
{
	std::cout << a << " ";
}

int main() {
	{
		std::cout << "Vector: " << std::endl;
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(2);

		std::for_each(v.begin(), v.end(), print);
		std::cout << std::endl;

		*easyfind(v, 2) = 17;
		std::cout << "find(2) = 17" << std::endl;
		try {
			std::cout << "find(5) = 17" << std::endl;
			*easyfind(v, 5) = 17;
		} catch (const std::exception& e) {
			std::cout << "Exception thrown!" << std::endl;
		}
		std::for_each(v.begin(), v.end(), print);
		std::cout << std::endl;
	}
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	{
		std::cout << "deque: " << std::endl;
		std::deque<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(2);

		std::for_each(v.begin(), v.end(), print);
		std::cout << std::endl;

		*easyfind(v, 2) = 17;
		std::cout << "find(2) = 17" << std::endl;
		try {
			std::cout << "find(5) = 17" << std::endl;
			*easyfind(v, 5) = 17;
		} catch (const std::exception& e) {
			std::cout << "Exception thrown!" << std::endl;
		}
		std::for_each(v.begin(), v.end(), print);
		std::cout << std::endl;
	}
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	{
		std::cout << "list: " << std::endl;
		std::list<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(2);

		std::for_each(v.begin(), v.end(), print);
		std::cout << std::endl;

		*easyfind(v, 2) = 17;
		std::cout << "find(2) = 17" << std::endl;
		try {
			std::cout << "find(5) = 17" << std::endl;
			*easyfind(v, 5) = 17;
		} catch (const std::exception& e) {
			std::cout << "Exception thrown!" << std::endl;
		}
		std::for_each(v.begin(), v.end(), print);
		std::cout << std::endl;
	}
}
