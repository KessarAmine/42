/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:15:35 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/04 14:41:45 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::string temp = "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	if (argc == 1)
	{
		std::cout << temp;
		return (1);
	}
	int	i = 0;
	while (argv[++i])
	{
		temp = argv[i];
		int	current = -1;
		while (temp[++current])
			temp[current] = std::toupper(temp[current]);
		std::cout << temp + "\n";
	}
	return (0);
}
