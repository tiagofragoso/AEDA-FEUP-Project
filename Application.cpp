#include "Application.h"
#include "exceptions.h"

Application::Application() {

    Company c = Company("TAP");
    company = c;
    passengersChanged = false;
    airplanesChanged = false;
    flightsChanged = false;
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
                if (passengersChanged || airplanesChanged || flightsChanged) {
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
    char auxOp;
    do {
        bool validOp = false;
        cout << "[FILE MANAGEMENT MENU]\n\n";

        cout << "NOTE:\n*Please load the files in the following order: Passengers-Flights-Airplanes.\n";
        cout << "*Loading multiple files for the same category will try to merge data, which may cause data overlapping.\n\n";

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
                } catch (InvalidFilePath &in){
                    in.print();
                }
                break;
            case 2:
                //flightsFilepath = inputFilePath("flight");
                try {
                    loadFlightFile();
                } catch(InvalidFilePath &in){
                    in.print();
                }
                for (auto const &f: this->company.getFlights()){
                    f->print();
                    cout << endl;
                }
                break;
            case 3:
                //airplanesFilepath = inputFilePath("airplane");
                try {
                    loadAirplaneFile();
                } catch (InvalidFilePath &in){
                    in.print();
                }
                break;
            case 4:

                if (passengersChanged || airplanesChanged || flightsChanged) {
                    do {
                        cout << "Saving all changes will replace the data in the files with the current state of the application. Proceed (Y/N) ? ";
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
                Airplane *airplane;
                printSummaryAirplane();
                do {
                    try {
                        airplane = chooseAirplane();
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
                flightShow(airplane);
                break;
            case 2:
                flightCreate(airplane);
                break;
            case 3:
                flightDelete(airplane);
                break;
            case 4:
                flightUpdateMenu(airplane);
                break;
        }

    } while (op != 9);

}
Passenger * Application::newCustomer() {
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

		Passenger *newpassenger = new Passenger(id, name, dateOfBirth);
		company.addPassenger(newpassenger);
		cout << "Passenger successfully added\n";
		passengersChanged = true;
		return newpassenger;
	}
	else if (foo == "c") {

		cout << "Job: ";
		getline(cin, job);
		normalize(job);

		nYear = 0;

		PassengerWithCard *newpassenger = new PassengerWithCard(id, name, dateOfBirth, job, nYear);
		company.addPassenger(newpassenger);
		cout << "Passenger successfully added\n";
		passengersChanged = true;
		return newpassenger;
	}
}

void Application::bookingsMenu() {
	string menuhelper;
	int id, op;
	Passenger* a;
	cout << "[BOOKING MANAGEMENT MENU]\n\n";
    cout << "Are you a new costumer? (y/n)\n";
	getline(cin, menuhelper);
	normalize(menuhelper);
	do {
		if (menuhelper == "y") {
			cout << endl;
			a = newCustomer();
			break;
		}
		else if (menuhelper == "n") {
			printSummaryPassenger();
			a = choosePassenger();
			break;
		}
		else {
			cout << "Invalid option. Reenter." << endl;
		}
	} while (true);
	cout << endl;
	do {
		cout << "[BOOKING MANAGEMENT MENU]\n\n";
		cout << "[1]- Show my scheduled flights";
		cout << "[2]- Book a Flight";
		cout << "[3]- Return a flight ticket";
		//TODO:CHECK IF THERE IS ANYTHING ELSE TO INSERT HERE
		cout << "[9]- Back.\n\n";
		do {
			cout << "Insert the desired option: ";
			if ((cin >> op) && ((op >= 1 && op <= 3) || op == 9)) {
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
			break;
		
		}

	} while (op != 9);

}
/*
void Application::showAllFlights(Passenger *p) {
	for (size_t i = 0; i < company.get; i++)
	{

	}
}
*/

void Application::printSummaryPassenger() {

    cout << "PASSENGER SUMMARY\n\n";

    for (auto &passenger : company.getPassangers()) {
        passenger->printSummary();
    }

}

void Application::printSummaryAirplane() {

    cout << "AIRPLANE SUMMARY\n\n";

    for (auto &airplane : company.getFleet()) {
        airplane->printSummary();
    }
}

void Application::printSummaryFlight(Airplane *airplane) {

    cout << "FLIGHT SUMMARY\n\n";

    for (auto &flight : airplane->getFlights()) {

        flight->printSummary();
    }
}

Passenger *Application::choosePassenger() {

    int pId;
    Passenger *cpassenger;
    do {
        cout << "Choose passenger: ";
        if (!validArg(pId)) continue;
        else break;

    } while (true);

    for (auto &passenger : company.getPassangers()) {

        if (passenger->getId() == pId) {
            cpassenger = passenger;
            return cpassenger;
        }
    }

    throw InvalidPassenger(pId);
}

Airplane *Application::chooseAirplane() {

    int aId;
    Airplane *cairplane;
    do {
        cout << "Choose airplane: ";
        if (!validArg(aId)) continue;
        else break;

    } while (true);

    for (auto &airplane : company.getFleet()) {

        if (airplane->getId() == aId) {
            cairplane = airplane;
            return cairplane;
        }
    }
    throw InvalidAirplane(aId);
}

Flight *Application::chooseFlight(Airplane *airplane) {

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


void Application::passengerShow() {

    if (company.getPassangers().size() == 0) {
        cout << "There are no passengers.\n";
        return;
    }

    printSummaryPassenger();
    string foo;
    Passenger *passenger;
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

void Application::airplaneShow() {

    if (company.getFleet().size() == 0) {

        cout << "There are no airplanes.\n";
        return;

    }

    printSummaryAirplane();
    string foo;
    Airplane *airplane;
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

void Application::flightShow(Airplane *airplane) {

    if (airplane->getFlights().size() == 0) {
        cout << "There are no flights in this airplane.\n";
        return;
    }

    printSummaryFlight(airplane);
    string foo;
    Flight *flight;
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

            } while (true);

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

        if (airplane->getId() == id)
            throw InvalidAirplane(id);
    }
}

void Application::validFlight(int id) {

    for (auto &airplane : company.getFleet()) {

        for (auto &flight : airplane->getFlights()) {

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

        Passenger *newpassenger = new Passenger(id, name, dateOfBirth);
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
            validAirplane(id);
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

    Airplane *newairplane = new Airplane(id, model, capacity);
    company.addAirplane(newairplane);
    cout << "Airplane successfully added\n";
    airplanesChanged = true;
}


void Application::flightCreate(Airplane *airplane) {

    string departure, destination, foo;
    int price, id, duration, time_to_flight;
    Passenger *buyer;
    Flight *flight;

    while (true) {

        cout << "Comercial flight or rented flight? (c/r)\n";
        getline(cin, foo);
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

    cout << "City of departure: ";
    getline(cin, departure);
    normalize(departure);

    cout << "City of arrival: ";
    getline(cin, destination);
    normalize(destination);

    do {
        cout << "Duartion (h): ";
        if (validArg(duration)) break;
    } while (true);

    do {
        cout << "Base price (€): ";
        if (validArg(price)) break;
    } while (true);

    do {
        cout << "Time to flight (h): ";
        if (validArg(time_to_flight)) break;
    } while (true);

    if (foo == "r") {

        printSummaryPassenger();
        cout << "Chose buyer (id): ";
        do {
            try {
                buyer = choosePassenger();
            }
            catch (const InvalidPassenger &i) {
                i.print();
                continue;
            }
            break;

        } while (true);

        flight = new RentedFlight(id, departure, destination, time_to_flight, price, duration, buyer);

    } else
        flight = new ComercialFlight(id, departure, destination, time_to_flight, price, duration);


    try {

        airplane->addFlight(flight);

    } catch (const OverlapingFlight &f) {

        f.print();
        return;
    }

    airplanesChanged = true;
    cout << "Flight added successfully\n";

}


void Application::passengerDelete() {

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
    company.removePassenger(passenger);
    cout << "Passenger deleted sucessfully.\n ";
    passengersChanged = true;

}

void Application::airplaneDelete() {

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
    company.removeAirplane(airplane);
    cout << "Airplane deleted sucessfully.\n ";
    airplanesChanged = true;
    flightsChanged = true;
}

void Application::flightDelete(Airplane *airplane) {

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

    do {
        try {
            airplane->removeFlight(flight);
        }
        catch (const ConnectionFlight &f) {
            f.print();
            continue;
        }
        break;

    } while (true);

    cout << "Flight deleted sucessfully.\n";
    airplanesChanged = true;
    flightsChanged = true;
}

void Application::passengerUpdateMenu() {

    printSummaryPassenger();
    int op;
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

void Application::passengerUpdateName(Passenger *passenger) {

    string newName;
    cout << "The current name for the chosen passenger is '" << passenger->getName() << "'.\n";
    cout << "Insert new name: ";
    getline(cin, newName);
    passenger->setName(newName);
    passengersChanged = true;
    cout << "Passenger name updated successfully.\n";

}

void Application::passengerUpdateDateOfBirth(Passenger *passenger) {

    string newDateOfBirth;
    cout << "The current date of birth for the chosen passenger is '" << passenger->getDateOfBirth() << "'.\n";
    cout << "Insert the new date of birth (DD/MM/YYYY): ";
    getline(cin, newDateOfBirth);
    passenger->setDateOfBirth(newDateOfBirth);
    passengersChanged = true;
    cout << "Passenger date of birth updated successfully.\n";
}


void Application::passengerUpdateJob(Passenger *passenger) {

    Card *card = passenger->getCard();

    string newJob;

    cout << "The current job for the chosen passenger is '" << card->getJob() << "'.\n";
    cout << "Insert the new job: ";
    getline(cin, newJob);
    card->setJob(newJob);
    passengersChanged = true;
    cout << "Passenger job updated successfully.\n";

}

void Application::passengerUpdateNYear(Passenger *passenger) {

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
                airplaneUpdateModel(airplane);
                break;
            case 2:
                airplaneUpdateCapacity(airplane);
                break;

        }

    } while (op != 9);
}

void Application::airplaneUpdateModel(Airplane *airplane) {

    string newModel;
    cout << "The current model for the chosen airplane is '" << airplane->getModel() << "'.\n";
    cout << "Insert new model: ";
    getline(cin, newModel);
    airplane->setModel(newModel);
    airplanesChanged = true;
    cout << "Airplane model updated successfully.\n";

}

void Application::airplaneUpdateCapacity(Airplane *airplane) {

    if (airplane->getFlights().size() != 0) {

        cout
                << "There are assigned seats in at least one flight in this airplane, if you want to change its capacity delete the flight\n";
        return;

    }

    int newcapacity;

    cout << "The current capacity for the chosen airplane is '" << airplane->getCapacity() << "'.\n";
    do {
        cout << "Insert the new capacity : ";
        if (!validArg(newcapacity)) continue;
        else break;

    } while (true);

    airplane->setCapacity(newcapacity);
    airplanesChanged = true;
    cout << "Airplane capacity updated successfully.\n";

}

void Application::flightUpdatePrice(Flight *flight) {

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

void Application::flightUpdateBuyer(Flight *flight) {

    Passenger *passenger = new Passenger;
    cout << "The current buyer for the chosen flight is:\n";
    flight->getBuyer()->print();

    printSummaryPassenger();

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

    flight->setBuyer(passenger);
    flightsChanged = true;
    cout << "Buyer updated successfully\n";
}

void Application::flightDeletePassenger(Flight *flight) {

    PassengerMap::iterator it;
    for (it = flight->getPassengers().begin(); it != flight->getPassengers().end(); it++)
    {
        cout << it->first << " : ";
        it->second->printSummary();
        cout << endl;
    }
    do {
        try {
            it = chooseSeat(flight);
        }
        catch (const InvalidSeat &it) {
            it.print();
            continue;
        }
        break;

    } while (true);
    flight->getPassengers().erase(it);
    cout << "The passenger was removed from the flight\n";
}

void Application::flightAddPassenger(Flight *flight) {

    Passenger * passenger = new Passenger;

    printSummaryPassenger();

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
    
}


void Application::flightUpdateMenu(Airplane *airplane) {

    printSummaryFlight(airplane);
    int op;
    string foo;
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
                    flightUpdatePrice(flight);
                    break;
                case 2:
                    flightUpdateBuyer(flight);
                    break;
            }
        }

        if (foo == "c") {

            cout << "[FLIGHT UPDATE MENU]\n\n";
            cout << "[1]- Change flight price.\n";
            cout << "[2]- Add passenger.\n";
            cout << "[3]- Delete passenger.\n";
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
                    flightUpdatePrice(flight);
                    break;
                case 3:
                    flightAddPassenger(flight);
                    break;
                case 4:
                    flightDeletePassenger(flight);
                    break;
            }
        }
    }while(op != 9);
}


Airplane * Application::readAirplane(string &a){

    Airplane * newAirplane = new Airplane;

    int temp;
    string st;

    try {next(temp, a, ";");} catch(InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
    }

    newAirplane->setId(temp);

    next(st, a, ";");
    newAirplane->setModel(st);

    try {next(temp, a, ";");} catch(InvalidFormat) {
        cout << "Please insert the Airplane data in the correct format.\n";
    }

    newAirplane->setCapacity(temp);

    next(st, a, ";");

    if (st == "no_flights") return newAirplane;

    vector<unsigned int> f;
    while (st != ""){
        int fid;
        try {next(fid, st, ",");} catch(InvalidFormat) {
            cout << "Please insert the Airplane data in the correct format.\n";
        }
        f.push_back((unsigned int)fid);
    }

    vector<Flight *> flights;

    for (auto const &id:f){
        Flight* fp = this->company.flightById(id);
        if (fp != nullptr) flights.push_back(fp);
    }

    newAirplane->setFlights(flights);
    newAirplane->print();

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
        while (st != ""){
            string st1;
            next(st1, st, ",");
            string seat;
            next(seat, st1, "-");
            int elem;
            try {next(elem, st1, "-");} catch(InvalidFormat) {
                cout << "Please insert the Flight data in the correct format.\n";
            }
            Passenger * p = this->company.passengerById((unsigned int)elem);


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
    while (getline(passFile, p)){
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
    while (getline(flFile, f)){
        this->company.addFlight(readFlight(f));
    }
    flFile.close();

}

void Application::loadAirplaneFile() {

    string a;

    if (airplanesFilepath == "") throw InvalidFilePath("empty");

    ifstream airFile(airplanesFilepath);
    if (!airFile) throw InvalidFilePath("fail");
    while (getline(airFile, a)){
        this->company.addAirplane(readAirplane(a));
    }
    airFile.close();

}

