#include "Technician.h"
#include <iomanip>
#include <string>

Technician::Technician(unsigned int id,string name, vector<string> models) {
	this->id = id;
	this->name = name;
	this->models = models;
    this->timeUntillAvailable = 0;
}


//get methods

unsigned int Technician::getId() const {
	return this->id;
}

string Technician::getName() const {
	return this->name;
}

vector <string> Technician::getModels() const {
	return this->models;
}

int Technician::getTimeUntilAvailable() const {
    return this->timeUntillAvailable;
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

void Technician::updateTimeUntilAvailabel(int timePassed) {
    timeUntillAvailable -= timePassed;
    if (timeUntillAvailable < 0) {
        timeUntillAvailable = 0;
    }
}

//Operator overload to sort the priority queue

bool Technician::operator<(const Technician &tech1) const {
	return (timeUntillAvailable < tech1.getTimeUntilAvailable());
}

bool Technician::operator=(const Technician &tech1) const {
	return (id == tech1.getId());
}

void Technician::setTimeUntilAvailable(int time) {
	timeUntillAvailable = time;
}

void Technician::print() const {
	cout << "Id: " << id << endl << "Name: " << name << endl << "Model: ";
	for (int i = 0; i < models.size() ; i++)
	{
		cout << models.at(i) << " , ";
	}
	cout << endl;
}

void Technician::printSummary() const {
	
	cout << std::left;
	cout << setw(12) << id << setw(3) << " " << setw(30) << name << setw(3) << " ";
	
	for (int i = 0; i < models.size(); i++)
	{
		cout << setw(30) << models.at(i) << setw(3) << " " ;
	}
	cout << endl;
}
