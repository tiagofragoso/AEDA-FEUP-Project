#include "Airplane.h"

Airplane::Airplane(string name, int capacity, vector<Flight *> flights)
{
}

Airplane::Airplane(string name, int capacity) {

    this->name = name;
    this->capacity = capacity;
    vector<Flight* > v;
    flights = v;
}

string Airplane::getModel() const
{
	return this->model;
}

int Airplane::getId() const 
{
	return this->id;
}

int Airplane::getCapacity() const
{
	return this->capacity;
}

vector<Flight *> Airplane::getFlights() const
{
	return this->flights;
}

void Airplane::setName(string name)
{
    this->model = name;
}

void Airplane::setId(int id)
{
	this->id = id;
}

void Airplane::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void Airplane::setFlights(vector<Flight*> flights)
{
    this->flights = flights;
}


void Airplane::printSummary() {

    cout << model << endl;
}

void Airplane::print() {

    cout << "Model: " << model  << endl;
    cout << "Capacity: " << capacity << endl;

}

void Airplane::removeFlight(int fIndex) {

    flights.erase(flights.begin() + fIndex);

}