#include "functions.h"

class TravelExpenses {
private:
    transportationExpenses transport;
    parkingExpenses parking;
    hotelExpenses hotel;
    mealExpenses meals;
    trip travel;

public:

    double conferenceFees = 0.00; // this should be in functions.h and used in calculations.cpp

    double calculateTotalReimbursed() {
        return transport.totalTransportationCost +
            parking.totalParkingFee +
            hotel.totalHotelExpenses * travel.totalNumberOfDays +
            meals.totalMealCost +
            conferenceFees;
    }
};
