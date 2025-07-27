#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void ) { return _nbAccounts; }

int Account::getTotalAmount( void ) { return _totalAmount; }

int Account::getNbDeposits( void ) { return _totalNbDeposits; }

int Account::getNbWithdrawals( void ) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts: " << _nbAccounts
	          << "; total: " << _totalAmount
              << "; deposits: " << _totalNbDeposits
              << "; withdrawals: " << _totalNbWithdrawals
              << std::endl;
}

Account::Account(int initial_deposit): _amount(initial_deposit) {
	_totalAmount += _amount;
	_accountIndex = _nbAccounts++;
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << "; amount: " << _amount << "; created" << std::endl;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << "index: " << _accountIndex
	          << "; amount: " << _amount
              << "; deposits: " << _nbDeposits
              << "; withdrawals: " << _nbWithdrawals
              << std::endl;
}

int Account::checkAmount() const { return _amount; }

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index: " << _accountIndex
	          << "; p_amount: " << _amount
              << "; deposit: " << deposit
              << "; amount: " << _amount + deposit
              << "; nb_deposits: " << ++_nbDeposits
              << std::endl;
    _amount += deposit;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index: " << _accountIndex
	          << "; p_amount: " << _amount
	          << "; withdrawal: ";
    if (withdrawal > _amount)
    {
    	std::cout << "refused" << std::endl;
     	return false;
    }
    std::cout << withdrawal
              << "; amount: " << _amount - withdrawal
              << "; nb_withdrawals: " << ++_nbWithdrawals
              << std::endl;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return true;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << "; amount: " << _amount << "; closed" << std::endl;
}

void Account::_displayTimestamp() {
	std::time_t t = std::time(NULL);
	char time_str[100];
	if (std::strftime(time_str, sizeof(time_str), "%Y%m%d_%H%M%S ", std::localtime(&t)))
		std::cout << time_str;
}
