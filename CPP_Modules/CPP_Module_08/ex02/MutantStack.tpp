/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 01:42:26 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 01:50:49 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_TPP__
#define __MUTANTSTACK_TPP__

/* ************************************************************************** */
/*                          Constructor & Destructor                          */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack()
	: std::stack<T>()
{
	// nothing to do
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& other)
	: std::stack<T>(other)
{
	// nothing to do
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator=(MutantStack const& other)
{
	if (this != &other)
	{
		this->std::stack<T>::operator=(other);
	}
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	// nothing to do
}

/* ************************************************************************** */
/*                           Public Member Function                           */
/* ************************************************************************** */

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator
MutantStack<T>::begin() const
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator
MutantStack<T>::end() const
{
	return this->c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator
MutantStack<T>::rbegin()
{
	return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator
MutantStack<T>::rend()
{
	return this->c.rend();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator
MutantStack<T>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator
MutantStack<T>::rend() const
{
	return this->c.rend();
}

#endif /* __MUTANTSTACK_TPP__ */
