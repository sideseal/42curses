/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:01:31 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/11 01:08:57 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <cstdlib>
#include <sstream>
#include <stack>
#include <stdexcept>

class RPN
{
private:
	RPN();
	RPN(RPN const& other);
	RPN&	operator=(RPN const& other);
	~RPN();

public:
	static int	execute(char* expr);

private:
	static std::stack<int>	sStack;
};

#endif /* __RPN_HPP__ */
