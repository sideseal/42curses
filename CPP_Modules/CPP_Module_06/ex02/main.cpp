/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 03:29:51 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/21 17:16:01 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main()
{
	Base*	p = generate();

	try
	{
		identify(p);
		identify(*p);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	delete p;

	return 0;
}
