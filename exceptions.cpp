#include <iostream>
#include "exceptions.h"

using namespace std;

InvalidFormat::InvalidFormat() {}

InvalidPassenger::InvalidPassenger(unsigned int id) {

    this->id = id;
}

void InvalidPassenger::print() const {

    cout << id << " is an invalid passenger id. Reenter.\n";

}

void InvalidPassenger::printDuplicate() const {

    cout << "This passenger already exists. Please insert another id or delete the passenger.\n";

}

InvalidAirplane::InvalidAirplane(unsigned int id) {

    this->id = id;
}

void InvalidAirplane::print() const {

    cout << id << " is an invalid airplane id. Reenter.\n";

}

void InvalidAirplane::printDuplicate() const {

    cout << "This airplane already exists. Please insert another id or delete the airplane.\n";

}

InvalidFlight::InvalidFlight(unsigned int id) {

    this->id = id;
}

void InvalidFlight::print() const {

    cout << id << " is an invalid flight id. Reenter.\n";

}

void InvalidFlight::printDuplicate() const {

    cout << "This flight already exists. Please insert another id or delete the flight.\n";

}

InvalidSeat::InvalidSeat(string seat) {

    this->seat = seat;
}

void InvalidSeat::print() const {

    cout << seat << " is and invalid seat on the flight. Reenter.\n";
}

OverlappingFlight::OverlappingFlight() {}


void OverlappingFlight::print() const {

    cout << "It is not possible to add this flight to this plane.\n";

}

ConnectionFlight::ConnectionFlight() {}

void ConnectionFlight::print() const {

    cout << "It is not possible to delete this flight.\n";
}

void InvalidFilePath::print() {

    if (type == "empty") cout << "File path is empty.\n";
    else if (type == "fail") cout << "Failed to open file.\n";
}

InvalidFilePath::InvalidFilePath(std::string type) : type(type) {}

UnavailableTechnician::UnavailableTechnician(string model) : model(model) {}

void UnavailableTechnician::print() const {
    cout << "There is no available technician for " << model
         << " airplane model. Please reschedule maintenance session.\n";
}

InvalidTechnician::InvalidTechnician(unsigned int id) {
    this->id = id;

}

void InvalidTechnician::print() const {

    cout << id << "is an invalid technician id. Reenter.\n";

}

void InvalidTechnician::printDuplicate() const {

    cout << "This technician already exists. Please insert another id or delete the technician.\n";
}
