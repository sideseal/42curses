/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:13:09 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/14 23:06:33 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::time_t, double>	BitcoinExchange::sDataMap;

static bool			_isValidDateFormat(std::string const& date);
static bool			_isValidDouble(std::string const& s);
static bool			_isNumber(std::string const& s);
static bool			_isLeapYear(int year);
static int			_stoi(std::string const& s);
static double		_stod(std::string const& s);
static std::string	_trim(std::string const& s);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

BitcoinExchange::BitcoinExchange()
{
	// nothing to do
}

BitcoinExchange::BitcoinExchange
(__attribute__((unused)) BitcoinExchange const& other)
{
	// nothing to do
}

BitcoinExchange&	BitcoinExchange::operator=
(__attribute__((unused)) BitcoinExchange const& other)
{
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	// nothig to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */

void	BitcoinExchange::setExchangeMap(char const* path)
{
	std::ifstream	dbFile(path);
	
	if (!dbFile.is_open())
	{
		throw std::runtime_error("could not open file.");
	}
	else
	{
		std::string	header;

		if (!std::getline(dbFile, header))
		{
			throw std::runtime_error("Unable to read db header.");
		}
		else if (header != "date,exchange_rate")
		{
			throw std::runtime_error("Malformed csv header.");
		}
		else
		{
			// header OK
		}
	}

	std::string	line;

	while (std::getline(dbFile, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		std::string			exchangeRate;
		std::string			remain;

		if (line.empty())
		{
			continue;
		}
		else if (std::getline(iss, date, ','))
		{
			if (!_isValidDateFormat(date))
			{
				throw std::runtime_error(std::string("bad input => ")
										 + date);
			}
			else if (!(iss >> exchangeRate))
			{
				throw std::runtime_error("Unable to read exchange rate.");
			}
			else if (!_isValidDouble(exchangeRate))
			{
				throw std::runtime_error(std::string("bad input => ")
										 + exchangeRate);
			}
			else if (std::getline(iss, remain))
			{
				throw std::runtime_error(std::string("bad input => ")
										 + line);
			}
			else
			{
				// data format OK
			}

			double	rate = _stod(exchangeRate);

			if (rate < 0)
			{
				throw std::runtime_error("not a positive number.");
			}
			else if (rate > std::numeric_limits<int>::max())
			{
				throw std::runtime_error("too large a number.");
			}
			else
			{
				std::tm		tm = {};
				std::time_t	epochTime;

				tm.tm_year = _stoi(date.substr(0, 4)) - 1900;
				tm.tm_mon = _stoi(date.substr(5, 2)) - 1;
				tm.tm_mday = _stoi(date.substr(8));

				if ((epochTime = std::mktime(&tm)) == -1)
				{
					throw std::runtime_error("Failed to convert epoch time.");
				}
				else
				{
					sDataMap.insert(std::make_pair(epochTime, rate));
				}
			}
		}
		else
		{
			throw std::runtime_error("Unable to read db data.");
		}
	}
}

void	BitcoinExchange::execute(char const* path)
{
	std::ifstream	inputFile(path);

	if (!inputFile.is_open())
	{
		throw std::runtime_error("could not open file.");
	}
	else
	{
		std::string	header;

		if (!std::getline(inputFile, header))
		{
			throw std::runtime_error("Unable to read input file header.");
		}
		else if (header != "date | value")
		{
			throw std::runtime_error("Malformed input file header.");
		}
		else
		{
			// header OK
		}
	}

	std::string	line;

	while (std::getline(inputFile, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		std::string			exchangeRate;
		std::string			remain;

		if (line.empty())
		{
			continue;
		}
		else if (std::getline(iss, date, '|'))
		{
			date = _trim(date);

			if (!_isValidDateFormat(date))
			{
				std::cout << "Error: bad input => " << date << std::endl;
				continue;
			}
			else if (!(iss >> exchangeRate))
			{
				std::cout << "Error: Unable to read exchange rate."
						  << std::endl;
				continue;
			}
			else if (!_isValidDouble(exchangeRate))
			{
				std::cout << "Error: bad input => " << exchangeRate
						  << std::endl;
				continue;
			}
			else if (std::getline(iss, remain))
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			else
			{
				// data format OK
			}

			double	rate = _stod(exchangeRate);

			if (rate < 0)
			{
				std::cout << "Error: not a positive number." << std::endl;
				continue;
			}
			else if (rate > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
			else
			{
				std::tm		tm = {};
				std::time_t	epochTime;

				tm.tm_year = _stoi(date.substr(0, 4)) - 1900;
				tm.tm_mon = _stoi(date.substr(5, 2)) - 1;
				tm.tm_mday = _stoi(date.substr(8));

				if ((epochTime = std::mktime(&tm)) == -1)
				{
					throw std::runtime_error("Failed to convert epoch time.");
				}
				else
				{
					std::map<std::time_t, double>::const_iterator
									  mit = sDataMap.lower_bound(epochTime);

					if (mit == sDataMap.begin() && epochTime < mit->first)
					{
						std::cout << "Error: data not found." << std::endl;
						continue;
					}
					else if (mit == sDataMap.end() || epochTime != mit->first)
					{
						--mit;
					}
					else
					{
						// go on!
					}

					std::cout << date << " => " << rate << " = "
							  << rate * mit->second << std::endl;
				}
			}
		}
		else
		{
			throw std::runtime_error("Unable to read input file data.");
		}
	}
}

/* ************************************************************************** */
/*                              Utility Function                              */
/* ************************************************************************** */

static bool	_isValidDateFormat(std::string const& date)
{
	int	year;
	int	month;
	int	day;

	/* Check date format(YYYY-MM-DD) and parse into int */
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		return false;
	}
	else
	{
		std::string	sYear = date.substr(0, 4);
		std::string	sMonth = date.substr(5, 2);
		std::string	sDay = date.substr(8);

		if (!_isNumber(sYear) || !_isNumber(sMonth) || !_isNumber(sDay))
		{
			return false;
		}
		else
		{
			year = _stoi(sYear);
			month = _stoi(sMonth);
			day = _stoi(sDay);
		}
	}

	/* check date has valid range */
	if (year < 1900 || year > 9999)
	{
		return false;
	}
	else if (month < 1 || month > 12)
	{
		return false;
	}
	else if (day < 1 || day > 31)
	{
		return false;
	}

	/* check date has valid day relate to month */
	switch (month)
	{
		case 2:
		{
			if (day == 29 && !_isLeapYear(year))
			{
				return false;
			}
			else if (day > 29)
			{
				return false;
			}
			else
			{
				break;
			}
		}
		case 4:
		case 6:
		case 9:
		case 11:
		{
			if (day > 30)
			{
				return false;
			}
			else
			{
				break;
			}
		}
		default:
		{
			if (day > 31)
			{
				return false;
			}
			else
			{
				break;
			}
		}
	}

	return true;
}

static bool	_isValidDouble(std::string const& s)
{
	char*	endptr;

	std::strtod(s.c_str(), &endptr);

	return *endptr == '\0';
}

static bool	_isNumber(std::string const& s)
{
	for (std::string::const_iterator cit = s.begin(); cit != s.end(); ++cit)
	{
		if (!std::isdigit(*cit))
		{
			return false;
		}
	}

	return true;
}

static bool	_isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0)
			|| (year % 100 == 0 && year % 400 == 0);
}

static int	_stoi(std::string const& s)
{
	std::istringstream	iss(s);
	int					ret;

	if (!(iss >> ret))
	{
		throw std::runtime_error("input stream error.");
	}

	return ret;
}

static double	_stod(std::string const& s)
{
	std::istringstream	iss(s);
	double				ret;

	if (!(iss >> ret))
	{
		throw std::runtime_error("input stream error.");
	}

	return ret;
}

static std::string	_trim(std::string const& s)
{
	std::string	ret;

	for (std::string::const_iterator cit = s.begin(); cit != s.end(); ++cit)
	{
		if (!std::isspace(*cit))
		{
			ret += *cit;
		}
	}

	return ret;
}

