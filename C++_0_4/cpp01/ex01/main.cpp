/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:22 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 20:22:31 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie	*heap = zombieHorde(5, "walking_dead");
	for (int i = 0; i < 5; i++)
		heap[i].announce();
	for (int i = 0; i < 5; i++)
		heap[i].~Zombie();
	return (0);
}
