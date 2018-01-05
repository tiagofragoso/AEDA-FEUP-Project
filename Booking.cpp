#include "Booking.h"

Booking::Booking(unsigned int id, Passenger *passenger, Flight *flight, string seat) : passenger(passenger),
                                                                                       flight(flight), seat(seat),
                                                                                       id(id) {}


Flight *Booking::getFlight() {
    return this->flight;
}

string Booking::getSeat() {
    return this->seat;
}

Passenger *Booking::getPassenger() {
    return this->passenger;
}

unsigned int Booking::getId() {
    return this->id;
}
