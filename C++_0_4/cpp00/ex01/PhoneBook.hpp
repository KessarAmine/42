/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:58:26 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/06 15:49:08 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

	private:
		Contact	contacts[8];
		int		count;
		void	add_contact(int count, int phone, std::string firstname, std::string lastname, std::string nick, std::string secret);
		void	search(int index);
		void	display_contact(Contact target);
		void	exit(void);
		int		ft_strlen(std::string name);
		void	display_name_trnc(std::string name);
		void	display_column(std::string name);
		int		ft_strcmp(std::string s1, std::string s2);
		bool	containsNonDigit(const std::string& str);
};
#endif