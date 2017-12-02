//
//  Card.hpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include <string>

using namespace std;

class Card {
    private:
        string cardType;
        int value;
    
    public:
        Card(int);
        string getCardType() const;
        int getValue() const;
        void setValue(int);
};

#endif /* Card_h */
