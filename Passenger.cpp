#include "Passenger.h"

Passenger::Passenger(string name, int dateOfBirth) : name(name), dateOfBirth(dateOfBirth)
{
}

string Passenger::getName() const
{
	return this->name;
}

int Passenger::getDateOfBirth() const
{
	return this->dateOfBirth;
}

void Passenger::setName(string name)
{
}

void Passenger::setDateOfBirth(int dateOfBirth)
{
}


PassengerWithCard::PassengerWithCard(string name, int dateOfBirth, Card *card) : Passenger(name, dateOfBirth), card(card)
{
}

Card * PassengerWithCard::getCard() const {

	return this-> card;
}

void PassengerWithCard::setCard(Card *card) {

	this->card = card;
}