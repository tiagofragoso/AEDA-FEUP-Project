#include "Airplane.h"
#include "exceptions.h"

Airplane::Airplane() {}

Airplane::Airplane(unsigned int id, string model, int capacity, vector<Flight *> flights)
{
}

Airplane::Airplane(unsigned int id, string model, int capacity) {

    this->id = id;
    this->model = model;
    this->capacity = capacity;
    vector<Flight* > v;
    flights = v;
}

string Airplane::getModel() const
{
	return this->model;
}

unsigned int Airplane::getId() const
{
	return this->id;
}

unsigned int Airplane::getCapacity() const
{
	return this->capacity;
}

vector<Flight *> Airplane::getFlights() const
{
	return this->flights;
}

void Airplane::setModel(string model)
{
    this->model = model;
}

void Airplane::setId(unsigned int id)
{
	this->id = id;
}

void Airplane::setCapacity(unsigned int capacity)
{
    this->capacity = capacity;
}

void Airplane::setFlights(vector<Flight*> flights)
{
    this->flights = flights;
}


void Airplane::printSummary() {

    cout << "Id: " << id << endl;
}

void Airplane::print() {

    cout << "Id: " << id << endl;
    cout << "Model: " << model  << endl;
    cout << "Capacity: " << capacity << endl;

}

void Airplane::removeFlight(Flight * flight) {

    int i = 0;

    for (auto &f : flights) {

        if (*f == *flight) {
            flights.erase(flights.begin() + i );
            i++;
        }
    }

}

bool Airplane::operator==(const Airplane &a1) {

    if (id == a1.getId())
        return true;
    else return false;

}

void Airplane::addFlight(Flight *flight) {

    if (flights.size() == 0) {

        flights.push_back(flight);
        return;
    }

    Flight * elem1 = flights.at(0);
    Flight * lelem = flights.at(flights.size()-1);

    if ((flight->getTime_to_flight()+flight->getDuration()) < elem1->getTime_to_flight() && flight->getDestination() == elem1->getDeparture()) {

        flights.insert(flights.begin(), flight);
        return;
    }

    if (flight->getTime_to_flight() > (lelem->getTime_to_flight() + lelem->getDuration()) && flight->getDeparture() == lelem->getDestination()) {

        flights.push_back(flight);
        return;
    }

    throw OverlapingFlight();
}
