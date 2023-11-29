/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BTC.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmohamed <kmohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:56:28 by kmohamed          #+#    #+#             */
/*   Updated: 2023/11/29 18:06:52 by kmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BTC.hpp"

bool metadata::operator<(const metadata& other) const
{
	if (year != other.year)
		return year < other.year;
	if (month != other.month)
		return month < other.month;
	 return days < other.days;
}

BTC::BTC(std::string file)
{
	std::ifstream inFile(file);
	if (!inFile) 
		throw(BTC::InvalidFile());
	split(inFile);
	inFile.close();
};

void BTC::split(std::ifstream& inFile)
{
	std::string line;
	std::getline(inFile, line);

	while (std::getline(inFile, line))
	{
		metadata date;
		size_t pos1 = line.find('-');
		if (pos1 == std::string::npos)
			throw InvalidFile();
		date.year = std::atoi(line.substr(0, pos1).c_str());

		size_t pos2 = line.find('-', pos1 + 1);
		if (pos2 == std::string::npos)
			throw InvalidFile();
		date.month = std::atoi(line.substr(pos1 + 1, pos2 - pos1 - 1).c_str());

		size_t pos3 = line.find('|', pos2 + 1);
		size_t pos4 = line.find(',', pos2 + 1);
		if (pos4 < pos3)
			pos3 = pos4;
		if (pos3 == std::string::npos)
			throw InvalidFile();
		date.days = std::atoi(line.substr(pos2 + 1, pos3 - pos2 - 1).c_str());
		float num = std::atof(line.substr(pos3 + 1).c_str());
		this->data[date] = num;
	}
}

void BTC::run()
{
	while (true)
	{
		std::cout << "Enter YEAR-MONTH-DAY|VALUE: ";
		std::string line;
		std::getline(std::cin, line);
		try
		{
			metadata date;
			size_t pos1 = line.find('-');
			size_t pos2 = line.find('-', pos1 + 1);
			size_t pos3 = line.find('|', pos2 + 1);
			size_t pos4 = line.find(',', pos2 + 1);
			if (line[0] == '-' || pos1 == std::string::npos || pos2 == std::string::npos || pos3 == std::string::npos)
				throw InvalidFile();
			date.year = std::stoi(line.substr(0, pos1));
			date.month = std::stoi(line.substr(pos1 + 1, pos2));
			date.days = std::stoi(line.substr(pos2 + 1, std::min(pos3, pos4)));
			if (date.month < 1 || date.month > 12)
				throw MonthNotSupported();
			if (date.days < 1 || date.days > 31)
				throw DayNotSupported();
			float num = std::stof(line.substr(pos3 + 1));
			if (num < 0 || num > 1000)
				throw OutOfRange();
			std::map<metadata,float>::iterator iter = this->data.lower_bound(date);
			float multi = iter->second;
			std::cout << "=> " << (multi * num) << std::endl;
		}
		catch(const std::string& e)
		{
			std::cerr << e << '\n';
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(const char* & e)
		{
			std::cerr << e << '\n';
		}
	}
}

const std::string BTC::InvalidFile::message() const
{
	return("Error: Invalid syntax input");
}

const std::string BTC::ErrorException::message() const
{
	return("Error!");
}

const std::string BTC::MonthNotSupported::message() const
{
	return("Month is not supported");
}

const std::string BTC::DayNotSupported::message() const
{
	return("Day is not supported");
}

const std::string BTC::OutOfRange::message() const
{
	return("Value : OutOfRange");
}
