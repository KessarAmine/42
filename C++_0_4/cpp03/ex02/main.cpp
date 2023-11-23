/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:35:51 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/18 19:51:56 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(int argc, char **argv)
{
	FragTrap	FragTrapA("FragTrapA");
	FragTrap	FragTrapB("FragTrapB");
	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;
	FragTrapA.attack("FragTrapB");
	FragTrapB.take_damage(FragTrapA.get_attack_damage());
	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;
	FragTrapB.be_repaired(5);
	std::cout << FragTrapA << "\n" << FragTrapB << std::endl;
	FragTrapB.highFivesGuys();
	return (0);
}
