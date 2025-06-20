#include "functions.h"
#include <iostream>
#include <ctime>

using namespace std;

// For double values (e.g., amounts)
double inputValue(const string subject) {
    double value;
    while (true) {
        cout << "Enter " << subject << " Amount: " << endl;
        cin >> value;
        if (cin.fail() || value < 0) {
            cout << "Invalid input. Value must be a non-negative number. Please try again." << endl;
            cin.clear();
        } else {
            return value;
        }
    }
}

// For integer values with a range (e.g., day, month, generic positive integer)
int inputValue(const string subject, int minValue, int maxValue) {
    int value;
    while (true) {
        cout << "Enter " << subject <<endl;
        cin >> value;
        if (cin.fail() || value < minValue || value > maxValue) {
            cout << "Invalid input. Value must be between " << minValue << " and " << maxValue << ". Please try again." << endl;
            cin.clear();
        } else {
            return value;
        }
    }
}

int trip::calculateTotalDays() {
    const int CURRENT_YEAR = 2025;

    tm startDate = {};
    startDate.tm_mday = startingDay;
    startDate.tm_mon = startingMonth - 1; // months in tm are 0-based
    startDate.tm_year = CURRENT_YEAR - 1900;

    tm endDate = {};
    endDate.tm_mday = endingDay;
    endDate.tm_mon = endingMonth - 1;
    endDate.tm_year = CURRENT_YEAR - 1900;

    time_t start = mktime(&startDate);
    time_t end = mktime(&endDate);

    const int secondsPerDay = 60 * 60 * 24;
    int daysDifference = (end - start) / secondsPerDay;

    if (daysDifference < 0) {
        return 0; // 返回天数为0，同时是false值，进行返回判断可查返回值是否正确
    }

    totalTripDays = daysDifference + 1; // include both start and end day
    return totalTripDays;
}


/**
 * @brief Calculates the reimbursement for miles driven based on the allowance per mile.
 * @return allowance: double
 */
double transportationExpenses::calculateMilesReimbursement() {
    // Calculate the reimbursement for miles driven
    if (milesDriven > 0) {
        totalFuelCost += milesDriven * maxAllowancePerMile;
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
    if (taxiFee <= maxTaxiFeePerDay) {
        totalTaxiFee += taxiFee;
        totalTransportationCost += taxiFee;
        return totalTaxiFee;
    }
    else if (taxiFee > maxTaxiFeePerDay) {
        totalTaxiFee += maxTaxiFeePerDay;
        totalTransportationCost += maxTaxiFeePerDay;
        return totalTaxiFee;
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
    if (roundTrip > 0) {
        totalRoundTrip += roundTrip;
        totalTransportationCost += roundTrip;
        return totalRoundTrip;
    }
    else {
        return 0.00; // No airfare
    }
}

/**
 * @brief Calculates the total car rental cost.
 * @return totalCarRental: double
 */
double transportationExpenses::calculateCarRental() {
    // Calculate the total car rental cost
    if (carRental > 0) {
        totalCarRental += carRental;
        totalTransportationCost += carRental;
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
        totalFuelCost += milesDriven * maxAllowancePerMile;
        return totalFuelCost;
    }
    else {
        return 0.00; // No miles driven
    }
}

/**
 * @brief Calculates the parking allowance
 * @param days Insert total of days
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

double parkingExpenses::calculationParkingFee(int days) {
    // Calculate the total parking fee, ensuring it does not exceed the maximum allowed fee
    if (parkingFeePerDay > 0) {
        if (parkingFeePerDay <= highestParkingFee) {
            totalParkingFee += parkingFeePerDay * days;
            return parkingFeePerDay;
        }
        else {
            totalParkingFee += highestParkingFee * days;
            return highestParkingFee;
        }
	}
    else {
        return 0.00; // No parking fee
    }
}

/**
 * @brief Calculate conference or registration expenses
 * @return conferenceFee: double 
 */
double ConferenceOrRegistrationExpenses::calculateConferenceFee(){
    if (conferenceFee >0){
        totalConferenceFee += conferenceFee;
        return conferenceFee;
    }
    else{
        return 0.00; // No conference fee
    }
}

/**
 * @brief Calculate hotel total reimbursed fee
 * @return totalHotelExpenses: double 
 */
double hotelExpenses::calculateReimbursedHotelFee() {
    double hotelExpenses = hotelFeePerNight;

    double allowedAmount = highestHotelFeePerNight;

    if (hotelExpenses > allowedAmount) {
        totalHotelExpenses += allowedAmount;
        return allowedAmount;
    } else {
        totalHotelExpenses += hotelExpenses;
        return hotelExpenses;
    }

    return allowedAmount;
}

/**
 * @brief Calculate hotel total reimbursed fee
 * @param days Insert total of days
 * @return totalHotelExpenses: double 
 */
double hotelExpenses::calculateReimbursedHotelFee(int days) {
    double hotelExpenses = hotelFeePerNight * days;

    double allowedAmount = highestHotelFeePerNight * days;

    if (hotelExpenses > allowedAmount) {
        totalHotelExpenses += allowedAmount;
        return allowedAmount;
    } else {
        totalHotelExpenses += hotelExpenses;
        return hotelExpenses;
    }

    return allowedAmount;
}

/**
 * @brief calculate total of breakfast, lunch, and dinner cost
 * 
 * @return totalMealCost: double 
 */
double mealExpenses::calculateReimbursedMeals() {
    double reimbursed = 0.0;

    // Reimbursement is limited to the max allowance per meal
    reimbursed += (breakfastCost <= breakfastAllowance) ? breakfastCost : breakfastAllowance;
    reimbursed += (lunchCost <= lunchAllowance) ? lunchCost : lunchAllowance;
    reimbursed += (dinnerCost <= dinnerAllowance) ? dinnerCost : dinnerAllowance;

    totalMealCost += breakfastCost + lunchCost + dinnerCost;

    // output excess amount:
    double excess = totalMealCost - reimbursed;

    return reimbursed;
}
