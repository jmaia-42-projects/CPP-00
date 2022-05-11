/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:09:03 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/11 12:38:50 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <ctime>
#include <iostream>
#include <time.h>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " " << "accounts:" << Account::_nbAccounts << ";" << "total:" << Account::_totalAmount << ";" << "deposits:" << Account::_totalNbDeposits << ";" << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
	this->_totalNbDeposits += this->_nbDeposits;
	this->_totalNbWithdrawals += this->_nbWithdrawals;

	this->_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "created" << std::endl;
}

Account::~Account(void)
{
	this->_nbAccounts--;
	this->_totalAmount -= this->_amount;
	this->_totalNbDeposits -= this->_nbDeposits;
	this->_totalNbWithdrawals -= this->_nbWithdrawals;

	this->_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	oldAmount;

	oldAmount = this->_amount;

	this->_nbDeposits++;
	this->_totalNbDeposits++;
	this->_amount += deposit;
	this->_totalAmount += deposit;

	this->_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "p_amount:" << oldAmount << ";" << "deposit:" << deposit << ";" << "amount:" << this->_amount << ";" << "nb_deposits:" << 1 << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	oldAmount;
	int	isAccepted;

	oldAmount = this->_amount;
	if (withdrawal > this->_amount)
		isAccepted = false;
	else
	{
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		isAccepted = true;
	}

	this->_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "p_amount:" << oldAmount << ";" << "withdrawal:";
	if (isAccepted)
		std::cout << withdrawal << ";" << "amount:" << this->_amount << ";" << "nb_withdrawals:" << 1 << std::endl;
	else
		std::cout << "refused" << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " " << "index:" << this->_accountIndex << ";" << "amount:" << this->_amount << ";" << "deposits:" << this->_nbDeposits << ";" << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t	time;
	std::tm		*now;
	char		timeStr[16];
   
	time = std::time(0);
	now = std::localtime(&time);
	strftime(timeStr, 16, "%Y%m%d_%H%M%S", now);
	std::cout << "[" << timeStr << "]";
}
