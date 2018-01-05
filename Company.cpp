#include "Company.h"
#include "Application.h"
#include <queue>

bool Company::passengersChanged = false;
bool Company::airplanesChanged = false;
bool Company::flightsChanged = false;
bool Company::techniciansChanged = false;

const string Company::AIRPLANE_IDENTIFIER = "airplane";
const string Company::FLIGHT_IDENTIFIER = "flight";
const string Company::PASSENGER_IDENTIFIER = "passenger";
const string Company::TECHNICIAN_IDENTIFIER = "technician";


Company::Company() {

    name = "";
    AirplanesSet a;
    vector<Passenger *> p;
    fleet = a;
    passengers = p;

}

Company::Company(string name) {

    this->name = name;
    AirplanesSet fleet;
    vector<Passenger *> passengers;
    this->fleet = fleet;
    this->passengers = passengers;
}

string Company::getName() const {
    return this->name;
}

AirplanesSet Company::getFleet() const {
    return this->fleet;
}

vector<Passenger *> Company::getPassengers() const {
    return this->passengers;
}

bool Company::getTechniciansChanged() const {

    return this->techniciansChanged;
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

void Company::setFleet(AirplanesSet fleet) {
    this->fleet = fleet;
}

void Company::setPassengers(vector<Passenger *> passengers) {
    this->passengers = passengers;
}

//Management methods

void Company::removePassenger(Passenger *passenger) {

    auto it = find(passengers.begin(), passengers.end(), passenger);
    if (it != passengers.end()) passengers.erase(it);
    auto ip = inactivePassengers.find(passenger);
    if (ip != inactivePassengers.end()) inactivePassengers.erase(ip);

}

void Company::removeAirplane(Airplane *airplane) {

    auto it = fleet.find(airplane);
    fleet.erase(it);
}


Flight *Company::flightById(unsigned int id) {
    for (auto const &f: flights) {
        if (f->getId() == id) return f;
    }
    throw InvalidFlight(id);
}

Passenger *Company::passengerById(unsigned int id) {
    for (auto const &p: getAllPassengers()) {
        if (p->getId() == id) return (Passenger *) p;
    }
    throw InvalidPassenger(id);
}

void Company::printSummaryPassenger() {

    cout << "PASSENGER SUMMARY\n\n";
    if (getAllPassengers().empty()) cout << "No passengers to display.\n";
    else {
        cout << std::left;
        cout << setw(12) << "Passenger ID" << setw(3) << " " << setw(30) << "Name" << setw(3) << " " << setw(13)
             << "Date of Birth\n";

        cout << "ACTIVE PASSENGERS\n";
        if (passengers.empty()) cout << "There are no active passengers.\n";
        else for (auto &passenger : passengers) passenger->printSummary();
        if (passengers.empty()) cout << "There are no inactive passengers.\n\n";
        else {
            cout << "INACTIVE PASSENGERS\n";

            if (getIncPassengers().empty())
                cout << "There are no inactive passengers.\n";
            else
                for (auto &passenger : getIncPassengers()) passenger->printSummary();

        }
    }
    cout << endl;
}

Passenger *Company::choosePassenger() {

    int pId;
    do {
        cout << "Choose passenger: ";
        if (!validArg(pId)) continue;
        else break;

    } while (true);

    for (auto &passenger : getAllPassengers()) {

        if (passenger->getId() == pId) {
            return passenger;
        }
    }

    throw InvalidPassenger(pId);
}

void Company::printNextMaintenanceSessions() {

    if (fleet.empty()) {

        cout << "There are no airplanes.\n";
        return;

    }

    cout << "Next maintenance sessions:\n";

    for (auto a : fleet) {
        cout << "Airplane " << a->getId() << " - ";
        cout << a->getMaintenance().print() << endl;
    }
}

void Company::printMaintenancePeriod() {
    Date d1, d2;

    if (fleet.empty()) {

        cout << "There are no airplanes.\n";
        return;

    }

    do {
        cout << "First day (DD/MM/YYYY): ";
        if (validDate(d1)) break;

    } while (true);

    do {
        cout << "Last day (DD/MM/YYYY): ";
        if (validDate(d2)) break;

    } while (true);

    vector<pair<int, Date> > maintenance;

    for (auto const &a : fleet) {
        Date date = a->getMaintenance();

        while (date < d2) {

            if (d1 < date && date < d2) {
                maintenance.emplace_back(a->getId(), date);
            }
            date = date + a->getMaintenancePeriod();
        }

    }

    sort(maintenance.begin(), maintenance.end(), compMaintenance);

    if (maintenance.empty()) {
        cout << "There are no scheduled maintenance sessions in this period.\n";
        return;
    }

    for (auto &m : maintenance) {

        cout << "Airplane " << m.first << " - ";
        cout << m.second.print();
        cout << endl;
    }
}

void Company::passengerShow() {

    if (getAllPassengers().empty()) {
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

    for (auto &passenger : getAllPassengers()) {

        if (passenger->getId() == id)
            throw InvalidPassenger(id);

    }
}

Passenger *Company::passengerCreate() {

    string foo;
    string name, dateOfBirth, job;
    Date dobd;
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
        if (validDate(dobd)) break;

    } while (true);

    Passenger *newpassenger;

    if (foo == "n") newpassenger = new Passenger(id, name, dobd);
    else if (foo == "c") {

        do {
            cout << "Job: ";
            if (!validString(job)) continue;
            else break;

        } while (true);
        trimString(job);

        newpassenger = new PassengerWithCard(id, name, dobd, job, 0);
    }
    addObject(newpassenger);
    passengersChanged = true;
    this->sortPassengers();
    updatePassengers();
    cout << "Passenger successfully added\n";
    return newpassenger;
}

void Company::passengerDelete() {

    if (getAllPassengers().empty()) {
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
    removePassengerFromBookings(passenger);
    removePassenger(passenger);
    cout << "Passenger deleted successfully.\n ";
    passengersChanged = true;
    updateTime();

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
    Date dobd;
    cout << "The current date of birth for the chosen passenger is '";
    passenger->getDateOfBirth().print();
    cout << "'.\n";
    do {
        cout << "Insert the new date of Birth: (DD/MM/YYYY): ";
        if (validDate(dobd)) break;

    } while (true);
    passenger->setDateOfBirth(dobd);
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

    vector<Airplane *> airplanes;

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
    Airplane *airplane;

    do {
        do {
            cout << "Do you wish to view detailed information about a airplane (Y/N)?: ";
            if (!validString(foo)) continue;
            else break;

        } while (true);

        normalize(foo);
        if (foo == "y") {
            cout << endl;
            do {
                try {
                    airplane = chooseAirplane();
                }
                catch (const InvalidAirplane &i) {
                    i.print();
                    continue;
                }

                airplane->print();
                break;

            } while (true);

        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Company::validAirplane(int id) {

    for (auto &airplane : fleet) {

        if (airplane->getId() == id)
            throw InvalidAirplane(id);
    }
}

void Company::airplaneCreate() {
    Date dateMaintenance;
    string model, date;
    int id, capacity, period;
    int day, month, year;

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

    do {
        cout << "Date of next maintenance: (DD/MM/YYYY): ";
        if (validDate(dateMaintenance)) break;

    } while (true);

    do {

        cout << "Insert period of airplane maintenance (days): ";
        if (validArg(period)) break;

    } while (true);

    Date mp;
    mp.day = period;

    Airplane *newairplane = new Airplane(id, model, capacity, dateMaintenance, mp);
    addObject(newairplane);
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

void Company::airplaneMaintenanceReschedule() {

    if (fleet.empty()) {
        cout << "There are no airplanes.\n";
        return;

    }

    printSummaryAirplane();
    string op;
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

    Date newDate;
    cout << "The next maintenance session date for the chosen airplane is '" << airplane->getMaintenance().print()
         << "'.\n";

    do {
        cout << "Insert the new date (DD/MM/YYYY): ";
        if (validDate(newDate)) break;
    } while (true);


    removeAirplane(airplane);
    airplane->setMaintenance(newDate);
    addObject(airplane);
    airplanesChanged = true;

    cout << "Maintenance date successfully rescheduled.\n";
}

void Company::airplanePerformMaintenance() {

    if (fleet.empty()) {

        cout << "There are no airplanes.\n";
        return;

    }

    printSummaryAirplane();
    string op;
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

    Technician *tech;

    try {
        tech = chooseTechnician(airplane->getModel());
    }
    catch (const UnavailableTechnician &t) {
        t.print();
        return;
    }

    techRemovefromQueue(tech);
    Date d = {0, 0, 0, 5, 0};
    d = d + tech->getTimeWhenAvailable();
    tech->setTimeWhenAvailable(d);
    technicians.push(tech);
    removeAirplane(airplane);
    Date date = airplane->getMaintenance();
    date = date + airplane->getMaintenancePeriod();
    //addTime(date, airplane->getMaintenancePeriod());
    airplane->setMaintenance(date);
    addObject(airplane);
    airplanesChanged = true;
    cout << "Maintenance session started successfully. Finished in 5 hours\n";
    cout << "Technician: Id-" << tech->getId() << " Name-" << tech->getName() << endl;
    cout << "Next maintenance session is scheduled to " << date.day << "/" << date.month << "/" << date.year << endl;

}

Technician *Company::chooseTechnician(string model) {
    techniciansPriorityQueue temp = technicians;

    while (!temp.empty()) {
        vector<string> aux = temp.top()->getModels();
        if (find(aux.begin(), aux.end(), model) != aux.end()) {
            if (temp.top()->getTimeWhenAvailable() == Application::currentDate)
                return temp.top();
        }
        temp.pop();
    }

    throw UnavailableTechnician(model);

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

void Company::airplaneUpdateMaintenancePeriod(Airplane *airplane) {

    int newPeriod;
    cout << "The current period between maintenance sessions for the chosen airplane is "
         << airplane->getMaintenancePeriod().day << " day(s).\n";
    do {
        cout << "Insert the new period (days): ";
        if (validArg(newPeriod)) break;
    } while (true);
    Date mp;
    mp.day = newPeriod;
    airplane->setMaintenancePeriod(mp);
    airplanesChanged = true;
    cout << "Airplane maintenance period updated successfully.\n";
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
    updateTime();
}

float Company::ticketPrice(Passenger *p, Flight *f, string type) {
    float price;
    Date priceDropDate;
    priceDropDate.hour = 48;
    priceDropDate.normalize();
    if (p->getType() == "c") {
        if (type == "r") {
            price = f->getBasePrice() * (100 - p->getCard()->getAvgYrFlights()) / 100;
        } else {
            if (f->getPassengers().size() < f->getCapacity() && f->getTimeToFlight() < priceDropDate) {
                price = 0.9 * f->getBasePrice() * (100 - p->getCard()->getAvgYrFlights()) / 100;
            } else {
                price = f->getBasePrice() * (100 - p->getCard()->getAvgYrFlights()) / 100;
            }
        }

    } else {
        if (type == "r") {
            price = f->getBasePrice();
        }
        if (type == "c") {
            if (f->getPassengers().size() < f->getCapacity() && f->getTimeToFlight() < priceDropDate) {
                price = 0.9 * f->getBasePrice();

            } else {
                price = f->getBasePrice();
            }
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
                 << setw(15) << fl->getDestination() << setw(3) << " " << setw(18) << fl->getDate().printFullDate()
                 << setw(3) << " " << setw(10) << std::fixed
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
        bookings.push_back(new Booking(getNextBookingId(), p, flight, "ALL"));
        cout << "You have rented the flight " << id << ".\n";
    }
    flightsChanged = true;
    updateTime();
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
    id--;
    auto selectedTicket = v.at(id);

    for (auto bit = bookings.begin(); bit != bookings.end(); bit++) {
        if ((*bit)->getSeat() == selectedTicket.first &&
            (*bit)->getFlight()->getId() == selectedTicket.second->getId()) {
            bookings.erase(bit);
            break;
        }
    }

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
    updateTime();

}

void Company::showAllTickets(Passenger *passenger, bool idx) {

    vector<pair<string, Flight *> > v = getTickets(passenger);
    unsigned int i = 1;
    cout << std::left;
    if (!v.empty()) {
        if (idx) cout << setw(5) << " ";
        cout << setw(9) << "Flight ID" << setw(3) << " " << setw(4) << "Seat" << setw(3) << " "
             << setw(15) << "Departure" << setw(3) << " " << setw(15) << "Destination" << setw(3) << " " << setw(18)
             << "Date" << endl;
        for (auto const &t: v) {
            if (idx) cout << "[" << i << "]- ";
            cout << setw(9) << to_string(t.second->getId()) << setw(3) << " " << setw(4) << t.first << setw(3) << " "
                 << setw(15) << t.second->getDeparture() << setw(3) << " " << setw(15) << t.second->getDestination()
                 << setw(3)
                 << " " << setw(18) << t.second->getDate().printFullDate() << endl;
            i++;
        }
    } else cout << "Selected passenger has no booked tickets.\n";
    cout << endl;
}


void Company::printSummaryFlight(Airplane *airplane) {

    cout << "FLIGHT SUMMARY\n\n";
    cout << std::left;
    cout << setw(9) << "Flight ID" << setw(3) << " " << setw(15) << "Departure" << setw(3) << " " << setw(15)
         << "Destination" << setw(3) << " " << setw(18) << "Date" << endl;

    for (auto &flight : airplane->getFlights()) {
        if (!pastFlight(flight))
            flight->printSummary();
    }
    cout << endl;
}


Flight *Company::chooseFlight(Airplane *airplane) {

    int fId;
    do {
        cout << "Choose flight: ";
        if (!validArg(fId)) continue;
        else break;

    } while (true);

    for (auto const flight : airplane->getFlights()) {

        if (flight->getId() == fId && !pastFlight(flight)) {
            return flight;
        }
    }
    throw InvalidFlight(fId);
}

Technician *Company::chooseTechnician() {

    int tId;
    do {
        cout << "Choose technician: ";
        if (!validArg(tId)) continue;
        else break;

    } while (true);

    techniciansPriorityQueue temp;
    Technician *aux;
    bool found = false;

    while (!technicians.empty()) {
        if (technicians.top()->getId() == tId) {
            aux = technicians.top();
            found = true;
        }
        temp.push(technicians.top());
        technicians.pop();
    }

    while (!temp.empty()) {
        technicians.push(temp.top());
        temp.pop();
    }

    if (!found) throw InvalidTechnician(tId);
    return aux;
}

void Company::validTechnician(int id) {

    bool found = false;
    techniciansPriorityQueue temp;

    while (!technicians.empty()) {
        if (technicians.top()->getId() == id) {
            found = true;
        }
        temp.push(technicians.top());
        technicians.pop();
    }

    while (!temp.empty()) {
        technicians.push(temp.top());
        temp.pop();
    }

    if (found) throw InvalidTechnician(id);
}

void Company::flightShow(Airplane *airplane) {

    unsigned int fnr = 0;

    for (auto const f: airplane->getFlights()) if (!pastFlight(f)) fnr++;

    if (!fnr) {
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

        for (auto const flight : airplane->getFlights()) {

            if (flight->getId() == id && !pastFlight(flight))
                throw InvalidFlight(id);
        }
    }
}

void Company::flightCreate(Airplane *airplane) {

    string departure, destination, foo;
    int price, id;
    Flight *flight;
    Date date, duration;

    while (true) {

        do {
            cout << "Commercial flight or rented flight? (c/r)\n";
            if (!validString(foo)) continue;
            else break;

        } while (true);
        if ((foo == "c") || (foo == "r"))
            break;
        else
            cout << "Invalid option.\n";
    }

    printRestrictions(airplane);

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
        cout << "Duration (hh:mm): ";
        if (validTime(duration)) break;
    } while (true);

    do {
        cout << "Base price (in euros): ";
        if (validArg(price)) break;
    } while (true);

    do {
        cout << "Date (DD/MM/YY-hh:mm): ";
        if (validFullDate(date)) {
            if (date < Application::currentDate || date == Application::currentDate)
                cout << "The date selected is prior to the current date. Reenter.\n";
            else break;
        }
    } while (true);


    if (foo == "r") {

        flight = new RentedFlight(id, departure, destination, date, price, duration, nullptr);

    } else
        flight = new CommercialFlight(id, departure, destination, date, price, duration);

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

    unsigned int fnr = 0;

    for (auto const f: airplane->getFlights()) if (!pastFlight(f)) fnr++;

    if (!fnr) {
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

    if (seats.empty()) {
        cout << "There are no available seats.\n";
        return;
    }

    printSeats(capacity, seats);

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
    bookings.push_back(new Booking(getNextBookingId(), passenger, flight, seat));
    cout << "Booking for seat " << seat << " on flight " << flight->getId() << " successful.\n";
    flightsChanged = true;
}

vector<pair<string, Flight *> > Company::getTickets(Passenger *p) {
    vector<pair<string, Flight *> > tickets;

    for_each(bookings.begin(), bookings.end(), [p, &tickets](Booking *b) {
        if (b->getPassenger()->getId() == p->getId())
            tickets.emplace_back(b->getSeat(), b->getFlight());
    });

    return tickets;

}

void Company::sortPassengers() {
    sort(passengers.begin(), passengers.end(), compPID);
}

void Company::passengerCreateWrapper() {
    passengerCreate();
}

void Company::sortFlights() {

    sort(flights.begin(), flights.end(), compFId);
}

void Company::clearData(string identifier) {

    if (identifier == Company::PASSENGER_IDENTIFIER) {
        passengers.clear();
        inactivePassengers.clear();
    } else if (identifier == Company::FLIGHT_IDENTIFIER) {
        flights.clear();
        pastFlights.clear();
    } else if (identifier == Company::AIRPLANE_IDENTIFIER) fleet.clear();

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
    this->fleet.insert(airplane);
}

void Company::removeFlight(Flight *flight) {

    bookings.erase(
            remove_if(bookings.begin(), bookings.end(), [flight](Booking *b) { return b->getFlight() == flight; }),
            bookings.end());

    auto it = find(flights.begin(), flights.end(), flight);
    if (it != flights.end()) flights.erase(it);
    updateTime();

}

void Company::flightUpdatePrice(Airplane *airplane) {

    unsigned int fnr = 0;

    for (auto const f: airplane->getFlights()) if (!pastFlight(f)) fnr++;

    if (!fnr) {
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


void Company::printRestrictions(Airplane *airplane) {

    if (airplane->getFlights().empty()) cout << "There are no restrictions for this flight.\n";
    else if (airplane->getFlights().size() == 1) {
        cout
                << "For efficiency purposes, the airplane will never fly empty. Therefore, we must apply some restrictions to flight creation.\n";
        auto it = airplane->getFlights().begin();
        Date begin = (*it)->getDate();
        Date final = (*it)->getDate() + (*it)->getDuration();
        final.normalize();
        if (begin > Application::currentDate) {
            cout << "The plane should be ready to land on " << (*it)->getDestination() << " on " << begin.print()
                 << " at " << begin.printTime() << ".\n";
        }
        if ((final < Application::currentDate)) {
            final = Application::currentDate;
        }
        cout << "The plane should be ready to take off from " << (*it)->getDestination() << " on " <<
             final.print() << " at " << final.printTime() << " or later.\n";
    } else {
        cout
                << "For efficiency purposes, the airplane will never fly empty. Therefore, we must apply some restrictions to flight creation.\n";
        auto firstf = airplane->getFlights().begin();
        auto lastf = firstf + (airplane->getFlights().size() - 1);
        Date dateFirst = (*firstf)->getDate();
        if (dateFirst > Application::currentDate) {
            cout << "The plane should be ready to land on " << (*firstf)->getDestination() << " on "
                 << dateFirst.print() << " at " << dateFirst.printTime() << ".\n";
        }
        Date dateLast = (*lastf)->getDate() + (*lastf)->getDuration();
        if (dateLast < Application::currentDate) {
            dateLast = Application::currentDate;
        }
        cout << "The plane should be ready to take off from " << (*lastf)->getDestination() << " on "
             << dateLast.print() << " at " << dateLast.printTime() << " or later.\n";
    }
}


void Company::removePassengerFromFlights(Passenger *passenger) {

    for (auto &f : flights) {

        f->removePassenger(passenger);

    }
}


void Company::technicianCreate() {
    string foo;
    string name, model;
    int id;

    do {
        do {
            cout << "Id: ";
            if (!validArg(id)) continue;
            else break;

        } while (true);

        try {
            validTechnician(id);
        }
        catch (const InvalidTechnician &i) {
            i.printDuplicate();
            continue;
        }
        break;

    } while (true);

    cout << "Insert the new technician information: \n\n";

    do {
        cout << "Name: ";
        if (!validString(name)) continue;
        else break;

    } while (true);

    do {
        cout << "Models (separated between commas ','): ";
        if (!validString(model)) continue;
        else break;

    } while (true);

    trimString(model);
    vector<string> models_v;
    string st;

    while (true) {
        if (model.find(",") != model.npos) {
            next(st, model, ",");
            models_v.push_back(st);
        } else {
            models_v.push_back(model);
            break;
        }
    }

    Technician *newtechnician = new Technician(id, name, models_v);
    technicians.push(newtechnician);
    techniciansChanged = true;
    cout << "Technician successfully added\n";

}

techniciansPriorityQueue Company::getTechnicians() const {
    return technicians;
}

void Company::printSummaryTechnician() const {

    if (technicians.empty()) {
        cout << "There are no technicians.\n";
        return;
    }
    cout << "TECHNICIAN SUMMARY\n\n";

    cout << std::left;
    cout << setw(13) << "Technician ID" << setw(3) << " " << setw(30) << "Name" << setw(3) << " " << setw(13)
         << "Models" << endl;
    techniciansPriorityQueue techs = technicians;

    while (!techs.empty()) {
        techs.top()->printSummary();
        techs.pop();
    }
}


void Company::technicianShow() {

    if (technicians.empty()) {
        cout << "There are no technicians.\n";
        return;
    }

    printSummaryTechnician();
    string foo;
    Technician *technician;
    do {
        do {
            cout << "Do you wish to view detailed information about a technician (Y/N)?: ";
            if (!validString(foo)) continue;
            else break;

        } while (true);

        normalize(foo);
        if (foo == "y") {
            cout << endl;
            do {
                try {
                    technician = chooseTechnician();
                }
                catch (const InvalidTechnician &i) {
                    i.print();
                    continue;
                }

                technician->print();
                break;

            } while (true);

        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;
}

void Company::techRemovefromQueue(Technician *tech) {

    techniciansPriorityQueue techs;

    while (!technicians.empty()) {
        if (technicians.top() == tech) {
            technicians.pop();
            continue;
        }
        techs.push(technicians.top());
        technicians.pop();
    }

    while (!techs.empty()) {
        technicians.push(techs.top());
        techs.pop();
    }
}

void Company::technicianDelete() {

    if (technicians.empty()) {
        cout << "There are no technicians.\n";
        return;
    }

    printSummaryTechnician();
    Technician *technician;
    do {
        try {
            technician = chooseTechnician();
        }
        catch (const InvalidTechnician &i) {
            i.print();
            continue;
        }
        break;

    } while (true);


    techRemovefromQueue(technician);
    cout << "Technician deleted sucessfully.\n ";
    techniciansChanged = true;

}

void Company::technicianUpdateName(Technician *technician) {

    string newName;
    cout << "The current name for the chosen technician is '" << technician->getName() << "'.\n";

    do {
        cout << "Insert new name: ";
        if (!validString(newName)) continue;
        else break;

    } while (true);
    technician->setName(newName);
    techniciansChanged = true;
    cout << "Technician name updated successfully.\n";
}

void Company::technicianAddModel(Technician *technician) {

    string newModel;

    do {
        cout << "Insert new model: ";
        if (!validString(newModel)) continue;
        else break;

    } while (true);

    vector<string> models = technician->getModels();
    models.push_back(newModel);
    technician->setModels(models);
    techniciansChanged = true;
    cout << "Technician new model added successfully.\n";

}

void Company::technicianDeleteModel(Technician *technician) {

    string model;

    do {
        cout << "Insert the model you wish to remove: ";
        if (!validString(model)) continue;
        else break;

    } while (true);

    vector<string> models = technician->getModels();
    bool found = false;
    for (unsigned int i = 0; i < models.size(); i++) {
        if (models.at(i) == model) {
            models.erase(models.begin() + i);
            found = true;
            techniciansChanged = true;
            cout << "Technician model removed successfully.\n";
            break;
        }
    }
    if (found) technician->setModels(models);
    else cout << "Technician model was not found.\n";
}

void Company::addObject(Technician *technician) {
    this->technicians.push(technician);
}

void Company::setFlag() {
    airplanesChanged = false;
    flightsChanged = false;
    passengersChanged = false;
    techniciansChanged = false;
}

unsigned int Company::getNextBookingId() {
    unsigned int id = 0;
    if (!bookings.empty()) {
        size_t idx = bookings.size() - 1;
        id = bookings.at(idx)->getId() + 1;
    }
    if (!pastBookings.empty()) {
        size_t idx = pastBookings.size() - 1;
        unsigned int newId = pastBookings.at(idx)->getId();
        if (newId >= id) id = newId + 1;
    }
    return id;
}

void Company::addBooking(Booking *booking) {
    bookings.push_back(booking);
}

void Company::addBookingsFromFlight(Flight *flight) {
    if (flight->getType() == "c") {
        auto pm = flight->getPassengers();
        if (!pm.empty()) {
            for (auto const &b: pm) this->addBooking(new Booking(getNextBookingId(), b.second, flight, b.first));

        }
    } else {
        if (flight->getBuyer() != nullptr)
            this->addBooking(new Booking(getNextBookingId(), flight->getBuyer(), flight, "ALL"));
    }
}

void Company::addInactivePassenger(Passenger *passenger) {
    inactivePassengers.insert(passenger);
}

void Company::removeInactivePassenger(Passenger *passenger) {
    auto it = inactivePassengers.find(passenger);
    if (it != inactivePassengers.end()) inactivePassengers.erase(it);
}

bool Company::pastFlight(Flight *f) {
    return ((f->getDate() + f->getDuration()) < Application::currentDate);
}

void Company::updateFlights() {
    vector<Flight *> activeFlights;
    for (auto const &f: flights) {
        if (pastFlight(f)) pastFlights.push_back(f);
        else activeFlights.push_back(f);
    }
    this->flights = activeFlights;
}

void Company::updateBookings() {
    vector<Booking *> activeBookings;
    for (auto const &b: bookings) {
        if (pastFlight(b->getFlight())) pastBookings.push_back(b);
        else activeBookings.push_back(b);
    }
    this->bookings = activeBookings;
}

void Company::updatePassengers() {
    vector<Passenger *> activeToInactive;
    vector<Passenger *> inactiveToActive;
    for (auto const &p: passengers) {
        if (inactivePassenger(p)) activeToInactive.push_back(p);
    }
    for (auto const &p: inactivePassengers) {
        if (!inactivePassenger(p)) inactiveToActive.push_back(p);
    }
    for (auto const &p: activeToInactive) {
        this->addInactivePassenger(p);
        passengers.erase(find(passengers.begin(), passengers.end(), p));
    }
    for (auto const &p: inactiveToActive) {
        passengers.push_back(p);
        this->removeInactivePassenger(p);
    }
}

void Company::updateTime() {
    updateFlights();
    updateBookings();
    updatePassengers();
    updateAirplanesDate();
    updateTechniciansDate();
}

Date Company::getLastReservation(Passenger *p) {
    Date d;
    for (auto const &b: bookings)
        if (b->getPassenger() == p && b->getFlight()->getDate() > d) d = b->getFlight()->getDate();

    for (auto const &b: pastBookings)
        if (b->getPassenger() == p && b->getFlight()->getDate() > d) d = b->getFlight()->getDate();

    return d;
}

bool Company::inactivePassenger(Passenger *p) {
    Date inactivePeriod;
    inactivePeriod.month = 6;
    return (getLastReservation(p) - Application::currentDate) > inactivePeriod;
}

vector<Passenger *> Company::getAllPassengers() {
    vector<Passenger *> pass;
    for (auto const &p: passengers) pass.push_back(p);
    for (auto const &p: inactivePassengers) pass.push_back(p);
    return pass;
}

void Company::removePassengerFromBookings(Passenger *passenger) {
    bookings.erase(remove_if(bookings.begin(), bookings.end(),
                             [passenger](Booking *b) { return b->getPassenger() == passenger; }), bookings.end());

}

vector<Passenger *> Company::getIncPassengers() {
    vector<Passenger *> pass;
    for (auto const &p: inactivePassengers) pass.push_back(p);
    if (!pass.empty())
        sort(pass.begin(), pass.end(), compPID);
    return pass;
}

void Company::updateAirplanesDate() {

    vector<Airplane *> airplanes;

    for (auto a : fleet) {
        airplanes.push_back(a);
    }

    for (auto a : airplanes) {

        Date date = a->getMaintenance();

        while (date < Application::currentDate) {
            date = date + a->getMaintenancePeriod();
        }

        Airplane *aux = a;
        removeAirplane(a);
        aux->setMaintenance(date);
        addObject(aux);
    }

}

void Company::updateTechniciansDate() {

    techniciansPriorityQueue temp = technicians;

    while (!technicians.empty()) { technicians.pop(); }

    while (!temp.empty()) {

        if (temp.top()->getTimeWhenAvailable() < Application::currentDate)
            temp.top()->setTimeWhenAvailable(Application::currentDate);

        technicians.push(temp.top());
        temp.pop();
    }
}
