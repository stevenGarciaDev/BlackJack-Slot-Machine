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

Player::Player() {
    this->numberOfCardsInHand = 0;
    this->valueOfCards = 0;
    
    this->cardMemoryCapacity = 10;
    this->cards = new Card[cardMemoryCapacity];
}

Player::Player(Account accountNumber) {
    this->playerAccount = accountNumber;
    this->numberOfCardsInHand = 0;
    this->valueOfCards = 0;
    
    this->cardMemoryCapacity = 10;
    this->cards = new Card[cardMemoryCapacity];
}

void Player::setAccount(Account userAccount) {
    this->playerAccount = userAccount;
}

double Player::getAccount() const {
    return playerAccount.getTotalAmount();
}

void Player::setNumberOfCardsInHand(int cardAmount) {
    this->numberOfCardsInHand = cardAmount;
}

int Player::getNumberOfCardsInHand() const {
    return this->numberOfCardsInHand;
}

void Player::addCard(Card& newCard) {
    // ensure have enough memory in dynamic array
    
    *(cards + numberOfCardsInHand + 1) = newCard;
    this->valueOfCards += newCard.getValue();
    setNumberOfCardsInHand(this->numberOfCardsInHand + 1);
}

int Player::getValueOfCards() {
    return this->valueOfCards;
}

void Player::stand() {
    
}

void Player::hit(Card& newCard) {
    addCard(newCard);
    if (valueOfCards >= 21) {
        loseGame();
    }
}

void Player::split() {
    
}

void Player::winGame() {
    
    cout << "You win this game!" << endl;
}

void Player::loseGame() {
    cout << "You lose this game." << endl;
}






