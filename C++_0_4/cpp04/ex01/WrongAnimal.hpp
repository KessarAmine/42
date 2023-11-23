/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:45:05 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/23 23:03:14 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class WrongAnimal
{
	protected :
		std::string type;

	public :
		WrongAnimal();
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};
