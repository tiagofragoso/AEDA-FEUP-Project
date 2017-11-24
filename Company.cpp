#include "Company.h"
#include "Application.h"

bool Company::passengersChanged = false;
bool Company::airplanesChanged = false;
bool Company::flightsChanged = false;

const string Company::AIRPLANE_IDENTIFIER = "airplane";
const string Company::FLIGHT_IDENTIFIER = "flight";
const string Company::PASSENGER_IDENTIFIER = "passenger";

Company::Company() {

    name = "";
    vector<Airplane *> a;
    vector<Passenger *> p;
    fleet = a;
    passengers = p;

}

Company::Company(string name) {

    this->name = name;
    vector<Airplane *> fleet;
    vector<Passenger *> passengers;
    this->fleet = fleet;
    this->passengers = passengers;
}

string Company::getName() const {
    return this->name;
}

vector<Airplane *> Company::getFleet() const {
    return this->fleet;
}

vector<Passenger *> Company::getPassengers() const {
    return this->passengers;
}

bool Company::getPassengersChanged() const {

    return this->passengersChanged;
}

bool Company::getAirplanesChanged() const {

    return this->airplanesChanged;
}

bool Company::getFlightsChanged() const {

    return this->flightsChanged;
}

void Company::setName(string name) {
    this->name = name;
}

void Company::setFleet(vector<Airplane *> fleet) {
    this->fleet = fleet;
}

void Company::setPassengers(vector<Passenger *> passengers) {
    this->passengers = passengers;
}

//Management methods

void Company::removePassenger(Passenger *passenger) {

    int i = 0;

    for (auto &p : passengers) {

        if (*p == *passenger) {
            passengers.erase(passengers.begin() + i);
        }
        i++;
    }
}

void Company::removeAirplane(Airplane *airplane) {

    int i = 0;

    for (auto a : fleet) {

        if (*a == *airplane) {
            fleet.erase(fleet.begin() + i);
        }
        i++;
    }
}


Flight *Company::flightById(unsigned int id) {
    for (auto const &f: flights) {
        if (f->getId() == id) return f;
    }
    throw InvalidFlight(id);
}

Passenger *Company::passengerById(unsigned int id) {
    for (auto const &p: passengers) {
        if (p->getId() == id) return (Passenger *) p;
    }
    throw InvalidPassenger(id);
}

void Company::printSummaryPassenger() {

    cout << "PASSENGER SUMMARY\n\n";

    cout << std::left;
    cout << setw(12) << "Passenger ID" << setw(3) << " " << setw(30) << "Name" << setw(3) << " " << setw(13)
         << "Date of Birth\n";
    for (auto &passenger : passengers) {
        passenger->printSummary();
    }

    cout << endl;
}

Passenger *Company::choosePassenger() {

    int pId;
    Passenger *cpassenger;
    do {
        cout << "Choose passenger: ";
        if (!validArg(pId)) continue;
        else break;

    } while (true);

    for (auto &passenger : passengers) {

        if (passenger->getId() == pId) {
            cpassenger = passenger;
            return cpassenger;
        }
    }

    throw InvalidPassenger(pId);
}

void Company::passengerShow() {

    if (passengers.empty()) {
        cout << "There are no passengers.\n";
        return;
    }

    printSummaryPassenger();
    string foo;
    Passenger *passenger;
    do {
        do {
            cout << "Do you wish to view detailed information about a passenger (Y/N)?: ";
            if (!validString(foo)) continue;
            else break;

        } while (true);

        normalize(foo);
        if (foo == "y") {
            cout << endl;
            do {
                try {
                    passenger = choosePassenger();
                }
                catch (const InvalidPassenger &i) {
                    i.print();
                    continue;
                }

                passenger->print();
                break;

            } while (true);

        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Company::validPassenger(int id) {

    for (auto &passenger : passengers) {

        if (passenger->getId() == id)
            throw InvalidPassenger(id);

    }
}

Passenger *Company::passengerCreate() {

    string foo;
    string name, dateOfBirth, job;
    int id;

    while (true) {

        do {
            cout << "Normal passenger or passenger with card? (n/c)\n";
            if (!validString(foo)) continue;
            else break;

        } while (true);

        if ((foo == "n") || (foo == "c"))
            break;
        else
            cout << "Invalid option.\n";

    }

    cout << "Insert the new passenger information: \n\n";

    do {

        do {

            cout << "Insert id: ";
            if (validArg(id)) break;

        } while (true);

        try {
            validPassenger(id);
        }
        catch (const InvalidPassenger &i) {
            i.printDuplicate();
            continue;
        }

        break;

    } while (true);


    do {
        cout << "Name: ";
        if (!validString(name)) continue;
        else break;

    } while (true);


    do {
        cout << "Date of Birth: (DD/MM/YYYY): ";
        if (!validString(dateOfBirth)) continue;
        if (dateOfBirth.length() < 8) {
            cout << "Insert date of birth using DD/MM/YYYY format.\n";
            continue;
        }
        try {
            int d, m, y;
            string dob = dateOfBirth;
            next(d, dob, "/");
            next(m, dob, "/");
            next(y, dob, "/");
        }
        catch (InvalidFormat i) {
            cout << "Insert date of birth using DD/MM/YYYY format.\n";
            continue;
        }
        break;

    } while (true);

    Passenger *newpassenger;

    if (foo == "n") newpassenger = new Passenger(id, name, dateOfBirth);
    else if (foo == "c") {

        do {
            cout << "Job: ";
            if (!validString(job)) continue;
            else break;

        } while (true);
        trimString(job);

        newpassenger = new PassengerWithCard(id, name, dateOfBirth, job, 0);
    }
    addObject(newpassenger);
    sortPassengers();
    passengersChanged = true;
    this->sortPassengers();
    cout << "Passenger successfully added\n";
    return newpassenger;
}

void Company::passengerDelete() {

    if (passengers.size() == 0) {
        cout << "There are no passengers.\n";
        return;
    }

    printSummaryPassenger();
    Passenger *passenger;
    do {
        try {
            passenger = choosePassenger();
        }
        catch (const InvalidPassenger &i) {
            i.print();
            continue;
        }
        break;

    } while (true);
    removePassengerFromFlights(passenger);
    removePassenger(passenger);
    cout << "Passenger deleted sucessfully.\n ";
    passengersChanged = true;

}

void Company::passengerUpdateName(Passenger *passenger) {

    string newName;
    cout << "The current name for the chosen passenger is '" << passenger->getName() << "'.\n";

    do {
        cout << "Insert new name: ";
        if (!validString(newName)) continue;
        else break;

    } while (true);
    passenger->setName(newName);
    passengersChanged = true;
    cout << "Passenger name updated successfully.\n";

}

void Company::passengerUpdateDateOfBirth(Passenger *passenger) {

    string newDateOfBirth;
    cout << "The current date of birth for the chosen passenger is '" << passenger->getDateOfBirth() << "'.\n";
    do {
        cout << "Insert the new date of birth (DD/MM/YYYY): ";
        if (!validString(newDateOfBirth)) continue;
        if (newDateOfBirth.length() < 8) {
            cout << "Insert date of birth using DD/MM/YYYY format.\n";
            continue;
        }
        try {
            int d, m, y;
            string dob = newDateOfBirth;
            next(d, dob, "/");
            next(m, dob, "/");
            next(y, dob, "/");
        }
        catch (InvalidFormat i) {
            cout << "Insert date of birth using DD/MM/YYYY format.\n";
            continue;
        }
        break;

    } while (true);
    passenger->setDateOfBirth(newDateOfBirth);
    passengersChanged = true;
    cout << "Passenger date of birth updated successfully.\n";
}


void Company::passengerUpdateJob(Passenger *passenger) {

    Card *card = passenger->getCard();

    string newJob;

    cout << "The current job for the chosen passenger is '" << card->getJob() << "'.\n";
    do {
        cout << "Insert the new job: ";
        if (!validString(newJob)) continue;
        else break;

    } while (true);
    card->setJob(newJob);
    passengersChanged = true;
    cout << "Passenger job updated successfully.\n";

}

void Company::passengerUpdateNYear(Passenger *passenger) {

    Card *card = passenger->getCard();

    int newN;

    cout << "The current number of flights/year for the chosen passenger is '" << card->getAvgYrFlights() << "'.\n";
    do {
        cout << "Insert the new number of flights/year : ";
        if (!validArg(newN)) continue;
        else break;

    } while (true);

    card->setAvgyrFlights(newN);
    passengersChanged = true;
    cout << "Passenger number of flights/year updated successfully.\n";

}

void Company::printSummaryAirplane() {

    cout << "AIRPLANE INFORMATION\n\n";

    cout << std::left;
    cout << setw(11) << "Airplane ID" << setw(3) << " " << setw(7) << "Model" << setw(3) << " " << setw(7)
         << "Capacity\n";

    for (auto &airplane : fleet) {
        airplane->printSummary();
    }
    cout << endl;
}

Airplane *Company::chooseAirplane() {

    int aId;
    Airplane *cairplane;
    do {
        cout << "Choose airplane: ";
        if (!validArg(aId)) continue;
        else break;

    } while (true);

    for (auto &airplane : fleet) {

        if (airplane->getId() == aId) {
            cairplane = airplane;
            return cairplane;
        }
    }
    throw InvalidAirplane(aId);
}

void Company::airplaneShow() {

    if (fleet.empty()) {

        cout << "There are no airplanes.\n";
        return;

    }

    printSummaryAirplane();
    string foo;
    cout << endl;

}

void Company::validAirplane(int id) {

    for (auto &airplane : fleet) {

        if (airplane->getId() == id)
            throw InvalidAirplane(id);
    }
}

void Company::airplaneCreate() {

    string model;
    int id, capacity;

    cout << "Insert the new airplane information: \n\n";

    do {

        do {

            cout << "Insert id: ";
            if (validArg(id)) break;

        } while (true);

        try {
            validAirplane(id);
        }
        catch (const InvalidAirplane &i) {
            i.printDuplicate();
            continue;
        }

        break;

    } while (true);

    do {
        cout << "Model: ";
        if (!validString(model)) continue;
        else break;

    } while (true);

    do {
        cout << "Capacity: ";
        if (!validArg(capacity)) continue;
        else if (capacity % 6 == 0) break;
        else cout << "Capacity must be a multiple of 6.\n";

    } while (true);

    Airplane *newairplane = new Airplane(id, model, capacity);
    addObject(newairplane);
    sortAirplanes();
    cout << "Airplane successfully added\n";
    airplanesChanged = true;
}

void Company::airplaneDelete() {

    if (fleet.empty()) {

        cout << "There are no airplanes.\n";
        return;

    }

    printSummaryAirplane();
    Airplane *airplane;
    do {
        try {
            airplane = chooseAirplane();
        }
        catch (const InvalidAirplane &i) {
            i.print();
            continue;
        }

        break;

    } while (true);
    if (airplane->getFlights().empty()) {
        removeAirplane(airplane);
        cout << "Airplane deleted sucessfully.\n ";
        airplanesChanged = true;
        flightsChanged = true;
    } else cout << "Cannot delete an airplane with assigned flights. Please delete the flights first.\n";

}

void Company::airplaneUpdateModel(Airplane *airplane) {

    string newModel;
    cout << "The current model for the chosen airplane is '" << airplane->getModel() << "'.\n";
    do {
        cout << "Insert new model: ";
        if (!validString(newModel)) continue;
        else break;

    } while (true);
    airplane->setModel(newModel);
    airplanesChanged = true;
    cout << "Airplane model updated successfully.\n";

}

void Company::airplaneUpdateCapacity(Airplane *airplane) {

    if (!airplane->getFlights().empty()) {

        cout
                << "There are assigned seats in at least one flight in this airplane, if you want to change its capacity delete the flight first.\n";
        return;

    }

    int newcapacity;

    cout << "The current capacity for the chosen airplane is '" << airplane->getCapacity() << "'.\n";
    do {
        cout << "Insert the new capacity : ";
        if (!validArg(newcapacity)) continue;
        else if (newcapacity % 6 == 0) break;
        else cout << "Capacity must be a multiple of 6.\n";

    } while (true);

    airplane->setCapacity((unsigned int) newcapacity);
    airplanesChanged = true;
    cout << "Airplane capacity updated successfully.\n";

}

void Company::bookFlight(Passenger *p) {
    string menuhelper;
    do {
        do {
            cout << "Do you wish to book a Rented or Commercial Flight (R/C) ? ";
            if (!validString(menuhelper)) continue;
            else break;

        } while (true);
        if (!menuhelper.empty()) normalize(menuhelper);
        if (menuhelper == "r" || menuhelper == "c") {
            bookFlightWithType(p, menuhelper);
            break;
        } else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;
}

float Company::ticketPrice(Passenger *p, Flight *f, string type) {
    float price;
    if (p->getType() == "c") {
        if (type == "r") {
            price = f->getBasePrice() * (100 - p->getCard()->getAvgYrFlights()) / 100;
        } else {
            if (f->getPassengers().size() < f->getCapacity() && f->getTime_to_flight() < 48) {
                price = 0.9 * f->getBasePrice() * (100 - p->getCard()->getAvgYrFlights()) / 100;
            } else {
                price = f->getBasePrice() * (100 - p->getCard()->getAvgYrFlights()) / 100;
            }
        }

    } else {
        if (type == "r") {
            price = f->getBasePrice();
        }
    }

    price = trunc(round(price * 100.0)) / 100.0;
    return price;
}

vector<Flight *> Company::getFlightsWithType(string type) {
    vector<Flight *> f;

    if (type == "c")
        for (auto const &fl: this->flights) {
            if (fl->getType() == type && fl->getPassengers().size() < fl->getCapacity()) f.push_back(fl);
        }
    else if (type == "r")
        for (auto const &fl: this->flights) {
            if (fl->getType() == type && fl->getBuyer() == nullptr) f.push_back(fl);
        }
    return f;

}


void Company::printFlightsByType(Passenger *p, string type, vector<Flight *> &fvector) {

    if (!fvector.empty()) {
        cout << std::left;
        cout << setw(9) << "Flight ID" << setw(3) << " " << setw(15) << "Departure" << setw(3) << " " << setw(15)
             << "Destination" << setw(3) << " " << setw(18) << "Time to flight(h)"
             << setw(3) << " " << setw(10) << "Price(€)";
        if (type == "c") cout << std::left << setw(3) << " " << setw(20) << "Occupancy";
        cout << endl;

        for (auto const &fl: fvector) {
            cout << std::left;
            cout << setw(9) << fl->getId() << setw(3) << " " << setw(15) << fl->getDeparture() << setw(3) << " "
                 << setw(15) << fl->getDestination() << setw(3) << " " << setw(18)
                 << to_string(fl->getTime_to_flight()) + "h" << setw(3) << " " << setw(10) << std::fixed
                 << setprecision(2) << ticketPrice(p, fl, type);
            if (type == "c")
                cout << std::left << setw(3) << " " << setw(20)
                     << to_string(fl->getPassengers().size()) + "/" + to_string(fl->getCapacity());
            cout << endl;
        }
    }
}


Flight *Company::chooseFlight(unsigned int id, vector<Flight *> &fvector) {
    for (auto const &f : fvector) {
        if (f->getId() == id)
            return f;
    }
    throw (InvalidFlight(id));
}

void Company::bookFlightWithType(Passenger *p, string type) {
    vector<Flight *> fvector = getFlightsWithType(type);
    printFlightsByType(p, type, fvector);
    int id;
    Flight *flight;
    do {
        cout << "Please insert the ID of the flight you wish to book: ";
        if (!validArg(id)) continue;
        else {
            try {
                flight = chooseFlight(id, fvector);
                break;
            }
            catch (const InvalidFlight &in) {
                in.print();
            }
        }
    } while (true);
    if (type == "c")
        flightAddPassenger(flight, p);
    else {
        flight->setBuyer(p);
        cout << "You have rented the flight " << id << ".\n";
    }
    flightsChanged = true;
}

void Company::returnTicket(Passenger *p) {
    int id;
    vector<pair<string, Flight *> > v = getTickets(p);
    showAllTickets(p, true);
    if (v.empty()) return;
    do {
        cout << "Please choose the ticket you wish to return: ";
        if (!validArg(id)) continue;
        else if (id >= 1 && id <= v.size()) break;
        cout << "Invalid input. Reenter.\n";
    } while (true);

    pair<string, Flight *> selectedTicket = static_cast<pair<string, Flight *> &&>(v.at(id - 1));

    if (selectedTicket.second->getType() == "c") {

        auto it = selectedTicket.second->getPassengers().find(selectedTicket.first);

        selectedTicket.second->getPassengers().erase(it);

        cout << "Your ticket for seat " << selectedTicket.first << " from ";

    } else {

        selectedTicket.second->setBuyer(nullptr);

        cout << "Your full reservation of";

    }

    flightsChanged = true;

    cout << " Flight " << selectedTicket.second->getId() << " was successfully removed.\n";

}

void Company::showAllTickets(Passenger *passenger, bool idx) {

    vector<pair<string, Flight *> > v = getTickets(passenger);
    unsigned int i = 1;
    cout << std::left;
    if (!v.empty()) {
        if (idx) cout << setw(5) << " ";
        cout << setw(9) << "Flight ID" << setw(3) << " " << setw(4) << "Seat" << setw(3) << " "
             << setw(15) << "Departure" << setw(3) << " " << setw(15) << "Destination" << endl;
        for (auto const &t: v) {
            if (idx) cout << "[" << i << "]- ";
            cout << setw(9) << to_string(t.second->getId()) << setw(3) << " " << setw(4) << t.first << setw(3) << " "
                 << setw(15) << t.second->getDeparture() << setw(3) << " " << setw(15) << t.second->getDestination()
                 << setw(3)
                 << " " << "Flight in " << to_string(t.second->getTime_to_flight()) << "h" << endl;
            i++;
        }
    } else cout << "Selected passenger has no booked tickets.\n";
    cout << endl;
}


void Company::printSummaryFlight(Airplane *airplane) {

    cout << "FLIGHT SUMMARY\n\n";
    cout << std::left;
    cout << setw(9) << "Flight ID" << setw(3) << " " << setw(15) << "Departure" << setw(3) << " " << setw(15)
         << "Destination" << setw(3) << " " << setw(14) << "Time to flight\n";

    for (auto &flight : airplane->getFlights()) {

        flight->printSummary();
    }
    cout << endl;
}


Flight *Company::chooseFlight(Airplane *airplane) {

    int fId;
    Flight *cflight;

    do {
        cout << "Choose flight: ";
        if (!validArg(fId)) continue;
        else break;

    } while (true);

    for (auto &flight : airplane->getFlights()) {

        if (flight->getId() == fId) {
            cflight = flight;
            return cflight;
        }
    }
    throw InvalidFlight(fId);
}


void Company::flightShow(Airplane *airplane) {

    if (airplane->getFlights().size() == 0) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

    printSummaryFlight(airplane);
    string foo;
    Flight *flight;
    do {
        do {
            cout << "Do you wish to view detailed information about a flight (Y/N)?: ";
            if (!validString(foo)) continue;
            else break;

        } while (true);
        normalize(foo);
        if (foo == "y") {
            cout << endl;
            do {
                try {
                    flight = chooseFlight(airplane);
                }
                catch (const InvalidFlight &i) {
                    i.print();
                    continue;
                }

                flight->print();
                break;

            } while (true);

        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}


void Company::validFlight(int id) {

    for (auto &airplane : fleet) {

        for (auto &flight : airplane->getFlights()) {

            if (flight->getId() == id)
                throw InvalidFlight(id);
        }
    }
}

void Company::flightCreate(Airplane *airplane) {

    string departure, destination, foo;
    int price, id, duration, time_to_flight;
    Passenger *buyer;
    Flight *flight;

    while (true) {

        do {
            cout << "Comercial flight or rented flight? (c/r)\n";
            if (!validString(foo)) continue;
            else break;

        } while (true);
        if ((foo == "c") || (foo == "r"))
            break;
        else
            cout << "Invalid option.\n";

    }

    cout << "Insert new flight information: \n\n";

    do {

        do {

            cout << "Insert id: ";
            if (validArg(id)) break;

        } while (true);

        try {
            validFlight(id);
        }
        catch (const InvalidFlight &i) {
            i.printDuplicate();
            continue;
        }
        break;
    } while (true);

    do {
        cout << "City of departure: ";
        if (!validString(departure)) continue;
        else break;

    } while (true);

    do {
        cout << "City of arrival: ";
        if (!validString(destination)) continue;
        else break;

    } while (true);

    do {
        cout << "Duration (h): ";
        if (validArg(duration)) break;
    } while (true);

    do {
        cout << "Base price (in euros): ";
        if (validArg(price)) break;
    } while (true);

    do {
        cout << "Time to flight (h): ";
        if (validArg(time_to_flight)) break;
    } while (true);

    if (foo == "r") {

        flight = new RentedFlight(id, departure, destination, time_to_flight, price, duration, nullptr);

    } else
        flight = new CommercialFlight(id, departure, destination, time_to_flight, price, duration);

    flight->setCapacity(airplane->getCapacity());

    try {

        airplane->addFlight(flight);
        addObject(flight);

    } catch (const OverlappingFlight &f) {

        f.print();
        return;
    }

    sortFlights();
    airplanesChanged = true;
    cout << "Flight added successfully\n";

}

void Company::flightDelete(Airplane *airplane) {

    if (airplane->getFlights().empty()) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

    printSummaryFlight(airplane);
    Flight *flight;
    do {

        try {
            flight = chooseFlight(airplane);
        }
        catch (const InvalidFlight &i) {
            i.print();
            continue;
        }
        break;

    } while (true);

    try {
        airplane->removeFlight(flight);
    }
    catch (const ConnectionFlight &f) {
        f.print();
        return;
    }

    removeFlight(flight);

    cout << "Flight deleted sucessfully.\n";
    airplanesChanged = true;
    flightsChanged = true;
}


void Company::flightUpdatePrice(Flight *flight) {

    int newPrice;
    cout << "The current price for the chosen flight is '" << flight->getBasePrice() << "'.\n";
    do {
        cout << "Insert new price: ";
        if (!validArg(newPrice)) continue;
        else break;

    } while (true);

    flight->setBasePrice(newPrice);
    flightsChanged = true;
    cout << "Flight base price updated successfully.\n";
}

vector<string> Company::availableSeats(Flight *flight, unsigned int capacity) {

    vector<string> seats;
    string line;
    string place;
    PassengerMap &passengers = flight->getPassengers();

    for (size_t i = 0; i < capacity / 6; i++) {


        line = to_string(i + 1);

        for (size_t j = 0; j < 6; j++) {

            string seat = "A";

            seat.at(0) += j;


            place = line + seat;

            if (flight->getPassengers().empty()) {

                seats.push_back(place);
                continue;
            }

            if (passengers.find(place) != passengers.end()) {
                continue;
            } else {
                seats.push_back(place);
            }
        }
    }


    return seats;
}


void Company::printSeats(unsigned int capacity, vector<string> seats) {

    string na = "N/A";

    string line;

    for (size_t i = 0; i < capacity / 6; i++) {


        line = to_string(i + 1);

        for (size_t j = 0; j < 6; j++) {

            string seat = "A";

            seat.at(0) += j;

            auto it = find(seats.begin(), seats.end(), line + seat);
            if (it == seats.end())
                cout << setw(5) << na << " ";
            else
                cout << setw(5) << line + seat << " ";
        }

        cout << endl;
    }

}

string Company::chooseSeat(vector<string> seats) {

    string seat;
    do {
        cout << "Insert the chosen seat: ";
        if (!validString(seat)) continue;
        else break;

    } while (true);

    auto it = find(seats.begin(), seats.end(), seat);
    if (it == seats.end())
        throw InvalidSeat(seat);

    return seat;

}

void Company::flightAddPassenger(Flight *flight, Passenger *passenger) {
    vector<string> seats;
    unsigned int capacity;
    string seat;

    for (auto const &a : fleet) {
        for (auto const &f : a->getFlights()) {
            if (*f == *flight) {
                capacity = a->getCapacity();
            }
        }
    }

    cout << "Available seats: \n";

    seats = availableSeats(flight, capacity);
    printSeats(capacity, seats);

    if (seats.empty()) {
        cout << "There are no available seats.\n";
        return;
    }
    do {
        try {
            seat = chooseSeat(seats);
        }
        catch (const InvalidSeat &s) {
            s.print();
            continue;
        }

        break;

    } while (true);
    flight->addPassenger(seat, passenger);
    cout << "Booking for seat " << seat << " on flight " << flight->getId() << " successful.\n";
    flightsChanged = true;
}

vector<pair<string, Flight *> > Company::getTickets(Passenger *p) {
    vector<pair<string, Flight *> > tickets;

    for (auto const &f: flights) {
        if (f->getType() == "c")
            for (auto const &pass: f->getPassengers()) {
                if (pass.second->getId() == p->getId()) tickets.emplace_back(pass.first, f);
            }
        else {
            if (f->getBuyer() != nullptr)
                if (*(f->getBuyer()) == *p) tickets.emplace_back("ALL", f);
        }
    }

    return tickets;

}

void Company::sortPassengers() {
    sort(passengers.begin(), passengers.end(), compPID);
}

void Company::passengerCreateWrapper() {
    passengerCreate();
}

void Company::sortAirplanes() {
    sort(fleet.begin(), fleet.end(), compAId);
}

void Company::sortFlights() {

    sort(flights.begin(), flights.end(), compFId);
}

void Company::clearData(string identifier) {

    if (identifier == Company::PASSENGER_IDENTIFIER) passengers.clear();
    else if (identifier == Company::FLIGHT_IDENTIFIER) flights.clear();
    else if (identifier == Company::AIRPLANE_IDENTIFIER) fleet.clear();

}

void Company::showAllTicketsWrapper(Passenger *p) {
    showAllTickets(p, false);
}

void Company::addObject(Passenger *passenger) {
    this->passengers.push_back(passenger);
}

void Company::addObject(Flight *flight) {
    this->flights.push_back(flight);
}

void Company::addObject(Airplane *airplane) {
    this->fleet.push_back(airplane);
}

void Company::removeFlight(Flight *flight) {

    for (size_t i = 0; i < flights.size(); i++) {

        if (*flights.at(i) == *flight) {

            flights.erase(flights.begin() + i);
            break;
        }


    }

}

void Company::flightUpdatePrice(Airplane *airplane) {

    if (airplane->getFlights().empty()) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

    printSummaryFlight(airplane);
    string op;
    Flight *flight;
    do {
        try {
            flight = chooseFlight(airplane);
        }
        catch (const InvalidFlight &i) {
            i.print();
            continue;
        }

        break;

    } while (true);

    flightUpdatePrice(flight);

}

void Company::removePassengerFromFlights(Passenger *passenger) {

    for (auto f : flights) {

        f->removePassenger(passenger);

    }
}
