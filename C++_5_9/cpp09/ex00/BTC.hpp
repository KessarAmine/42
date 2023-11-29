/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTC.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:44:59 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/29 18:08:31 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTC_HPP
#define BTC_HPP

#include <map>
#include <string>
#include <iostream>
#include <exception>
#include <fstream>
#include <unistd.h>

typedef struct	metadata
{
	int		days;
	int		month;
	int		year;
	bool	operator<(const metadata&other) const;
}				t_metadata;

class BTC
{
	private:
		// my container
		std::map<t_metadata,float> data;

	public:
		BTC(void){};
		BTC(std::string file);
		~BTC(){};
		BTC(const BTC& copy)
		{
			*this = copy;
		};
		BTC& operator=(const BTC& copy){return(*this);};
		struct ErrorException :public std::exception
		{
			virtual const std::string message() const;
		};
		struct InvalidFile :public BTC::ErrorException
		{
			virtual const std::string message() const;
		};
		struct MonthNotSupported :public BTC::ErrorException
		{
			virtual const std::string message() const;
		};
		struct DayNotSupported :public BTC::ErrorException
		{
			virtual const std::string message() const;
		};
		struct OutOfRange :public BTC::ErrorException
		{
			virtual const std::string message() const;
		};
		void	split(std::ifstream& inFile);
		void	run();
};
#endif