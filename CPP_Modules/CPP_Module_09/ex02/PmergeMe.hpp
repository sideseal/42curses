/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:08:24 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/05 20:59:25 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <algorithm>
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
	static void	fordJohnsonSort(std::vector<int>& v, int size, int turn = 1);
//	static void	fordJohnsonSort(std::deque<int>& d);

private:
	static std::vector<int>	sSequence;
	static std::deque<int>	sPartialJacobsthalSequence;
};





template <typename T>
bool	isAllSorted(const T arr[], int size)
{
	if (size <= 1)
	{
		return true;
	}

	for (int i = 1; i < size; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			return false;
		}
	}

	return true;
}

#endif /* __PMERGEME_HPP__ */
