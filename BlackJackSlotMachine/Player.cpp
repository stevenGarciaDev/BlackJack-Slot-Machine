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
    
}

Player::Player(Account accountNumber) {
    this->playerAccount = accountNumber;
}

void Player::setAccount(Account userAccount) {
    this->playerAccount = userAccount;
}

double Player::getAccount() const {
    return playerAccount.getTotalAmount();
}

int Player::getNumberOfCardsInHand() const {
    return hand.getNumberOfCards();
}

void Player::addCard(Card& newCard) {
    hand.addCard(newCard);
}

int Player::getValueOfCards() {
    return hand.getValueOfCards();
}

void Player::stand() {
    // Player does nothing
}

void Player::hit(Card& newCard) {
    addCard(newCard);
    if (hand.getValueOfCards() > 21) {
        loseGame();
    }
}

void Player::split() {
//    this->splitCards = new Card[cardMemoryCapacity];
	// 
}

void Player::winGame() {
    // User bet is doubled
    cout << "You win this game!" << endl;
}

void Player::loseGame() {
	// User wins nothing
    cout << "You lose this game." << endl;
}

void Player::tieGame(){
	// User bet is split in half
}






