/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:21:22 by kmohamed          #+#    #+#             */
/*   Updated: 2023/07/08 22:21:11 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "check your args\n";
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inputFile(filename);
 	std::ofstream outputFile(filename + ".replace");

	if (inputFile.is_open())
	{
		std::string line;
		while (std::getline(inputFile, line))
		{
			size_t	pos = line.find(argv[2]);
			while (pos != std::string::npos)
			{
				int i = 0;
				while (i < s1.length())
				{
					if (s2[i])
						line[pos] = s2[i];
					else
						line[pos] = ' ';
					i++;
					pos++;
				}
				pos = line.find(argv[2], pos);
			}
			outputFile << line << std::endl;
		}
		inputFile.close();
		return (0);
	}
	else
		std::cout << "bad path\n";
	return (1);
}
