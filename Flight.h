#include <iostream>
#include <string>
#include <vector>
#include "Passenger.h"

using namespace std;

#ifndef AEDA_FEUP_PROJECT_FLIGHT_H
#define AEDA_FEUP_PROJECT_FLIGHT_H

class Flight {

private:
	string departure;
	string destination;
	int time_to_flight;
	int basePrice;
	int duration;

public:
	Flight(string departure, string destination, int time_to_flight, int basePrice, int duration);

	//get Methods
	string getDeparture() const;
	string getDestination() const;
	int getTime_to_flight() const;
	int getBasePrice() const;
	int getDuration() const;

	//set Methods
	void setDeparture(string departure);
	void setDestination(string destination);
	void setTime_to_flight(int time_to_flight);
	void setBasePrice(int basePrice);
	void setDuration(int duration);

};

class RentedFlight : public Flight {

private:
	Passenger * buyer;

public:
	RentedFlight(string departure, string destination, int time_to_flight, int basePrice, int duration, Passenger *buyer);

	//get Methods
	Passenger * getBuyer() const;

	//set Methods
	void setBuyer(Passenger * buyer);

};

class ComercialFlight : public Flight {

private:
	vector<Passenger * > passengers;

public:
	ComercialFlight( string departure, string destination, int time_to_flight, int basePrice, int duration, vector<Passenger *> passengers);

	//get methods
	vector<Passenger * > getPassengers() const;

	//set methods
	void setPassengers(vector<Passenger * > passengers);
};
#endif //AEDA_FEUP_PROJECT_FLIGHT_H
