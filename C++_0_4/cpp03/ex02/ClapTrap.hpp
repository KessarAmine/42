/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:35:57 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/21 17:03:24 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP
# define CLAP_TRAP

#include <string>
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		ClapTrap();
		~ClapTrap();
		void				set_name(std::string name);
		std::string			get_name();
		void				set_health(unsigned int amount);
		unsigned int		get_health();
		void				set_energy(unsigned int amount);
		unsigned int		get_energy();
		void				set_attack_damage(unsigned int amount);
		unsigned int		get_attack_damage();

		void				attack(const std::string &target);
		void				take_damage(unsigned int damage);
		void				be_repaired(unsigned int heal);

	protected:
		std::string 		name;
		unsigned int		health;
		unsigned int		energy;
		unsigned int		attack_damage;
};
std::ostream	&operator<<(std::ostream &stream,ClapTrap &clapTrap);
#endif