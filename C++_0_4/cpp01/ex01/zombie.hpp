/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:24 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 19:44:26 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include<string>
# include<stdio.h>
# include <iostream>

class Zombie
{
	public:
		Zombie(std::string	name);
		Zombie();
		~Zombie();
		void	set_name(std::string input);
		void	announce(void);
	private:
		std::string	name;
};
Zombie* zombieHorde( int N, std::string name );
#endif