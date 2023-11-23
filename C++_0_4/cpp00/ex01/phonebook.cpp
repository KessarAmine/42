/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:02:02 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/06 16:13:05 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	system("clear");
	count = -1;
	std::string choice;
	std::cout << "Welcome to the 80s PhoneBook" << std::endl;
	while(1)
	{
		std::cout << "input one of the options :" << std::endl;
		std::cout << "\t1: ADD\n\t2: SEARCH\n\t3: EXIT :(" << std::endl;
		std::getline(std::cin, choice);
		if (ft_strcmp(choice,"ADD") == 1)
		{
			system("clear");
			std::string	first_name_input;
			std::string	last_name_input;
			std::string	nickname_input;
			std::string	darkest_secret_input;
			std::string	phone_number_input;
			int			phone_number;
			std::cout << "=======-Adding a new contact * we don't accept empty fields *-=======" << std::endl;
			std::cout << "\t1/5...Enter the First name :" << std::endl;
			while (first_name_input.empty())
				std::getline(std::cin, first_name_input);
			std::cout << "\t2/5...Enter the Last name :" << std::endl;
			while (last_name_input.empty())
				std::getline(std::cin, last_name_input);
			std::cout << "\t3/5...Enter the NickName :" << std::endl;
			while (nickname_input.empty())
				std::getline(std::cin, nickname_input);
			std::cout << "\t4/5...Enter the darkest secret :" << std::endl;
			while (darkest_secret_input.empty())
				std::getline(std::cin, darkest_secret_input);
			std::cout << "\t5/5...Enter the phone number :" << std::endl;
			while (phone_number_input.empty() || containsNonDigit(phone_number_input))
				std::getline(std::cin, phone_number_input);
			phone_number = std::stoi(phone_number_input);
			add_contact(count, phone_number, first_name_input, last_name_input,
				nickname_input, darkest_secret_input);
			count++;
			std::cout << "Press any key to continue..." << std::endl;
			std::getline(std::cin, nickname_input);
			system("clear");
		}
		else if (ft_strcmp(choice,"SEARCH"))
		{
			system("clear");
			int target;
			std::string byebye;
			std::cout << "=======-Searching a contact-=======" << std::endl;
			std::cout << "\tEnter the index of the contact:" << std::endl;
			std::cin >> target;
			if (target < 0 || target > 7)
				std::cout << "Sorry,your index is out of range, we just have 8 contacts[0->7]\n";
			else
				search(target);
			std::cout << "Press any key to continue..." << std::endl;
			std::cin.ignore();
			std::getline(std::cin, byebye);
			system("clear");
		}
		else if (ft_strcmp(choice,"EXIT"))
			break;
		else
			std::cout << "ehum ehum...it's not that hard to type right c'mon! try harder :)\n";
	}
}

PhoneBook::~PhoneBook()
{
	std::cout << "Time travel Machine destroyed!" << std::endl;
}

void		PhoneBook::add_contact(int count, int phone, std::string firstname, std::string lastname, std::string nick, std::string secret)
{
	Contact new_contact((count + 1) % 8, phone, firstname, lastname, nick, secret);
	contacts[new_contact.get_Index()] = new_contact;
	std::cout << new_contact.get_Number() << " added\n";
}

void	PhoneBook::search(int index)
{
	std::string	first_name_input;
	std::string	last_name_input;
	std::string	nickname_input;
	std::string	darkest_secret_input;
	int			phone_number_input;

	Contact target = contacts[index];
	if (target.get_lastName().empty())
		std::cout << "No records on this index yet\n";
	else
		display_contact(target);
}

void	PhoneBook::display_contact(Contact target)
{
	std::string	first_name_input;
	std::string	last_name_input;
	std::string	nickname_input;

	first_name_input = target.get_FirstName().c_str();
	last_name_input = target.get_lastName().c_str();
	nickname_input = target.get_NickName().c_str();
	std::cout << "     index|    f_name|    l_name|    n_name" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	std::cout << "         ";
	std::cout << target.get_Index();
	std::cout << "|";
	display_column(first_name_input);
	std::cout << "|";
	display_column(last_name_input);
	std::cout << "|";
	display_column(nickname_input);
	std::cout << std::endl;
}

int	PhoneBook::ft_strlen(std::string name)
{
	int i = 0;

	while (name[i])
		i++;
	return (i);
}

void	PhoneBook::display_name_trnc(std::string name)
{
	int i = 0;

	while (name[i] < 10)
		std::cout << name[i++];
	if (i == 10)
		std::cout << ".";
}

void	PhoneBook::display_column(std::string name)
{
	int	spaces_count = 0;

	if (ft_strlen(name) > 10)
		display_name_trnc(name);
	else
	{
		spaces_count = 10 - ft_strlen(name);
		while (spaces_count > 0)
		{
			std::cout << " ";
			spaces_count--;
		}
		std::cout << name.c_str();
	}
}

int	PhoneBook::ft_strcmp(std::string s1, std::string s2)
{
	int i = 0;
	while (s1[i] && s2[i])
	{
		if ((s1[i] - s2[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

bool PhoneBook::containsNonDigit(const std::string& str)
{
	size_t pos = str.find('+');
	if (pos == 0)
	{
		std::string modifiedStr = str.substr(pos + 1);
		for (size_t i = 0; i < modifiedStr.length(); i++)
		{
			if (!std::isdigit(modifiedStr[i]))
				return (true);
		}
	}
	else
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (!std::isdigit(str[i]))
				return (true);
		}
	}
	return (false);
}