#pragma once

// from ./terminal.cpp
void displayMenu();

// refer to ./calculations.cpp
// The default values for the parameters in the classes are setted to ensure that the classes can be instantiated without requiring any arguments.

/** 
 * @class trip
 * @brief Represents parking expenses information for travel expenses.
 * 
 * @param startingDay Starting day of the trip
 * @param startingMonth Starting month of the trip
 * @param endingDay Ending day of the trip
 * @param endingMonth Ending month of the trip
 * @param totalNumberOfDays Total number of days for the trip
 * @param totalTripCost Total cost of the trip
 * @param totalTripCost Total cost of the trip
 */
class trip {
public:
    int startingDay = 1; // Starting day of the trip
    int startingMonth = 1; // Starting month of the trip

    int endingDay = 1;  // Ending day of the trip
    int endingMonth = 1; // Ending month of the1 trip

    int totalNumberOfDays = 1; // Total number of days for the trip
    double totalTripCost = 0.00; // Total cost of the trip

    double calculateTotalDays();
};

/** 
 * @class transportationExpenses
 * @brief transportation expenses information for travel expenses.
 * 
 * @param totalTransportationCost Total transportation cost
 * @param totalRoundTrip Total round trip airfare
 * @param totalCarRental Total cost of car rental
 * @param milesDriven Total miles driven
 * @param totalTaxiFee Total taxi fee
 * 
 * @param maxAllowancePerMile Allowance per mile for reimbursement
 * @param maxTaxiFeePerDay Taxi fee per day
 */
class transportationExpenses {
public:
    double totalTransportationCost = 0.00;
    double totalRoundTrip = 0.00; // Total round trip miles
    double totalCarRental = 0.00; // Total cost of car rental
    double milesDriven = 0.00; // Total miles driven
    double totalTaxiFee = 0.00;

    const double maxAllowancePerMile = 0.58; // Allowance per mile for reimbursement
    const double maxTaxiFeePerDay = 40;

    double calculateMilesReimbursement();
    double calculateTaxiFee();
    double calculateAirfare();
    double calculateCarRental();
    double calculationVehicleAllowance();
};

/** 
 * @class parkingExpenses
 * @brief 
 * @param totalParkingFee Total parking fees
 * @param parkingExpenses Total parking expenses
 * @param highestParkingFee Highest parking fee allowed per day
 */
class parkingExpenses {
public:
    double totalParkingFee = 0.00;
    double parkingFeePerDay = 0.00; // Parking fee per day

    const double highestParkingFee = 12; // Highest parking fee allowed per day

    double calculationParkingFee();
};

/** 
 * @class hotelExpenses
 * @brief hotel expenses information for expenses calculation.
 * 
 * @param totalHotelExpenses Total hotel expenses
 * @param hotelFeePerNight Hotel fee per night
 * @param highestHotelFeePerNight Highest hotel fee allowed per night
 */
class hotelExpenses {
public:
    double totalHotelExpenses = 0.00;
    double hotelFeePerNight = 0.00; // Hotel fee per night

    const double highestHotelFeePerNight = 90; // Hotel fee per night

    double calculateReimbursedHotelFee();
};

/** 
 * @class mealExpenses
 * @brief 
 * 
 * @param breakfastCost Total breakfast const
 * @param lunchCost Total lunch cost
 * @param dinnerCost Total dinner cost
 * @param totalMealCost Total meal cost
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

    const double breakfastAllowance = 18;
    const double lunchAllowance = 12;
    const double dinnerAllowance = 20;

    double calculateReimbursedMeals();
};

class TravelExpenses {};

