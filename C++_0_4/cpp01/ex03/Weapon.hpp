/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:24 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/24 16:39:28 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <stdio.h>
# include <iostream>

class Weapon
{
	public:
		Weapon(std::string	input);
		Weapon();
		~Weapon();
		void		set_type(std::string input);
		std::string	get_type(void);

	private:
		std::string	type;
};
#endif