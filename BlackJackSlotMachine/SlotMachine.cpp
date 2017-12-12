//
//  main.cpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#include <iostream>
#include <stdlib.h> // for rand() and srand() function
#include <exception>
#include <iomanip>
#include "Player.h"
#include "Account.h"
#include "Card.h"

using namespace std;

Card generateRandomCard();
const int POSSIBLE_CARDS = 13;
bool playAgain();

int main(int argc, const char * argv[]) {
    cout << fixed << showpoint << setprecision(2);
    
    bool isInvalidAccount = true;
    bool isInvalidAmount = true;
    bool userWantsToPlay = true;
    bool hasDistributedInitCards = false;
    int decimalOccurances = 0;
    string accountNumber;
    double amountBeingGambled;
    string userInputDecision;
    
    Account userAccount;
    Player dealer;
    Player user;
    
    /* ----------------
     Accept a valid user account number.
     ---------------- */
    
    do {
        cout << "Enter your account number: ";
        try {
            cin >> accountNumber;
            
            for (int i = 0; i < accountNumber.length(); i++) {
                if (48 > accountNumber[i] || 57 < accountNumber[i]) {
                    throw "Invalid Character";
                }
            }
            isInvalidAccount = false;
            userAccount.setAccountNumber(accountNumber);
            
        } catch (char const* exc) {
            cout << "Invalid account number." << endl;
        }
    } while (isInvalidAccount);
    
    /* ----------------
     Accept valid double precision amount that user wants to gamble.
     ---------------- */
    
    cin.ignore();
    
    do {
        try {
            cout << "Enter the amount of money you want to bet (Ex: 1150.49): ";
            getline(cin, userInputDecision); // take in input as a string
            
            for (int i = 0; i < userInputDecision.length(); i++) {
                if (userInputDecision[i] == 46) {
                    decimalOccurances++;
                    
                    if (decimalOccurances > 1) {
                        throw "Invalid Character, too many decimal points";
                    }
                    
                    continue;
                }
                
                if (48 > userInputDecision[i] || 57 < userInputDecision[i]) {
                    throw "Invalid Character";
                 }
            }
            
            // str needs to be converted to c_str then converted to double value
            amountBeingGambled = atof(userInputDecision.c_str());
            userAccount.setTotalAmount( amountBeingGambled );
            cout << amountBeingGambled << endl;
            
            isInvalidAmount = false;
            
        } catch (char const* exc) {
            cout << "Invalid amount entered. Please enter in format example: 2500.00 " << endl;
        }
    } while( isInvalidAmount );
    
    user.setAccount(userAccount);
    
    /* ----------------
     Game functionality.
     ---------------- */
    
    cout << "Welcome to Blackjack! \n" << endl;
    
    Card newCard = generateRandomCard();
    
    // generate four random cards, 2 for dealer, and 2 for player
//        if (!hasDistributedInitCards) {

            for (int i = 0; i < 2; i++) {
                Card newUserCard = generateRandomCard();
                user.addCard( newUserCard );
                cout << "line 200" << endl;
                Card newDealerCard = generateRandomCard();
                dealer.addCard( newDealerCard );
            }
            
            hasDistributedInitCards = true;
//        }
    while (userWantsToPlay) {
    	bool playing = true;
    	while(playing){
	    	while(dealer.getValueOfCards() < 12){
	    		// Dealer will hit as long as cards are less than 12
	    		Card newDealerCard = generateRandomCard();
	    		dealer.hit(newDealerCard);
			}
	        
	        cout << "The value of the dealer's cards is " << dealer.getValueOfCards() << endl;
	        cout << "The value of your cards is " << user.getValueOfCards() <<  endl;
	        
	        // add input validation
	        cout << "Do you want to HIT, STAND, or SPLIT? : ";
	        cin >> userInputDecision;
	        if(userInputDecision == "HIT"){
	        	Card newUserCard = generateRandomCard();
	            user.hit( newUserCard );
			}
			else if(userInputDecision == "SPLIT"){
				Card card1 = generateRandomCard();
				Card card2 = generateRandomCard();
				user.split(card1, card2);
			}
			else if(userInputDecision == "STAND"){
				user.stand();
			}
	        if(user.getValueOfCards() > 21){
	        	user.loseGame();
	        	playing = false;
			}
			else if(user.getValueOfCards() == 21){
				user.winGame();
				playing = false;
			}
			else if(dealer.getValueOfCards() > 21){
				user.winGame();
				playing = false;
			}
		}
		
		// Prompt user to play again
		userWantsToPlay = playAgain();
    }
    
    return 0;
}

Card generateRandomCard() {
    srand(time(0));
    int randomCardIdentifier = rand() % POSSIBLE_CARDS;
    //Card newCard( randomCardIdentifier );
    Card* newCard = new Card( randomCardIdentifier );
    return *newCard;
}

bool playAgain(){
	char userChoice;
	while(true){
		// loop only breaks when given valid answer (Y/N)
		cout << "Would you like to play again (Y/N)?" << endl;
		cin >> userChoice;
		if(userChoice == 'Y') return true; 
		else if (userChoice == 'N') return false;
		else cout << "Please enter a valid answer (Y/N)" << endl;
	}
	
}
