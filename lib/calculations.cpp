// calculations.cpp : This file contains calculations for travel expenses.
#include "functions.h"

using namespace std;

/**
 * @brief Calculates the reimbursement for miles driven based on the allowance per mile.
 * @return allowance: double
 */
double transportationExpenses::calculateMilesReimbursement() const {
    // Calculate the reimbursement for miles driven
    return milesDriven * allowancePerMile;
}


/**
 * @brief Calculates the taxi fee for the day, ensuring it does not exceed the maximum allowed fee.
 * @return taxiFee: double
 */
double transportationExpenses::calculateTaxiFee() const {
    // excess of maximum taxi fee paid by employee
    if (totalTaxiFee <= maxTaxiFeePerDay) {
        return totalTaxiFee;
    } else {
        return maxTaxiFeePerDay;
    }
}
