/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:01:14 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/16 15:40:42 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int, std::list<int> >	RPN::sStack;

static void	_calculate(std::stack<int, std::list<int> >& s, char const& oprt);
static int	_popOperand(std::stack<int, std::list<int> >& s);
static bool	_isValidToken(std::string const& token);
static bool	_isOperator(char const& ch);

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

RPN::RPN()
{
	// nothing to do
}

RPN::RPN(__attribute__((unused)) RPN const& other)
{
	// nothing to do
}

RPN&	RPN::operator=(__attribute__((unused)) RPN const& other)
{
	return *this;
}

RPN::~RPN()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */

int	RPN::execute(char* expr)
{
	std::istringstream	iss(expr);
	std::string			token;

	while (std::getline(iss, token, ' '))
	{
		if (iss.fail())
		{
			throw std::runtime_error("Failed to read string stream");
		}
		else if (!_isValidToken(token))
		{
			throw std::invalid_argument("Invalid argument: " + token);
		}
		else
		{
			if (token.length() == 1 && _isOperator(token[0]))
			{
				_calculate(sStack, token[0]);
			}
			else
			{
				sStack.push(std::atoi(token.c_str()));
			}
		}
	}

	if (sStack.size() != 1)
	{
		throw std::runtime_error("Malformed expression");
	}
	else
	{
		// good!
	}

	return sStack.top();
}

/* ************************************************************************** */
/*                              Utility Function                              */
/* ************************************************************************** */

static void	_calculate(std::stack<int, std::list<int> >& s, char const& oprt)
{
	if (s.size() < 2)
	{
		throw std::runtime_error("Malformed expression");
	}
	else
	{
		// ready to calculate
	}

	int	opd2 = _popOperand(s);
	int	opd1 = _popOperand(s);

	switch (oprt)
	{
		case '+':
			s.push(opd1 + opd2);
			break;
		case '-':
			s.push(opd1 - opd2);
			break;
		case '*':
			s.push(opd1 * opd2);
			break;
		case '/':
		{
			if (opd2 == 0)
			{
				throw std::runtime_error("Division by zero");
			}
			else
			{
				s.push(opd1 / opd2);
			}
			break;
		}
		default:
			// unreachable
			std::logic_error("Debugger ON...");
	}
}

static int	_popOperand(std::stack<int, std::list<int> >& s)
{
	int	op = s.top();

	s.pop();
	return op;
}

static bool	_isValidToken(std::string const& token)
{
	if (token.length() == 1 && _isOperator(token[0]))
	{
		return true;
	}
	else if (token.length() == 1 && std::isdigit(token[0]))
	{
		return true;
	}
	else if (token.length() == 2 && token[0] == '+' && std::isdigit(token[1]))
	{
		return true;
	}
	else if (token.length() == 2 && token[0] == '-' && std::isdigit(token[1]))
	{
		return true;
	}
	else
	{
		// invalid input
	}
	return false;
}

static bool	_isOperator(char const& ch)
{
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
