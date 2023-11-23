/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:22 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 16:50:38 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main(int argc, char **argv)
{
	Zombie	*heap = newZombie("new Zombie");
	heap->announce();
	randomChump("random Zombie");

	delete (heap);
	return (0);
}
