// terminal.cpp : This file contains the termial interface for the application.

#include <iostream>
#include "functions.h"

using namespace std;

// Main menu function to display options to the user
void displayMenu()
{
    trip tripUser; // Object for trip-related data
    transportationExpenses transportUser; // Object for transportation-related data
    parkingExpenses parkingUser; // Object for parking-related data
    hotelExpenses hotelUser; // Object for hotel-related data
    mealExpenses mealUser; // Object for meal-related data

    cout << "Travel Calculator Menu:" << endl;
    cout << "1. Calculate Trip Cost" << endl;
    cout << "2. Exit" << endl;
    cout << "Please select an option: ";

    int n;
    cin >> n;
}
