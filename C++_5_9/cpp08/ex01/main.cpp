/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:34:18 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:21:20 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() 
{
	try 
	{
		Span s(5);
		int first_test[5] = {2, 4, 6, 8, 10};
		unsigned int size_test = sizeof(first_test) / sizeof(first_test[0]);
		s.addNumbers(first_test, size_test);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try 
	{
		Span s(5);
		s.addNumber(2);
		s.addNumber(4);
		s.addNumber(6);
		s.addNumber(8);
		s.addNumber(10);
		s.addNumber(12);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try 
	{
		Span s(5);
		s.addNumber(2);
		std::cout << "longest span : " << s.longestSpan() << std::endl;
		std::cout << s.shortestSpan() << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}

	try 
	{
		Span s(1);
		s.addNumber(2);
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}


	std::cout << std::endl;
	std::vector<int> big(10000);
	for (int i = 0; i < 10000; ++i) big[i] = i;
	try 
	{
		Span s(10000);
		s.addRange(big.begin(), big.end());
		std::cout << "shortest span: " << s.shortestSpan() << std::endl;
		std::cout << "longest span : " << s.longestSpan() << std::endl;
	} 
	catch (std::exception& e) 
	{
		std::cerr << "EXCEPTION: " << e.what() << std::endl;
	}
	return (0);
}