/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 21:06:13 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/18 23:17:42 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::string s("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
		std::cout << s;
	}
	else
	{
		for (size_t i = 1; argv[i] != 0; i++)
			for (size_t j = 0; j < std::char_traits<char>::length(argv[i]); j++)
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
	}
	std::cout << '\n';
	return (0);
}
