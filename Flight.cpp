#include "Flight.h"

Flight::Flight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration): id(id), departure(departure),
                destination(destination), time_to_flight(time_to_flight), basePrice(basePrice), duration(duration) {}

string Flight::getDeparture() const
{
    return this->departure;
}

string Flight::getDestination() const
{
    return this->destination;
}

unsigned int Flight::getTime_to_flight() const
{
    return this->time_to_flight;
}

unsigned int Flight::getBasePrice() const
{
    return this->basePrice;
}

unsigned int Flight::getDuration() const
{
    return this->duration;
}

void Flight::setDeparture(string departure)
{
    this->departure = departure;
}

void Flight::setDestination(string destination)
{
    this->destination = destination;
}

void Flight::setTime_to_flight(unsigned int time_to_flight)
{
    this->time_to_flight = time_to_flight;
}

void Flight::setBasePrice(unsigned int basePrice)
{
    this->basePrice = basePrice;
}

void Flight::setDuration(unsigned int duration)
{
    this->duration = duration;
}

void Flight::printSummary() {

    cout << "Id: " << id;
    cout << " Departure: " << departure;
    cout << " Destination: " << destination;
    cout << " Time to flight: " << time_to_flight << endl;

}

void Flight::print() {

    cout << "Id: " << id << endl;
    cout << "Departure: " << departure << endl;
    cout << "Destination: " << destination << endl;
    cout << "Time to flight: " << time_to_flight << endl;
    cout << "Base Price: " << basePrice << endl;
    cout << "Flight duration: " << duration << endl;
}

unsigned int Flight::getId() const{
    return this->id;
}

bool Flight::operator==(const Flight &f) {
    return (id == f.getId());
}

bool Flight::operator<(const Flight &f) {

    return (time_to_flight < f.getTime_to_flight());
}

void Flight::setId(unsigned int id) {
    this->id = id;
}

ostream &operator<<(ostream &o, const Flight *f) {
    o << f->getType() << to_string(f->id) << "; " << f->departure << "; " << f->destination << "; " << to_string(f->time_to_flight) << "; " << to_string(f->basePrice) << "; " << to_string(f->duration) << "; ";
    if (f->getType() == "c"){
        unsigned int i = f->getPassengers().size();
        if (i > 0){
        for(auto const &p: f->getPassengers()){
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

RentedFlight::RentedFlight() : Flight(0, "", "", 0, 0, 0){

    Passenger * p = new Passenger;
    buyer = p;
}

RentedFlight::RentedFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration, Passenger *buyer) : Flight(id, departure, destination, time_to_flight, basePrice, duration), buyer(buyer) {}

Passenger * RentedFlight::getBuyer() const {

    return this-> buyer;
}

PassengerMap RentedFlight::getPassengers() const {

    PassengerMap c;
    return c;

}

void RentedFlight::setBuyer(Passenger *buyer) {

    this->buyer = buyer;
}

void RentedFlight::print() {

    Flight::print();
    cout << "Buyer: ";
    buyer->printSummary();
    cout << endl;
}

void RentedFlight::setPassengers(PassengerMap passengers) {}

ComercialFlight::ComercialFlight() : Flight(0, "", "", 0, 0, 0){
    PassengerMap p;
    passengers = p;
}

ComercialFlight::ComercialFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration, map<string, Passenger *> passengers) : Flight(id, departure, destination, time_to_flight, basePrice, duration), passengers(passengers) {}


PassengerMap ComercialFlight::getPassengers() const {

    return this->passengers;
}

Passenger * ComercialFlight::getBuyer() const {

    return nullptr;
}


void ComercialFlight::setPassengers(PassengerMap passengers) {

    this->passengers = passengers;
}

void ComercialFlight::setBuyer(Passenger *buyer) {

}

void ComercialFlight::print() {

    Flight::print();

    cout << "Passengers:\n";

    if (passengers.size() == 0)
        cout << "There are no passengers in this flight.\n";
    else {

    for (auto& p : passengers) {

        Passenger* passenger = p.second;

        cout << p.first << " ";

        passenger->printSummary();
    }

    }

}

ComercialFlight::ComercialFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight,
                                 unsigned int basePrice, unsigned int duration) : Flight(id, departure, destination,
                                                                                         time_to_flight, basePrice,
                                                                                         duration) {

    PassengerMap passengers;
    this->passengers = passengers;
}

void ComercialFlight::addPassenger(string seat, Passenger *passenger) {

    passengers[seat] = passenger;
}
