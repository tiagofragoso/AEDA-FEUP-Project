#include <iomanip>
#include <vector>
#include "Application.h"

Date Application::currentDate;

Application::Application() {

    Company c = Company("AirRoad");
    company = c;
    passengersFilepath = "";
    airplanesFilepath = "";
    flightsFilepath = "";
    techniciansFilepath = "";

}

void Application::setupMenus() {

    //main menu
    menuMain["1"] = &Application::filesMenu;
    menuMain["2"] = &Application::passengersMenu;
    menuMain["3"] = &Application::airplanesMenu;
    menuMain["4"] = &Application::techniciansMenu;
    menuMain["5"] = &Application::bookingsMenu;
    menuMain["6"] = &Application::maintenanceMenu;
    menuMain["7"] = &Application::listsMenu;
    menuMain["0"] = &Application::exitMenu;

    //files menu
    menuFiles["1"] = &Application::loadPassengerFile;
    menuFiles["2"] = &Application::loadFlightFile;
    menuFiles["3"] = &Application::loadAirplaneFile;
    menuFiles["4"] = &Application::loadTechnicianFile;
    menuFiles["5"] = &Application::saveChanges;

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
    menuFlights["4"] = &Company::flightUpdatePrice;

    //bookings menu
    menuBookings["1"] = &Company::showAllTicketsWrapper;
    menuBookings["2"] = &Company::bookFlight;
    menuBookings["3"] = &Company::returnTicket;

    //airplanes update menu
    menuAirplaneUpdate["1"] = &Company::airplaneUpdateModel;
    menuAirplaneUpdate["2"] = &Company::airplaneUpdateCapacity;
    menuAirplaneUpdate["3"] = &Company::airplaneUpdateMaintenancePeriod;

    //passengers update menu
    menuPassengersUpdate["1n"] = &Company::passengerUpdateName;
    menuPassengersUpdate["1c"] = &Company::passengerUpdateName;
    menuPassengersUpdate["2n"] = &Company::passengerUpdateDateOfBirth;
    menuPassengersUpdate["2c"] = &Company::passengerUpdateDateOfBirth;
    menuPassengersUpdate["3c"] = &Company::passengerUpdateJob;
    menuPassengersUpdate["4c"] = &Company::passengerUpdateNYear;

    //maintenance menu
    menuMaintenance["1"] = &Company::airplaneMaintenanceReschedule;
    menuMaintenance["2"] = &Company::airplanePerformMaintenance;
    menuMaintenance["3"] = &Company::printNextMaintenanceSessions;
    menuMaintenance["4"] = &Company::printMaintenancePeriod;

    //technicians menu
    menuTechnicians["1"] = &Company::technicianShow;
    menuTechnicians["2"] = &Company::technicianCreate;
    menuTechnicians["3"] = &Company::technicianDelete;

    //technicians update menu
    menuTechnicianUpdate["1"] = &Company::technicianUpdateName;
    menuTechnicianUpdate["2"] = &Company::technicianAddModel;
    menuTechnicianUpdate["3"] = &Company::technicianDeleteModel;
}

void Application::printMainMenu() const {

    cout << "\n[MAIN MENU]\n\n";
    cout << "[1]- File management.\n";
    cout << "[2]- Passenger management.\n";
    cout << "[3]- Airplane management.\n";
    cout << "[4]- Technician management.\n";
    cout << "[5]- Bookings.\n";
    cout << "[6]- Maintenance.\n";
    cout << "[7]- Lists.\n";
    cout << "[0]- Quit.\n\n";

}

void Application::printFilesMenu() const {

    cout << "\n[FILE MANAGEMENT MENU]\n\n";

    cout << "NOTE:\n*Please load the files in the following order: Passengers-Flights-Airplanes.\n";
    cout << "*Loading multiple files for the same category will erase previous data.\n";
    cout << "*If you must reload a file, please reload all other files in the previously stated load order.\n\n";

    cout << "[1]- Load passenger file ";
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
    cout << "[4]- Load technician file ";
    if (techniciansFilepath.empty()) {
        cout << "(No file loaded).";
    } else {
        cout << "('" << techniciansFilepath << "' loaded).";
    }
    cout << endl;
    cout << "[5]- Save all changes to files.\n";
    cout << "[9]- Back.\n\n";

}

void Application::printPassengersMenu() const {

    cout << "\n[PASSENGER MANAGEMENT MENU]\n\n";
    cout << "[1]- Show passenger info.\n";
    cout << "[2]- Create new passenger.\n";
    cout << "[3]- Delete passenger.\n";
    cout << "[4]- Update passenger.\n";
    cout << "[9]- Back.\n\n";

}


void Application::printAirplanesMenu() const {

    cout << "\n[AIRPLANES MANAGEMENT MENU]\n\n";
    cout << "[1]- Show airplane info.\n";
    cout << "[2]- Create new airplane.\n";
    cout << "[3]- Delete airplane.\n";
    cout << "[4]- Update airplane.\n";
    cout << "[5]- Flights management.\n";
    cout << "[9]- Back.\n\n";
}

void Application::printListsMenu() const {

    cout << "[LISTS MENU]\n\n";
    cout << "Passenger lists.\n\n";
    cout << "[1]- Passengers by id.\n";
    cout << "[2]- Passengers by name.\n";
    cout << "[3]- Passengers by age.\n\n";
    cout << "Airplane lists.\n\n";
    cout << "[4]- Airplanes by id.\n";
    cout << "Flights lists.\n\n";
    cout << "[5]- Flights by id.\n";
    cout << "[6]- Flights by price (low to high).\n";
    cout << "[7]- Flights by price (high to low).\n";
    cout << "[8]- Flights by destination.\n";
    cout << "[9]- Flights by time to flight.\n\n";
    cout << "[0]- Back.\n\n";
}

void Application::printFlightsMenu() const {

    cout << "[FLIGHT MANAGEMENT MENU]\n\n";
    cout << "[1]- Show flight info.\n";
    cout << "[2]- Create new flight.\n";
    cout << "[3]- Delete flight.\n";
    cout << "[4]- Update flight price.\n";
    cout << "[9]- Back.\n\n";
}

void Application::printBookingsMenu() const {

    cout << "[BOOKING MANAGEMENT MENU]\n\n";
    cout << "[1]- Show scheduled Flights\n";
    cout << "[2]- Book a Flight\n";
    cout << "[3]- Return a Flight ticket\n";
    cout << "[9]- Back.\n\n";
}

void Application::printAirplaneUpdateMenu(Airplane *airplane) const {

    cout << "Airplane selected: \n\n";
    airplane->print();
    cout << "[AIRPLANE UPDATE MENU]\n\n";
    cout << "[1]- Change airplane model.\n";
    cout << "[2]- Change airplane capacity.\n";
    cout << "[3]- Change period between maintenance sessions.\n";
    cout << "[9]- Back.\n\n";

}

void Application::printPassengerUpdateMenu(Passenger *passenger) const {

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

void Application::printMaintenanceMenu() const {

    cout << "[MAINTENANCE MENU]\n\n";
    cout << "[1]- Reschedule maintenance session\n";
    cout << "[2]- Perform maintenance session.\n";
    cout << "[3]- Show next maintenance sessions.\n";
    cout << "[4]- Show maintenance sessions in given period of time.\n";
    cout << "[9]- Back.\n\n";
}

void Application::printTechniciansMenu() const {

    cout << "[TECHNICIAN MENU]\n\n";
    cout << "[1]- Show technician info.\n";
    cout << "[2]- Create new technician.\n";
    cout << "[3]- Delete technician.\n";
    cout << "[4]- Update technician.\n";
    cout << "[9]- Back.\n\n";
}

void Application::printTechniciansUpdateMenu(Technician * technician) const {
    cout << "Technician selected: \n\n";
    technician->print();
    cout << "[TECHNICIAN UPDATE MENU]\n\n";
    cout << "[1]- Change technician name.\n";
    cout << "[2]- Add model.\n";
    cout << "[3]- Delete model.\n";
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
void Application::resetFlags() {
    this->company.setFlag();
}
void Application::saveChanges() {

    char auxOp;
    if (company.getPassengersChanged() || company.getAirplanesChanged() || company.getFlightsChanged() || company.getTechniciansChanged()) {
        cout << "There are changes to be deployed to the files.\n";
        do {
            cout << "Would you like to save those changes (Y/N) ? ";
            if (cin >> auxOp && (auxOp == 'Y' || auxOp == 'N' || auxOp == 'y' || auxOp == 'n')) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (auxOp == 'Y' || auxOp == 'y') {
                    saveAllFiles();
                    resetFlags();
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
    } else {cout << "There are no changes to be deployed\n";}
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

void Application::techniciansMenu() {

    string op;

    do {

        printTechniciansMenu();

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuTechnicians.find(op) == menuTechnicians.end()) {
                if (op == "9") return;
                if (op == "4") break;
                cout << "Invalid option.\n";
            } else break;

        } while(true);

        if (op == "4") {
            technicianUpdateMenu();
            continue;
        }

        (company.*menuTechnicians[op])();
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
        default:
            return;
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

    vector<Airplane* > airplanes;
    string title;

    for (auto a : company.getFleet()) {
        airplanes.push_back(a);
    }

    sort(airplanes.begin(), airplanes.end(), compAId);
    title = "Airplane by id:\n";

    cout << title;
    cout << std::left;
    cout << setw(11) << "Airplane ID" << setw(3) << " " << setw(7) << "Model" << setw(3) << " " << setw(7)
         << "Capacity\n";

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
        default:
            return;

    }

    cout << title;
    cout << std::left;
    cout << setw(9) << "Flight ID" << setw(3) << " " << setw(15) << "Departure" << setw(3) << " " << setw(15)
         << "Destination" << setw(3) << " " << setw(17) << "Time to flight (h)" << setw(3) << " " << setw(9)
         << "Price (€)\n";

    for (auto &flight : flights) {

        flight->printList();
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
                cout << "Invalid option.\n";
            } else break;


        } while (true);

        (company.*menuFlights[op])(airplane);
        pause();

    } while (true);
}

void Application::bookingsMenu() {

    string menuhelper;
    Passenger *passenger;

    if (company.getPassengers().empty()) {
        cout << "There are no passengers.\n";
        return;
    }

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

void Application::maintenanceMenu() {

    string op;

    do {
        printMaintenanceMenu();

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuMaintenance.find(op) == menuMaintenance.end()) {
                if (op == "9") return;
                cout << "Invalid option.\n";
            } else break;
        } while (true);

        (company.*menuMaintenance[op])();
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

void Application::technicianUpdateMenu() {

    if (company.getTechnicians().empty()) {
        cout << "There are no technicians.\n";
        return;
    }

    company.printSummaryTechnician();
    string op;
    Technician * technician;
    do {
        try {
            technician = company.chooseTechnician();
        }
        catch (const InvalidTechnician &i) {
            i.print();
            continue;
        }

        break;

    } while(true);

    do {
        printTechniciansUpdateMenu(technician);

        do {
            cout << "Insert the desired option: ";
            getline(cin, op);
            if (op.empty() || menuTechnicianUpdate.find(op) == menuTechnicianUpdate.end()) {
                if (op == "9") return;
                cout << "Invalid option.\n";
            } else break;
        } while (true);

        (company.*menuTechnicianUpdate[op])(technician);
        pause();

    } while(true);
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
    int day, month, year;
    try {
        next(day, st, "/");
        next(month, st, "/");
        next(year, st, "/");

    } catch (InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
        return nullptr;
    }
    Date date;
    date.day = day;
    date.month = month;
    date.year = year;

    newAirplane->setMaintenance(date);

    try { next(temp, a, ";"); } catch (InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
        return nullptr;
    }

    Date mp;
    mp.day = temp;
    newAirplane->setMaintenancePeriod(mp);

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

    //date

    try {
        next(st, f, ";");
    } catch (InvalidFormat) {
        cout << "Flight " << to_string(newFlight->getId())
             << ": Please insert the Flight data in the correct format.\n";
        return nullptr;
    }

    Date d;
    next(d.day, st, "/");
    next(d.month, st, "/");
    next(d.year, st, "-");
    next(d.hour, st, ":");
    next(d.minute, st, ";");

    newFlight->setDate(d);

    try { next(st, f, ";"); } catch (InvalidFormat) {
        cout << "Flight " << to_string(newFlight->getId())
             << ": Please insert the Flight data in the correct format.\n";
        return nullptr;
    }

    newFlight->setBasePrice((unsigned int) temp);

    try { next(st, f, ";"); } catch (InvalidFormat) {
        cout << "Flight " << to_string(newFlight->getId())
             << ": Please insert the Flight data in the correct format.\n";
        return nullptr;
    }

    Date d2;

    next(d2.hour, st, ":");
    next(d2.minute, st, ";");

    newFlight->setDuration(d2);

    next(st, f, ";");

    if (st == "no_passengers") {
        newFlight->setBuyer(nullptr);
        return newFlight;
    }

    if (type == 'r') {

        try { next(temp, st, ";"); } catch (InvalidFormat) {
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
Technician *Application::readTechnician(string &p) {
    vector <string> models_v;
	Technician *newTechnician = new Technician(0,"",models_v);

	int temp;
	try { next(temp, p, ";"); }
	catch (InvalidFormat) {
		cout << "Please insert the Passenger data in the correct format.\n";
		return nullptr;
	}

	newTechnician->setId((unsigned int)temp);

	string st;
	string models;

	next(st, p, ";");
	newTechnician->setName(st);

    models_v.clear();

	while (true) {
		if (p.find(',') != p.npos) {
			next(models, p, ",");
            models_v.push_back(models);
		} 
		else {
            p.substr(0,p.npos);
            trimString(p);
            models_v.push_back(p);
            break; }
	}

	newTechnician->setModels(models_v);

	return newTechnician;
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

    Date d1;

    next(d1.day, st, "/");
    next(d1.month, st, "/");
    next(d1.year, st, "/");

    newPassenger->setDateOfBirth(d1);


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
void Application::loadTechnicianFile() {

    string f;

    techniciansFilepath = inputFilePath(Company::TECHNICIAN_IDENTIFIER);

    if (techniciansFilepath == "") throw InvalidFilePath("empty");

    ifstream flFile(techniciansFilepath);
    if (!flFile) {
        techniciansFilepath.clear();
        throw InvalidFilePath("fail");
    }
    this->company.clearData(Company::TECHNICIAN_IDENTIFIER);
    while (getline(flFile, f)) {
        if (f.empty()) continue;
        Technician *technician = readTechnician(f);
        if (technician != nullptr) this->company.addObject(technician);
    }

    flFile.close();

    cout << "File successfully loaded.\n";

}
void Application::loadFlightFile() {

    string f;

    flightsFilepath = inputFilePath(Company::FLIGHT_IDENTIFIER);

    if (flightsFilepath == "") throw InvalidFilePath("empty");

    ifstream flFile(flightsFilepath);
    if (!flFile) {
        flightsFilepath.clear();
        throw InvalidFilePath("fail");
    }
    this->company.clearData(Company::FLIGHT_IDENTIFIER);
    while (getline(flFile, f)) {
        if (f.empty()) continue;
        Flight *flight = readFlight(f);
        if (flight != nullptr) {
            this->company.addObject(flight);
            this->company.addBookingsFromFlight(flight);
        }
    }

    flFile.close();
    this->company.sortFlights();

    cout << "File successfully loaded.\n";

}

void Application::loadAirplaneFile() {

    airplanesFilepath = inputFilePath(Company::AIRPLANE_IDENTIFIER);

    string a;

    if (airplanesFilepath == "") throw InvalidFilePath("empty");

    ifstream airFile(airplanesFilepath);
    if (!airFile) {
        airplanesFilepath.clear();
        throw InvalidFilePath("fail");
    }
    this->company.clearData(Company::AIRPLANE_IDENTIFIER);
    while (getline(airFile, a)) {
        if (a.empty()) continue;
        Airplane *airplane = readAirplane(a);
        if (airplane != nullptr) this->company.addObject(airplane);
    }
    airFile.close();
    cout << company.getFleet().size();

    cout << "File successfully loaded.\n";

}

void Application::loadPassengerFile() {

    passengersFilepath = inputFilePath(Company::PASSENGER_IDENTIFIER);

    string p;

    if (passengersFilepath == "") throw InvalidFilePath("empty");

    ifstream passFile(passengersFilepath);
    if (!passFile) {
        passengersFilepath.clear();
        throw InvalidFilePath("fail");
    }
    this->company.clearData(Company::PASSENGER_IDENTIFIER);
    while (getline(passFile, p)) {
        if (p.empty()) continue;
        Passenger *passenger = readPassenger(p);
        if (passenger != nullptr) this->company.addObject(passenger);
    }
    passFile.close();
    this->company.sortPassengers();

    cout << "File successfully loaded.\n";

}

void Application::saveFile(string &path, AirplanesSet fleet) {
    ofstream file(path);

    if (!file) throw InvalidFilePath("fail");
    auto it = fleet.begin();
    while(it != fleet.end()) {
        file << (*it);
        it++;
        if (it != fleet.end())
            file << endl;
    }
    file.close();
}
void Application::saveFile(string &path, priority_queue <Technician *> techs) {
	ofstream file(path);

	if (!file) throw InvalidFilePath("fail");
	while (!techs.empty()) {
		file << techs.top();
		techs.pop();
		if (techs.size() != 0)
			file << endl;
	}
	file.close();
}

void Application::saveAllFiles() {
    if (company.getAirplanesChanged()) {

        if (airplanesFilepath.empty()) airplanesFilepath = inputFilePath(Company::AIRPLANE_IDENTIFIER);

        try { saveFile(airplanesFilepath, this->company.getFleet()); } catch (InvalidFilePath &in) { in.print(); }

    }

    if (company.getFlightsChanged()) {

        if (flightsFilepath.empty()) flightsFilepath = inputFilePath(Company::FLIGHT_IDENTIFIER);

        try { saveFile(flightsFilepath, this->company.getFlights()); } catch (InvalidFilePath &in) { in.print(); }

    }

    if (company.getPassengersChanged()) {

        if (passengersFilepath.empty()) passengersFilepath = inputFilePath(Company::PASSENGER_IDENTIFIER);

        try { saveFile(passengersFilepath, this->company.getPassengers()); } catch (InvalidFilePath &in) { in.print(); }

    }

    if (company.getTechniciansChanged()){

        if(techniciansFilepath.empty()) techniciansFilepath = inputFilePath(Company::TECHNICIAN_IDENTIFIER);

        try { saveFile(techniciansFilepath, this->company.getTechnicians()); } catch (InvalidFilePath &in) {in.print(); }
    }

    cout << "All changes were saved.\n";

}