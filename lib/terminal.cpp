// terminal.cpp : This file contains the termial interface for the application.

#include <iostream>
#include "functions.h"

using namespace std;

void getUserTripInfo()
{
    Trip tempTrip;

    cout << "Enter the starting day of the trip: ";
    cin >> tempTrip.startingDay;
}

// Main menu function to display options to the user
void displayMenu()
{
    cout << "Travel Calculator Menu:" << endl;
    cout << "1. Calculate Trip Cost" << endl;
    cout << "2. Exit" << endl;
    cout << "Please select an option: ";
}
