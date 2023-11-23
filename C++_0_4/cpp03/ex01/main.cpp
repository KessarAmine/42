/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:35:51 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/18 19:23:50 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(int argc, char **argv)
{
	ScavTrap	ScavTrapA("ScavTrapA");
	ScavTrap	ScavTrapB("ScavTrapB");

	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;
	ScavTrapA.attack("ScavTrapB");
	ScavTrapB.take_damage(ScavTrapA.get_attack_damage());
	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;
	ScavTrapB.be_repaired(5);
	std::cout << ScavTrapA << "\n" << ScavTrapB << std::endl;
	ScavTrapB.guardGate();
	return (0);
}
