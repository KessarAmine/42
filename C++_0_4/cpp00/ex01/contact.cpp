/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:01:59 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/04 21:04:16 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(int index, int number, std::string	first_name, std::string	last_name, std::string	nickname,
				std::string	darkest_secret)
{
	set_Index(index);
	set_Number(number);
	set_FirstName(first_name);
	set_lastName(last_name);
	set_NickName(nickname);
	set_DarkestSecret(darkest_secret);
}

Contact ::Contact()
{
	return ;
}

Contact::~Contact()
{
	std::cout << "an Object of Contact class destroyed\n";
}

void	Contact::set_Index(int idx)
{
	index = idx;
}

int	Contact::get_Index(void)
{
	return (index);
}

char	Contact::get_Index_char(void)
{
	return (static_cast<char>(index));
}

void	Contact::set_Number(int input)
{
	number = input;
}

int	Contact::get_Number(void)
{
	return (number);
}

void	Contact::set_FirstName(std::string input)
{
	first_name = input;
}

std::string	Contact::get_FirstName(void)
{
	return (first_name);
}

void	Contact::set_lastName(std::string input)
{
	last_name = input;
}

std::string	Contact::get_lastName(void)
{
	return (last_name);
}

void	Contact::set_NickName(std::string input)
{
	nickname = input;
}

std::string	Contact::get_NickName(void)
{
	return (nickname);
}

void	Contact::set_DarkestSecret(std::string input)
{
	darkest_secret = input;
}

std::string	Contact::get_DarkestSecret(void)
{
	return (darkest_secret);
}
