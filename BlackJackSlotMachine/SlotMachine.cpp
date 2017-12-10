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

using namespace std;

Card generateRandomCard();
const int POSSIBLE_CARDS = 13;

int main(int argc, const char * argv[]) {
    cout << fixed << showpoint << setprecision(2);
    
    bool isInvalidAccount = true;
    bool isInvalidAmount = true;
    bool userWantsToPlay = true;
    bool hasDistributedInitCards = false;
    string accountNumber;
    double amountBeingGambled;
    string userInputDecision;
    
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
            user.setAccountNumber(accountNumber);
            
        } catch (char const* exc) {
            cout << "Invalid account number." << endl;
        }
    } while (isInvalidAccount);
    
    /* ----------------
     Accept valid double precision amount that user wants to gamble.
     ---------------- */
    
    cin.ignore();
    int decimalOccurances = 0;
    
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
            
            cout << amountBeingGambled << endl;
            
            isInvalidAmount = false;
            
        } catch (char const* exc) {
            cout << "Invalid amount entered. Please enter in format example: 2500.00 " << endl;
        }
    } while( isInvalidAmount );
    
    /* ----------------
     Game functionality.
     ---------------- */
    
//    while (userWantsToPlay) {
//        
//        // generate four random cards, 2 for dealer, and 2 for player
//        if (!hasDistributedInitCards) {
//            for (int i = 0; i < 4; i++) {
//                
//            }
//            hasDistributedInitCards = true;
//        }
//        
//        cout << "The value of your cards is " << endl;
//        
//        // add input validation
//        cout << "Do you want to HIT, STAND, or SPLIT? : ";
//        cin >> userInputDecision;
//    }
    
    return 0;
}

Card generateRandomCard() {
    srand(time(0));
    int randomCardIdentifier = rand() % POSSIBLE_CARDS;
    Card newCard( randomCardIdentifier );
    
    return newCard;
}
