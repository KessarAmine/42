/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:20:11 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/29 18:28:09 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int check_op_compute(int a, int b, char symbol)
{
	switch (symbol)
	{
		case '+':
			return(a + b);
		case '-':
			return(a - b);
		case '*':
			return(a * b);
		case '/':
			return(a / b);
		default:
			throw(RPN::InvalidOperator());
			break;
	}
}

void RPN::processing(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (std::strrchr("1234567890",input[i]))
		{
			this->stak.push((int)(input[i] - '0'));
		}
		else if (std::strrchr("+-*/",input[i]))
		{
			if (this->stak.size() == 1)
				throw(RPN::InvalidAction());
			int b = this->pull();
			int a = this->pull();
			int c = check_op_compute(a,b,input[i]);
			stak.push(c);
		}
		else if (input[i] == ' ')
		{
			;
		}
		else
			throw(RPN::InvalidOperator());
	}
	if (stak.size() != 1)
		throw(RPN::MultipleSolution());
	else
		std::cout << this->pull() << std::endl;

	
}

const std::string RPN::Exception::message() const
{
	return("Error:: error");
}

const std::string RPN::InvalidOperator::message() const
{
	return("Error:: Invalid Operator");
}

const std::string RPN::InvalidAction::message() const
{
	return("Error:: Invalid Action");
}

const std::string RPN::MultipleSolution::message() const
{
	return("Error:: Too Many Solution");
}

int RPN::pull()
{
	int tmp = this->stak.top();
	this->stak.pop();
	return(tmp);
}





