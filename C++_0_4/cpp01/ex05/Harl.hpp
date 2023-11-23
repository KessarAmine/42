/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:29:50 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/28 15:40:07 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;

class Harl 
{
	public:
	Harl();
	void	complain(std::string level);

	private:
	typedef struct _lut
	{
		string	level;
		void	(Harl::*f)(void);
	}				t_lut;
	t_lut	lut[4];
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

};

#endif
