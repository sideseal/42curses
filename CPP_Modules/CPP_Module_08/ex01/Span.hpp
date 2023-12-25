/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 00:12:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/26 00:28:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <stdexcept>
#include <vector>

class	Span
{
public:
	Span();
	Span(unsigned int n);
	Span(Span const& target);
	Span&				operator=(Span const& target);
	~Span();

public:
	void				addNumber(int num);
	unsigned int		shortestSpan();
	unsigned int		longestSpan();

private:
	unsigned int		mSize;
	std::vector<int>	mVec;
};

#endif /* __SPAN_HPP__ */
