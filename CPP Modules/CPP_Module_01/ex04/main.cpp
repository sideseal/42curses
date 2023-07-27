/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:05:36 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/28 00:54:07 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string	editString(const std::string& str, const std::string& pattern, const std::string& replacement)
{
	std::string	output;
	std::size_t	pos = 0;
	std::size_t	strLength = str.length();
	std::size_t	patternLength = pattern.length();

	if (!patternLength || !strLength)
		return (str);
	while (pos <= strLength - patternLength)
	{
		if (str.substr(pos, patternLength) == pattern)
		{
			output += replacement;
			pos += patternLength;
		}
		else
			output += str[pos++];
	}
	output += str.substr(pos);
	return (output);
}

int	main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	const std::string	infile = argv[1];
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];
	std::ostringstream	buffer;
	std::ifstream		ifs(infile.c_str());
	if (ifs.fail())
	{
		std::cout << "Error: Cannot open input file: " << infile << std::endl;
		return (1);
	}
	else
	{
		buffer << ifs.rdbuf();
		ifs.close();
	}
	std::string	output = editString(buffer.str(), s1, s2);
	const std::string	outfile = infile + ".replace";
	std::ofstream		ofs(outfile.c_str());
	if (ofs.fail())
	{
		std::cout << "Error: Cannot create output file: " << outfile << std::endl;
		return (1);
	}
	else
		ofs << output;
	return (0);
}
