//
// Created by Tiago Fragoso on 18/12/2017.
//

#ifndef AEDA_FEUP_PROJECT_BOOKING_H
#define AEDA_FEUP_PROJECT_BOOKING_H

#include "Passenger.h"
#include "Flight.h"


class Booking {

private:
    Passenger * passenger;
    Flight * flight;
    string seat;
public:
    Booking(){}
    Booking(Passenger * passenger, Flight* flight, string seat);
    Passenger * getPassenger();
    Flight * getFlight();
    string getSeat();
};


#endif //AEDA_FEUP_PROJECT_BOOKING_H
