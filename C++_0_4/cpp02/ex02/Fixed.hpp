/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 11:55:32 by kmohamed          #+#    #+#             */
/*   Updated: 2023/08/04 14:39:21 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					fixed_point_value;
		static const int	fractional_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed(const int input);
		Fixed(const float input);
		~Fixed();
		Fixed		&operator=(const Fixed &source);
		bool		operator<(const Fixed &cmp) const;
		bool		operator>(const Fixed &cmp) const;
		bool		operator<=(const Fixed &cmp) const;
		bool		operator>=(const Fixed &cmp) const;
		bool		operator==(const Fixed &cmp) const;
		bool		operator!=(const Fixed &cmp) const;
		Fixed		operator+(const Fixed &source);
		Fixed		operator-(const Fixed &source);
		Fixed		operator*(const Fixed &source);
		Fixed		operator/(const Fixed &source);
		Fixed		operator++(void);
		Fixed		operator++(int);
		Fixed		operator--(void);
		Fixed		operator--(int);
		int			getRawBits(void) const;
		void		setRawBits(int const raw);
		float		toFloat(void) const;
		int			toInt(void) const;
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
};
std::ostream	&operator<<(std::ostream &stream, Fixed const &f);
#endif