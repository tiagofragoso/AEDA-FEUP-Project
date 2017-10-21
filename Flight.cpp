//
// Created by Tiago Fragoso on 17/10/2017.
//

#include "Flight.h"

Flight::Flight(string departure, string destination, int time_to_flight, int basePrice, int duration)
{
}

string Flight::getDeparture() const
{
	return this->departure;
}

string Flight::getDestination() const
{
	return this->destination;
}

int Flight::getTime_to_flight() const
{
	return this->time_to_flight;
}

int Flight::getBasePrice() const
{
	return this->basePrice;
}

int Flight::getDuration() const
{
	return this->duration;
}

void Flight::setDeparture(string departure)
{
    this->departure = departure;
}

void Flight::setDestination(string destination)
{
    this->destination = destination;
}

void Flight::setTime_to_flight(int time_to_flight)
{
    this->time_to_flight = time_to_flight;
}

void Flight::setBasePrice(int basePrice)
{
    this->basePrice = basePrice;
}

void Flight::setDuration(int duration)
{
    this->duration = duration;
}
