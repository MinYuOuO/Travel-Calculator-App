// terminal.cpp : This file contains the termial interface for the application.

#include <iostream>
#include "functions.h"

using namespace std;

trip tripUser; // Object for trip-related data
transportationExpenses transportUser; // Object for transportation-related data
parkingExpenses parkingUser; // Object for parking-related data
hotelExpenses hotelUser; // Object for hotel-related data
mealExpenses mealUser; // Object for meal-related data
ConferenceOrRegistrationExpenses ConferenceUser;

void calculatorMenu() {
    /**
     * @brief Section of the code that handles user input
     *
     */
    int choose;

    cout << "--------------------------------" << endl;
    cout << "Travel Calculator Menu:" << endl;
    cout << "1. Amount Round-trip airfare" << endl;
    cout << "2. Amount of Car Rentals" << endl;
    cout << "3. Vehicle Driven" << endl;
    cout << "4. Insert Parking Fee" << endl;
    cout << "5. Taxi Fees" << endl;
    cout << "6. Conference or Seminar Registration Fee" << endl;
    cout << "7. Hotel Expenses" << endl;
    cout << "8. Meal Expenses" << endl;
    cout << "9. Exit" << endl;
    cout << "Please select an option: ";
    cin >> choose;
    cout << "--------------------------------" << endl;

    switch (choose) {
    case 1:
        transportUser.totalRoundTrip = inputValue("Round-trip Airfare");
        transportUser.calculateAirfare();
        return calculatorMenu(); // go back
    case 2:
        transportUser.totalCarRental = inputValue("Car Rental");
        transportUser.calculateCarRental();
        return calculatorMenu(); // go back
    case 3:
        transportUser.milesDriven = inputValue("Miles Driven");
        transportUser.calculateMilesReimbursement();
        return calculatorMenu(); // go back
    case 4:
        parkingUser.parkingFeePerDay = inputValue("Parking Fee");
        parkingUser.calculationParkingFee();
        cout << "Total parking fee: " << parkingUser.totalParkingFee << endl;
        return calculatorMenu(); // go back
    case 5:
        transportUser.totalTaxiFee = inputValue("Taxi Fee");
        transportUser.calculateTaxiFee();
        cout << "Total transportation cost: " << transportUser.totalTransportationCost << endl;
        return calculatorMenu();
    case 6:
        double registrationFee; 
        ConferenceUser.conferenceFee = inputValue("Conference or Seminar Registration Fee");
        ConferenceUser.calculateConferenceFee();
        return calculatorMenu();
    case 7:
        hotelUser.hotelFeePerNight = inputValue("Hotel Expenses");
        hotelUser.calculateReimbursedHotelFee(tripUser.totalNumberOfDays);
        cout << "Total hotel expenses: " << hotelUser.totalHotelExpenses << endl;
        return calculatorMenu();
    case 8:
        mealUser.breakfastCost = inputValue("Breakfast Cost");
        mealUser.lunchCost = inputValue("Lunch Cost");
        mealUser.dinnerCost = inputValue("Dinner Cost");
        mealUser.calculateReimbursedMeals();
        cout << "Total meal cost: " << mealUser.totalMealCost << endl;
        return calculatorMenu();
    case 9:
        exit(0);
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
}

// Main menu function to display options to the user
void displayMenu()
{
    while (true) {
        cout << "Travel Calculator Menu:" << endl;
        cout << "1. Calculate Trip Cost" << endl;
        cout << "2. View Expenses Report" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";

        int n;
        cin >> n;

        if (n == 1) {
            cout << "Trip Cost Calculator" << endl;
            cout << "Enter starting day of the trip:";
            cin >> tripUser.startingDay;
            cout << "Enter starting month of the trip:";
            cin >> tripUser.startingMonth;
            cout << "Enter ending day of the trip:";
            cin >> tripUser.endingDay;
            cout << "Enter ending month of the trip:";
            cin >> tripUser.endingMonth;

            tripUser.totalNumberOfDays = tripUser.calculateTotalDays();

        }
        else if (n == 2) {
            cin.ignore();
        }
        else if (n == 3) {
            cout << "Exiting the program." << endl;
            exit(0);
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}
