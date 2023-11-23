/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:42:23 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 20:22:36 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[5];
	for (int i = 0; i < N; i++)
		zombies[i].set_name(name + " (" + std::to_string(i + 1) +")");
	return (zombies);
}
