#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"

using namespace std;

#ifndef AEDA_FEUP_PROJECT_AIRPLANE_H
#define AEDA_FEUP_PROJECT_AIRPLANE_H

class Airplane {

private:
	string name;
	int capacity;
	vector <Flight *> flights;

public:
	Airplane(string name, int capacity, vector <Flight *> flights);

	//get Methods
	string getName() const;
	int getCapacity() const;
	vector <Flight *> getFlights() const;

	//set Methods
	void setName(string name);
	void setCapacity(int capacity);
	void setFlights(vector <Flight *> flights);

};

#endif //AEDA_FEUP_PROJECT_AIRPLANE_H
