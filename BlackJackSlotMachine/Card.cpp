//
//  Card.cpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#include "Card.h"

using namespace std;

/**
 This constructor allows for instantiating
 of any one of possible cards based on the
 argument of a randomly generated number.
 **/
Card::Card(int randomNum) {
    switch (randomNum) {
        case 1:
            // ace
            this->cardType = "Ace";
            this->value = 1; // 1 or 11 based on hand
            break;
        case 2:
            this->cardType = "Face Value";
            this->value = 2;
            break;
        case 3:
            this->cardType = "Face Value";
            this->value = 3;
            break;
        case 4:
            this->cardType = "Face Value";
            this->value = 4;
            break;
        case 5:
            this->cardType = "Face Value";
            this->value = 5;
            break;
        case 6:
            this->cardType = "Face Value";
            this->value = 6;
            break;
        case 7:
            this->cardType = "Face Value";
            this->value = 7;
            break;
        case 8:
            this->cardType = "Face Value";
            this->value = 8;
            break;
        case 9:
            this->cardType = "Face Value";
            this->value = 9;
            break;
        case 10:
            this->cardType = "Face Value";
            this->value = 10;
            break;
        case 11:
            this->cardType = "King (FaceCard)";
            this->value = 10;
            break;
        case 12:
            this->cardType = "Queen (FaceCard)";
            this->value = 10;
            break;
        case 13:
            this->cardType = "Jack (FaceCard)";
            this->value = 10;
            break;
    }
}

string Card::getCardType() const {
    return this->cardType;
}

int Card::getValue() const {
    return this->value;
}

void Card::setValue(int value) {
    this->value = value;
}














