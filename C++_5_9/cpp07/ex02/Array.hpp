/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:13:22 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 19:31:11 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY
#define ARRAY

#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		unsigned int n;
		T *_arr;

	public:
		Array(void);
		Array(unsigned int size);
		Array(const Array& other);
		~Array();
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;
	
	class OufOfBoundsExeption:public std::exception
	{
		public:
			virtual const char * what() const throw()
			{return " index is out of bounds";}
	};
};
#include "Array.tpp"
#endif