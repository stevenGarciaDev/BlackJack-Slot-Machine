//
//  Account.hpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#ifndef Account_h
#define Account_h

#include <string>

using namespace std;

class Account {
    private:
        string accountNumber;
        double totalAmount;
    
    public:
        Account();
        Account(string);
        ~Account();
        string getAccountNumber() const;
        void setAccountNumber(string);
        double getTotalAmount() const;
        void setTotalAmount(double);
};

#endif /* Account_h */
