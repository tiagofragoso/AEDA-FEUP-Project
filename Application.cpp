#include "Application.h"
#include "exceptions.h"

Application::Application() {

    Company c = Company("TAP");
    company = c;
    passengersChanged = false;
    airplanesChanged = false;
    flightsChanged = false;
    passengersFilepath = "";
    airplanesFilepath = "";
    flightsFilepath = "";

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

void Application::flightsMenu(Airplane airplane) {

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
                flightShow(airplane);
                break;
            case 2:
                //TODO flights create
                break;
            case 3:
                flightDelete(airplane);
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

    cout << "PASSENGER SUMMARY\n\n";

    for (auto &passenger : company.getPassangers()) {
        passenger->printSummary();
    }

}

void Application::printSummaryAirplane(){

    cout << "AIRPLANE SUMMARY\n\n";

    for (auto &airplane : company.getFleet()) {
        airplane.printSummary();
    }
}

void Application::printSummaryFlight(Airplane airplane) {

    cout << "FLIGHT SUMMARY\n\n";

    for (auto &flight : airplane.getFlights()) {

        flight->printSummary();
    }
}

Passenger * Application::choosePassenger() {

    int pId;
    Passenger * cpassenger;
    do {
        cout << "Choose passenger: ";
        if (!validArg(pId)) continue;
        else break;

    } while(true);

    for (auto &passenger : company.getPassangers()) {

        if (passenger->getId() == pId) {
            cpassenger = passenger;
            return cpassenger;
        }
    }

    throw InvalidPassenger(pId);
}

Airplane Application::chooseAirplane() {

     int aId;
     Airplane cairplane;
     do {
         cout << "Choose airplane: ";
         if (!validArg(aId)) continue;
         else break;

     } while (true);

    for (auto &airplane : company.getFleet()) {

        if (airplane.getId() == aId) {
            cairplane = airplane;
            return cairplane;
        }
    }
    throw  InvalidAirplane(aId);
}

Flight * Application::chooseFlight(Airplane airplane) {

    int fId;
    Flight * cflight;

    do {
        cout << "Choose flight: ";
        if (!validArg(fId)) continue;
        else break;

    } while (true);

    for (auto &flight : airplane.getFlights()) {

        if (flight->getId() == fId) {
            cflight = flight;
            return cflight;
        }
    }
    throw  InvalidFlight(fId);
}


void Application::passengerShow() {

    if (company.getPassangers().size() == 0) {
        cout << "There are no passengers.\n";
        return;
    }

    printSummaryPassenger();
    string foo;
    Passenger * passenger;
    do {
        cout << "Do you wish to view detailed information about a passenger (Y/N)?: ";
        getline(cin, foo);
        normalize(foo);
        if (foo == "y") {
            cout << endl;
            do {
                try {
                    passenger = choosePassenger();
                }
                catch(const InvalidPassenger &i) {
                    i.print();
                    continue;
                }

                passenger->print();
                break;

            }while(true);

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
    Airplane airplane;
    do {
        cout << "Do you wish to view detailed information about an airplane (Y/N)?: ";
        getline(cin, foo);
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

                airplane.print();
                break;
            }while(true);

        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Application::flightShow(Airplane airplane) {

    if (airplane.getFlights().size() == 0) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

    printSummaryFlight(airplane);
    string foo;
    Flight * flight;
    do {
        cout << "Do you wish to view detailed information about a flight (Y/N)?: ";
        getline(cin, foo);
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

            }while(true);

        } else if (foo == "n") break;
        else {
            cout << "Invalid option. Reenter." << endl;
        }
    } while (true);
    cout << endl;

}

void Application::validPassenger(int id) {

    for (auto &passenger : company.getPassangers()) {

        if (passenger->getId() == id)
            throw InvalidPassenger(id);

    }
}

void Application::validAirplane(int id) {

    for (auto &airplane : company.getFleet()) {

        if (airplane.getId() == id)
            throw InvalidAirplane(id);
    }
}

void Application::validFlight(int id) {

    for (auto &airplane : company.getFleet()) {

        for (auto &flight : airplane.getFlights()) {

            if (flight->getId() == id)
                throw InvalidFlight(id);
        }
    }
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

        try {
            validPassenger(id);
        }
        catch (const InvalidPassenger &i) {
            i.printDuplicate();
            continue;
        }

        break;

    } while (true);


    cout << "Name: ";
    getline(cin, name);

    cout << "Date of Birth: (DD/MM/YYYY): ";
    getline(cin, dateOfBirth);

    if (foo == "n") {

        Passenger * newpassenger = new Passenger(id, name, dateOfBirth);
        company.addPassenger(newpassenger);
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
        company.addPassenger(newpassenger);
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

        try {
            validPassenger(id);
        }
        catch (const InvalidAirplane &i) {
            i.printDuplicate();
            continue;
        }

        break;

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
    Passenger * passenger;
    do {
        try {
            passenger = choosePassenger();
        }
        catch (const InvalidPassenger &i) {
            i.print();
            continue;
        }
        break;

    }while(true);
    company.removePassenger(passenger);
    cout << "Passenger deleted sucessfully.\n ";
    passengersChanged = true;

}

void Application::airplaneDelete() {

    printSummaryAirplane();
    Airplane airplane;
    do {
        try {
            airplane = chooseAirplane();
        }
        catch (const InvalidAirplane &i) {
            i.print();
            continue;
        }

        break;

    }while(true);
    company.removeAirplane(airplane);
    cout << "Airplane deleted sucessfully.\n ";
    airplanesChanged = true;
    flightsChanged = true;
}

void Application::flightDelete(Airplane airplane) {

    printSummaryFlight(airplane);
    Flight * flight;
    do {
        try {
            flight = chooseFlight(airplane);
        }
        catch (const InvalidFlight &i) {
            i.print();
            continue;
        }
        break;

    }while(true);
    airplane.removeFlight(flight);
    cout << "Flight deleted sucessfully.\n";
    airplanesChanged = true;
    flightsChanged = true;
}

void Application::passengerUpdateMenu() {

    printSummaryPassenger();
    int op;
    Passenger * passenger;
    do {
        try {
            passenger = choosePassenger();
        }
        catch (const InvalidPassenger &i) {
            i.print();
            continue;
        }
        break;

    }while(true);

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
                passengerUpdateName(passenger);
                break;
            case 2:
                passengerUpdateDateOfBirth(passenger);
                break;
            case 3:
                passengerUpdateJob(passenger);
                break;
            case 4:
                passengerUpdateNYear(passenger);
                break;
        }

    } while (op != 9);
}

void Application::passengerUpdateName(Passenger * passenger) {

    string newName;
    cout << "The current name for the chosen passenger is '" << passenger->getName() << "'.\n";
    cout << "Insert new name: ";
    getline(cin, newName);
    passenger->setName(newName);
    passengersChanged = true;
    cout << "Passenger name updated successfully.\n";

}

void Application::passengerUpdateDateOfBirth(Passenger * passenger) {

    string newDateOfBirth;
    cout << "The current date of birth for the chosen passenger is '" << passenger->getDateOfBirth() << "'.\n";
    cout << "Insert the new date of birth (DD/MM/YYYY): ";
    getline(cin, newDateOfBirth);
    passenger->setDateOfBirth(newDateOfBirth);
    passengersChanged = true;
    cout << "Passenger date of birth updated successfully.\n";
}


void Application::passengerUpdateJob(Passenger * passenger) {

    Card *card = passenger->getCard();

    string newJob;

    cout << "The current job for the chosen passenger is '" << card->getJob() << "'.\n";
    cout << "Insert the new job: ";
    getline(cin, newJob);
    card->setJob(newJob);
    passengersChanged = true;
    cout << "Passenger job updated successfully.\n";

}

void Application::passengerUpdateNYear(Passenger * passenger) {

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

void Application::airplaneUpdateMenu() {

    printSummaryAirplane();
    int op;
    Airplane airplane;
    do {
        try {
            airplane = chooseAirplane();
        }
        catch (const InvalidAirplane &i) {
            i.print();
            continue;
        }

        break;

    }while(true);

    do {
        cout << "Airplane selected: \n\n";
        airplane.print();
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
                airplaneUpdateName(airplane);
                break;
            case 2:
                airplaneUpdateCapacity(airplane);
                break;
        }

    } while (op != 9);
}

void Application::airplaneUpdateName(Airplane airplane) {

    string newModel;
    cout << "The current model for the chosen airplane is '" << airplane.getModel() << "'.\n";
    cout << "Insert new model: ";
    getline(cin, newModel);
    airplane.setModel(newModel);
    company.setAirplane(airplane);
    airplanesChanged = true;
    cout << "Airplane model updated successfully.\n";

}

void Application::airplaneUpdateCapacity(Airplane airplane) {

    if (airplane.getFlights().size() != 0) {

        cout
                << "There are assigned seats in at least one flight in this airplane, if you want to change its capacity delete the flight\n";
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
    company.setAirplane(airplane);
    airplanesChanged = true;
    cout << "Airplane capacity updated successfully.\n";

}