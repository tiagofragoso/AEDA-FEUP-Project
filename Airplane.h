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
	int id;
	int capacity;
	vector <Flight *> flights;

public:
	Airplane(string name, int capacity, vector <Flight *> flights);
    Airplane(string name, int capacity);

	//get Methods
	string getModel() const;
	int getId() const;
	int getCapacity() const;
	vector <Flight *> getFlights() const;

	//set Methods
	void setName(string name);
	void setId(int id);
	void setCapacity(int capacity);
	void setFlights(vector <Flight *> flights);

    void printSummary();
    void print();

    void removeFlight(int fIndex);




};

#endif //AEDA_FEUP_PROJECT_AIRPLANE_H
