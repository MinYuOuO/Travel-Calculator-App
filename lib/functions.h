#pragma once
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// from ./terminal.cpp
void displayMenu();
void travelExpenses();

// refer to ./calculations.cpp
// The default values for the parameters in the classes are setted to ensure that the classes can be instantiated without requiring any arguments.

/**
 * @brief Prompts the user to input a value.
 * 
 * @param subject string subject title for the value
 * @return Validated input value.
 */
double inputValue(const string subject);

/**
 * @brief Prompts the user to input a value
 *  
 * @param subject string subject title for the value
 * @param minValue minimum value for the input
 * @param maxValue maximum value for the input
 * 
 * @return Validated input value.
 */
int inputValue(const string subject, int minValue, int maxValue);


/**
/**
 * @class trip
 * @brief Represents parking expenses information for travel expenses.
 *
 *
 * @param startingDay Starting day of the trip
 * @param startingMonth Starting month of the trip
 * @param endingDay Ending day of the trip
 * @param endingMonth Ending month of the trip
 * @param totalTripDays Total number of days for the trip
 * @param totalTripCost Total cost of the trip
 */
class trip {
public:
    int startingDay; // Starting day of the trip
    int startingMonth; // Starting month of the trip

    int endingDay;  // Ending day of the trip
    int endingMonth; // Ending month of the1 trip

    int totalTripDays; // Total number of days for the trip
    double totalTripCost; // Total cost of the trip

    trip() {
        startingDay = 0;
        startingMonth = 0;

        endingDay = 0;
        endingMonth = 0;

        totalTripDays = 0;
        totalTripCost = 0;
    }

    int calculateTotalDays();
};

/**
/**
 * @class transportationExpenses
 * @brief transportation expenses information for travel expenses.
 * 
 * @param carRental
 * @param taxiFee
 * @param milesDriven Total miles driven
 * @param totalTransportationCost Total transportation cost
 * @param totalRoundTrip Total round trip airfare
 * @param totalCarRental Total cost of car rental
 * @param totalTaxiFee Total taxi fee
 *
 *
 * @param maxAllowancePerMile Allowance per mile for reimbursement
 * @param maxTaxiFeePerDay Taxi fee per day
 */
class transportationExpenses {
public:
    double carRental;
    double taxiFee;
    double milesDriven; // Total miles driven
    double roundTrip;
    double totalTransportationCost;
    double totalRoundTrip; // Total round trip miles
    double totalCarRental; // Total cost of car rental
    double totalTaxiFee;
    double totalFuelCost;

    transportationExpenses() {
        carRental = 0.00;
        taxiFee = 0.00;
        milesDriven = 0.00;
        roundTrip = 0.00;
        totalTransportationCost = 0.00;
        totalRoundTrip = 0.00; 
        totalCarRental = 0.00;
        totalTaxiFee = 0.00;
        totalFuelCost = 0.00;
    }

    double calculateMilesReimbursement();
    double calculateTaxiFee();
    double calculateAirfare();
    double calculateCarRental();
    double calculationVehicleAllowance();

protected:
    const double maxAllowancePerMile = 0.58; // Allowance per mile for reimbursement
    const double maxTaxiFeePerDay = 40; //Taxi fee per day
};

/**
/**
 * @class parkingExpenses
 * @brief
 * @brief
 * @param totalParkingFee Total parking fees
 * @param parkingExpenses Total parking expenses
 * @param highestParkingFee Highest parking fee allowed per day
 */
class parkingExpenses {
public:
    double totalParkingFee;
    double parkingFeePerDay; // Parking fee per day
    
    parkingExpenses() {
        totalParkingFee = 0.00;
        parkingFeePerDay = 0.00;
    }

    double calculationParkingFee();
    double calculationParkingFee(int days);
    
protected:
    const double highestParkingFee = 12; // Highest parking fee allowed per day
};

/**
/**
 * @class hotelExpenses
 * @brief hotel expenses information for expenses calculation.
 *
 *
 * @param totalHotelExpenses Total hotel expenses
 * @param hotelFeePerNight Hotel fee per night
 * @param highestHotelFeePerNight Highest hotel fee allowed per night
 */
class hotelExpenses {
public:
    double totalHotelExpenses;
    double hotelFeePerNight; // Hotel fee per night

    hotelExpenses() {
        totalHotelExpenses = 0.00;
        hotelFeePerNight = 0.00;
    }

    double calculateReimbursedHotelFee();
    double calculateReimbursedHotelFee(int days);

protected:
    const double highestHotelFeePerNight = 90; // Hotel fee per night
};

/**
/**
 * @class mealExpenses
 * @brief
 *
 * @brief
 *
 * @param breakfastCost Total breakfast const
 * @param lunchCost Total lunch cost
 * @param dinnerCost Total dinner cost
 * @param totalMealCost Total meal cost
 *
 *
 * @param breakfastAllowance 18 Breakfast allowance per day
 * @param lunchAllowance Lunch allowance per day
 * @param dinnerAllowance Dinner allowance per day
 */
class mealExpenses
{
public:
    double breakfastCost = 0.00;
    double lunchCost = 0.00;
    double dinnerCost = 0.00;
    double totalMealCost = 0.00;

    mealExpenses() {
        breakfastCost = 0.00;
        lunchCost = 0.00;
        dinnerCost = 0.00;
        totalMealCost = 0.00;
    }

    double calculateReimbursedMeals();
    
protected:
    const double breakfastAllowance = 18;
    const double lunchAllowance = 12;
    const double dinnerAllowance = 20;
};


class ConferenceOrRegistrationExpenses {
public:
    double totalConferenceFee;
    double conferenceFee;

    ConferenceOrRegistrationExpenses() {
        totalConferenceFee = 0;
        conferenceFee = 0;
    }
    
    double calculateConferenceFee();
};


/**
 * @brief Child Class inheritance from transportationExpenses, parking Expenses, hotelExpenses, mealExpenses, ConferenceOrRegistrationExpenses
 * 
 */
class user : public trip, public transportationExpenses, public parkingExpenses, public hotelExpenses, public mealExpenses, public ConferenceOrRegistrationExpenses {
public:
    char userID;
    string userName;

    user() {
        userID = 0;
        userName = "UNKNOWN";
    }
};
