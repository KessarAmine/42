/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:57:10 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/24 00:00:07 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal *tab[4];
	Brain *cat_brain;
	Brain *dog_brain;

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			tab[i] = new Dog();
			tab[i]->makeSound();
		}
		else
		{
			tab[i] = new Cat();
			tab[i]->makeSound();
		}
	}
	cat_brain = tab[0]->get_brain();
	dog_brain = tab[2]->get_brain();
	cat_brain->ideas[0] = dog_brain->ideas[0] = "lalalalala";
	cat_brain->ideas[1] = dog_brain->ideas[1] = "tralalalalala";
	cat_brain->ideas[2] = dog_brain->ideas[2] = "other idea";
	cat_brain->ideas[3] = dog_brain->ideas[3] = "finisshhh";
	cat_brain->ideas[4] = dog_brain->ideas[4] = "...";
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "|" << tab[0]->get_brain()->ideas[0] << "|" << std::endl;
	*(tab[1]) = *(tab[0]);
	std::cout << "|" << tab[1]->get_brain()->ideas[1] << "|" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "|" << tab[2]->get_brain()->ideas[2] << "|" << std::endl;
	*(tab[3]) = *(tab[2]);
	std::cout << "|" << tab[3]->get_brain()->ideas[3] << "|" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	delete tab[0];
	delete tab[1];
	delete tab[2];
	delete tab[3];

	return (0);
}