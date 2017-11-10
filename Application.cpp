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
            } else {
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

void Application::filesMenu() {
    int op;
    do {
        bool validOp = false;
        cout << "[FILE MANAGEMENT MENU]\n\n";
        cout << "[1]- Load passengers file ";
        if (passengersFilepath.empty()) {
            cout << "(No file loaded).";
        } else {
            cout << "('" << passengersFilepath << "' loaded).";
        }
        cout << endl;
        cout << "[2]- Load airplane file ";
        if (airplanesFilepath.empty()) {
            cout << "(No file loaded).";
        } else {
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
            } else {
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
            } else {
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
                passengerDelete();
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
                airplaneShow();
                break;
            case 2:
                airplaneCreate();
                break;
            case 3:
                airplaneDelete();
                break;
            case 4:
                airplaneUpdateMenu();
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
            } else {
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
                flightDelete(aIndex);
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
    return pIndex - 1;

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
    return aIndex - 1;
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
    return fIndex - 1;

}


void Application::passengerShow() {

    if (company.getPassangers().size() == 0) {
        cout << "There are no passengers.\n";
        return;
    }

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
        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Application::airplaneShow() {

    if (company.getFleet().size() == 0) {

        cout << "There are no airplanes.\n";
        return;

    }

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
        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Application::flightShow(int aIndex) {

    if (company.getFleet().at(aIndex).getFlights().size() == 0) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

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
        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

bool Application::validPassenger(int id) {

    for (auto &passenger : company.getPassangers()) {

        if (passenger->getId() == id)
            return false;

    }

    return true;

}

bool Application::validAirplane(int id) {

    for (auto &airplane : company.getFleet()) {

        if (airplane.getId() == id)
            return false;
    }

    return true;
}

void Application::passengerCreate() {

    string foo;
    string name, dateOfBirth, job;
    int id, nYear;

    while (true) {

        cout << "Normal passenger or passenger with card? (n/c)\n";
        getline(cin, foo);
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

        if (!validPassenger(id)) {
            cout << "This passenger already exists. Please insert another id or delete the passenger." << endl;
        } else {
            break;
        }

    } while (true);


    cout << "Name: ";
    getline(cin, name);

    cout << "Date of Birth: (DD/MM/YYYY): ";
    getline(cin, dateOfBirth);

    if (foo == "n") {

        Passenger *newpassenger = new Passenger(id, name, dateOfBirth);
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

        PassengerWithCard *newpassenger = new PassengerWithCard(id, name, dateOfBirth, job, nYear);
        company.addPassanger(newpassenger);
        cout << "Passenger successfully added\n";
        passengersChanged = true;
        return;
    }
}

void Application::airplaneCreate() {

    string model;
    int id, capacity;

    cout << "Insert the new airplane information: \n\n";

    do {

        do {

            cout << "Insert id: ";
            if (validArg(id)) break;

        } while (true);

        if (!validAirplane(id)) {
            cout << "This airplane already exists. Please insert another id or delete the airplane." << endl;
        } else {
            break;
        }

    } while (true);


    cout << "Model: ";
    getline(cin, model);

    do {
        cout << "Capacity: ";
        if (validArg(capacity)) break;
    } while (true);

    Airplane newairplane = Airplane(id, model, capacity);
    company.addAirplane(newairplane);
    cout << "Airplane successfully added\n";
    airplanesChanged = true;
}

void Application::passengerDelete() {

    printSummaryPassenger();
    int pIndex;
    pIndex = choosePassenger();
    company.removePassenger(pIndex);
    cout << "Passenger deleted sucessfully.\n ";
    passengersChanged = true;

}

void Application::airplaneDelete() {

    printSummaryAirplane();
    int aIndex;
    aIndex = chooseAirplane();
    company.removeAirplane(aIndex);
    cout << "Airplane deleted sucessfully.\n ";
    airplanesChanged = true;
}

void Application::flightDelete(int aIndex) {

    printSummaryFlight(aIndex);
    int fIndex;
    fIndex = chooseFlight(aIndex);
    company.getFleet().at(aIndex).removeFlight(fIndex);
    cout << "Flight deleted sucessfully.\n";
    airplanesChanged = true;
}

void Application::passengerUpdateMenu() {

    printSummaryPassenger();
    int pIndex, op;
    pIndex = choosePassenger();

    do {
        cout << "Passenger selected: \n\n";
        company.getPassangers().at(pIndex)->print();
        cout << "[PASSENGER UPDATE MENU]\n\n";
        cout << "[1]- Change passenger name.\n";
        cout << "[2]- Change passenger date of birth.\n";

        if (company.getPassangers().at(pIndex)->getType() == "c") {


            cout << "[3]- Change passenger job.\n";
            cout << "[4]- Change passenger number of flights/year.\n";

        }
        cout << "[9]- Back.\n\n";

        if (company.getPassangers().at(pIndex)->getType() == "c") {

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

        if (company.getPassangers().at(pIndex)->getType() == "n") {

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
                passengerUpdateName(pIndex);
                break;
            case 2:
                passengerUpdateDateOfBirth(pIndex);
                break;
            case 3:
                passengerUpdateJob(pIndex);
                break;
            case 4:
                passengerUpdateNYear(pIndex);
                break;
        }

    } while (op != 9);
}

void Application::passengerUpdateName(int pIndex) {

    Passenger *passenger = company.getPassangers().at(pIndex);

    string newName;
    cout << "The current name for the chosen passenger is '" << passenger->getName() << "'.\n";
    cout << "Insert new name: ";
    getline(cin, newName);
    passenger->setName(newName);
    passengersChanged = true;
    cout << "Passenger name updated successfully.\n";

}

void Application::passengerUpdateDateOfBirth(int pIndex) {

    Passenger *passenger = company.getPassangers().at(pIndex);

    string newDateOfBirth;
    cout << "The current date of birth for the chosen passenger is '" << passenger->getDateOfBirth() << "'.\n";
    cout << "Insert the new date of birth (DD/MM/YYYY): ";
    getline(cin, newDateOfBirth);
    passenger->setDateOfBirth(newDateOfBirth);
    passengersChanged = true;
    cout << "Passenger date of birth updated successfully.\n";
}


void Application::passengerUpdateJob(int pIndex) {

    Card *card = company.getPassangers().at(pIndex)->getCard();

    string newJob;

    cout << "The current job for the chosen passenger is '" << card->getJob() << "'.\n";
    cout << "Insert the new job: ";
    getline(cin, newJob);
    card->setJob(newJob);
    passengersChanged = true;
    cout << "Passenger job updated successfully.\n";

}

void Application::passengerUpdateNYear(int pIndex) {

    Card *card = company.getPassangers().at(pIndex)->getCard();

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

void Application::airplaneUpdateMenu() {

    printSummaryAirplane();
    int aIndex, op;
    aIndex = chooseAirplane();

    do {
        cout << "Airplane selected: \n\n";
        company.getFleet().at(aIndex).print();
        cout << "[AIRPLANE UPDATE MENU]\n\n";
        cout << "[1]- Change airplane name.\n";
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
                airplaneUpdateName(aIndex);
                break;
            case 2:
                airplaneUpdateCapacity(aIndex);
                break;
        }

    } while (op != 9);
}

void Application::airplaneUpdateName(int aIndex) {

    Airplane airplane = company.getFleet().at(aIndex);

    string newModel;
    cout << "The current model for the chosen airplane is '" << airplane.getModel() << "'.\n";
    cout << "Insert new model: ";
    getline(cin, newModel);
    airplane.setModel(newModel);
    company.setAirplane(aIndex, airplane);
    airplanesChanged = true;
    cout << "Airplane model updated successfully.\n";

}

void Application::airplaneUpdateCapacity(int aIndex) {

    Airplane airplane = company.getFleet().at(aIndex);

    if (airplane.getFlights().size() != 0) {

        cout
                << "There are asigned seats in at least one flight in this airplane, if you want to change its capacity delete the flight\n";
        return;

    }

    int newcapacity;

    cout << "The current capacity for the chosen airplane is '" << airplane.getCapacity() << "'.\n";
    do {
        cout << "Insert the new capacity : ";
        if (!validArg(newcapacity)) continue;
        else break;

    } while (true);

    airplane.setCapacity(newcapacity);
    company.setAirplane(aIndex, airplane);
    airplanesChanged = true;
    cout << "Airplane capacity updated successfully.\n";

}


