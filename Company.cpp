//
// Created by Tiago Fragoso on 17/10/2017.
//

#include "Company.h"

Company::Company(string name, vector<Airplane> fleet, vector<Passenger> passengers)
{
}

string Company::getName() const
{
	return this->name;
}

vector<Airplane> Company::getFleet() const
{
	return this->fleet;
}

vector<Passenger> Company::getPassangers() const
{
	return this->passengers;
}

void Company::setName(string name)
{
    this->name = name;
}

void Company::setFleet(vector<Airplane> fleet)
{
    this->fleet = fleet;
}

void Company::setPassengers(vector<Passenger> passengers)
{
    this->passengers = passengers;
}
