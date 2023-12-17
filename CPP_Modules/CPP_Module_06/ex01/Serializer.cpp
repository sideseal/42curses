/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:25:53 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/18 02:50:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

Serializer::Serializer()
{
	// nothing to do
}

Serializer::Serializer
(__attribute__((unused)) Serializer const& target)
{
	// nothing to do
}

Serializer&	Serializer::operator=
(__attribute((unused)) Serializer const& target)
{
	return *this;
}

Serializer::~Serializer()
{
	// nothing to do
}

/* ************************************************************************** */
/*                          Static Member Functions                           */
/* ************************************************************************** */

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
