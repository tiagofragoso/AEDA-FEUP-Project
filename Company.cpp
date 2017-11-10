#include "Company.h"

Company::Company() {

    name = "";
    vector<Airplane> a;
    vector<Passenger*> p;
    fleet = a;
    passengers = p;

}

Company::Company(string name, vector<Airplane> fleet, vector<Passenger*> passengers)
{

}

Company::Company(string name) {

    this->name = name;
    vector<Airplane> fleet;
    vector<Passenger*> passengers;
    this->fleet = fleet;
    this->passengers = passengers;

}

string Company::getName() const
{
	return this->name;
}

vector<Airplane> Company::getFleet() const
{
	return this->fleet;
}

vector<Passenger*> Company::getPassangers() const
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

void Company::setPassengers(vector<Passenger*> passengers)
{
    this->passengers = passengers;
}

//Management methods

void Company::addPassanger(Passenger *passenger) {

    passengers.push_back(passenger);

}

void Company::addAirplane(Airplane airplane) {
    fleet.push_back(airplane);
}

void Company::removePassenger(int pIndex) {

    passengers.erase(passengers.begin() + pIndex);

}

void Company::removeAirplane(int aIndex) {

    fleet.erase(fleet.begin() + aIndex);
}

void Company::setAirplane(int aIndex, Airplane newairplane) {

    fleet.at(aIndex) = newairplane;

}
