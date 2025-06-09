// terminal.cpp : This file contains the termial interface for the application.

#include <iostream>
#include <conio.h>
#include "functions.h"

using namespace std;

// trip tripUser; // Object for trip-related data
// transportationExpenses transportUser; // Object for transportation-related data
// parkingExpenses parkingUser; // Object for parking-related data
// hotelExpenses hotelUser; // Object for hotel-related data
// mealExpenses mealUser; // Object for meal-related data
// ConferenceOrRegistrationExpenses conferenceUser;

user newUser;

void travelExpenses() {
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
    newUser.totalRoundTrip = inputValue("Round-trip Airfare");
    cout << "Data Insert" << newUser.calculateAirfare();
        cout << "Total Transportation Cost:" << newUser.totalTransportationCost << endl;
        cin.get(); // 不要问我为什么要放两个cin.get()，删了就会出bug
        break;
    case 2:
    newUser.totalCarRental = inputValue("Car Rental");
    cout << "Data Insert" << newUser.calculateCarRental();
        cout << "Total Transportation Cost:" << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 3:
    newUser.milesDriven = inputValue("Miles Driven");
    cout << "Data Insert" << newUser.calculateMilesReimbursement();\
        cout << "Total Transportation Cost:" << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 4:
        newUser.parkingFeePerDay = inputValue("Parking Fee");
        cout << "Data Insert" << newUser.calculationParkingFee();
        cout << "Total parking fee: " << newUser.totalParkingFee << endl;
        cin.get();
        break;
    case 5:
    newUser.totalTaxiFee = inputValue("Taxi Fee");
    cout << "Data Insert" << newUser.calculateTaxiFee();
        cout << "Total transportation cost: " << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 6:
        newUser.conferenceFee = inputValue("Conference or Seminar Registration Fee");
        cout << "Data Insert" << newUser.calculateConferenceFee();
        cout << "Total transportation cost: " << newUser.totalConferenceFee << endl;
        cin.get();
        break;
    case 7:
        newUser.hotelFeePerNight = inputValue("Hotel Expenses");
        cout << "Data Insert" << newUser.calculateReimbursedHotelFee(newUser.totalNumberOfDays);
        cout << "Total hotel expenses: " << newUser.totalHotelExpenses << endl;
        cin.get();
        break;
    case 8:
        newUser.breakfastCost = inputValue("Breakfast Cost");
        newUser.lunchCost = inputValue("Lunch Cost");
        newUser.dinnerCost = inputValue("Dinner Cost");
        cout << "Data Insert" << newUser.calculateReimbursedMeals();
        cout << "Total meal cost: " << newUser.totalMealCost << endl;
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
    cout << "Trip Duration: " << newUser.totalNumberOfDays << " days" << endl;
    cout << "From:  Day " << newUser.startingDay << " / " << newUser.startingMonth << endl;
    cout << "To:    Day " << newUser.endingDay << " / " << newUser.endingMonth << endl;
    cout << "------------------------------------" << endl;

    // Transportation Expenses
    cout << "Transportation Expenses" << endl;
    cout << "Airfare:                       $" << newUser.totalRoundTrip << endl;
    cout << "Car Rental:                    $" << newUser.totalCarRental << endl;
    cout << "Miles Driven: " << newUser.milesDriven << " miles" << endl;
    cout << "Mileage Reimbursement:         $" << newUser.milesDriven * newUser.maxAllowancePerMile << endl;
    cout << "Taxi Fees:                     $" << newUser.totalTaxiFee << endl;
    cout << "Total Transportation Expenses: $" << newUser.totalTransportationCost << endl;
    cout << "------------------------------------" << endl;

    // Parking Expenses
    cout << "Parking Expenses" << endl;
    cout << "Daily Parking Fee:             $" << newUser.parkingFeePerDay << endl;
    cout << "Total Expenses:                $" << newUser.totalParkingFee << endl;
    cout << "------------------------------------" << endl;
    
    // Conference/Registration Expenses
    cout << "Conference/Registration" << endl;
    cout << "Total Fees:                    $" << newUser.totalConferenceFee << endl;
    cout << "------------------------------------" << endl;

    // Hotel Expenses
    cout << "Hotel Expenses" << endl;
    cout << "Hotel Fee Per Night:           $" << newUser.hotelFeePerNight << endl;
    cout << "Total Hotel Expenses:          $" << newUser.totalHotelExpenses << endl;
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
            cout << "Enter starting day of the trip" << endl;
            newUser.startingDay = inputValue("day", 0);
            
            cout << "\nEnter starting month of the trip" << endl;
            newUser.startingMonth = inputValue("month", 0);

            cout << "\nEnter ending day of the trip" << endl;
            newUser.endingDay = inputValue("day", 0);

            cout << "\nEnter ending month of the trip" << endl;
            newUser.endingMonth = inputValue("month", 0);

            newUser.totalNumberOfDays = newUser.calculateTotalDays();

            travelExpenses();
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
            return displayMenu();
        }
    }
}
