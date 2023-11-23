/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:55:35 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/04 14:40:41 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
	;
}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
}

Fixed::Fixed(const int input)
{
	fixed_point_value = (input << fractional_bits);
}

Fixed::Fixed(const float input)
{
	fixed_point_value = std::roundf(input * (1 << fractional_bits));
}

Fixed::~Fixed()
{
	;
}

Fixed	&Fixed::operator=(const Fixed &source)
{
	if (*this != source)
		setRawBits(source.getRawBits());
	return (*this);
}

bool	Fixed::operator>(const Fixed &cmp) const
{
	return (fixed_point_value > cmp.getRawBits());
}

bool	Fixed::operator<(const Fixed &cmp) const
{
	return (fixed_point_value < cmp.getRawBits());
}

bool	Fixed::operator>=(const Fixed &cmp) const
{
	return (fixed_point_value >= cmp.getRawBits());
}

bool	Fixed::operator<=(const Fixed &cmp) const
{
	return (fixed_point_value <= cmp.getRawBits());
}

bool	Fixed::operator==(const Fixed &cmp) const
{
	return (fixed_point_value == cmp.getRawBits());
}

bool	Fixed::operator!=(const Fixed &cmp) const
{
	return (fixed_point_value != cmp.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &right)
{
	fixed_point_value += right.getRawBits();
	return (*this);
}

Fixed	Fixed::operator-(const Fixed &right)
{
	fixed_point_value -= right.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(const Fixed &right)
{
	fixed_point_value = (this->toFloat() * right.toFloat()) * (1 << fractional_bits);
	return (*this);
}

Fixed	Fixed::operator/(const Fixed &right)
{
	fixed_point_value = (this->toFloat() / right.toFloat()) * (1 << fractional_bits) ;
	return (*this);
}

Fixed	Fixed::operator++(void)
{
	fixed_point_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	Fixed::operator--(void)
{
	fixed_point_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

int		Fixed::getRawBits(void) const
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

int		Fixed::toInt(void) const
{
	return (fixed_point_value >> fractional_bits);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (b);
	return (a);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (b);
	return (a);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &f)
{
	stream << f.toFloat();
	return (stream);
}
