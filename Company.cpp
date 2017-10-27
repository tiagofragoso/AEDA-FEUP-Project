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

//Helper methods
int Company::chooseAirplane() {
	int AirplaneID;
	vector <Airplane> fleet = getFleet();
	if (!fleet.empty()) {
		cout << "Available  IDs: ";
		for (auto& x : fleet) {
			cout << x.getId() << " ";
		}
		cout << endl;
	}
	do {
		cout << "Choose airplane: ";
		if (!validArg(AirplaneID)) continue;
		if (validIdAirplane(AirplaneID)) break;
		else {
			cout << "Invalid id. Reenter.\n";
		}
	} while (true);
	return AirplaneID;
}

// Tests if the line with id id_number exists
bool Company::validIdAirplane(int id) {
	vector <Airplane> fleet = getFleet();
	for (int i = 0; i < fleet.size(); i++)
	{
		if (fleet.at(i).getId() == id)
		{
			return true;
		}
	}
	return false;
}

//Management methods

//Airplane

void addAirplane() {

}
