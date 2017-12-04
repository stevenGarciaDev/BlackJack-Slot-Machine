//
//  Player.cpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#include "Player.h"
#include "Card.h"
#include <iostream>

using namespace std;

Player::Player(Account accountNumber) {
    this->playerAccount = accountNumber;
    this->numberOfCardsInHand = 0;
    this->valueOfCards = 0;
    
    this->cardMemoryCapacity = 4;
    this->cards = new Card[cardMemoryCapacity];
}

void Player::setNumberOfCardsInHand(int cardAmount) {
    this->numberOfCardsInHand = cardAmount;
}

int Player::getNumberOfCardsInHand() const {
    return this->numberOfCardsInHand;
}

void Player::addCard(Card& newCard) {
    // ensure have enough memory,
    
    
    *(cards + numberOfCardsInHand + 1) = newCard;
    setNumberOfCardsInHand(this->numberOfCardsInHand + 1);
}

int Player::getValueOfCards() {
    return this->valueOfCards;
}

void Player::stand() {
    
}

void Player::hit() {
    
}

void Player::split() {
    
}

double Player::winGame() {
    
    return 0.0;
}






