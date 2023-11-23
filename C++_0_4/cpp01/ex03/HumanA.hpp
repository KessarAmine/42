/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:24 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/24 16:38:41 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include <stdio.h>
# include <iostream>
# include "Weapon.hpp"

// we have to change the weapon later on and the human A must have a weapon so we have to init it in the constructor
// we use references cuz it point to the same variable with a different name thats all so any changes will be done on both sides
class HumanA
{
	public:
		HumanA(std::string	input, Weapon& weapon);
		HumanA(Weapon& weapon);
		~HumanA();
		void		set_name(std::string input);
		std::string	get_name(void);
		void		set_slot_1(Weapon input);
		std::string	get_slot_1(void);
		void		attack(void);

	private:
		std::string	name;
		Weapon&		slot_1;
};
#endif