/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:44:02 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 03:30:52 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate()
{
	int randomNum = rand() % 3;
	switch (randomNum)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return nullptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout<< "Type :: A" <<std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout<< "Type :: B" <<std::endl;
	 else if (dynamic_cast<C*>(p) != nullptr)
		std::cout<< "Type :: C" <<std::endl;
	else
		std::cout<< "Type :: Unknown "<<std::endl;
	if (dynamic_cast<Base*>(p) != nullptr)
		std::cout<< "Derived from BASE" <<std::endl;
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p) != nullptr)
		std::cout<< "Type :: A" <<std::endl;
	else if (dynamic_cast<B*>(&p) != nullptr)
		std::cout<< "Type :: B" <<std::endl;
	else if (dynamic_cast<C*>(&p) != nullptr)
		std::cout<< "Type :: C" <<std::endl;
	else
		std::cout<< "Type :: Unknown "<<std::endl;

	if (dynamic_cast<Base*>(&p) != nullptr)
		std::cout<< "Derived from BASE" <<std::endl;
}
Base::~Base(){}
