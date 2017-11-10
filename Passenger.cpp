#include "Passenger.h"

Passenger::Passenger(unsigned int id, string name, string dateOfBirth) : id(id), name(name), dateOfBirth(dateOfBirth)
{
}

unsigned int Passenger::getId() const {
    return this->id;
}

string Passenger::getName() const
{
	return this->name;
}

Date Passenger::getDateOfBirth() const
{
	return this->dateOfBirth;
}

void Passenger::setId(unsigned int id) {
    this->id = id;
}

void Passenger::setName(string name)
{
  this->name = name;
}

void Passenger::setDateOfBirth(Date dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

string Passenger::getType() {

    return "n";
}

Card* Passenger::getCard() const{

    return nullptr;
}

void Passenger::setCard(Card *card) {}


PassengerWithCard::PassengerWithCard(unsigned int id, string name, string dateOfBirth, Card *card) : Passenger(id, name, dateOfBirth), card(card)
{
}

PassengerWithCard::PassengerWithCard(unsigned int id, string name, string dateOfBirth, string job, int nYear) : Passenger(id, name, dateOfBirth) {

    Card* c = new Card(job, nYear);
    card = c;
}



Card* PassengerWithCard::getCard() const {

	return card;
}

void PassengerWithCard::setCard(Card *card) {

	this->card = card;
}

void Passenger::printSummary() {
    cout << "Id: " << id << "Name: " << name << endl;
}


void Passenger::print() {
    cout << "Id: " << id << endl << "Name: " << name << endl << "Date of Birth: " << dateOfBirth << endl;
}

bool Passenger::operator==(const Passenger &p) {
    if(id == p.getId())
        return true;
    else return false;
}

void PassengerWithCard::print() {

    cout << "Id: " << Passenger::getId() << endl;
    cout << "Name: " << Passenger::getName() << endl;
    cout << "Date of Birth: " << Passenger::getDateOfBirth() << endl;
    cout << "Job: " << card->getJob() << endl;
    cout << "Number of flights/year: " << card->getAvgYrFlights() << endl;


}

string PassengerWithCard::getType() {

    return "c";
}