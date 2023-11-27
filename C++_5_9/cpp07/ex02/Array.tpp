/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:21:17 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/27 19:31:16 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>

Array<T>::Array(void): n(0)
{
	_arr = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n): n(n)
{
	_arr = new T[n];
	for (unsigned int i = 0; i < n; i++) 
		_arr[i] = 0;
}
// Array<int>::Array(Array<int> const&)
template <typename T>
Array<T>::Array(const Array& src): n(src.n)
{
	_arr = new T[n];
	for (unsigned int i = 0; i < n; i++)
		_arr[i] = src._arr[i];
}

template <typename T>
Array<T>::~Array()
{
	delete [] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &src)
{
	if (this != &src)
	{
		delete [] _arr;
		n = src.n;
		_arr = new T[n];
		for (unsigned int i = 0; i < n; i++)
			_arr[i] = src._arr[i];
	}
	return (*this);
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if ((i >= n )|| (i < 0 ))
		throw OufOfBoundsExeption();
	return (_arr[i]);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if ((i >= n) || (i < 0))
		throw OufOfBoundsExeption();
	return (_arr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (n);
}
