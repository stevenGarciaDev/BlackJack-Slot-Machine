//
//  Account.cpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#include "Account.h"

Account::Account() {
    accountNumber = "";
    totalAmount = 0.0;
}

Account::Account(string accountNumber) {
    this->accountNumber = accountNumber;
}

string Account::getAccountNumber() const {
    return this->accountNumber;
}

void Account::setAccountNumber(string accountNumber) {
    this->accountNumber = accountNumber;
}

double Account::getTotalAmount() const {
    return this->totalAmount;
}

void Account::setTotalAmount(double totalAmount) {
    this->totalAmount = totalAmount;
}
