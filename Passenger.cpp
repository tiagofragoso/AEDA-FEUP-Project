#include "Passenger.h"
#include <iomanip>
#include <string>

Passenger::Passenger(unsigned int id, string name, Date dateOfBirth) : id(id), name(name), dateOfBirth(dateOfBirth) {}

unsigned int Passenger::getId() const {
    return this->id;
}

string Passenger::getName() const {
    return this->name;
}

Date Passenger::getDateOfBirth() const {
    return this->dateOfBirth;
}

void Passenger::setId(unsigned int id) {
    this->id = id;
}

void Passenger::setName(string name) {
    this->name = name;
}

void Passenger::setDateOfBirth(Date dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

string Passenger::getType() const {

    return "n";
}

Card *Passenger::getCard() const {

    return nullptr;
}

void Passenger::setCard(Card *card) { return; }


PassengerWithCard::PassengerWithCard(unsigned int id, string name, Date dateOfBirth, Card *card) : Passenger(id, name,
                                                                                                               dateOfBirth),
                                                                                                     card(card) {
}

PassengerWithCard::PassengerWithCard(unsigned int id, string name, Date dateOfBirth, string job, int nYear = 0)
        : Passenger(id, name, dateOfBirth) {

    card = new Card(job, nYear);
}


Card *PassengerWithCard::getCard() const {

    return card;
}

void PassengerWithCard::setCard(Card *card) {

    this->card = card;
}

void Passenger::printSummary() const {

    cout << std::left;
    cout << setw(12) << id << setw(3) << " " << setw(30) << name << setw(3) << " ";
    this->getDateOfBirth().print();
    cout << endl;
}


void Passenger::print() const {
    cout << "Id: " << id << endl << "Name: " << name << endl << "Date of Birth: ";
    this->getDateOfBirth().print();
    cout<< endl;
}

bool Passenger::operator==(const Passenger &p) {
    return id == p.getId();
}

Passenger::Passenger() {

    id = 0;
    name = "";
    Date d;
    dateOfBirth = d;

}

ostream &operator<<(ostream &o, const Passenger *p) {
    //TODO
    //o << p->getType() << p->getId() << "; " << p->getName() << "; " << p->getDateOfBirth();
    if (p->getType() == "c" && p->getCard() != nullptr) {
        o << "; " << p->getCard()->getJob() << "; " << to_string(p->getCard()->getAvgYrFlights());
    }
    return o;
}

PassengerWithCard::PassengerWithCard() : Passenger() {

    card = new Card;
}

void PassengerWithCard::print() const {

    cout << "Id: " << Passenger::getId() << endl;
    cout << "Name: " << Passenger::getName() << endl;
    cout << "Date of Birth: ";
    this->getDateOfBirth().print();
    cout << endl;
    cout << "Job: " << card->getJob() << endl;
    cout << "Number of flights/year: " << card->getAvgYrFlights() << endl;


}

string PassengerWithCard::getType() const {

    return "c";
}

//Compare functions

bool compPID(Passenger *p1, Passenger *p2) {

    return (p1->getId() < p2->getId());

}

bool compPNAME(Passenger *p1, Passenger *p2) {

    return (p1->getName() < p2->getName());
}

bool compPAGE(Passenger *p1, Passenger *p2) {

    return p1->getDateOfBirth() > p2->getDateOfBirth();
}