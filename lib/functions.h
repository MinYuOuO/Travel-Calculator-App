#pragma once

// from ./terminal.cpp
void displayMenu();

// refer to ./calculations.cpp

/** 
 * @file functions.h
 * @brief trip details information for travel expenses.
 * 
 * @param startingDay Starting day of the trip
 * @param startingMonth Starting month of the trip
 * @param endingDay Ending day of the trip
 * @param endingMonth Ending month of the trip
 * @param totalNumberOfDays Total number of days for the trip
 * @param totalCost Total cost of the trip
 */
class Trip {
public:

    int startingDay; // Starting day of the trip
    int startingMonth; // Starting month of the trip

    int endingDay;  // Ending day of the trip
    int endingMonth; // Ending month of the trip

    int totalNumberOfDays; // Total number of days for the trip
    double totalCost; // Total cost of the trip

};

/** 
 * @file functions.h
 * @brief transportation expenses information for travel expenses.
 * 
 * @param totalRoundTrip Total round trip miles
 * @param totalCarRental Total cost of car rental
 * 
 */
class transportationExpenses {
public:
    double totalRoundTrip; // Total round trip miles
    double totalCarRental; // Total cost of car rental
    double milesDriven; // Total miles driven
    double totalTaxiFee;

    const double allowancePerMile = 0.58; // Allowance per mile for reimbursement
    const double taxiFeePerDay = 40;
};
class parkingExpenses {};
class hotelExpenses {};
class mealExpenses {};
class TravelExpenses {};
