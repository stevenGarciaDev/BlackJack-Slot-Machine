#ifndef Hand_h
#define Hand_h

#include "Card.h"

using namespace std;

class Hand{
	private:
		Card* cards = nullptr;
		int valueOfCards;
		int numberOfCards;
		int cardMemoryCapacity;
	public:
		Hand();
		Hand(Card&);
		void addCard(Card&);
        int getValueOfCards();
        void setValueOfCards(int);
        int getNumberOfCards() const;
        
};

#endif
