/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:09:18 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:18:19 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# include <sstream>
# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <cstddef>
# include <algorithm>

class Span
{
	private:
		typedef std::vector<int>::iterator IT;
		const unsigned int N;
		std::vector<int> vector;

	public:
		Span(unsigned int _n);
		Span(const Span& _other);
		~Span();
		Span& operator=(const Span& other);

		void			addNumber(int n);
		void			addNumbers(const int* numbers, unsigned int size);
		void			addRange(IT begin, IT end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		std::size_t		get_size() const;

		class SpanIsFullException : public std::exception
		{
			public: virtual const char* what() const throw();
		};

		class SizeTooSmallException : public std::exception
		{
			public: virtual const char* what() const throw();
		};
};

template <typename T>
inline std::string to_string(T __val)
{
	std::ostringstream __stream;
	__stream << __val;
	return __stream.str();
}

#endif