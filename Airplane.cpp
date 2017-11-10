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

string Airplane::getName() const
{
	return this->name;
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
    this->name = name;
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

    cout << name << endl;
}

void Airplane::print() {

    cout << "Id: " << id << endl;
    cout << "Name: " << name  << endl;
    cout << "Capacity: " << capacity << endl;

}

void Airplane::removeFlight(int fIndex) {

    flights.erase(flights.begin() + fIndex);

}