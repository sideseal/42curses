/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:17:49 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 02:59:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack const& other);
	MutantStack&	operator=(MutantStack const& other);
	virtual ~MutantStack();

public:
	typedef typename std::stack<T>::container_type::iterator
													iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator
													reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator
													const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator
													const_reverse_iterator;

public:
	iterator				begin();
	iterator				end();
	const_iterator			begin() const;
	const_iterator			end() const;
	reverse_iterator		rbegin();
	reverse_iterator		rend();
	const_reverse_iterator	rbegin() const;
	const_reverse_iterator	rend() const;
};

#include "MutantStack.tpp"
#endif /* __MUTANTSTACK_HPP__ */
