#ifndef Hand_h
#define Hand_h

#include <string>
#include "Card.h"

using namespace std;

class Hand{
	private:
		Card* cards = nullptr;
		string type;
		int valueOfCards;
		int numberOfCards;
		int cardMemoryCapacity;
    
	public:
		Hand();
		Hand(string);
		~Hand();
		void addCard(Card&);
		string getType() const;
		void setType(string);
        int getValueOfCards() const;
        void setValueOfCards(int);
        int getNumberOfCards() const;
        void setNumberOfCards(int);
        void allocateDynamicMemory();
        
};

#endif
