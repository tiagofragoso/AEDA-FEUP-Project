#include "Technician.h"

Technician::Technician(string name, string model, unsigned int avaiability) {
	this->name = name;
	this->model = model;
	this->avaiability = avaiability;
}

//get methods

string Technician::getName() {
	return this->name;
}

string Technician::getModel() {
	return this->model;
}

unsigned int Technician::getAvaiability() {
	return this->avaiability;
}

//Operator overload to sort the priority queue

bool Technician::operator<(const Technician &tech1) const {
	return (this->avaiability < tech1.avaiability);
}