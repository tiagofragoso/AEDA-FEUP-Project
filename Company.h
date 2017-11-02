#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"
#include "Card.h"
#include "Flight.h"
#include "Passenger.h"
#include "helper.h"

using namespace std;

#ifndef AEDA_FEUP_PROJECT_COMPANY_H
#define AEDA_FEUP_PROJECT_COMPANY_H

class Company {

private:
	string name;
	vector <Airplane> fleet;
	vector <Passenger*> passengers;

public:
    Company();
	Company(string name, vector <Airplane> fleet, vector <Passenger*> passengers);
    Company(string name);
	
	//get methods
	string getName() const;
	vector <Airplane> getFleet() const;
	vector <Passenger*> getPassangers() const;

	//set methods
	void setName(string name);
	void setFleet(vector <Airplane> fleet);
	void setPassengers(vector <Passenger*> passengers);

	//Other methods

	//int chooseAirplane();
	//bool validIdAirplane(int id);

	//Management methods
	//Airplane
	void addAirplane(Airplane airplane);
	void removeAirplane(int aIndex);


	//Passenger
	void addPassanger(Passenger *passenger);
	void removePassenger(int pIndex);


};

#endif //AEDA_FEUP_PROJECT_COMPANY_H
