/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:44:06 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:08:09 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>
#include <iostream>

template<typename T, class My_Container = std::deque<T> >
class MutantStack : public std::stack<T, My_Container>
{
	public:
		MutantStack() {};
		MutantStack(MutantStack const & other):std::stack<T>(other) {*this = other;};
		~MutantStack()
		{
			this->c.clear();
		};
		MutantStack & operator=(MutantStack const & obj) 
		{
			if (obj != *this) 
			{
				this->c = obj.c;
			}
			return *this;
		};
		typedef typename My_Container::iterator IT;
		IT begin() { return this->c.begin(); }
		IT end() { return this->c.end(); }
};
#include "MutantStack.tpp"
#endif