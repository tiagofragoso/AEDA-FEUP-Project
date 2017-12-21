//
// Created by Tiago Fragoso on 18/12/2017.
//

#include "Booking.h"

Booking::Booking(Flight *flight, string seat): flight(flight), seat(seat), state(ACTIVE) {}


Flight *Booking::getFlight() {
    return this->flight;
}

string Booking::getSeat() {
    return this->seat;
}

void Booking::completeBokking() {
    this->state = COMPLETED;
}

void Booking::cancelBooking() {
    this->state = CANCELED;
}

booking_state_t Booking::getState() {
    return this->state;
}
