//
// Created by Tiago Fragoso on 18/12/2017.
//

#ifndef AEDA_FEUP_PROJECT_BOOKING_H
#define AEDA_FEUP_PROJECT_BOOKING_H

#include "Passenger.h"
#include "Flight.h"


class Booking {

private:
    unsigned int id;
    Passenger * passenger;
    Flight * flight;
    string seat;
public:
    /**
     * @brief Default constructor for class Booking
     */
    Booking(){}
    /**
     * @brief Constructor of a Booking object with all of its data members
     * @param id unsigned int id
     * @param passenger Passenger * passenger
     * @param flight Flight * flight
     * @param seat string seat
     */
    Booking(unsigned int id, Passenger * passenger, Flight* flight, string seat);
    /**
     * @brief Gets the Passenger (as a pointer) of a Booking object
     * @return Passenger *
     */
    Passenger * getPassenger();
    /**
     * @brief Gets the Flight (as a pointer) of a Booking object
     * @return Flight *
     */
    Flight * getFlight();
    /**
     * @brief Gets the Seat(string) of a Booking object
     * @return string
     */
    string getSeat();
    /**
     * @brief Gets the id(unsigned int) of a Booking object
     * @return unsigned int
     */
    unsigned int getId();
};


#endif //AEDA_FEUP_PROJECT_BOOKING_H
