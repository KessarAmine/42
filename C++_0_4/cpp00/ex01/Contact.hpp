/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:58:23 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/24 16:32:57 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
	public:
		Contact(int index, int number, std::string	first_name,
				std::string	last_name, std::string	nickname, std::string	darkest_secret);
		Contact();
		~Contact();
		int			get_Index(void);
		char		get_Index_char(void);
		void		set_Index(int index);
		void		set_Number(int number);
		int 		get_Number(void);
		void		set_FirstName(std::string first_name);
		std::string	get_FirstName(void);
		void		set_lastName(std::string last_name);
		std::string	get_lastName(void);
		void		set_NickName(std::string nick_name);
		std::string	get_NickName(void);
		std::string	get_DarkestSecret(void);
		void 		set_DarkestSecret(std::string secret);

	private:
		int			index;
		int			number;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
};
#endif