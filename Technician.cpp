#include "Technician.h"

Technician::Technician(unsigned int id,string name, string models) {
	this->id = id;
	this->name = name;
	this->models = models;
}


//get methods

unsigned int Technician::getId() {
	return this->id;
}

string Technician::getName() {
	return this->name;
}

vector <string> Technician::getModels() {
	return this->models;
}

//set methods

void Technician::setId(unsigned int id) {
	this->id = id;
}

void Technician::setName(string name) {
	this->name = name;
}

void Technician::setModels(vector <string> models) {
	this->models = models;
}

//Operator overload to sort the priority queue

bool Technician::operator<(const Technician &tech1) const {
	return (this->maintenances.top() < tech1.maintenances.top());
}