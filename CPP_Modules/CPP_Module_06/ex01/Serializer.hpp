/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:26:03 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/18 02:51:02 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <stdint.h>
#include <iostream>

struct Data
{
	std::string	data;
};

class Serializer
{
private:
	Serializer();
	Serializer(Serializer const& target);
	Serializer&	operator=(Serializer const& target);
	~Serializer();

public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif /* __SERIALIZER_HPP__ */
