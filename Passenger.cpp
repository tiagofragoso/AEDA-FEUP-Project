#include "Passenger.h"
#include <iomanip>
#include <string>

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

string Passenger::getDateOfBirth() const
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

void Passenger::setDateOfBirth(string dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

string Passenger::getType() const{

    return "n";
}

Card* Passenger::getCard() const{

    return nullptr;
}

void Passenger::setCard(Card *card) {}


PassengerWithCard::PassengerWithCard(unsigned int id, string name, string dateOfBirth, Card *card) : Passenger(id, name, dateOfBirth), card(card)
{
}

PassengerWithCard::PassengerWithCard(unsigned int id, string name, string dateOfBirth, string job, int nYear = 0) : Passenger(id, name, dateOfBirth) {

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

    cout << std::left;
    cout << setw(12) << id << setw(3) << " " << setw(30) << name << setw(3) << " " << setw(13) << dateOfBirth << endl;
}


void Passenger::print() {
    cout << "Id: " << id << endl << "Name: " << name << endl << "Date of Birth: " << dateOfBirth << endl;
}

bool Passenger::operator==(const Passenger &p) {
    if(id == p.getId())
        return true;
    else return false;
}

Passenger::Passenger() {

    id = 0;
    name = "";
    dateOfBirth = "";

}

ostream &operator<<(ostream &o, const Passenger *p) {
    o << p->getType() << p->getId() << "; " << p->getName() << "; " << p->getDateOfBirth();
    if (p->getType() == "c" && p->getCard() != nullptr){
        o << "; " << p->getCard()->getJob() << "; " << to_string(p->getCard()->getAvgYrFlights());
    }
    return o;
}

PassengerWithCard::PassengerWithCard() : Passenger(){

    Card * c = new Card;
    card = c;
}

void PassengerWithCard::print() {

    cout << "Id: " << Passenger::getId() << endl;
    cout << "Name: " << Passenger::getName() << endl;
    cout << "Date of Birth: " << Passenger::getDateOfBirth() << endl;
    cout << "Job: " << card->getJob() << endl;
    cout << "Number of flights/year: " << card->getAvgYrFlights() << endl;


}

string PassengerWithCard::getType() const{

    return "c";
}

//Compare functions

bool compPID(Passenger * p1, Passenger * p2) {

    return (p1->getId() < p2->getId());

}

bool compPNAME(Passenger *p1, Passenger *p2) {

    return (p1->getName() < p2->getName());
}

bool compPAGE(Passenger *p1, Passenger *p2) {

    string year1 = p1->getDateOfBirth().substr(6,4);
    string year2 = p2->getDateOfBirth().substr(6,4);
    string month1 = p1->getDateOfBirth().substr(3,2);
    string month2 = p2->getDateOfBirth().substr(3,2);
    string day1 = p1->getDateOfBirth().substr(0,2);
    string day2 = p2->getDateOfBirth().substr(0,2);

    if (year1 < year2)
        return false;
    if (year1 > year2)
        return true;
    if (month1 < month2)
        return false;
    if (month1 > month2)
        return true;
    if (day1 < day2)
        return false;
    if (day1 > day2)
        return true;
}

