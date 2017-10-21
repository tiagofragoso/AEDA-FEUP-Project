//
// Created by Tiago Fragoso on 17/10/2017.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef AEDA_FEUP_PROJECT_AIRPLANE_H
#define AEDA_FEUP_PROJECT_AIRPLANE_H

class Airplane {

private:
	string name;
	int capacity;
	vector <Flight> flights;

public:
	Airplane(string name, int capacity; vector <Flight> flights);

	//get Methods
	string getName();
	int getCapacity();
	vector <Flight> getFlights();

	//set Methods
	void setName( string name);
	void setCapacity(int capacity);
	void setFlights(vector <Flight> flights);

};

#endif //AEDA_FEUP_PROJECT_AIRPLANE_H
