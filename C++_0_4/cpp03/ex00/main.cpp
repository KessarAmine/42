/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:35:51 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/16 15:50:11 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(int argc, char **argv)
{
	ClapTrap	ClaptrapA("ClaptrapA");
	ClapTrap	ClaptrapB("ClaptrapB");

	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;
	ClaptrapA.set_attack_damage(5);
	ClaptrapA.attack("ClaptrapB");
	ClaptrapB.take_damage(ClaptrapA.get_attack_damage());
	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;
	ClaptrapB.be_repaired(5);
	std::cout << ClaptrapA << "\n" << ClaptrapB << std::endl;
	return 0;
}
