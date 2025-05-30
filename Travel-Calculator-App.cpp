// Travel-Calculator-App.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Main menu function to display options to the user
void displayMenu()
{
    cout << "Travel Calculator Menu:" << endl;
    cout << "1. Calculate Trip Cost" << endl;
    cout << "2. Exit" << endl;
    cout << "Please select an option: ";
    cout << "...";
}


class Trip
{
public:

    int startingDay; // Starting day of the trip
    int startingMonth; // Starting month of the trip

    int endingDay;  // Ending day of the trip
    int endingMonth; // Ending month of the trip

    int totalNumberOfDays; // Total number of days for the trip
    double totalCost; // Total cost of the trip


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

private:
    
};


class TravelExpenses
{
public:

private:

};


int main()
{
    displayMenu();

    return 0;
}
