//
// Created by Mariana on 31/10/2017.
//

#ifndef AEDA_FEUP_PROJECT_APPLICATION_H
#define AEDA_FEUP_PROJECT_APPLICATION_H

#include <iostream>
#include <vector>
#include "Company.h"
#include "helper.h"


using namespace std;

class Application {

private:
    Company company;
    bool passengersChanged;
    bool airplanesChanged;
    bool flightsChanged;
    string passengersFilepath;
    string airplanesFilepath;
    string flightsFilepath;

public:
    Application();

    //menus
    void mainMenu();
    void filesMenu();
    void passengersMenu();
    void airplanesMenu();
    void flightsMenu(Airplane airplane);
    void bookingsMenu();

    //passenger fucntions
    void passengerShow();
    void passengerCreate();
    void passengerDelete();
    void passengerUpdateMenu();
    void printSummaryPassenger();
    Passenger * choosePassenger();
    bool validPassenger(int id);
    void passengerUpdateName(Passenger * passenger);
    void passengerUpdateDateOfBirth(Passenger * passenger);
    void passengerUpdateJob(Passenger * passenger);
    void passengerUpdateNYear(Passenger * passenger);

    //airplane functions
    void airplaneShow();
    void airplaneCreate();
    void airplaneDelete();
    void airplaneUpdateMenu();
    void printSummaryAirplane();
    Airplane chooseAirplane();
    bool validAirplane(int id);
    void airplaneUpdateName(Airplane airplane);
    void airplaneUpdateCapacity(Airplane airplane);


    void flightShow(Airplane airplane);
    void flightCreate(Airplane airplane);
    void flightDelete(Airplane airplane);
    void flightUpdateMenu(Airplane airplane);
    void printSummaryFlight(Airplane airplane);
    Flight * chooseFlight(Airplane airplane);
    void flightUpdateDeparture(Airplane airplane, Flight * flight);
    void flightUpdateDestination(Airplane airplane, Flight * flight);
    void flightUpdateTimeToFlight(Airplane airplane, Flight * flight);
    void flightUpdatePrice(Airplane airplane, Flight * flight);
    void flightUpdateDuration(Airplane airplane, Flight * flight);
    //nao sei se vale a pena
    void flightAddPassenger();
    void flightDeletePassenger();
    void flightUpdateBuyer();


};


#endif //AEDA_FEUP_PROJECT_APPLICATION_H
