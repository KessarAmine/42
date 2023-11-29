/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:15:37 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/29 18:27:47 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stack>
#include <iostream>
#include <exception>
#include <cstring>

#ifndef RPN_HPP
# define RPN_HPP

class RPN
{
	// stack container
	private:
		std::stack<long long int> stak;

	public:
		RPN(){};
		RPN(const RPN &a){};
		~RPN(){};
		RPN		&operator= (const RPN& a){return(*this);};
		int		pull();
		void	processing(std::string str);

	struct Exception : public std::exception
	{
		virtual const std::string message() const;
	};
	struct InvalidOperator : public RPN::Exception
	{
		const std::string message() const;
	};
	struct InvalidAction : public RPN::Exception
	{
		const std::string message() const;
	};
	struct MultipleSolution : public RPN::Exception
	{
		const std::string message() const;
	};
};
#endif
