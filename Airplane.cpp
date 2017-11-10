#include "Airplane.h"

Airplane::Airplane(int id, string model, int capacity, vector<Flight *> flights)
{
}

Airplane::Airplane(int id, string model, int capacity) {

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

void Airplane::setModel(string model)
{
    this->model = model;
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

    cout << id << endl;
}

void Airplane::print() {

    cout << "Id: " << id << endl;
    cout << "Model: " << model  << endl;
    cout << "Capacity: " << capacity << endl;

}

void Airplane::removeFlight(int fIndex) {

    flights.erase(flights.begin() + fIndex);

}