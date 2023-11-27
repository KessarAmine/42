/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:17:51 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 00:34:58 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <sstream>

ScalarConverter:: ScalarConverter()
{
	std::cout << "Destrcutor Constructor called\n";
}

ScalarConverter:: ~ScalarConverter()
{
	std::cout << "Destrcutor called\n";
}

ScalarConverter:: ScalarConverter(const ScalarConverter& copy)
{
	if (this != &copy)
		std::cout << "ScalarConverter Copy Constuctor Called !"<< std::endl;
}

const ScalarConverter& ScalarConverter:: operator=(const ScalarConverter &src)
{
	if (this != &src)
		std::cout << "ScalarConverter Copy Assignment Operator Constuctor Called !" << std::endl;
	return *this;
}

t_dataType	get_type(std::string str)
{
	if (isChar(str))
		return (CHAR);
	if (isString(str))
		return (STRING);
	if (isFloat(str))
		return (FLOAT);
	if (isDouble(str))
		return (DOUBLE);
	if (isInt(str))
		return (INT);
	return (UNKOWN);
}

bool isChar(std::string str)
{
	if (str.length() > 1)
		return (false);
	if ((str[0] >= 'a' && str[0] <= 'z')
		|| (str[0] >= 'A' && str[0] <= 'Z'))
		return (true);
	return (false);
}

bool isInt(std::string str)
{
	if (str.size() == 0)
		return (false);
	for(unsigned long i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
			i++;
		if (i == str.size())
			return false;
		if (str[i] < '0' || str[i] > '9')
			return false;
	}
	return true;
}

bool isFloat(std::string str)
{
	unsigned long dotCount = 0;
	unsigned long j = 0;

	if (str.length() <= 2)
		return (false);
	if (str[0] == '-')
		j++;
	for(unsigned long i = j; i < str.length() - 1; i++)
	{
		if (str[i] == '.')
		{
			dotCount++;
			if (dotCount > 1 || i == j || i == str.length() - 2)
				return (false);
		} else if(!isdigit(str[i]))
			return (false);
	}
	if (str[str.length() - 1] == 'f' && dotCount == 1)
		return (true);
	return (false);
}

bool isDouble(std::string str)
{
	unsigned long i = 0;
	int k = 0;

	if (isInt(str) == true || isFloat(str) == true || isChar(str) == true || isString(str) == true || str.length() <= 2)
		return (false);
	if (str[i] == '-')
		i++;
	for (;i < str.length(); i++)
	{
		if (str[i] == '.' && k == 0)
		{
			i++;
			k++;
		}
		if (!(isdigit(str[i])))
			return false;
	}
	return true;
}

bool isDisplayable(char c)
{
	if (c < 32 || c > 126)
		return false;
	return true;
}

bool isString(std::string str)
{
	// std::cout<< isInt(str) << isFloat(str) << isDouble(str) << isChar(str) <<std::endl;
	if (isInt(str) == true || isFloat(str) == true || isDouble(str) == true || isChar(str) == true)
		return false;
	return true;
}

void fix_value(std::string &str)
{
	int dotCount = 0;

	// Check for more than one dot
	// Count the number of dots in the string
	for (unsigned long i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dotCount++;
	}
	if (dotCount > 1)
	{
		std::cerr << "Error: Multiple dots in input!" << std::endl;
		exit(0); // Consider using exceptions or returning a status instead of exit
	}

	// Handle cases where a dot is misplaced or a leading zero is missing
	if ((str[0] == '.' || (str[0] == '-' && str[1] == '.')) && str.size() > 1)
	{
		std::string formated;
		if (str[0] == '.')
			formated = "0" + str;
		else
			formated = "-0" + str.substr(1);
		str = formated;
	}
}

bool handleSpecialCases(const std::string &str, const std::string &charMsg, const std::string &intMsg, const std::string &floatMsg, const std::string &doubleMsg)
{
	std::cout << "char : " << charMsg << std::endl;
	std::cout << "int : " << intMsg << std::endl;
	std::cout << "float : " << floatMsg << std::endl;
	std::cout << "double : " << doubleMsg << std::endl;
	return true;
}

bool isNan(std::string str)
{
	if (str == "nan" || str == "nanf")
		return handleSpecialCases(str, "impossible", "impossible", "nanf", "nan");
	return false;
}

bool isInff(std::string str)
{
	if (str == "-inff" || str == "+inff" || str == "inff")
		return handleSpecialCases(str, "impossible", "impossible", str.substr(0, 5), str.substr(0, 5));
	return false;
}

bool isInf(std::string str)
{
	if (str == "-inf" || str == "+inf" || str == "inf")
		return handleSpecialCases(str, "impossible", "impossible", str + "f", str);
	return false;
}

void ScalarConverter:: convert(std::string str)
{
	fix_value(str);
	char char_c = '\0';
	int int_nb = 0;
	float float_nb = 0.0f;
	double dbl_nb = 0.0;

	// Special case handling already done in isNan, isInff, isInf
	if (isNan(str) || isInff(str) || isInf(str))
		;
	else if (isString(str))
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible"<< std::endl;
	}
	else
	{
		if (str.length() == 1 || isInt(str) == true || isFloat(str) == true || isDouble(str) == true)
		{
			if (str.length() == 1 && isInt(str) == false && isFloat(str) == false && isDouble(str) == false)
			{
				char_c = str[0];
				int_nb = static_cast<int>(char_c);
				float_nb = static_cast<float>(char_c);
				dbl_nb = static_cast<double>(char_c);
			}
			else
			{
				int_nb = std::stoi(str);
				char_c = static_cast<char>(int_nb);
				float_nb = std::stof(str);
				dbl_nb = std::stod(str);
			}
		}
		else
		{
			// scalar out of reach
			char_c = FAILURE_2;
			int_nb = FAILURE_1;
			float_nb = FAILURE_1;
			dbl_nb = FAILURE_1;
		}

		// scalar char
		if (isDisplayable(char_c))
				std::cout << "char : '" << char_c << "\'" << std::endl;
		else if (int_nb < '!' || int_nb > '~')
			std::cout << "char : Non displayable" << std::endl;
		else
			std::cout << "char : impossible" << std::endl;

		// scalar int
		if (int_nb != FAILURE_1)
			std::cout << "int : " << std::fixed << int_nb << std::endl;
		else
			std::cout << "int : impossible" << std::endl;

		// scalar float
		if (float_nb != FAILURE_1)
			std::cout << "float : " <<  std::setiosflags(std::ios::fixed)<< std::setprecision(1) << float_nb << "f" << std::endl;
		else
			std::cout << "float : impossible" << std::endl;

		// scalar double
		if (dbl_nb != FAILURE_1)
			std::cout << "double : " <<  std::setiosflags(std::ios::fixed) << std::setprecision(1) << dbl_nb << std::endl;
		else
			std::cout << "double : impossible" << std::endl;
	}
}
