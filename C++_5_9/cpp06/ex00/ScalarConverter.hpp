/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:14:21 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 00:36:03 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

#define FAILURE_1 -895623
#define FAILURE_2 3

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		const ScalarConverter &operator=(const ScalarConverter& src);
		~ScalarConverter();
	public:
		static void convert(std::string str);
};

typedef enum	dataType
{
    CHAR,
    FLOAT,
    DOUBLE,
	STRING,
	INT,
	UNKOWN
}				t_dataType;

static bool		isChar(std::string str);
static bool		isFloat(std::string str);
static bool		isDouble(std::string str);
static bool		isString(std::string str);
static bool		isDisplayable(char c);
static bool		isInt(std::string str);
static bool		isNan(std::string str);
static bool		isInf(std::string str);
static bool		isInff(std::string str);
static t_dataType	get_type(std::string str);
#endif