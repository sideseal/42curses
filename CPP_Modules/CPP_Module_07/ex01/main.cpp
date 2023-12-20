/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:02:56 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/21 01:28:14 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"

int	main()
{
	int	iArr[] = {1, 2, 3};

	std::cout << "Testing int array" << std::endl;
	::iter(iArr, 3, ::display<int>);

	std::cout << std::endl;

	std::string	sArr[] = {"hello", "42", "seoul"};

	std::cout << "Testing string array" << std::endl;
	::iter(sArr, 3, ::display<std::string>);

	return 0;
}
