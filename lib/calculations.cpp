// calculations.cpp : This file contains calculations for travel expenses.
#include "functions.h"
#include <iostream>
using namespace std;

double inputValue(const string subject) {
    double value;
    value = -1; // 以防在进行判断前value已经有数值

    do {
        cout << "Enter " << subject << " Amount: ";
        cin >> value;
        if (value < 0) {
            cout << "Value cannot be negative. Please try again." << endl;
            value = -1;
        }
    } while (value < 0); // Ensure the value is non-negative
    return value;
    
}

int inputValue(const string subject, int dummy) {
    int value;
    value = -1; // 以防在进行判断前value已经有数值
    
    do {
        cout << "Enter " << subject << " Amount: ";
        cin >> value;
        if (value < 0) {
            cout << "Value cannot be negative. Please try again." << endl;
            value = -1;
        }
    } while (value < 0); // Ensure the value is non-negative
    return value;
    
}

int trip::calculateTotalDays() {
    
    return totalTripDays;
}


/**
 * @brief Calculates the reimbursement for miles driven based on the allowance per mile.
 * @return allowance: double
 */
double transportationExpenses::calculateMilesReimbursement() {
    // Calculate the reimbursement for miles driven
    if (milesDriven > 0) {
        totalTransportationCost += milesDriven * maxAllowancePerMile;
        return milesDriven * maxAllowancePerMile;
    }
    else {
        return 0.00; // No miles driven
    }
}


/**
 * @brief Calculates the taxi fee for the day, ensuring it does not exceed the maximum allowed fee.
 * @return taxiFee: double
 */
double transportationExpenses::calculateTaxiFee() {
    // excess of maximum taxi fee paid by employee
    if (totalTaxiFee <= maxTaxiFeePerDay) {
        totalTransportationCost += totalTaxiFee;
        return totalTaxiFee;
    }
    else if (totalTaxiFee > maxTaxiFeePerDay) {
        totalTransportationCost += maxTaxiFeePerDay;
        return maxTaxiFeePerDay;
    }
    else {
        return 0.00; // No taxi fee
    }
}

/**
 * @brief Calculates the total airfare for a round trip.
 * @return airfare: double
 */
double transportationExpenses::calculateAirfare() {
    // Calculate the total round trip airfare
    if (totalRoundTrip > 0) {
        totalTransportationCost += totalRoundTrip;
        return totalRoundTrip;
    }
    else {
        return 0.00; // No airfare
    }
}

/**
 * @brief Calculates the total car rental cost.
 * @return carRental: double
 */
double transportationExpenses::calculateCarRental() {
    // Calculate the total car rental cost
    if (totalCarRental > 0) {
        totalTransportationCost += totalCarRental;
        return totalCarRental;
    }
    else {
        return 0.00; // No car rental
    }
}

 /**
  * @brief Calculates the vehicle allowance based on miles driven.
  * @return vehicleAllowance: double
  */
double transportationExpenses::calculationVehicleAllowance() {
    // Calculate the total vehicle allowance based on miles driven
    if (milesDriven > 0) {
        return milesDriven * maxAllowancePerMile;
    }
    else {
        return 0.00; // No miles driven
    }
}

/**
 * @brief 
 * @return ParkingFee: double
 */
double parkingExpenses::calculationParkingFee() {
    // Calculate the total parking fee, ensuring it does not exceed the maximum allowed fee
    if (parkingFeePerDay > 0) {
        if (parkingFeePerDay <= highestParkingFee) {
            totalParkingFee += parkingFeePerDay;
            return parkingFeePerDay;
        }
        else {
            totalParkingFee += highestParkingFee;
            return highestParkingFee;
        }
	}
    else {
        return 0.00; // No parking fee
    }
}

double ConferenceOrRegistrationExpenses::calculateConferenceFee(){
    if (conferenceFee >0){
        totalConferenceFee += conferenceFee;
        return conferenceFee;
    }
    else{
        return 0.00; // No conference fee
    }
}


double hotelExpenses::calculateReimbursedHotelFee(int days) {
    totalHotelExpenses = hotelFeePerNight * days;

    double allowedAmount = highestHotelFeePerNight * days;

    if (totalHotelExpenses > allowedAmount) {
        cout << "Excess (to be paid by employee): $"
             << totalHotelExpenses - allowedAmount << endl;
    } else {
        cout << "No excess payment required by employee." << endl;
    }

    return allowedAmount;
}

double mealExpenses::calculateReimbursedMeals() {
    return 1;
}
