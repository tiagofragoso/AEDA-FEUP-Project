#include "Flight.h"
#include "Application.h"
#include <iomanip>

Flight::Flight(unsigned int id, string departure, string destination, Date date,
               unsigned int basePrice, Date duration) : id(id), departure(departure),
                                                                destination(destination), date(date),
                                                                basePrice(basePrice), duration(duration) {}

string Flight::getDeparture() const {
    return this->departure;
}

string Flight::getDestination() const {
    return this->destination;
}

unsigned int Flight::getBasePrice() const {
    return this->basePrice;
}

Date Flight::getDuration() const {
    return this->duration;
}

unsigned int Flight::getCapacity() const {
    return this->capacity;
}

void Flight::setDeparture(string departure) {
    this->departure = departure;
}

void Flight::setDestination(string destination) {
    this->destination = destination;
}

void Flight::setDate(Date date) {
    this->date = date;
}

void Flight::setBasePrice(unsigned int basePrice) {
    this->basePrice = basePrice;
}

void Flight::setDuration(Date duration) {
    this->duration = duration;
}

void Flight::printSummary() const {

    cout << setw(9) << id << setw(3) << " " << setw(15) << departure << setw(3) << " " << setw(15) << destination
         << setw(3) << " " << setw(14);
    this->getDate().printFullDate();
    cout << endl;

}

void Flight::printList() const {

    cout << setw(9) << id << setw(3) << " " << setw(15) << departure << setw(3) << " " << setw(15) << destination
         << setw(3) << " ";
    this->getDate().printFullDate();
     cout << setw(3) << " " << setw(9) << basePrice << endl;
}

void Flight::print() const {

    cout << "Id: " << id << endl;
    cout << "Departure: " << departure << endl;
    cout << "Destination: " << destination << endl;
    cout << "Date:  ";
    this->getDate().printFullDate();
    cout << endl;
    cout << "Base Price: " << basePrice << "€" << endl;
    cout << "Flight duration: ";
    this->getDuration().printTime();
    cout << endl;
}

unsigned int Flight::getId() const {
    return this->id;
}

bool Flight::operator==(const Flight &f) {
    return (id == f.getId());
}

bool Flight::operator<(const Flight &f) {

    return (this->date < f.getDate());
}

void Flight::setId(unsigned int id) {
    this->id = id;
}

ostream &operator<<(ostream &o, Flight *f) {
    o << f->getType() << to_string(f->id) << "; " << f->departure << "; " << f->destination << "; "
      << f->getDate().hour << ":" << f->getDate().minute << "; " << to_string(f->basePrice) << "; " << f->getDuration().hour << ":" << f->getDuration().minute << "; ";
    if (f->getType() == "c") {
        unsigned int i = f->getPassengers().size();
        if (i > 0) {
            for (auto const &p: f->getPassengers()) {
                o << p.first << "-" << to_string(p.second->getId());
                i--;
                if (i != 0) o << ", ";
            }

        } else o << "no_passengers";
    } else {
        if (f->getBuyer() != nullptr) o << to_string(f->getBuyer()->getId());
        else o << "no_passengers";
    }
    return o;
}

void Flight::setCapacity(unsigned int capacity) {
    this->capacity = capacity;
}

Date Flight::getDate() const {
    return this->date;
}

Date Flight::getTimeToFlight() {
    return this->getDate() - Application::currentDate;
}

Flight::Flight() : id(0), departure(""), destination(""), basePrice(0){
    Date d1;
    date = d1;
    duration = d1;
}

RentedFlight::RentedFlight() : Flight(), buyer(nullptr){}

RentedFlight::RentedFlight(unsigned int id, string departure, string destination, Date date,
                           unsigned int basePrice, Date duration, Passenger * buyer) : Flight(id, departure,
                                                                                                     destination,
                                                                                                     date,
                                                                                                     basePrice,
                                                                                                     duration),
                                                                                              buyer(buyer) {}

Passenger *RentedFlight::getBuyer() const {

    return this->buyer;
}

PassengerMap &RentedFlight::getPassengers() {

    PassengerMap c = PassengerMap();
    return c;

}

void RentedFlight::setBuyer(Passenger *buyer) {

    this->buyer = buyer;
}

void RentedFlight::print() const {

    Flight::print();
    cout << "Buyer: " << buyer->getName() << " - " << buyer->getId();
    cout << endl;
}

void RentedFlight::setPassengers(PassengerMap passengers) {}

void RentedFlight::removePassenger(Passenger *passenger) {

    if (buyer == nullptr) return;
    if (buyer == passenger)
        setBuyer(nullptr);
}

CommercialFlight::CommercialFlight() : Flight()  {
    PassengerMap * passengers = new PassengerMap;
    this->passengers = *passengers;
}

CommercialFlight::CommercialFlight(unsigned int id, string departure, string destination, Date date,
                                   unsigned int basePrice,Date duration, PassengerMap passengers)
        : Flight(id, departure, destination, date, basePrice, duration), passengers(passengers) {}


PassengerMap &CommercialFlight::getPassengers() {

    return passengers;
}

Passenger *CommercialFlight::getBuyer() const {

    return nullptr;
}


void CommercialFlight::setPassengers(PassengerMap passengers) {

    this->passengers = passengers;
}


void CommercialFlight::setBuyer(Passenger *buyer) {}

void CommercialFlight::print() const {

    Flight::print();

    cout << "Passengers:\n";

    if (passengers.empty())
        cout << "There are no passengers in this flight.\n";
    else {

        for (auto &p : passengers) {

            Passenger *passenger = p.second;

            cout << p.first << " ";

            passenger->printSummary();
        }

    }

}

CommercialFlight::CommercialFlight(unsigned int id, string departure, string destination, Date date,
                                   unsigned int basePrice, Date duration) : Flight(id, departure, destination,
                                                                                           date, basePrice,
                                                                                           duration) {

    PassengerMap * passengers = new PassengerMap;
    this->passengers = *passengers;
}

void CommercialFlight::addPassenger(string seat, Passenger *passenger) {

    passengers[seat] = passenger;
}

void CommercialFlight::removePassenger(Passenger *passenger) {

    if (passengers.empty()) return;
    for (auto it = passengers.begin(); it != passengers.end();) {

        if ((*it).second == passenger)
            passengers.erase(it++);
        else
            it++;
    }
}

bool compFId(Flight *f1, Flight *f2) {

    return f1->getId() < f2->getId();

}

bool compFPriceL(Flight *f1, Flight *f2) {

    return f1->getBasePrice() < f2->getBasePrice();
}

bool compFPriceH(Flight *f1, Flight *f2) {

    return f1->getBasePrice() > f2->getBasePrice();
}

bool compFTime(Flight *f1, Flight *f2) {

    return f1->getDate() < f2->getDate();
}

bool compFDest(Flight *f1, Flight *f2) {

    return f1->getDestination() < f2->getDestination();
}