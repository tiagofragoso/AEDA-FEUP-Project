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
	string dateOfBirth;

public:
	Passenger(string name, string dateOfBirth);

	//get Methods
	string getName() const;
	string getDateOfBirth() const;

	//set Methods
	void setName(string name);
	void setDateOfBirth(string dateOfBirth);

    void printSummary();
    void virtual print();
};

class PassengerWithCard: public Passenger {

private:
	Card *card;

public:
	PassengerWithCard(string name, string dateOfBirth, Card *card);

	//get Methods
	Card * getCard() const;

	//Set Methods
	void setCard(Card * card);
    void print();

};

#endif //AEDA_FEUP_PROJECT_PASSENGER_H
