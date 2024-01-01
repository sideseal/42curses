/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:52:54 by gychoi            #+#    #+#             */
/*   Updated: 2024/01/01 23:46:41 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <iomanip>
#include "PmergeMe.hpp"

void	displaySequence(std::vector<int> const& vec, std::string const& str)
{
	std::cout << std::left << std::setw(8) << str + ": ";
	for (std::vector<int>::const_iterator it = vec.begin();
		 it != vec.end(); it++)
	{
		std::cout << " " << *it;
	}
	std::cout << std::right << std::endl;
}

void	measureSortTime
(struct timespec const& start, struct timespec const& end,
 std::string const& container, int len)
{
	double	elapsed;

	elapsed = (end.tv_sec - start.tv_sec);
	elapsed += (end.tv_nsec - start.tv_nsec) / 1000000000.0;

	std::cout << "Time to process a range of " << std::setw(3) << len;
	std::cout << " elements with "
			  << std::left << std::setw(16) << std::setfill(' ')
			  << container << " : ";
	std::cout << std::fixed << std::setprecision(5)
			  << std::right << std::setw(8)
			  << elapsed << " us";
	std::cout << std::endl;
}

// CPU Time으로 바꿔야 할까?
void	execute(std::vector<int> const& sequence)
{
	std::deque<int>		dq;
	std::vector<int>	vec;
	struct timespec		vStartTime;
	struct timespec		vEndTime;
	struct timespec		dStartTime;
	struct timespec		dEndTime;

	clock_gettime(CLOCK_MONOTONIC, &vStartTime);
	vec.assign(sequence.begin(), sequence.end());
	PmergeMe::fordJohnsonSort(vec, vec.size());
	clock_gettime(CLOCK_MONOTONIC, &vEndTime);

	clock_gettime(CLOCK_MONOTONIC, &dStartTime);
	dq.assign(sequence.begin(), sequence.end());
	// sorting deque sequence
	clock_gettime(CLOCK_MONOTONIC, &dEndTime);

	displaySequence(sequence, "Before");
	displaySequence(vec, "After");
	measureSortTime(vStartTime, vEndTime, "std::vector<int>", vec.size());
	measureSortTime(dStartTime, dEndTime, "std::deque<int>", sequence.size());
}

int	main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cout
		<< "Usage: " << argv[0]
		<< " <positive integer sequence>"
		<< std::endl;
		return 1;
	}
	else
	{
		// ready to execute
	}

	try
	{
		PmergeMe::setSequence(argv, argc);
		execute(PmergeMe::getSequence());
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
