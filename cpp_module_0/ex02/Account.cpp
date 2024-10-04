/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpambhar <rpambhar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:07:13 by rpambhar          #+#    #+#             */
/*   Updated: 2024/08/01 14:32:41 by rpambhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

// Variable intialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit) : _amount(initial_deposit) {
	static int index = 0;

	_accountIndex = index;
	index++;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

// Deconstructor
Account::~Account(void){
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

/* std::time_t is a data type used to store system time values.
std::time(NULL) fetches the current system time and returns it as a time_t value.
If you pass NULL as an argument, it simply stores the current time into the time_t variable currentTime.
std::tm is a structure holding a calendar date and time broken down into its components (e.g., year, month, day, hour, minute, second).
std::localtime converts the time_t value pointed to by &currentTime into local time as a tm structure.
The return value is a pointer to a tm structure representing the local time.
char formattedTime[19]: Declares a character array of size 19 to hold the formatted date and time string.
std::strftime formats the time data from the tm structure (now) into a specified format and stores it into formattedTime.
*/
void Account::_displayTimestamp(void) {
	std::time_t	currentTime = std::time(NULL);
	std::tm		*calenderTime = std::localtime(&currentTime);
	char		formattedTime[19];

	std::strftime(formattedTime, sizeof(formattedTime), "[%Y%m%d_%H%M%S]", calenderTime);
	std::cout << formattedTime;

}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";"
				<< "total:" << getTotalAmount() << ";"
				<< "desposits:" << getNbDeposits() << ";"
				<< "withdrawls:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount - deposit << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout	<< withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int Account::checkAmount(void) const {
	return (_amount);
}

// getters

int Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int Account::getTotalAmount(void) {
	return (_totalAmount);
}

int Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}