#include "Hand.h"

Hand::Hand(){
	this->numberOfCards = 0;
	this->valueOfCards = 0;
	this->cardMemoryCapacity = 10;
	this->cards = new Card[cardMemoryCapacity];
}
Hand::Hand(Card* _cards){
	this->numberOfCards = 0;
	this->valueOfCards = 0;
	this->cardMemoryCapacity = 10;
	this->cards = _cards;
}

void Hand::addCard(Card& newCard){
	// ensure have enough memory in dynamic array
	if(this->numberOfCards < this->cardMemoryCapacity){
    	*(cards + numberOfCardsInHand + 1) = newCard;
    	this->valueOfCards += newCard.getValue();
    	this->numberOfCards++;
	}
	else{
		cout << "Card Memory Capacity exceeded. Unable to add new card. " << endl;
	}
}

int Hand::getValueOfCards(){
	return valueOfCards;
}
int getNumberOfCards() const{
	return numberOfCards;
}
