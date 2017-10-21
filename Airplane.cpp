//
// Created by Tiago Fragoso on 17/10/2017.
//

#include "Airplane.h"

Airplane::Airplane(string name, int capacity, vector<Flight *> flights)
{
}

string Airplane::getName() const
{
	return this->name;
}

int Airplane::getCapacity() const
{
	return this->capacity;
}

vector<Flight *> Airplane::getFlights() const
{
	return flights;
}

void Airplane::setName(string name)
{
    this->name = name;
}

void Airplane::setCapacity(int capacity)
{
    this->capacity = capacity;
}

void Airplane::setFlights(vector<Flight*> flights)
{
    this->flights = flights;
}
