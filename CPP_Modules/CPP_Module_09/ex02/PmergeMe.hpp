/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:08:24 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/16 21:09:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <limits>
#include <stdexcept>
#include <string>
#include <vector>

struct ValuePair
{
	int	value;
	int	index;
};

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
	static void	fordJohnsonSort(std::vector<int>& v, int size, int turn = 1);
	static void	fordJohnsonSort(std::deque<int>& d, int size, int turn = 1);

private:
	static std::vector<int>	sSequence;
	static std::deque<int>	sPartialJacobsthalSequence;
};

template <typename T>
bool	isAllSorted(T const& arr)
{
	std::vector<int>	originSequence = PmergeMe::getSequence();
	if (originSequence.size() != arr.size())
	{
		return false;
	}

	std::sort(originSequence.begin(), originSequence.end());

	for (size_t i = 0; i < originSequence.size(); i++)
	{
		if (originSequence[i] != arr[i])
		{
			return false;
		}
	}

	return true;
}

#endif /* __PMERGEME_HPP__ */

