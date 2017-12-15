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
    this->usingSplitHand = false;
    this->betAmount = 0;
}

Player::Player(Account accountNumber) {
    this->playerAccount = accountNumber;
    this->hasSplit = false;
    this->usingSplitHand = false;
    this->betAmount = 0;
}
Player::~Player(){
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
void Player::switchHands(){
	usingSplitHand = !usingSplitHand;
}
bool Player::isSplit() const{
	return hasSplit;
}
int Player::getNumberOfCardsInHand() const {
    if(usingSplitHand){
		return splitHand.getValueOfCards();
	}
    else{
    	return hand.getValueOfCards();
	}
}
string Player::getCurrentHand(){
	if(usingSplitHand){
		return splitHand.getType();
	}
	else{
		return hand.getType();
	}
}
void Player::addCard(Card& newCard) {
    hand.addCard(newCard);
}

int Player::getValueOfCards() {
	if(usingSplitHand){
		return splitHand.getValueOfCards();
	}
    else{
    	return hand.getValueOfCards();
	}
}

void Player::stand() {
	// Player does nothing
}

void Player::hit(Card& newCard) {
    if(usingSplitHand) {
    	splitHand.addCard(newCard);	
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
	splitHand.setType("Secondary");
}

void Player::winGame() {
    this->playerAccount.setTotalAmount(this->playerAccount.getTotalAmount() + (2 * this->betAmount));
    cout << "You win $" << betAmount << endl;
    cout << "The total amount in your account is $" << getAccount() << endl;
    betAmount = 0;
}

void Player::loseGame() {
	cout << "You lose $" << betAmount << endl;
    cout << "The total amount in your account is $" << getAccount() << endl;
    betAmount = 0;
}

void Player::tieGame(){
	// User bet is split in half
	this->playerAccount.setTotalAmount(this->playerAccount.getTotalAmount() + (this->betAmount / 2));
    betAmount = 0;
}






