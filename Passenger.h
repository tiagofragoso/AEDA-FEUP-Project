#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

using namespace std;

#ifndef AEDA_FEUP_PROJECT_PASSENGER_H
#define AEDA_FEUP_PROJECT_PASSENGER_H

class Passenger {

private:
	string name;
	int dateOfBirth;

public:
	Passenger(string name, int dateOfBirth);

	//get Methods
	string getName() const;
	int getDateOfBirth() const;

	//set Methods
	void setName(string name);
	void setDateOfBirth(int dateOfBirth);
};

class PassengerWithCard: public Passenger {

private:
	Card *card;

public:
	PassengerWithCard(string name, int dateOfBirth, Card *card);

	//get Methods
	Card * getCard() const;

	//Set Methods
	void setCard(Card * card);

};

#endif //AEDA_FEUP_PROJECT_PASSENGER_H
