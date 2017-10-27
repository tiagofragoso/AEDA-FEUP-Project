#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"
#include "Card.h"
#include "Flight.h"
#include "Passenger.h"

using namespace std;

#ifndef AEDA_FEUP_PROJECT_COMPANY_H
#define AEDA_FEUP_PROJECT_COMPANY_H

class Company {

private:
	string name;
	vector <Airplane> fleet;
	vector <Passenger> passengers;

public:
	Company(string name, vector <Airplane> fleet, vector <Passenger> passengers);
	
	//get methods
	string getName() const;
	vector <Airplane> getFleet() const;
	vector <Passenger> getPassangers() const;

	//set methods
	void setName(string name);
	void setFleet(vector <Airplane> fleet);
	void setPassengers(vector <Passenger> passengers);

	//Other methods

	int Company::chooseAirplane();

	//Management methods
	//Airplane
	void addAirplane();
	void removeAirplane();

	//Card
	void addCard();
	void removeCard();

	//Flight
	void addFlight();
	void removeFlght();

	//Passenger
	void addPassanger();
	void removePassenger();


};

#endif //AEDA_FEUP_PROJECT_COMPANY_H
