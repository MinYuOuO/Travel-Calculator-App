// calculations.cpp : This file contains calculations for travel expenses.
#include "functions.h"

using namespace std;

class Trip; // Class declaration, find in functions.h

class transportationExpenses
{
public:
    double totalRoundTrip; // Total round trip miles
    double totalCarRental; // Total cost of car rental
    double milesDriven; // Total miles driven
    double totalTaxiFee;

    const double allowancePerMile = 0.58; // Allowance per mile for reimbursement
    const double taxiFeePerDay = 40;

    // Function to calculate the total charge based on miles and rate
    double calculateMileageReimbursement() const
    {
        return milesDriven * allowancePerMile;
    }

    // Function to calculate the total taxi fee based on days
    double calculateTaxiAllowance() const
    {
        return totalTaxiFee * taxiFeePerDay;
    }
};


class parkingExpenses
{
public:
    double parkingFeePerDay; // Parking fee per day
    double totalParkingFee;

    const double highestParkingFee = 12; // Highest parking fee allowed per day
    const double taxiFeePerDay = 40;

    void calculateParkingCost()
    {

    }
};

class hotelExpenses
{
public:
    double hotelFeePerNight;

    const double highestHotelFeePerNight = 90; // Hotel fee per night

    void calculateHotelCost()
    {

    }
};

class mealExpenses
{
public:
    double breakfastCost;
    double lunchCost;
    double dinnerCost;
    double totalMealCost;

    const double breakfastAllowance = 18;
    const double lunchAllowance = 12;
    const double dinnerAllowance = 20;

    void calculateMealCost()
    {

    }
};

