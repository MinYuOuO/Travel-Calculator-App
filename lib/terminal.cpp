// terminal.cpp : This file contains the termial interface for the application.

#include <iostream>
#include <conio.h>
#include "functions.h"

using namespace std;

// Old Reference before inheritance class retreve
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

    cout << "--------------------------------------------" << endl;
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
    cout << "--------------------------------------------" << endl;

    double temp;

    switch (choose) {
    case 1:
        newUser.roundTrip = inputValue("Round-trip Airfare");
        temp = newUser.calculateAirfare();
        cout << "Data Insert: $" << temp << endl;
        cout << "Total Round Trip Cost: $" << newUser.totalRoundTrip << endl;
        cout << "Total Transportation Expenses: $" << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 2:
        newUser.carRental = inputValue("Car Rental");
        temp = newUser.calculateCarRental();
        cout << "Data Insert $" << temp << endl;
        cout << "Total Car Rental Cost: $" << newUser.totalCarRental << endl;
        cout << "Total Transportation Expenses: $" << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 3:
        newUser.milesDriven = inputValue("Miles Driven (km)");
        temp = newUser.calculateMilesReimbursement();
        cout << "Data Insert: $" << temp << endl;
        cout << "Total Fuel Cost: $" << newUser.totalFuelCost << endl;
        cout << "Total Transportation Expenses: $" << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 4:
        newUser.parkingFeePerDay = inputValue("Parking Fee");
        temp = newUser.calculationParkingFee(newUser.totalTripDays);
        cout << "Data Insert: $" << temp << endl;
        cout << "Total parking fee: $" << newUser.totalParkingFee << endl;
        cout << "Total Transportation Expenses: $" << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 5:
        newUser.taxiFee = inputValue("Taxi Fee");
        temp = newUser.calculateTaxiFee();
        cout << "Data Insert: $" << temp << endl;
        cout << "Total taxi cost: $" << newUser.totalTaxiFee << endl;
        cout << "Total Transportation Expenses: $" << newUser.totalTransportationCost << endl;
        cin.get();
        break;
    case 6:
        newUser.conferenceFee = inputValue("Conference or Seminar Registration Fee");
        temp = newUser.calculateConferenceFee();
        cout << "Data Insert: $" << temp << endl;
        cout << "Total Fee: $" << newUser.totalConferenceFee << endl;
        cin.get();
        break;
    case 7:
        newUser.hotelFeePerNight = inputValue("Hotel Expenses");
        temp = newUser.calculateReimbursedHotelFee(newUser.totalTripDays);
        cout << "Data Insert: $" << temp << endl;
        cout << "Total hotel expenses: $" << newUser.totalHotelExpenses << endl;
        cin.get();
        break;
    case 8:
        newUser.breakfastCost = inputValue("Breakfast Cost");
        newUser.lunchCost = inputValue("Lunch Cost");
        newUser.dinnerCost = inputValue("Dinner Cost");
        temp = newUser.calculateReimbursedMeals();
        cout << "Data Insert" << temp << endl;
        cout << "Total meal cost: " << newUser.totalMealCost << endl;
        cin.get();
        break;
    case 9:
        return displayMenu();
    default:
        cout << "Invalid choice. Please try again." << endl;
        cin.get();
    }

    cout << "--------------------------------------------" << endl;
    cout << '\n' << "Press a key to continue..." << endl;
    cin.get();
    return travelExpenses();
}

/**
 * @brief 
 * 
 */
void expensesReport() {
    system("cls");

    cout << "========== Travel Expenses Report ==========" << endl;
    cout << "--------------------------------------------" << endl;

    // Trip Duration Information
    cout << "Trip Duration: " << newUser.totalTripDays << " days" << endl;
    cout << "From:  Day " << newUser.startingDay << " / " << newUser.startingMonth << endl;
    cout << "To:    Day " << newUser.endingDay << " / " << newUser.endingMonth << endl;
    cout << "--------------------------------------------" << endl;

    // Transportation Expenses
    cout << "Transportation Expenses" << endl;
    cout << "Airfare:                               $" << newUser.totalRoundTrip << endl;
    cout << "Car Rental:                            $" << newUser.totalCarRental << endl;
    cout << "Mileage Reimbursement:                 $" << newUser.totalFuelCost << endl;
    cout << "Taxi Fees:                             $" << newUser.totalTaxiFee << endl;
    cout << "                                       -----" << endl;
    cout << "Total Transportation Expenses:         $" << newUser.totalTransportationCost << endl;
    cout << "                                       -----" << endl;

    // Parking Expenses
    cout << "Total Parking Expenses:                $" << newUser.totalParkingFee << endl;
    cout << "                                       -----" << endl;
    
    // Conference/Registration Expenses
    cout << "Total Conference/Registration Fees:    $" << newUser.totalConferenceFee << endl;
    cout << "                                       -----" << endl;

    // Hotel Expenses
    cout << "Total Hotel Expenses:                  $" << newUser.totalHotelExpenses << endl;
    cout << "                                       -----" << endl;

    // Meal Expenses
    cout << "Total Meal Expenses:                   $" << newUser.totalMealCost << endl;
    cout << "                                       -----" << endl;
    
    newUser.totalTripCost = newUser.totalTransportationCost + newUser.totalParkingFee + newUser.totalConferenceFee + newUser.totalHotelExpenses + newUser.totalMealCost;
    cout << "Total Cost:                            $" << newUser.totalTripCost << endl;
    cout << "--------------------------------------------" << endl;
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

        int choose;
        cin >> choose;

        if (choose == 1) {
            system("cls");
            cout << "Trip Cost Calculator" << endl;
            if (newUser.totalTripDays <= 0) // means first time editing
            {
                cout << "Enter starting day of the trip: ";
                newUser.startingDay = inputValue("day", 1, 32);
                
                cout << "\nEnter starting month of the trip: ";
                newUser.startingMonth = inputValue("month", 1, 12);

                cout << "\nEnter ending day of the trip: ";
                newUser.endingDay = inputValue("day", 1, 32);

                cout << "\nEnter ending month of the trip: ";
                newUser.endingMonth = inputValue("month", 1, 12);
            }
            
            if (newUser.calculateTotalDays() > 0) { // return 0 means errors occur
                return travelExpenses();
            } else {
                cin.get();
                cout << "Invalid: Ending date is before starting date!" << endl;
                cout << "--------------------------------------------" << endl;
                cout << '\n' << "Press a key to continue..." << endl;
                cin.get();
                return displayMenu();
            };

            travelExpenses();
        }
        else if (choose == 2) {
            cin.get();
            expensesReport();
            cout << "--------------------------------------------" << endl;
            cout << '\n' << "Press a key to continue..." << endl;
            cin.get();
        }
        else if (choose == 3) {
            cout << "Exiting the program." << endl;
            exit(0);
        }
        else {
            cin.get();
            cout << "Error: Invalid choice. Please try again." << endl;
            cout << "--------------------------------------------" << endl;
            cout << '\n' << "Press a key to continue..." << endl;
            cin.get();
            return displayMenu();
        }
    }
}
