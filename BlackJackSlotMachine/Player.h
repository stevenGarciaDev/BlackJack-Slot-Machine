//
//  Player.hpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include <stdio.h>
#include "Account.h"
#include "Card.h"

class Player {
    private:
        Account playerAccount;
        Card* cards = nullptr;
        int numberOfCardsInHand;
    
    public:
        Player();
        void setNumberOfCardsInHand(int);
        int getNumberOfCardsInHand() const;
        void addCard(Card&);
        
};

#endif /* Player_h */
