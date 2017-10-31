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

void Flight::printSummary() {

    cout << "Departure: " << departure;
    cout << "Destination: " << destination;
    cout << "Time to flight: " << time_to_flight << endl;

}

void Flight::print() {

    cout << "Departure: " << departure << endl;
    cout << "Destination: " << destination << endl;
    cout << "Time to flight: " << time_to_flight << endl;
    cout << "Base Price: " << basePrice << endl;
    cout << "Flight duration: " << duration << endl;
}

RentedFlight::RentedFlight(string departure, string destination, int time_to_flight, int basePrice, int duration, Passenger *buyer) : Flight(departure, destination, time_to_flight, basePrice, duration), buyer(buyer) {}

Passenger * RentedFlight::getBuyer() const {

    return this-> buyer;
}

void RentedFlight::setBuyer(Passenger *buyer) {

    this->buyer = buyer;
}

void RentedFlight::print() {

    Flight::print();
    cout << "Buyer: ";
    buyer->printSummary();
    cout << endl;
}

ComercialFlight::ComercialFlight(string departure, string destination, int time_to_flight, int basePrice, int duration, map<string, Passenger *> passengers) : Flight(departure, destination, time_to_flight, basePrice, duration), passengers(passengers) {}


map<string, Passenger *> ComercialFlight::getPassengers() const {

    return this->passengers;
}

void ComercialFlight::setPassengers(map<string, Passenger *> passengers) {

    this->passengers = passengers;
}

void ComercialFlight::print() {

    cout << "Passengers:\n";

    Flight::print();

    for (auto& p : passengers) {

        Passenger* passenger = p.second;

        passenger->printSummary();
    }

}