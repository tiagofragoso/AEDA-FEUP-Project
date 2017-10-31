#include "Passenger.h"

Passenger::Passenger(string name, string dateOfBirth) : name(name), dateOfBirth(dateOfBirth)
{
}

string Passenger::getName() const
{
	return this->name;
}

string Passenger::getDateOfBirth() const
{
	return this->dateOfBirth;
}

void Passenger::setName(string name)
{
}

void Passenger::setDateOfBirth(string dateOfBirth)
{
}


PassengerWithCard::PassengerWithCard(string name, string dateOfBirth, Card *card) : Passenger(name, dateOfBirth), card(card)
{
}

Card * PassengerWithCard::getCard() const {

	return this-> card;
}

void PassengerWithCard::setCard(Card *card) {

	this->card = card;
}

void Passenger::printSummary() {
    cout << name << endl;
}


void Passenger::print() {
    cout << "Name: " << name << " Date of Birth: " << dateOfBirth << endl;
}

void PassengerWithCard::print() {

    cout << "Name: " << Passenger::getName();
    cout << "Date of Birth: " << Passenger::getDateOfBirth();
    cout << "Job: " << card->getJob();
    cout << "Number of flights/year: " << card->getAvgYrFlights() << endl;


}