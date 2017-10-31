#include "Application.h"
#include "Company.h"
#include "helper.h"
#include <string>

Application::Application() {

    Company c = Company("TAP");
    company = c;
    passengersChanged = false;
    airplanesChanged = false;
    passengersFilepath = "";
    airplanesFilepath = "";

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
        cout << "[0]- Quit.\n\n";

        do {
            cout << "Insert the desired option: ";
            if ((cin >> op) && op >= 0 && op <= 4) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }
            else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);


        switch (op) {
            case 1:
                filesMenu();
                break;
            case 2:
                passengersMenu();
                break;
            case 3:
                airplanesMenu();
                break;
            case 4:
                bookingsMenu();
                break;
            case 0:
                if (passengersChanged || airplanesChanged) {
                    cout << "There are changes to be deployed to the files.\n";
                    do {
                        cout << "Would you like to save those changes (Y/N) ? ";
                        if (cin >> auxOp && (auxOp == 'Y' || auxOp == 'N' || auxOp == 'y' || auxOp == 'n')) {
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if (auxOp == 'Y') {
                                //TODO functions to update files.
                                cout << "Press any key to continue...";
                                getchar();
                                break;
                            }
                            else {
                                break;
                            }
                        }
                        else {
                            cerr << "Invalid option.\n";
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        }
                    } while (true);
                }
        }

    } while (op != 0);
}

void Application::filesMenu() {
    int op;
    do {
        bool validOp = false;
        cout << "[FILE MANAGEMENT MENU]\n\n";
        cout << "[1]- Load passengers file ";
        if (passengersFilepath.empty()) {
            cout << "(No file loaded).";
        }
        else {
            cout << "('" << passengersFilepath << "' loaded).";
        }
        cout << endl;
        cout << "[2]- Load airplane file ";
        if (airplanesFilepath.empty()) {
            cout << "(No file loaded).";
        }
        else {
            cout << "('" << airplanesFilepath << "' loaded).";
        }
        cout << endl;
        cout << "[3]- Save all changes to files.\n";
        cout << "[9]- Back.\n\n";

        do {
            cout << "Insert the desired option: ";
            if (cin >> op && ((op >= 0 && op <= 3) || op == 9)) {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                validOp = true;
            }
            else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (!validOp);

        switch (op) {
            case 1:
                //TODO function to load passenger's file
                break;
            case 2:
                //TODO funtion to load airplanes's file
                break;
            case 3:
                //TODO funtion to save changes
                cout << "Press any key to continue...";
                getchar();
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
            }
            else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                passengerShow();
                break;
            case 2:
                passengerCreate();
                break;
            case 3:
                //TODO passengers delete
                break;
            case 4:
                //TODO passengers update (chamar outro menu)
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
            }
            else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                airplaneShow();
                break;
            case 2:
                airplaneCreate();
                break;
            case 3:
                //TODO airplanes delete
                break;
            case 4:
                //TODO airplanes update (chamar outro menu)
                break;
            case 5:
                flightsMenu(chooseAirplane());
                break;
        }

    } while (op != 9);
}

void Application::flightsMenu(int aIndex) {

    int op;

    Airplane airplane = company.getFleet().at(aIndex);

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
            }
            else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                flightShow(aIndex);
                break;
            case 2:
                //TODO flights create
                break;
            case 3:
                //TODO flights delete
                break;
            case 4:
                //TODO flights update (chamar outro menu), nao esquecer adicionar e eliminar passageiros
                break;
        }

    } while (op != 9);

}

void Application::bookingsMenu() {

    cout << "Are you a new costumer? (y/n)\n";
    //...
    //...
    //..

}

void Application::printSummaryPassenger() {

    int i = 1;

    cout << "PASSENGER SUMMARY\n\n";

    for (auto &passenger : company.getPassangers()) {
        cout << i << ". ";
        passenger->printSummary();
        i++;
    }

}

void Application::printSummaryAirplane() {

    int i = 1;

    cout << "AIRPLANE SUMMARY\n\n";

    for (auto &airplane : company.getFleet()) {
        cout << i << ". ";
        airplane.printSummary();
        i++;
    }
}

void Application::printSummaryFlight(int aIndex) {

    int i = 1;
    Airplane a = company.getFleet().at(aIndex);

    cout << "FLIGHT SUMMARY\n\n";

    for (auto &flight : a.getFlights()) {
        cout << i << ". ";
        flight->printSummary();
        i++;
    }
}

int Application::choosePassenger() {

    int pIndex;
    do {
        cout << "Choose passenger: ";
        if (!validArg(pIndex)) continue;
        if (pIndex <= company.getPassangers().size()) break;
        else {
            cout << "Invalid number. Reenter.\n";
        }
    } while (true);
    return pIndex-1;

}

int Application::chooseAirplane() {

    int aIndex;
    do {
        cout << "Choose airplane: ";
        if (!validArg(aIndex)) continue;
        if (aIndex <= company.getFleet().size()) break;
        else {
            cout << "Invalid number. Reenter.\n";
        }
    } while (true);
    return aIndex-1;
}

int Application::chooseFlight(int aIndex) {

    int fIndex;
    do {
        cout << "Choose flight: ";
        if (!validArg(fIndex)) continue;
        if (fIndex <= company.getFleet().at(fIndex).getFlights().size()) break;
        else {
            cout << "Invalid number. Reenter.\n";
        }
    } while (true);
    return fIndex-1;

}


void Application::passengerShow() {

    printSummaryPassenger();
    string foo;
    int pIndex;
    do {
        cout << "Do you wish to view detailed information about a passenger (Y/N)?: ";
        getline(cin, foo);
        normalize(foo);
        if (foo == "y") {
            cout << endl;
            pIndex = choosePassenger();
            company.getPassangers().at(pIndex)->print();
        }
        else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Application::airplaneShow() {

    printSummaryAirplane();
    string foo;
    int aIndex;
    do {
        cout << "Do you wish to view detailed information about an airplane (Y/N)?: ";
        getline(cin, foo);
        normalize(foo);
        if (foo == "y") {
            cout << endl;
            aIndex = chooseAirplane();
            company.getFleet().at(aIndex).print();
        }
        else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Application::flightShow(int aIndex) {

    printSummaryFlight(aIndex);
    string foo;
    int fIndex;
    do {
        cout << "Do you wish to view detailed information about a flight (Y/N)?: ";
        getline(cin, foo);
        normalize(foo);
        if (foo == "y") {
            cout << endl;
            fIndex = chooseFlight(aIndex);
            company.getFleet().at(aIndex).getFlights().at(fIndex)->print();
        }
        else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

bool Application::validPassenger(string name) {

    normalize(name);
     for (auto &passenger : company.getPassangers()) {

         if (passenger->getName() == name)
             return false;

     }

    return true;

}

bool Application::validAirplane(string name) {

    normalize(name);
    for (auto &airplane : company.getFleet()) {

        if (airplane.getName() == name)
            return false;
    }

    return true;
}

void Application::passengerCreate() {

    string foo;
    string name, dateOfBirth, job;
    int nYear;

    cout << "Normal passenger or passenger with card? (n/c)\n";
    getline(cin, foo);

    cout << "Insert the new passenger information: \n\n";
    do {
        cout << "Insert name: ";
        getline(cin, name);
        normalize(name);
        if (!validPassenger(name)) {
            cout << "This passenger already exists. Please insert another name or delete the airplane." << endl;
        }
        else {
            break;
        }
    } while (true);

    cout << "Date of Birth: (DD/MM/YYYY): ";
    getline(cin, dateOfBirth);

    if (foo == "n") {

        Passenger *newpassenger = new Passenger(name, dateOfBirth);
        company.addPassanger(newpassenger);
        cout << "Passenger successfully added\n";
        passengersChanged = true;
        return;
    } else if (foo == "c") {

        cout << "Job: ";
        getline(cin, job);
        normalize(job);

        do {
            cout << "Number of flights/year: ";
            if (validArg(nYear)) break;
        } while (true);

        PassengerWithCard *newpassenger = new PassengerWithCard(name, dateOfBirth, job, nYear);
        company.addPassanger(newpassenger);
        cout << "Passenger successfully added\n";
        passengersChanged = true;
        return;
    }
}

void Application::airplaneCreate() {

    string name;
    int capacity;

    cout << "Insert the new airplane information: \n\n";
    do {
        cout << "Insert name: ";
        getline(cin, name);
        normalize(name);
        if (!validAirplane(name)) {
            cout << "This airplane already exists. Please insert another name or delete the airplane." << endl;
        }
        else {
            break;
        }
    } while (true);

    do {
        cout << "Capacity: ";
        if (validArg(capacity)) break;
    } while (true);

    Airplane newairplane = Airplane(name, capacity);
    company.addAirplane(newairplane);
    cout << "Airplane successfully added\n";
    airplanesChanged = true;
}

