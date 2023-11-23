/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:15 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/24 16:36:18 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "zombie.hpp"

Zombie* newZombie( std::string name)
{
	Zombie *newZombie = new Zombie(name);
	return (newZombie);
}
