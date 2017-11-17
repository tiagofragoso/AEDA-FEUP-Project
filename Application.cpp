#include <iomanip>
#include <vector>
#include "Application.h"



Application::Application() {

    Company c = Company("TAP");
    company = c;
    passengersFilepath = "../Files/Passengers.txt";
    airplanesFilepath = "../Files/Airplanes.txt";
    flightsFilepath = "../Files/Flights.txt";

}


void Application::mainMenu() {

    int op;
    char auxOp;
    do {
        cout << "[MAIN MENU]\n\n";
        cout << "[1]- File management.\n";
        cout << "[2]- Passenger management.\n";
        cout << "[3]- Airplane management.\n";
        cout << "[4]- Bookings.\n";
        cout << "[5]- Lists.\n";
        cout << "[0]- Quit.\n\n";

        do {
            cout << "Insert the desired option: ";
            if ((cin >> op) && op >= 0 && op <= 5) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);


        switch (op) {
            case 1:
                filesMenu();
                pause();
                break;
            case 2:
                passengersMenu();
                pause();
                break;
            case 3:
                airplanesMenu();
                pause();
                break;
            case 4:
                bookingsMenu();
                pause();
                break;
            case 5:
                listsMenu();
                pause();
                break;
            case 0:
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

    } while (op != 0);
}


void Application::listsMenu() {

    int op;
    char auxOp;
    do {
        cout << "[LISTS MENU]\n\n";
        cout << "Passenger lists.\n";
        cout << "[1]- Passengers by name.\n";
        cout << "[2]- Passengers by id.\n";
        cout << "[3]- Passengers by age.\n";
        cout << "Airplane lists.\n";
        cout << "[4]- Airplanes by id.\n";
        cout << "Flights lists.\n";
        cout << "[5]- Flights by id.\n";
        cout << "[6]- Flights by price (low to high).\n";
        cout << "[7]- Flights by price (high to low).\n";
        cout << "[8]- Flights by time to flight.\n";
        cout << "[9]- Flights by destination.\n";
        cout << "[10]- Exit.\n\n";

        do {
            cout << "Insert the desired option: ";
            if ((cin >> op) && op >= 0 && op <= 10) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);


        switch (op) {
            case 1:
                printListPassengers(company.getPassengers(), PNAME);
                pause();
                break;
            case 2:
                printListPassengers(company.getPassengers(), PID);
                pause();
                break;
            case 3:
                printListPassengers(company.getPassengers(), PAGE);
                pause();
                break;
            case 4:
                printListAirplane(company.getFleet(), AID);
                pause();
                break;
            case 5:
                pause();
                break;
        }

    } while (op != 0);
}

void Application::printListPassengers(vector<Passenger *> passengers, type t) {

    string title;
    switch(t) {

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
    cout << setw(12) << "Passenger ID" << setw(3) << " " << setw(30) << "Name" << setw(3) << " " << setw(13) << "Date of Birth\n";
    for (auto &passenger : passengers) {

        passenger->printSummary();
    }

}

void Application::printListAirplane(vector<Airplane *> airplanes, type t) {

    string title;
    switch(t) {

        case AID:
            sort(airplanes.begin(), airplanes.end(), compAId);
            title = "Airplane by id:\n";
            break;
    }

    cout << title;
    cout << std::left;
    cout << setw(11) << "Airplane ID\n";

    for (auto &airplane : airplanes) {

        airplane->printSummary();
    }
}


void Application::filesMenu() {
    int op;
    char auxOp;
    do {
        bool validOp = false;
        cout << "[FILE MANAGEMENT MENU]\n\n";

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

        do {
            cout << "Insert the desired option: ";
            if (cin >> op && ((op >= 0 && op <= 4) || op == 9)) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                validOp = true;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (!validOp);

        switch (op) {
            case 1:
                //passengersFilepath = inputFilePath("passenger");
                try {
                    loadPassengerFile();
                } catch (InvalidFilePath &in) {
                    in.print();
                }
                pause();
                break;
            case 2:
                //flightsFilepath = inputFilePath("flight");
                try {
                    loadFlightFile();
                } catch (InvalidFilePath &in) {
                    in.print();
                }
                break;
            case 3:
                //airplanesFilepath = inputFilePath("airplane");
                try {
                    loadAirplaneFile();
                } catch (InvalidFilePath &in) {
                    in.print();
                }
                pause();
                break;
            case 4:

                if (company.getPassengersChanged() || company.getAirplanesChanged() || company.getFlightsChanged()) {
                    do {
                        cout
                                << "Saving all changes will replace the data in the files with the current state of the application. Proceed (Y/N) ? ";
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
                } else cout << "There are no changes to be deployed.\n";
                break;
        }
    } while (op != 9);
}

void Application::passengersMenu() {

    int op;

    do {
        cout << "[PASSENGER MANAGEMENT MENU]\n\n";
        cout << "[1]- Show passenger info.\n";
        cout << "[2]- Create new passenger.\n";
        cout << "[3]- Delete passenger.\n";
        cout << "[4]- Update passenger.\n";
        //provavelmente mais cenas tipo varios tipos de listagens
        cout << "[9]- Back.\n\n";

        do {
            cout << "Insert the desired option: ";
            if ((cin >> op) && ((op >= 1 && op <= 4) || op == 9)) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                company.passengerShow();
                pause();
                break;
            case 2:
                company.passengerCreate();
                pause();
                break;
            case 3:
                company.passengerDelete();
                pause();
                break;
            case 4:
                passengerUpdateMenu();
                break;
        }

    } while (op != 9);
}

void Application::airplanesMenu() {

    int op;

    do {
        cout << "[AIRPLANES MANAGEMENT MENU]\n\n";
        cout << "[1]- Show airplane info.\n";
        cout << "[2]- Create new airplane.\n";
        cout << "[3]- Delete airplane.\n";
        cout << "[4]- Update airplane.\n";
        cout << "[5]- Flights management.\n";
        //provavelmente mais cenas tipo varios tipos de listagens
        cout << "[9]- Back.\n\n";

        do {
            cout << "Insert the desired option: ";
            if ((cin >> op) && ((op >= 1 && op <= 5) || op == 9)) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                company.airplaneShow();
                pause();
                break;
            case 2:
                company.airplaneCreate();
                pause();
                break;
            case 3:
                company.airplaneDelete();
                pause();
                break;
            case 4:
                airplaneUpdateMenu();
                pause();
                break;
            case 5:
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

                flightsMenu(airplane);
                break;
        }

    } while (op != 9);
}

void Application::flightsMenu(Airplane *airplane) {

    int op;

    do {
        cout << "[FLIGHT MANAGEMENT MENU]\n\n";
        cout << "[1]- Show flight info.\n";
        cout << "[2]- Create new flight.\n";
        cout << "[3]- Delete flight.\n";
        cout << "[4]- Update flight.\n";
        //provavelmente mais cenas tipo varios tipos de listagens
        cout << "[9]- Back.\n\n";

        do {
            cout << "Insert the desired option: ";
            if ((cin >> op) && ((op >= 1 && op <= 4) || op == 9)) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                company.flightShow(airplane);
                pause();
                break;
            case 2:
                company.flightCreate(airplane);
                pause();
                break;
            case 3:
                company.flightDelete(airplane);
                pause();
                break;
            case 4:
                flightUpdateMenu(airplane);
                break;
        }

    } while (op != 9);

}

void Application::bookingsMenu() {

    string menuhelper;
    int id, op;
	Passenger *passenger = new Passenger;
    cout << "[BOOKING MANAGEMENT MENU]\n\n";
    do {
        cout << "Is the customer new (Y/N)? ";
        getline(cin, menuhelper);
        if (menuhelper != "") normalize(menuhelper);
        if (menuhelper == "y") {
            cout << endl;
            passenger = company.newCustomer();
            break;
        } else if (menuhelper == "n") {
            company.printSummaryPassenger();
            try { passenger = company.choosePassenger(); } catch (InvalidPassenger &ip) { ip.print(); }
            break;
        } else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;
    do {
        cout << "[BOOKING MANAGEMENT MENU]\n\n";
        cout << "[1]- Show my scheduled Flights\n";
        cout << "[2]- Book a Flight\n";
        cout << "[3]- Return a Flight ticket\n";
        cout << "[9]- Back.\n\n";
        do {
            cout << "Insert the desired option: ";
            if ((cin >> op) && ((op >= 1 && op <= 3) || op == 9)) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                company.showAllTickets(company.getTickets(passenger));
                pause();
                break;
            case 2:
                company.bookFlight(passenger);
                pause();
                break;
            case 3:
                company.returnTicket(passenger);
                pause();
                break;
        }
    } while (op != 9);
}



void Application::passengerUpdateMenu() {

    if (company.getPassengers().size() == 0) {
        cout << "There are no passengers.\n";
        return;
    }

    company.printSummaryPassenger();
    int op;
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

        if (passenger->getType() == "c") {

            do {
                cout << "Insert the desired option: ";
                if (cin >> op && ((op >= 1 && op <= 4) || op == 9)) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    cerr << "Invalid option.\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (true);

        }

        if (passenger->getType() == "n") {

            do {
                cout << "Insert the desired option: ";
                if (cin >> op && ((op >= 1 && op <= 2) || op == 9)) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    cerr << "Invalid option.\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (true);

        }

        switch (op) {
            case 1:
                company.passengerUpdateName(passenger);
                break;
            case 2:
                company.passengerUpdateDateOfBirth(passenger);
                break;
            case 3:
                company.passengerUpdateJob(passenger);
                break;
            case 4:
                company.passengerUpdateNYear(passenger);
                break;
        }

    } while (op != 9);
}



void Application::airplaneUpdateMenu() {

    if (company.getFleet().size() == 0) {

        cout << "There are no airplanes.\n";
        return;

    }

    company.printSummaryAirplane();
    int op;
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
        cout << "Airplane selected: \n\n";
        airplane->print();
        cout << "[AIRPLANE UPDATE MENU]\n\n";
        cout << "[1]- Change airplane model.\n";
        cout << "[2]- Change airplane capacity.\n";
        cout << "[9]- Back.\n\n";

        do {
            cout << "Insert the desired option: ";
            if (cin >> op && ((op >= 1 && op <= 2) || op == 9)) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            } else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                company.airplaneUpdateModel(airplane);
                break;
            case 2:
                company.airplaneUpdateCapacity(airplane);
                break;

        }

    } while (op != 9);
}




void Application::flightUpdateMenu(Airplane *airplane) {

    if (airplane->getFlights().size() == 0) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

    company.printSummaryFlight(airplane);
    int op;
    string foo;
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
        cout << "Flight selected: \n\n";
        flight->print();
        foo = flight->getType();

        if (foo == "r") {

            cout << "[FLIGHT UPDATE MENU]\n\n";
            cout << "[1]- Change flight price.\n";
            cout << "[2]- Change flight buyer.\n";
            cout << "[9]- Back.\n\n";

            do {
                cout << "Insert the desired option: ";
                if (cin >> op && ((op >= 1 && op <= 2) || op == 9)) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    cerr << "Invalid option.\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (true);

            switch (op) {
                case 1:
                    company.flightUpdatePrice(flight);
                    break;
                case 2:
                    company.flightUpdateBuyer(flight);
                    break;
            }
        }

        if (foo == "c") {

            cout << "[FLIGHT UPDATE MENU]\n\n";
            cout << "[1]- Change flight price.\n";
            cout << "[2]- Delete passenger.\n";
            cout << "[9]- Back.\n\n";

            do {
                cout << "Insert the desired option: ";
                if (cin >> op && ((op >= 1 && op <= 3) || op == 9)) {
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                } else {
                    cerr << "Invalid option.\n";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (true);

            switch (op) {
                case 1:
                    company.flightUpdatePrice(flight);
                    break;
                case 2:
                    company.flightDeletePassenger(flight);
                    break;
            }
        }

    } while (op != 9);
}


Airplane *Application::readAirplane(string &a) {

    Airplane *newAirplane = new Airplane;

    int temp;
    string st;

    try { next(temp, a, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
    }

    newAirplane->setId(temp);

    next(st, a, ";");
    newAirplane->setModel(st);

    try { next(temp, a, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
    }

    newAirplane->setCapacity(temp);

    next(st, a, ";");

    if (st == "no_flights") return newAirplane;

    vector<unsigned int> f;
    while (st != "") {
        int fid;
        try { next(fid, st, ","); } catch (InvalidFormat) {
            cout << "Please insert the Airplane data in the correct format.\n";
        }
        f.push_back((unsigned int) fid);
    }

    vector<Flight *> flights;

    for (auto const &id:f) {
        Flight *fp = this->company.flightById(id);
        if (fp != nullptr) flights.push_back(fp);
    }

    newAirplane->setFlights(flights);

    return newAirplane;

}


Flight *Application::readFlight(string &f) {

    char type = f.at(0);
    Flight *newFlight;

    if (type == 'c') {

        //Comercial Flight

        newFlight = new ComercialFlight;

    } else if (type == 'r') {
        //Rented Flight
        newFlight = new RentedFlight;

    } else throw InvalidFlight(0);

    f = f.substr(1);

    int temp;
    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Flight data in the correct format.\n";
    }

    newFlight->setId((unsigned int) temp);

    string st;

    next(st, f, ";");

    newFlight->setDeparture(st);

    next(st, f, ";");

    newFlight->setDestination(st);

    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Flight data in the correct format.\n";
    }

    newFlight->setTime_to_flight((unsigned int) temp);

    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Flight data in the correct format.\n";
    }

    newFlight->setBasePrice((unsigned int) temp);

    try { next(temp, f, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Flight data in the correct format.\n";
    }

    newFlight->setDuration((unsigned int) temp);

    if (type == 'r') {

        try { next(temp, f, ";"); } catch (InvalidFormat) {
            cout << "Please insert the Flight data in the correct format.\n";
        }

        Passenger *p = this->company.passengerById((unsigned int) temp);

        if (p != nullptr) newFlight->setBuyer(p);

    } else {

        next(st, f, ";");

        if (st == "no_passengers") return newFlight;

        PassengerMap pmap;
        while (st != "") {
            string st1;
            next(st1, st, ",");
            string seat;
            next(seat, st1, "-");
            int elem;
            try { next(elem, st1, "-"); } catch (InvalidFormat) {
                cout << "Please insert the Flight data in the correct format.\n";
            }
            Passenger *p = this->company.passengerById((unsigned int) elem);


            pmap.emplace(seat, p);
        }

        newFlight->setPassengers(pmap);

    }

    return newFlight;

}

Passenger *Application::readPassenger(string &p) {
    Passenger *newPassenger;

    char type = p.at(0);

    if (type == 'c') newPassenger = new PassengerWithCard;
    else if (type == 'n') newPassenger = new Passenger;
    else throw InvalidPassenger(0);


    p = p.substr(1);

    int temp;
    try { next(temp, p, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Passenger data in the correct format.\n";
    }

    newPassenger->setId((unsigned int) temp);

    string st;

    next(st, p, ";");

    newPassenger->setName(st);

    next(st, p, ";");

    /*try {
        Date d(st);
    } catch (InvalidFormat) {
        cout << "Please insert the correct Date format.\n";
    }*/

    newPassenger->setDateOfBirth(st);


    if (type == 'c') {
        next(st, p, ";");

        try { next(temp, p, ";"); } catch (InvalidFormat) {
            cout << temp << endl;
            cout << "Please insert the Passenger data in the correct format.\n";
        }

        Card *c = new Card(st, temp);
        newPassenger->setCard(c);

    }

    return newPassenger;
}

void Application::loadPassengerFile() {

    string p;

    if (passengersFilepath == "") throw InvalidFilePath("empty");

    ifstream passFile(passengersFilepath);
    if (!passFile) throw InvalidFilePath("fail");
    while (getline(passFile, p)) {
        this->company.addPassenger(readPassenger(p));
    }
    passFile.close();

}

string Application::inputFilePath(string s) {
    string input;
    cout << "Insert " << s << "'s filename: ";
    getline(cin, input);
    return input;
}

void Application::loadFlightFile() {

    string f;

    if (flightsFilepath == "") throw InvalidFilePath("empty");

    ifstream flFile(flightsFilepath);
    if (!flFile) throw InvalidFilePath("fail");
    while (getline(flFile, f)) {
        this->company.addFlight(readFlight(f));
    }
    flFile.close();

}

void Application::loadAirplaneFile() {

    string a;

    if (airplanesFilepath == "") throw InvalidFilePath("empty");

    ifstream airFile(airplanesFilepath);
    if (!airFile) throw InvalidFilePath("fail");
    while (getline(airFile, a)) {
        this->company.addAirplane(readAirplane(a));
    }
    airFile.close();

}

void Application::saveAllFiles() {
    if (company.getAirplanesChanged()) {

        if (airplanesFilepath.empty()) airplanesFilepath = inputFilePath("airplane");

        try { saveAirplaneFile(); } catch (InvalidFilePath &in) { in.print(); }

    }

    if (company.getFlightsChanged()) {

        if (flightsFilepath.empty()) flightsFilepath = inputFilePath("flight");

        try { saveFlightFile(); } catch (InvalidFilePath &in) { in.print(); }

    }

    if (company.getPassengersChanged()) {

        if (passengersFilepath.empty()) passengersFilepath = inputFilePath("passenger");

        try { savePassengerFile(); } catch (InvalidFilePath &in) { in.print(); }

    }

    cout << "All changes were saved.\n";


}

void Application::saveAirplaneFile() {

    ofstream airFile(airplanesFilepath);

    if (!airFile) throw InvalidFilePath("fail");
    for (size_t i = 0; i < this->company.getFleet().size(); i++) {
        airFile << this->company.getFleet().at(i);
        if (i != this->company.getFleet().size() - 1) airFile << endl;
    }

    airFile.close();

}

void Application::saveFlightFile() {

    ofstream fFile(flightsFilepath);

    if (!fFile) throw InvalidFilePath("fail");
    for (size_t i = 0; i < this->company.getFlights().size(); i++) {
        fFile << this->company.getFlights().at(i);
        if (i != this->company.getFlights().size() - 1) fFile << endl;
    }

    fFile.close();

}

void Application::savePassengerFile() {

    ofstream passFile(passengersFilepath);

    if (!passFile) throw InvalidFilePath("fail");
    for (size_t i = 0; i < this->company.getPassengers().size(); i++) {
        passFile << this->company.getPassengers().at(i);
        if (i != this->company.getPassengers().size() - 1) passFile << endl;
    }

    passFile.close();

}


