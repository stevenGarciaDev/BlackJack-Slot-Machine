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
#include <algorithm> // for transform()
#include <iomanip>
#include "Player.h"
#include "Account.h"
#include "Card.h"

using namespace std;

Card generateRandomCard();
const int POSSIBLE_CARDS = 13;
bool playAgain();
string getUserDecision();
double getAmountToBet(string, double);

int main(int argc, const char * argv[]) {
    cout << fixed << showpoint << setprecision(2);
    
    bool isInvalidAccount = true;
    bool isInvalidAmount = true;
    bool userWantsToPlay = true;
    int decimalOccurances = 0;
    string accountNumber;
    string userInputDecision;
    double amountBeingGambled;
    
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
     Set amount in account.
     ---------------- */
    
    do {
        try {
            cout << "\nEnter the amount of money you want in account (Ex: 1150.49): ";
            //getline(cin, userInputDecision); // take in input as a string
            cin >> userInputDecision;
            
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
            userAccount.setTotalAmount(amountBeingGambled);
            cout << endl; // Output formatting
            cout << "The total amount in your account: $" << amountBeingGambled << endl;
            
            isInvalidAmount = false;
            
        } catch (char const* exc) {
            cout << "Invalid amount entered. Please enter in format example: 2500.00 " << endl;
        }
    } while( isInvalidAmount );
    
    user.setAccount(userAccount);
    
    /* ----------------
     Game functionality.
     ---------------- */
    
    cout << endl; // Output formatting
    cout << "Welcome to Blackjack! \n" << endl;
    
    
    // Loop Until User decides not to play
    while (userWantsToPlay) {
    	
        amountBeingGambled = getAmountToBet(userInputDecision, user.getAccount());
    	user.bet(amountBeingGambled);
        cout << "Total amount in your account: $" << user.getAccount() << endl;
        
    	user.resetHand();
    	dealer.resetHand();
    	// generate initial four random cards, 2 for dealer, and 2 for player
	    for (int i = 0; i < 2; i++) {
	        Card newUserCard = generateRandomCard();
	        user.addCard( newUserCard );
	        Card newDealerCard = generateRandomCard();
	        dealer.addCard( newDealerCard );
	    }
    	
    	// Infinite Loop will Break when Dealer or User loses/wins
    	while(true){
	    	while(dealer.getValueOfCards() < 15 ){
	    		// Dealer will continue to hit as long as cards are less than 15
	    		Card newDealerCard = generateRandomCard();
	    		dealer.hit(newDealerCard);
	    		if(dealer.getValueOfCards() > 21){
	    			break;
				}
			}
	        
	        cout << "The value of the dealer's cards is " << dealer.getValueOfCards() << endl;
	        cout << "The value of your current hand is " << user.getValueOfCards() <<  endl;
	        
	        // add input validation
	        userInputDecision = getUserDecision();
	        
	        if(userInputDecision == "HIT"){
	        	cout << endl; // Output formatting
	        	cout << "Dealing card..." << endl; // Output formatting
	        	Card newUserCard = generateRandomCard();
	            user.hit( newUserCard );
	            if(user.getValueOfCards() > 21){
	            	cout << "The value of your hand is " << user.getValueOfCards() << endl;
	            	user.loseGame();
	            	break;
				}
				else if(user.getValueOfCards() == 21){
					cout << "The value of your hand is " << user.getValueOfCards() << endl;
					user.winGame();
					break;
				}
			}
			else if(userInputDecision == "SPLIT"){
				// Need to add Player implementation of split scenario
				Card card1 = generateRandomCard();
				Card card2 = generateRandomCard();
				user.split(card1, card2);
				if(user.getValueOfCards() > 21){
	            	user.loseGame();
	            	break;
				}
			}
			else if(userInputDecision == "STAND"){
				user.stand(); // Arbitrary function; does nothing
				if(dealer.getValueOfCards() > 21){
					user.winGame();
					break;
				}
				else{
					if(user.getValueOfCards() < dealer.getValueOfCards()){
						user.loseGame();
						break;
					}
					else{
						user.winGame();
						break;
					}
				}
			}
		}
		
		// Prompt user to play again
		userWantsToPlay = playAgain();
	}
    
    return 0;
}

Card generateRandomCard() {
    srand(time(0));
    int randomCardIdentifier = 0;
    // Loop ensures that 0 is not returned
    while(randomCardIdentifier <= 0){
    	randomCardIdentifier = rand() % POSSIBLE_CARDS;
	}
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
string getUserDecision(){
	string input;
	while(true){
		cout << "Do you want to HIT, STAND, or SPLIT? : ";
		cin >> input;
		
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		
		if(input == "HIT")
	    	return "HIT";
		else if(input == "SPLIT")
			return "SPLIT";
		else if(input == "STAND")
			return "STAND";
		else
			cout << "Please enter a valid answer. " << endl;
	}
}

double getAmountToBet(string userInputDecision, double maxAmount) {
    bool isInvalidAmount = true;
    int decimalOccurances = 0;
    double amountBeingGambled = 0;
    
    do {
        try {
            cout << "\nEnter the amount of money you want to bet (Ex: 1150.49): ";
            //getline(cin, userInputDecision); // take in input as a string
            cin >> userInputDecision;

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
            cout << endl; // Output formatting
            
            if (amountBeingGambled > maxAmount) {
                cout << "Invalid amount. Must enter amount less than or equal to $" << maxAmount << endl;
                continue;
            }
            
            cout << "The amount being gambled is: $" << amountBeingGambled << endl;
            
            isInvalidAmount = false;
            
        } catch (char const* exc) {
            cout << "Invalid amount entered. Please enter in format example: 2500.00 " << endl;
        }
    } while( isInvalidAmount );
    
    return amountBeingGambled;
}

