/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:39:06 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/28 15:41:22 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>

template<typename T>

typename T::iterator easyfind(T& generic_container, int target) 
{
	typename T::iterator res = std::find(generic_container.begin(), generic_container.end(), target);
	if (res == generic_container.end())
		throw std::exception();
	return (res);
}
#endif