#include <iomanip>
#include <vector>
#include "Application.h"

static const string AIRPLANE_IDENTIFIER = "airplane";
static const string FLIGHT_IDENTIFIER = "flight";
static const string PASSENGER_IDENTIFIER = "passenger";


Application::Application() {

    Company c = Company("TAP");
    company = c;
    passengersFilepath = "../Files/Passengers.txt";
    airplanesFilepath = "../Files/Airplanes.txt";
    flightsFilepath = "../Files/Flights.txt";

}

void Application::setupMenus() {

    //main menu
    menuMain["1"] = &Application::filesMenu;
    menuMain["2"] = &Application::passengersMenu;
    menuMain["3"] = &Application::airplanesMenu;
    menuMain["4"] = &Application::bookingsMenu;
    menuMain["5"] = &Application::listsMenu;
    menuMain["0"] = &Application::exitMenu;

    //files menu
    menuFiles["1"] = &Application::loadPassengerFile;
    menuFiles["2"] = &Application::loadFlightFile;
    menuFiles["3"] = &Application::loadAirplaneFile;
    menuFiles["4"] = &Application::saveChanges;

    //passengers Menu
    menuPassengers["1"] = &Company::passengerShow;
    menuPassengers["2"] = &Company::passengerCreateWrapper;
    menuPassengers["3"] = &Company::passengerDelete;

    //airplanes menu
    menuAirplanes["1"] = &Company::airplaneShow;
    menuAirplanes["2"] = &Company::airplaneCreate;
    menuAirplanes["3"] = &Company::airplaneDelete;

    //lists menu
    menuLists["1"] = &Application::printListPassengers;
    menuLists["2"] = &Application::printListPassengers;
    menuLists["3"] = &Application::printListPassengers;
    menuLists["4"] = &Application::printListAirplane;
    menuLists["5"] = &Application::printListFlights;
    menuLists["6"] = &Application::printListFlights;
    menuLists["7"] = &Application::printListFlights;
    menuLists["8"] = &Application::printListFlights;
    menuLists["9"] = &Application::printListFlights;

    //flights menu
    menuFlights["1"] = &Company::flightShow;
    menuFlights["2"] = &Company::flightCreate;
    menuFlights["3"] = &Company::flightDelete;

    //bookings menu
    menuBookings["1"] = &Company::showAllTickets;
    menuBookings["2"] = &Company::bookFlight;
    menuBookings["3"] = &Company::returnTicket;

    //airplanes update menu
    menuAirplaneUpdate["1"] = &Company::airplaneUpdateModel;
    menuAirplaneUpdate["2"] = &Company::airplaneUpdateCapacity;

    //flights update menu
    menuFlightsUpdate["1c"] = &Company::flightUpdatePrice;
    menuFlightsUpdate["1r"] = &Company::flightUpdatePrice;
    menuFlightsUpdate["2r"] = &Company::flightUpdateBuyer;
    menuFlightsUpdate["2c"] = &Company::flightDeletePassenger;

    //passengers update menu
    menuPassengersUpdate["1n"] = &Company::passengerUpdateName;
    menuPassengersUpdate["1c"] = &Company::passengerUpdateName;
    menuPassengersUpdate["2n"] = &Company::passengerUpdateDateOfBirth;
    menuPassengersUpdate["2c"] = &Company::passengerUpdateDateOfBirth;
    menuPassengersUpdate["3c"] = &Company::passengerUpdateJob;
    menuPassengersUpdate["4c"] = &Company::passengerUpdateNYear;

}

void Application::printMainMenu() {

    cout << "\n[MAIN MENU]\n\n";
    cout << "[1]- File management.\n";
    cout << "[2]- Passenger management.\n";
    cout << "[3]- Airplane management.\n";
    cout << "[4]- Bookings.\n";
    cout << "[5]- Lists.\n";
    cout << "[0]- Quit.\n\n";

}

void Application::printFilesMenu() {

    cout << "\n[FILE MANAGEMENT MENU]\n\n";

    cout << "NOTE:\n*Please load the files in the following order: Passengers-Flights-Airplanes.\n";
    cout
            << "*Loading multiple files for the same category will try to merge data, which may cause data overlapping.\n\n";

    cout << "[1]- Load passengers file ";
    if (passengersFilepath.empty()) {
        cout << "(No file loaded).";
    } else {
        cout << "('" << passengersFilepath << "' loaded).";
    }
    cout << endl;
    cout << "[2]- Load flight file ";
    if (flightsFilepath.empty()) {
        cout << "(No file loaded).";
    } else {
        cout << "('" << flightsFilepath << "' loaded).";
    }
    cout << endl;
    cout << "[3]- Load airplane file ";
    if (airplanesFilepath.empty()) {
        cout << "(No file loaded).";
    } else {
        cout << "('" << airplanesFilepath << "' loaded).";
    }
    cout << endl;
    cout << "[4]- Save all changes to files.\n";
    cout << "[9]- Back.\n\n";

}

void Application::printPassengersMenu() {

    cout << "\n[PASSENGER MANAGEMENT MENU]\n\n";
    cout << "[1]- Show passenger info.\n";
    cout << "[2]- Create new passenger.\n";
    cout << "[3]- Delete passenger.\n";
    cout << "[4]- Update passenger.\n";
    cout << "[9]- Back.\n\n";

}


void Application::printAirplanesMenu() {

    cout << "\n[AIRPLANES MANAGEMENT MENU]\n\n";
    cout << "[1]- Show airplane info.\n";
    cout << "[2]- Create new airplane.\n";
    cout << "[3]- Delete airplane.\n";
    cout << "[4]- Update airplane.\n";
    cout << "[5]- Flights management.\n";
    cout << "[9]- Back.\n\n";
}

void Application::printListsMenu() {

    cout << "[LISTS MENU]\n\n";
    cout << "Passenger lists.\n\n";
    cout << "[1]- Passengers by id.\n";
    cout << "[2]- Passengers by name.\n";
    cout << "[3]- Passengers by age.\n\n";
    cout << "Airplane lists.\n\n";
    cout << "[4]- Airplanes by id.\n\n";
    cout << "Flights lists.\n\n";
    cout << "[5]- Flights by id.\n";
    cout << "[6]- Flights by price (low to high).\n";
    cout << "[7]- Flights by price (high to low).\n";
    cout << "[8]- Flights by destination.\n";
    cout << "[9]- Flights by time to flight.\n";
    cout << "[0]- Back.\n\n";
}

void Application::printFlightsMenu() {

    cout << "[FLIGHT MANAGEMENT MENU]\n\n";
    cout << "[1]- Show flight info.\n";
    cout << "[2]- Create new flight.\n";
    cout << "[3]- Delete flight.\n";
    cout << "[4]- Update flight.\n";
    cout << "[9]- Back.\n\n";
}

void Application::printBookingsMenu() {

    cout << "[BOOKING MANAGEMENT MENU]\n\n";
    cout << "[1]- Show my scheduled Flights\n";
    cout << "[2]- Book a Flight\n";
    cout << "[3]- Return a Flight ticket\n";
    cout << "[9]- Back.\n\n";
}

void Application::printAirplaneUpdateMenu(Airplane *airplane) {

    cout << "Airplane selected: \n\n";
    airplane->print();
    cout << "[AIRPLANE UPDATE MENU]\n\n";
    cout << "[1]- Change airplane model.\n";
    cout << "[2]- Change airplane capacity.\n";
    cout << "[9]- Back.\n\n";

}

void Application::printFlightUpdateMenu(Flight *flight) {

    string foo;
    cout << "Flight selected: \n\n";
    flight->print();
    foo = flight->getType();

    if (foo == "r") {

        cout << "[FLIGHT UPDATE MENU]\n\n";
        cout << "[1]- Change flight price.\n";
        cout << "[2]- Change flight buyer.\n";
        cout << "[9]- Back.\n\n";

    }

    if (foo == "c") {

        cout << "[FLIGHT UPDATE MENU]\n\n";
        cout << "[1]- Change flight price.\n";
        cout << "[2]- Delete passenger.\n";
        cout << "[9]- Back.\n\n";
    }
}

void Application::printPassengerUpdateMenu(Passenger *passenger) {

    cout << "Passenger selected: \n\n";
    passenger->print();
    cout << "[PASSENGER UPDATE MENU]\n\n";
    cout << "[1]- Change passenger name.\n";
    cout << "[2]- Change passenger date of birth.\n";

    if (passenger->getType() == "c") {


        cout << "[3]- Change passenger job.\n";
        cout << "[4]- Change passenger number of flights/year.\n";

    }
    cout << "[9]- Back.\n\n";
}

void Application::exitMenu() {

    saveChanges();
    exit(0);

}

void Application::mainMenu() {

    string op;

    setupMenus();

    do {

        printMainMenu();

        do {

            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op == "" || menuMain.find(op) == menuMain.end()) {
                cout << "Invalid option.\n";
            } else break;
        } while (true);

        (this->*menuMain[op])();

    } while (true);


}


void Application::filesMenu() {

    string op;

    do {

        printFilesMenu();

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuFiles.find(op) == menuFiles.end()) {
                if (op == "9") return;
                cout << "Invalid option.\n";
            } else break;

        } while (true);

        try {
            (this->*menuFiles[op])();
        }
        catch (InvalidFilePath &i) {
            i.print();
            continue;
        }

        pause();

    } while (true);

}

void Application::saveChanges() {

    char auxOp;
    if (company.getPassengersChanged() || company.getAirplanesChanged() || company.getFlightsChanged()) {
        cout << "There are changes to be deployed to the files.\n";
        do {
            cout << "Would you like to save those changes (Y/N) ? ";
            if (cin >> auxOp && (auxOp == 'Y' || auxOp == 'N' || auxOp == 'y' || auxOp == 'n')) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (auxOp == 'Y') {
                    saveAllFiles();
                    pause();
                    break;
                } else {
                    break;
                }
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);
    }
}

void Application::passengersMenu() {

    string op;

    do {

        printPassengersMenu();

        do {

            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuPassengers.find(op) == menuPassengers.end()) {

                if (op == "9") return;
                if (op == "4") break;
                cout << "Invalid option.\n";
            } else break;


        } while (true);

        if (op == "4") {
            passengerUpdateMenu();
            continue;
        }

        (company.*menuPassengers[op])();
        pause();

    } while (true);
}

void Application::airplanesMenu() {

    string op;

    do {

        printAirplanesMenu();

        do {

            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuAirplanes.find(op) == menuAirplanes.end()) {

                if (op == "9") return;
                if (op == "4" || op == "5") break;
                cout << "Invalid option.\n";
            } else break;


        } while (true);

        if (op == "4") {
            airplaneUpdateMenu();
            continue;
        }

        if (op == "5") {
            flightsMenu();
            continue;
        }

        (company.*menuAirplanes[op])();
        pause();

    } while (true);

}


void Application::listsMenu() {

    string op;

    do {

        printListsMenu();

        do {

            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuLists.find(op) == menuLists.end()) {

                if (op == "0") return;
                cout << "Invalid option.\n";
            } else break;

        } while (true);

        (this->*menuLists[op])(static_cast<type>(stoi(op)));
        pause();

    } while (true);

}

void Application::printListPassengers(type t) {

    if (company.getPassengers().empty()) {

        cout << "There are no passengers.\n";
        return;

    }

    vector<Passenger *> passengers = company.getPassengers();
    string title;
    switch (t) {

        case PID:
            sort(passengers.begin(), passengers.end(), compPID);
            title = "Passengers by id:\n";
            break;
        case PNAME:
            sort(passengers.begin(), passengers.end(), compPNAME);
            title = "Passengers by name:\n";
            break;
        case PAGE:
            sort(passengers.begin(), passengers.end(), compPAGE);
            title = "Passengers by age:\n";
            break;
    }

    cout << title;
    cout << std::left;
    cout << setw(12) << "Passenger ID" << setw(3) << " " << setw(30) << "Name" << setw(3) << " " << setw(13)
         << "Date of Birth" << endl;
    for (auto &passenger : passengers) {
        passenger->printSummary();
    }

}

void Application::printListAirplane(type t) {

    if (company.getFleet().empty()) {

        cout << "There are no airplanes.\n";
        return;

    }

    vector<Airplane *> airplanes = company.getFleet();
    string title;

    sort(airplanes.begin(), airplanes.end(), compAId);
    title = "Airplane by id:\n";

    cout << title;
    cout << std::left;
    cout << setw(11) << "Airplane ID\n";

    for (auto &airplane : airplanes) {

        airplane->printSummary();
    }
}

void Application::printListFlights(type t) {

    if (company.getFlights().empty()) {

        cout << "There are no flights.\n";
        return;

    }

    vector<Flight *> flights = company.getFlights();
    string title;
    switch (t) {

        case FID:
            sort(flights.begin(), flights.end(), compFId);
            title = "Flight by id:\n";
            break;
        case FPRICEL:
            sort(flights.begin(), flights.end(), compFPriceL);
            title = "Flight by price (low to high):\n";
            break;
        case FPRICEH:
            sort(flights.begin(), flights.end(), compFPriceH);
            title = "Flight by price (high to low):\n";
            break;
        case FDEST:
            sort(flights.begin(), flights.end(), compFDest);
            title = "Flight by destination:\n";
            break;
        case FTIME:
            sort(flights.begin(), flights.end(), compFTime);
            title = "Flight by price:\n";
            break;

    }

    cout << title;
    cout << std::left;
    cout << setw(12) << "Passenger ID" << setw(3) << " " << setw(30) << "Name" << setw(3) << " " << setw(13)
         << "Date of Birth\n";

    for (auto &flight : flights) {

        flight->printSummary();
    }

}

void Application::flightsMenu() {

    string op;
    Airplane *airplane;
    company.printSummaryAirplane();

    do {
        try {
            airplane = company.chooseAirplane();
        }
        catch (const InvalidAirplane &i) {
            i.print();
            continue;
        }

        airplane->print();
        cout << endl;
        break;
    } while (true);

    do {

        printFlightsMenu();

        do {

            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuFlights.find(op) == menuFlights.end()) {

                if (op == "9") return;
                if (op == "4") break;
                cout << "Invalid option.\n";
            } else break;


        } while (true);

        if (op == "4") {
            flightUpdateMenu(airplane);
            continue;
        }

        (company.*menuFlights[op])(airplane);
        pause();

    } while (true);
}

void Application::bookingsMenu() {

    string menuhelper;
    Passenger *passenger;

    cout << "[BOOKING MANAGEMENT MENU]\n\n";
    do {
        cout << "Do you wish to book a flight for an existing customer(Y/N)? ";
        getline(cin, menuhelper);
        if (!menuhelper.empty()) normalize(menuhelper);
        if (menuhelper == "n") {
            cout << endl;
            passenger = company.passengerCreate();
            break;
        } else if (menuhelper == "y") {
            company.printSummaryPassenger();
            try { passenger = company.choosePassenger(); } catch (InvalidPassenger &ip) { ip.print(); }
            break;
        } else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

    string op;

    do {

        printBookingsMenu();

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuBookings.find(op) == menuBookings.end()) {
                if (op == "9") return;
                cout << "Invalid option.\n";
            } else break;

        } while (true);

        (company.*menuBookings[op])(passenger);
        pause();

    } while (true);
}


void Application::passengerUpdateMenu() {

    if (company.getPassengers().empty()) {
        cout << "There are no passengers.\n";
        return;
    }

    company.printSummaryPassenger();
    string op, op1;
    Passenger *passenger;
    do {
        try {
            passenger = company.choosePassenger();
        }
        catch (const InvalidPassenger &i) {
            i.print();
            continue;
        }
        break;

    } while (true);

    do {

        printPassengerUpdateMenu(passenger);

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            op1 = op + passenger->getType();
            if (op.empty() || menuPassengersUpdate.find(op1) == menuPassengersUpdate.end()) {
                if (op == "9") return;
                cout << "Invalid option.\n";
            } else break;

        } while (true);

        (company.*menuPassengersUpdate[op1])(passenger);
        pause();

    } while (true);
}


void Application::airplaneUpdateMenu() {

    if (company.getFleet().empty()) {

        cout << "There are no airplanes.\n";
        return;

    }

    company.printSummaryAirplane();
    string op;
    Airplane *airplane;
    do {
        try {
            airplane = company.chooseAirplane();
        }
        catch (const InvalidAirplane &i) {
            i.print();
            continue;
        }

        break;

    } while (true);

    do {

        printAirplaneUpdateMenu(airplane);

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuAirplaneUpdate.find(op) == menuAirplaneUpdate.end()) {
                if (op == "9") return;
                cout << "Invalid option.\n";
            } else break;

        } while (true);

        (company.*menuAirplaneUpdate[op])(airplane);
        pause();

    } while (true);
}


void Application::flightUpdateMenu(Airplane *airplane) {

    if (airplane->getFlights().empty()) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

    company.printSummaryFlight(airplane);
    string op, op1;
    Flight *flight;
    do {
        try {
            flight = company.chooseFlight(airplane);
        }
        catch (const InvalidFlight &i) {
            i.print();
            continue;
        }

        break;

    } while (true);

    do {

        printFlightUpdateMenu(flight);

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            op1 = op + flight->getType();
            if (op.empty() || menuFlightsUpdate.find(op1) == menuFlightsUpdate.end()) {
                if (op == "9") return;
                cout << "Invalid option.\n";
            } else break;

        } while (true);

        (company.*menuFlightsUpdate[op1])(flight);
        pause();

    } while (true);


}


Airplane *Application::readAirplane(string &a) {

    Airplane *newAirplane = new Airplane;

    int temp;
    string st;

    try { next(temp, a, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
        return nullptr;
    }

    newAirplane->setId(temp);

    next(st, a, ";");
    newAirplane->setModel(st);

    try { next(temp, a, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
        return nullptr;
    }

    newAirplane->setCapacity(temp);

    next(st, a, ";");

    if (st == "no_flights") return newAirplane;

    vector<unsigned int> f;

    while (st != "") {
        int fid;
        try { next(fid, st, ","); } catch (InvalidFormat) {
            cout << "Please insert the Airplane data in the correct format.\n";
            return nullptr;
        }
        f.push_back((unsigned int) fid);
    }

    vector<Flight *> flights;

    for (auto const &id:f) {
        Flight *fp;

        try {
            fp = this->company.flightById(id);
        } catch (InvalidFlight &i) {
            cout << "Invalid flight.\n";
            return nullptr;
        }

        fp->setCapacity(newAirplane->getCapacity());
        flights.push_back(fp);

    }

    newAirplane->setFlights(flights);

    return newAirplane;

}


Flight *Application::readFlight(string &f) {

    char type = f.at(0);
    Flight *newFlight;

    if (type == 'c') {

        //Comercial Flight

        newFlight = new CommercialFlight;

    } else if (type == 'r') {
        //Rented Flight
        newFlight = new RentedFlight;

    }

    f = f.substr(1);

    int temp;
    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Flight data in the correct format.\n";
        return nullptr;
    }

    newFlight->setId((unsigned int) temp);

    string st;

    next(st, f, ";");

    newFlight->setDeparture(st);

    next(st, f, ";");

    newFlight->setDestination(st);

    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Flight " << to_string(newFlight->getId())
             << ": Please insert the Flight data in the correct format.\n";
        return nullptr;
    }

    newFlight->setTime_to_flight((unsigned int) temp);

    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Flight " << to_string(newFlight->getId())
             << ": Please insert the Flight data in the correct format.\n";
        return nullptr;
    }

    newFlight->setBasePrice((unsigned int) temp);

    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Flight " << to_string(newFlight->getId())
             << ": Please insert the Flight data in the correct format.\n";
        return nullptr;
    }

    newFlight->setDuration((unsigned int) temp);

    next(st, f, ";");

    if (st == "no_passengers") return newFlight;

    if (type == 'r') {

        try { next(temp, f, ";"); } catch (InvalidFormat) {
            cout << "Flight " << to_string(newFlight->getId())
                 << ": Please insert the Flight data in the correct format.\n";
            return nullptr;
        }

        Passenger *p;

        try {
            p = this->company.passengerById((unsigned int) temp);
        } catch (InvalidPassenger &i) {
            cout << "Flight " << to_string(newFlight->getId()) << ": Invalid buyer id.\n";
            return nullptr;
        }
        newFlight->setBuyer(p);
        return newFlight;
    }

    PassengerMap pmap;

    while (st != "") {
        string st1;
        next(st1, st, ",");
        string seat;
        next(seat, st1, "-");
        int elem;
        try { next(elem, st1, "-"); } catch (InvalidFormat) {
            cout << "Flight " << to_string(newFlight->getId()) << ": Invalid passenger id.\n";
            return nullptr;
        }

        Passenger *p;

        try {
            p = this->company.passengerById((unsigned int) elem);
        } catch (InvalidPassenger &i) {
            cout << "Flight " << to_string(newFlight->getId()) << ": Invalid passenger id.\n";
            return nullptr;
        }


        pmap.emplace(seat, p);
    }

    newFlight->setPassengers(pmap);

return newFlight;
}

Passenger *Application::readPassenger(string &p) {
    Passenger *newPassenger;

    char type = p.at(0);

    if (type == 'c') newPassenger = new PassengerWithCard;
    else if (type == 'n') newPassenger = new Passenger;
    else return nullptr;


    p = p.substr(1);

    int temp;
    try { next(temp, p, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Passenger data in the correct format.\n";
        return nullptr;
    }

    newPassenger->setId((unsigned int) temp);

    string st;

    next(st, p, ";");

    newPassenger->setName(st);

    next(st, p, ";");

    newPassenger->setDateOfBirth(st);


    if (type == 'c') {
        next(st, p, ";");

        try { next(temp, p, ";"); } catch (InvalidFormat) {
            cout << "Please insert the Passenger data in the correct format.\n";
            return nullptr;
        }

        Card *c = new Card(st, temp);
        newPassenger->setCard(c);

    }

    return newPassenger;
}

string Application::inputFilePath(string s) {
    string input;
    cout << "Insert " << s << "'s filename: ";
    getline(cin, input);
    return input;
}

void Application::loadPassengerFile() {

    //passengersFilepath = inputFilePath(PASSENGER_IDENTIFIER);

    string p;

    if (passengersFilepath == "") throw InvalidFilePath("empty");

    ifstream passFile(passengersFilepath);
    if (!passFile) {
        passengersFilepath.clear();
        throw InvalidFilePath("fail");
    }
    while (getline(passFile, p)) {
        if (p.empty()) continue;
        Passenger *passenger = readPassenger(p);
        if (passenger != nullptr) this->company.addPassenger(passenger);
    }
    passFile.close();
    this->company.sortPassengers();

    cout << "File successfully loaded.\n";

}


void Application::loadFlightFile() {

    string f;

    //flightsFilepath = inputFilePath(FLIGHT_IDENTIFIER);

    if (flightsFilepath == "") throw InvalidFilePath("empty");

    ifstream flFile(flightsFilepath);
    if (!flFile) {
        flightsFilepath.clear();
        throw InvalidFilePath("fail");
    }
    while (getline(flFile, f)) {
        if (f.empty()) continue;
        Flight *flight = readFlight(f);
        if (flight != nullptr) this->company.addFlight(flight);
    }

    flFile.close();
    this->company.sortFlights();

    cout << "File successfully loaded.\n";

}

void Application::loadAirplaneFile() {

    //airplanesFilepath = inputFilePath(AIRPLANE_IDENTIFIER);

    string a;

    if (airplanesFilepath == "") throw InvalidFilePath("empty");

    ifstream airFile(airplanesFilepath);
    if (!airFile) {
        airplanesFilepath.clear();
        throw InvalidFilePath("fail");
    }
    while (getline(airFile, a)) {
        if (a.empty()) continue;
        Airplane *airplane = readAirplane(a);
        if (airplane != nullptr) this->company.addAirplane(airplane);
    }
    airFile.close();
    this->company.sortAirplanes();

    cout << "File successfully loaded.\n";

}

void Application::saveAllFiles() {
    if (company.getAirplanesChanged()) {

        if (airplanesFilepath.empty()) airplanesFilepath = inputFilePath("airplane");

        try { saveFile(airplanesFilepath, this->company.getFleet()); } catch (InvalidFilePath &in) { in.print(); }

    }

    if (company.getFlightsChanged()) {

        if (flightsFilepath.empty()) flightsFilepath = inputFilePath("flight");

        try { saveFile(flightsFilepath, this->company.getFlights()); } catch (InvalidFilePath &in) { in.print(); }

    }

    if (company.getPassengersChanged()) {

        if (passengersFilepath.empty()) passengersFilepath = inputFilePath("passenger");

        try { saveFile(passengersFilepath, this->company.getPassengers()); } catch (InvalidFilePath &in) { in.print(); }

    }

    cout << "All changes were saved.\n";

}



