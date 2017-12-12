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
    this->hasSplit = false;
    this->betAmount = 0;
}

Player::Player(Account accountNumber) {
    this->playerAccount = accountNumber;
    this->hasSplit = false;
    this->betAmount = 0;
}

void Player::setAccount(Account userAccount) {
    this->playerAccount = userAccount;
}

double Player::getAccount() const {
    return playerAccount.getTotalAmount();
}
double Player::bet(double amount){
	this->playerAccount.setTotalAmount(this->playerAccount.getTotalAmount() - amount);
	this->betAmount += amount;
    return this->betAmount;
}
void Player::resetHand(){
	// !!!Potential Memory Leak!!!
	Hand* newHand = new Hand();
	this->hand = *newHand;
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
    if (hand.getValueOfCards() > 21){
        if(this->hasSplit) {
        	splitHand.addCard(newCard);	
		}
    }
    else{
    	hand.addCard(newCard);
	}
}

void Player::split(Card& handCard, Card& splitCard) {
	this->hasSplit = true;
	bet(this->betAmount); // Double the bet
	hand.addCard(handCard);
	splitHand.addCard(splitCard);
}

void Player::winGame() {
    this->playerAccount.setTotalAmount(this->playerAccount.getTotalAmount() + (2 * this->betAmount));
    cout << "You win $" << betAmount << endl;
    betAmount = 0;
}

void Player::loseGame() {
	cout << "You lose $" << betAmount << endl;
    betAmount = 0;
}

void Player::tieGame(){
	// User bet is split in half
	this->playerAccount.setTotalAmount(this->playerAccount.getTotalAmount() + (this->betAmount / 2));
    betAmount = 0;
}






