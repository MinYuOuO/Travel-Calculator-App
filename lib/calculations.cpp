// calculations.cpp : This file contains calculations for travel expenses.
#include "functions.h"

using namespace std;

int trip::calculateTotalDays() {
    return 1;
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

double hotelExpenses::calculateReimbursedHotelFee() {
    return 1;
}

double mealExpenses::calculateReimbursedMeals() {
    return 1;
}