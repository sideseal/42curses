/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:08:24 by gychoi            #+#    #+#             */
/*   Updated: 2023/12/31 21:35:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <cstdlib>
#include <deque>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(PmergeMe const& other);
	PmergeMe&	operator=(PmergeMe const& other);
	~PmergeMe();

public:
	static std::vector<int> const&	getSequence();
	static void						setSequence(char** seq, int len);

public:
//	static void	fordJohnsonSort(std::vector<int>& v);
//	static void	fordJohnsonSort(std::deque<int>& d);

private:
	static std::vector<int>	sSequence;
};

#endif /* __PMERGEME_HPP__ */
