//
//  main.cpp
//  BlackJackSlotMachine
//
//  Created by Steven Garcia on 11/20/17.
//  Copyright © 2017 Steven Garcia. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int accountNumber;
    double amountBeingGambled;
    string userInputDecision;
    
    cout << "Enter your account number: ";
    try {
        cin >> accountNumber;
    } catch () {
        cout << "Invalid account number." << endl;
    }
    
    cout << "Enter the amount of money you want to bet: ";
    cin >> amountBeingGambled;
    
    // generate random two cards to display
    
    //
    
    cout << "The value of your cards is " << endl;
    cout << "Do you want to HIT, STAND, or SPLIT? : ";
    cin >> userInputDecision;
    
    return 0;
}
