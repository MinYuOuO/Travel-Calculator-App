// terminal.cpp : This file contains the termial interface for the application.

#include <iostream>
#include <conio.h>
#include "functions.h"

using namespace std;

trip tripUser; // Object for trip-related data
transportationExpenses transportUser; // Object for transportation-related data
parkingExpenses parkingUser; // Object for parking-related data
hotelExpenses hotelUser; // Object for hotel-related data
mealExpenses mealUser; // Object for meal-related data
ConferenceOrRegistrationExpenses conferenceUser;

void calculatorMenu() {
    system("cls");
    //@brief Section of the code that handles user input
    int choose;

    cout << "------------------------------------" << endl;
    cout << "Travel Calculator Menu:" << endl;
    cout << "1. Amount Round-trip airfare" << endl;
    cout << "2. Amount of Car Rentals" << endl;
    cout << "3. Vehicle Driven" << endl;
    cout << "4. Insert Parking Fee" << endl;
    cout << "5. Taxi Fees" << endl;
    cout << "6. Conference or Seminar Registration Fee" << endl;
    cout << "7. Hotel Expenses" << endl;
    cout << "8. Meal Expenses" << endl;
    cout << "9. Back" << endl;
    cout << "Please select an option: ";
    cin >> choose;
    cout << "------------------------------------" << endl;

    switch (choose) {
    case 1:
        transportUser.totalRoundTrip = inputValue("Round-trip Airfare");
        transportUser.calculateAirfare();
        cout << "Total Transportation Cost:" << transportUser.totalTransportationCost << endl;
        cin.get(); // 不要问我为什么要放两个cin.get()，删了就会出bug
        break;
    case 2:
        transportUser.totalCarRental = inputValue("Car Rental");
        transportUser.calculateCarRental();
        cout << "Total Transportation Cost:" << transportUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 3:
        transportUser.milesDriven = inputValue("Miles Driven");
        transportUser.calculateMilesReimbursement();\
        cout << "Total Transportation Cost:" << transportUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 4:
        parkingUser.parkingFeePerDay = inputValue("Parking Fee");
        parkingUser.calculationParkingFee();
        cout << "Total parking fee: " << parkingUser.totalParkingFee << endl;
        cin.get();
        break;
    case 5:
        transportUser.totalTaxiFee = inputValue("Taxi Fee");
        transportUser.calculateTaxiFee();
        cout << "Total transportation cost: " << transportUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 6:
        conferenceUser.conferenceFee = inputValue("Conference or Seminar Registration Fee");
        conferenceUser.calculateConferenceFee();
        cout << "Total transportation cost: " << conferenceUser.totalConferenceFee << endl;
        cin.get();
        break;
    case 7:
        hotelUser.hotelFeePerNight = inputValue("Hotel Expenses");
        hotelUser.calculateReimbursedHotelFee(tripUser.totalNumberOfDays);
        cout << "Total hotel expenses: " << hotelUser.totalHotelExpenses << endl;
        cin.get();
        break;
    case 8:
        mealUser.breakfastCost = inputValue("Breakfast Cost");
        mealUser.lunchCost = inputValue("Lunch Cost");
        mealUser.dinnerCost = inputValue("Dinner Cost");
        mealUser.calculateReimbursedMeals();
        cout << "Total meal cost: " << mealUser.totalMealCost << endl;
        cin.get();
        break;
    case 9:
        return displayMenu();
    default:
        cout << "Invalid choice. Please try again." << endl;
        cin.get();
    }

    cout << "------------------------------------";
    cout << '\n' << "Press a key to continue...";
    cin.get();
    return calculatorMenu();

}

/**
 * @brief 
 * 
 */
void expensesReport() {
    system("cls");

    cout << "===== Travel Expenses Report =====" << endl;
    cout << "------------------------------------" << endl;

    // Trip Duration Information
    cout << "Trip Duration: " << tripUser.totalNumberOfDays << " days" << endl;
    cout << "From:  Day " << tripUser.startingDay << " / " << tripUser.startingMonth << endl;
    cout << "To:    Day " << tripUser.endingDay << " / " << tripUser.endingMonth << endl;
    cout << "------------------------------------" << endl;

    // Transportation Expenses
    cout << "Transportation Expenses" << endl;
    cout << "Airfare:                       $" << transportUser.totalRoundTrip << endl;
    cout << "Car Rental:                    $" << transportUser.totalCarRental << endl;
    cout << "Miles Driven: " << transportUser.milesDriven << " miles" << endl;
    cout << "Mileage Reimbursement:         $" << transportUser.milesDriven * transportUser.maxAllowancePerMile << endl;
    cout << "Taxi Fees:                     $" << transportUser.totalTaxiFee << endl;
    cout << "Total Transportation Expenses: $" << transportUser.totalTransportationCost << endl;
    cout << "------------------------------------" << endl;

    // Parking Expenses
    cout << "Parking Expenses" << endl;
    cout << "Daily Parking Fee:             $" << parkingUser.parkingFeePerDay << endl;
    cout << "Total Expenses:                $" << parkingUser.totalParkingFee << endl;
    cout << "------------------------------------" << endl;
    
    // Conference/Registration Expenses
    cout << "Conference/Registration" << endl;
    cout << "Total Fees:                    $" << conferenceUser.totalConferenceFee << endl;
    cout << "------------------------------------" << endl;

    // Hotel Expenses
    cout << "Hotel Expenses" << endl;
    cout << "Hotel Fee Per Night:           $" << hotelUser.hotelFeePerNight << endl;
    cout << "Total Hotel Expenses:          $" << hotelUser.totalHotelExpenses << endl;
}

// Main menu function to display options to the user
void displayMenu()
{
    while (true) {
        system("cls");
        cout << "Travel Calculator Menu:" << endl;
        cout << "1. Calculate Trip Cost" << endl;
        cout << "2. View Expenses Report" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";

        int n;
        cin >> n;

        if (n == 1) {
            system("cls");
            cout << "Trip Cost Calculator" << endl;
            cout << "Enter starting day of the trip: ";
            cin >> tripUser.startingDay;
            cout << "\nEnter starting month of the trip: ";
            cin >> tripUser.startingMonth;
            cout << "\nEnter ending day of the trip: ";
            cin >> tripUser.endingDay;
            cout << "\nEnter ending month of the trip: ";
            cin >> tripUser.endingMonth;

            tripUser.totalNumberOfDays = tripUser.calculateTotalDays();

            calculatorMenu();
        }
        else if (n == 2) {
            cin.get(); // 不要问我为什么要放两个，删了就会出bug
            expensesReport();
            cout << "------------------------------------";
            cout << '\n' << "Press a key to continue...";
            cin.get();
        }
        else if (n == 3) {
            cout << "Exiting the program." << endl;
            exit(0);
        }
        else {
            cin.get(); // 不要问我为什么要放两个，删了就会出bug
            cout << "Error: Invalid choice. Please try again." << endl;
            cout << "------------------------------------";
            cout << '\n' << "Press a key to continue...";
            cin.get();
        }
    }
}
