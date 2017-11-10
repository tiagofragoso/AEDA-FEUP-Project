#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"

using namespace std;
	
#ifndef AEDA_FEUP_PROJECT_AIRPLANE_H
#define AEDA_FEUP_PROJECT_AIRPLANE_H

class Airplane {

private:
	string model;
	unsigned int id;
	int capacity;
	vector <Flight *> flights;

public:
	Airplane();
	Airplane(unsigned int id, string name, int capacity, vector <Flight *> flights);
    Airplane(unsigned int id, string name, int capacity);

	//get Methods
	string getModel() const;
	unsigned int getId() const;
	unsigned int getCapacity() const;
	vector <Flight *> getFlights() const;

	//set Methods
	void setModel(string model);
	void setId(unsigned int id);
	void setCapacity(unsigned int capacity);
	void setFlights(vector <Flight *> flights);

    void printSummary();
    void print();

	bool operator==(const Airplane &a1);

    void removeFlight(Flight * flight);

};

#endif //AEDA_FEUP_PROJECT_AIRPLANE_H
