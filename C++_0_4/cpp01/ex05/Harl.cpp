/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:39:18 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/28 16:00:39 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() 
{
	lut[0].level = "DEBUG";
	lut[0].f = &Harl::debug;
	lut[1].level = "INFO";
	lut[1].f = &Harl::info;
	lut[2].level = "WARNING";
	lut[2].f = &Harl::warning;
	lut[3].level = "ERROR";
	lut[3].f = &Harl::error;

	complain("INFO");
	complain("DEBUG");
	complain("ERROR");
	complain("WARNING");
}

void	Harl::debug(void) 
{
	cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n";
}

void	Harl::info(void) 
{
	cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n";
}

void	Harl::warning(void) 
{
	cout << "[WARNING] I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error(void) 
{
	cout << "[ERROR] This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain( std::string level ) 
{
	static int i = -1;
	if (i <= 3)
		level == lut[++i].level ? (this->*lut[i].f)() : complain(level) ;
	i = -1;
}
