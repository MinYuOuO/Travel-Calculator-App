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
        }
    } while (value < 0); // Ensure the value is non-negative

    return value;
}

int inputValue(const string subject, int dummy) {
    int value;

    do {
        value = 0; // 以防在进行判断前value已经有数值

        cout << "Enter " << subject << ": ";
        cin >> value;

        if (subject == "day") {
            if (value >= 1 && value <= 32)
                return value;
        } else if (subject == "month") {
            if (value >= 1 && value <= 12)
                return value;
        } else
            if (value >= 1)
                return value;
        
        cout << "Value cannot be negative. Please try again." << endl;
    } while (value < 0); // Ensure the value is non-negative

    return -1; // debug non-void function warning
}

int trip::calculateTotalDays() {
    int year = 2025;

    tm startDate = {};
    startDate.tm_mday = startingDay;
    startDate.tm_mon = startingMonth - 1; // months in tm are 0-based
    startDate.tm_year = year - 1900;

    tm endDate = {};
    endDate.tm_mday = endingDay;
    endDate.tm_mon = endingMonth - 1;
    endDate.tm_year = year - 1900;

    time_t start = mktime(&startDate);
    time_t end = mktime(&endDate);

    double secondsDiff = difftime(end, start);
    int days = static_cast<int>(secondsDiff / (60 * 60 * 24));

    if (days < 0) {
        return 0; // 返回天数为0，同时是false值，进行返回判断可查返回值是否正确
    }

    totalTripDays = days + 1; // include both start and end day
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
 * @brief Calculates the parking allowance
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
 * @param days Insert total of days
 * @return totalHotelExpenses: double 
 */
double hotelExpenses::calculateReimbursedHotelFee(int days) {
    double hotelExpenses = hotelFeePerNight * days;

    double allowedAmount = highestHotelFeePerNight * days;

    if (hotelExpenses > allowedAmount) {
        totalHotelExpenses += allowedAmount;
        cout << "The Payment Excess: $" << totalHotelExpenses - allowedAmount << endl;
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

    totalMealCost = breakfastCost + lunchCost + dinnerCost;

    // output excess amount:
    double excess = totalMealCost - reimbursed;
    if (excess > 0) {
        std::cout << "Excess amount to be paid by employee: $" << excess << std::endl;
    }

    return reimbursed;
}
