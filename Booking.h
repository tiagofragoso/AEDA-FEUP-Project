//
// Created by Tiago Fragoso on 18/12/2017.
//

#ifndef AEDA_FEUP_PROJECT_BOOKING_H
#define AEDA_FEUP_PROJECT_BOOKING_H

#include "Flight.h"
#include "Airplane.h"

typedef enum {ACTIVE ,COMPLETED, CANCELED} booking_state_t;


class Booking {

private:
    Flight * flight;
    string seat;
    booking_state_t state;
public:
    Booking(){}
    Booking(Flight* flight, string seat);
    Flight * getFlight();
    string getSeat();
    booking_state_t getState();
    void completeBokking();
    void cancelBooking();
};


#endif //AEDA_FEUP_PROJECT_BOOKING_H
