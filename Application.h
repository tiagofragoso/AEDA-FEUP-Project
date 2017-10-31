//
// Created by Mariana on 31/10/2017.
//

#ifndef AEDA_FEUP_PROJECT_APPLICATION_H
#define AEDA_FEUP_PROJECT_APPLICATION_H

#include <iostream>
#include <vector>
#include "helper.h"
#include "Company.h"

using namespace std;

class Application {

private:
    Company company;
    bool passengersChanged;
    bool airplanesChanged;
    string passengersFilepath;
    string airplanesFilepath;

public:
    Application();
    void mainMenu();
    void filesMenu();
    void passengersMenu();
    void airplanesMenu();
    void flightsMenu();
    void bookingsMenu();
};


#endif //AEDA_FEUP_PROJECT_APPLICATION_H
