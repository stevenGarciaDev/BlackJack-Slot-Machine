//
//  main.cpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#include <iostream>
#include "Player.h"

using namespace std;

Card generateRandomCard();

int main(int argc, const char * argv[]) {
    bool isInvalidAccount = true;
    bool userWantsToPlay = true;
    string accountNumber;
    double amountBeingGambled;
    string userInputDecision;
    
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
            
        } catch (char const* exc) {
            cout << "Invalid account number." << endl;
        }
    } while (isInvalidAccount);
    
    
    // add input validation here
    cout << "Enter the amount of money you want to bet (Ex: 150.49): ";
    cin >> amountBeingGambled;

    while (userWantsToPlay) {
        // generate four random cards, 2 for dealer, and 2 for player
        
        cout << "The value of your cards is " << endl;
        
        // add input validation
        cout << "Do you want to HIT, STAND, or SPLIT? : ";
        cin >> userInputDecision;
        
    }
    
    return 0;
}
