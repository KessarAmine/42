/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:43:23 by kmohamed          #+#    #+#             */
/*   Updated: 2023/09/23 23:28:41 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H
#include <iostream>
#include <string>
#include <cstring>

class Brain
{
	public :
		Brain();
		~Brain();
		Brain &operator=(const Brain &oterh);
		std::string	ideas[100];
};
#endif