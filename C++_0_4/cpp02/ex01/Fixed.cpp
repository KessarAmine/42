/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:55:35 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/04 12:46:36 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called\n";
	*this = source;
}

Fixed::Fixed(const int input)
{
	std::cout << "Int constructor called\n";
	fixed_point_value = (input << fractional_bits);
}

Fixed::Fixed(const float input)
{
	std::cout << "Float constructor called\n";
	fixed_point_value = std::roundf(input * (1 << fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed	&Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called\n";
	setRawBits(source.getRawBits());
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) fixed_point_value / (1 << fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (fixed_point_value >> fractional_bits);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &f)
{
	stream << f.toFloat();
	return (stream);
}
