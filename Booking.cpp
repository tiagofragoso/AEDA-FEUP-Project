//
// Created by Tiago Fragoso on 18/12/2017.
//

#include "Booking.h"

Booking::Booking(Passenger *passenger, Flight *flight, string seat): passenger(passenger), flight(flight), seat(seat), state(ACTIVE) {}

Passenger *Booking::getPassenger() {
    return this->passenger;
}

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
