/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:57:10 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/23 23:11:29 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* hayawan = new Animal();
	const Animal* kurama = new Dog();
	const Animal* katkout = new Cat();
	std::cout << kurama->get_type() << " " << std::endl;
	std::cout << katkout->get_type() << " " << std::endl;
	kurama->makeSound();
	katkout->makeSound();
	hayawan->makeSound();
	return 0;
}