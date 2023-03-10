//
// Created by nskiba on 3/10/23.
//
#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();

	_accountIndex = _nbAccounts++;
	std::cout << " index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = initial_deposit;
}

Account::~Account()
{
	this->_displayTimestamp();

	std::cout << " index:" << _accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
	char time_str[20];
	std::time_t current_time = std::time(NULL);
	std::strftime(time_str, sizeof(time_str), "[%Y%m%d_%H%M%S]", std::localtime(&current_time));
	std::cout << time_str;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits+1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if ((this->checkAmount() - withdrawal) < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
	{
		std::cout << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
	}
	return true;
}

void	Account::displayStatus() const
{
	this->_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}
