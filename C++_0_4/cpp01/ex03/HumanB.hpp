/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:24 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/24 16:38:51 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <stdio.h>
# include <iostream>
# include "Weapon.hpp"

// we have to change the weapon later on and the human B does not have to have a weapon
// we use a pointer instead of a reference cuz we wont be initializing the weapon all the time
// so we pass the reference of that object to our pointer to track the changes
class HumanB
{
	public:
		HumanB(std::string	input);
		~HumanB();
		void		set_name(std::string input);
		std::string	get_name(void);
		void		set_slot_1(Weapon& weapon);
		std::string	get_slot_1();
		void		attack(void);

	private:
		std::string	name;
		Weapon		*slot_1;
};
#endif