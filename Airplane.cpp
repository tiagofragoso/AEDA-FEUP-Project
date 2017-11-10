#include "Airplane.h"

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

    cout << << "Id: " << id << endl;
}

void Airplane::print() {

    cout << "Id: " << id << endl;
    cout << "Model: " << model  << endl;
    cout << "Capacity: " << capacity << endl;

}

void Airplane::removeFlight(Flight * flight) {

    int i = 0;

    for (auto &f : flights) {

        if (f == flight) {
            flights.erase(fligths.begin() + i);
            i++;
        }
    }

}