//
// Created by Tiago Fragoso on 17/10/2017.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef AEDA_FEUP_PROJECT_PASSENGER_H
#define AEDA_FEUP_PROJECT_PASSENGER_H

class Passenger{

private:
	string name;
	int dateOfBirth;

public:
	Passenger(int name, int dateOfBirth);

	//get Methods
	string getName();
	int getDateOfBirth();

	//set Methods
	void setName(string name);
	void setDateOfBirth(int dateOfBirth);
};

#endif //AEDA_FEUP_PROJECT_PASSENGER_H
