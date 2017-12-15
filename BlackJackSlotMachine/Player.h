//
//  Player.hpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#ifndef Player_h
#define Player_h


#include "Account.h"
#include "Hand.h"
#include "Card.h"
#include <string>

class Player {
    private:
        Account playerAccount;
        Hand hand;
        Hand splitHand;
        double betAmount;
        bool hasSplit;
        bool usingSplitHand;
    
    public:
        Player();
        Player(Account);
        ~Player();
        void setAccount(Account);
        double getAccount() const;
        double bet(double);
        void resetHand();
        bool isSplit() const;
        void switchHands();
        string getCurrentHand();
        void setNumberOfCardsInHand(int);
        int getNumberOfCardsInHand() const;
        void addCard(Card&);
        int getValueOfCards();
        void stand();
        void hit(Card&);
        void split(Card&, Card&);
    
        void winGame();
        void loseGame();
        void tieGame();
};

#endif /* Player_h */
