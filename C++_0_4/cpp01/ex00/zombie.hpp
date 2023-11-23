/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:24 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/24 12:08:54 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include<string>
# include <iostream>

class Zombie
{
	public:
		Zombie(std::string	name);
		Zombie();
		~Zombie();
		void		set_name(std::string input);
		std::string	get_name(void);
		void		announce(void);

	private:
		std::string	name;
};
Zombie* newZombie(std::string name);
void	randomChump(std::string name);
#endif