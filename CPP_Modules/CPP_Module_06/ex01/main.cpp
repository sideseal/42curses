/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:25:25 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/18 02:51:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data		data = { "original data" };
	Data*		retval;
	uintptr_t	serial;

	std::cout << "origin data: " << &data
			  << ", data: " << data.data << std::endl;
	serial = Serializer::serialize(&data);
	std::cout << "serialize: " << serial << std::endl;
	retval = Serializer::deserialize(serial);
	std::cout << "deserialize: " << retval
			  << ", data: " << retval->data << std::endl;
	std::cout << "FYI: serial hex value: " << std::hex << serial << std::endl;
	return 0;
}
