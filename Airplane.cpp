#include "Airplane.h"
#include <iomanip>

Airplane::Airplane() {}

Airplane::Airplane(unsigned int id, string model, unsigned int capacity, vector<Flight *> flights) : id(id), model(model), capacity(capacity), flights(flights) {}

Airplane::Airplane(unsigned int id, string model, unsigned int capacity) {

    this->id = id;
    this->model = model;
    this->capacity = capacity;
    vector<Flight* > v;
    flights = v;
}

string Airplane::getModel() const {
	return this->model;
}

unsigned int Airplane::getId() const {
	return this->id;
}

unsigned int Airplane::getCapacity() const {
	return this->capacity;
}

vector<Flight *> Airplane::getFlights() const {
	return this->flights;
}

void Airplane::setModel(string model) {
    this->model = model;
}

void Airplane::setId(unsigned int id) {
	this->id = id;
}

void Airplane::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}

void Airplane::setFlights(vector<Flight*> flights) {
    this->flights = flights;
}


void Airplane::printSummary() const {

    cout << setw(11) << id << endl;
}

void Airplane::print() const {

    cout << "Id: " << id << endl;
    cout << "Model: " << model  << endl;
    cout << "Capacity: " << capacity << endl;

}

void Airplane::removeFlight(Flight * flight) {

    if (flight->getId() == flights.at(0)->getId()) {

        flights.erase(flights.begin());
        return;
    }

    if (flight->getId() == flights.at(flights.size() - 1)->getId()) {

        flights.erase(flights.begin() + flights.size() - 1);
        return;
    }

    throw ConnectionFlight();

}

bool Airplane::operator==(const Airplane &a1) {

    return id == a1.getId();

}

void Airplane::addFlight(Flight *flight) {

    if (flights.empty()) {
        flights.push_back(flight);
        return;
    }

    Flight * elem1 = flights.at(0);
    Flight * lelem = flights.at(flights.size()-1);

    if ((flight->getTime_to_flight()+flight->getDuration()) < elem1->getTime_to_flight() && flight->getDestination() == elem1->getDeparture()) {


        flights.insert(flights.begin(), flight);
        return;
    }

    if (flight->getTime_to_flight() > (lelem->getTime_to_flight() + lelem->getDuration()) && flight->getDeparture() == lelem->getDestination()) {

        flights.push_back(flight);
        return;
    }

    throw OverlappingFlight();
}

ostream &operator<<(ostream &o, const Airplane * a) {
    o << to_string(a->id) << "; " << a->model << "; " << to_string(a->capacity) << "; ";
    if (!a->flights.empty()) {
        for (size_t i = 0; i < a->flights.size(); i++) {
            o << to_string(a->flights.at(i)->getId());
            if (i != a->flights.size() - 1) o << ", ";
        }
    } else o << "no_flights";
    return o;
}

bool compAId(Airplane *a1, Airplane *a2) {

    return (a1->getId() < a2->getId());
}

