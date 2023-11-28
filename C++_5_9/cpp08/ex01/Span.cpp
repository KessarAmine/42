/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:16:21 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/28 17:19:28 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int _n) :N(_n)
{
	;
}

Span::Span(const Span& _other) : vector(_other.vector), N(_other.N)
{
	*this = _other;
}

Span::~Span()
{

}

Span& Span::operator=(const Span& _other)
{
	if (this == &_other)
		return *this;
	*this = _other;
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->vector.size() == this->N)
		throw Span::SpanIsFullException();
	this->vector.push_back(n);
}

void Span::addNumbers(const int* numbers, unsigned int size)
{
	if (N < this->vector.size() + size)
		throw Span::SizeTooSmallException();
	this->vector.insert(this->vector.end(), numbers, numbers + size);
}

void Span::addRange(IT begin, IT end)
{
	if (vector.size() + std::distance(begin, end) > N) 
		throw Span::SpanIsFullException();
	vector.insert(vector.end(), begin, end);
}

unsigned int Span::shortestSpan() const 
{
	if (this->N < 2 || this->vector.size() < 2) throw Span::SizeTooSmallException();

	std::vector<int> copy(this->vector);
	std::sort(copy.begin(), copy.end());

	unsigned int shortest = std::numeric_limits<unsigned int>::max();
	for (size_t i = 0; i < copy.size() - 1; ++i) 
	{
		unsigned int diff = static_cast<unsigned int>(copy[i + 1]) - static_cast<unsigned int>(copy[i]);
		if (diff < shortest) 
			shortest = diff;
	}
	return (shortest);
}

unsigned int Span::longestSpan() const 
{
	if (this->N < 2 || this->vector.size() < 2) throw Span::SizeTooSmallException();
	unsigned int max = *std::max_element(this->vector.begin(), this->vector.end());
	unsigned int min = *std::min_element(this->vector.begin(), this->vector.end());
	return (max - min);
}

const char* Span::SpanIsFullException::what() const throw() 
{
	return "Span: it is full";
}

const char* Span::SizeTooSmallException::what() const throw() 
{
	return "Span: needs at least 2 values inside Span";
}
