#include "Application.h"
#include "Company.h"
#include "helper.h"

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
                        if (cin >> auxOp && (auxOp == 'Y' || auxOp == 'N')) {
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
                //TODO passengers show
                break;
            case 2:
                //TODO passengers create
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
                //TODO airplanes show
                break;
            case 2:
                //TODO airplanes create
                break;
            case 3:
                //TODO airplanes delete
                break;
            case 4:
                //TODO airplanes update (chamar outro menu)
                break;
            case 5:
                flightsMenu();
                break;
        }

    } while (op != 9);
}

void Application::flightsMenu() {

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
            }
            else {
                cerr << "Invalid option.\n";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (true);

        switch (op) {
            case 1:
                //TODO flights show
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
