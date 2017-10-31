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

//Helper methods
//estou confusa porque os avioes nao tem id's so nomes, o que é que isto esta aqui a fazer????
//int Company::chooseAirplane() {
//	int AirplaneID;
//	vector <Airplane> fleet = getFleet();
//	if (!fleet.empty()) {
//		cout << "Available  IDs: ";
//		for (auto& x : fleet) {
//			cout << x.getId() << " ";
//		}
//		cout << endl;
//	}
//	do {
//		cout << "Choose airplane: ";
//		if (!validArg(AirplaneID)) continue;
//		if (validIdAirplane(AirplaneID)) break;
//		else {
//			cout << "Invalid id. Reenter.\n";
//		}
//	} while (true);
//	return AirplaneID;
//}
//
//Tests if the line with id id_number exists
//bool Company::validIdAirplane(int id) {
//	vector <Airplane> fleet = getFleet();
//	for (int i = 0; i < fleet.size(); i++)
//	{
//		if (fleet.at(i).getId() == id)
//		{
//			return true;
//		}
//	}
//	return false;
//}

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