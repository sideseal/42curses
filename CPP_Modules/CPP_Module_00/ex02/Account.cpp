/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:10:45 by gychoi            #+#    #+#             */
/*   Updated: 2023/07/21 00:15:12 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include <sstream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::_totalAmount = 0;

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::_totalNbDeposits = 0;

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::_totalNbWithdrawals = 0;

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

Account::Account(void) {}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::makeDeposit(int deposit)
{
	int	newAmount = _amount + deposit;

	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << newAmount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_amount = newAmount;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	newAmount = _amount - withdrawal;

	if (newAmount < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";";
		std::cout << "p_amount:" << _amount << ";";
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << newAmount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount = newAmount;
	_totalAmount -= withdrawal;
	return (true);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	current_time;
	std::tm*	time_info;
	char		timestamp[24];

	std::time(&current_time);
	time_info = std::localtime(&current_time);
	std::strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", time_info);
	std::cout << "[" << timestamp << "] ";
}
