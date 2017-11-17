//
// Created by Mariana on 31/10/2017.
//

#ifndef AEDA_FEUP_PROJECT_APPLICATION_H
#define AEDA_FEUP_PROJECT_APPLICATION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include "Company.h"



using namespace std;

class Application {

    typedef void(Company::*Menu)(void);

private:
    /**
     * @brief Company company
     */
    Company company;

    /**
     * @brief string passengersFilepath is the name of the file containing the Passengers information
     */
    string passengersFilepath;
    /**
    * @brief string airplanesFilepath is the name of the file containing the Airplanes information
    */
    string airplanesFilepath;
    /**
    * @brief string flightsFilepath is the name of the file containing the Flights information
    */
    string flightsFilepath;

public:
    /**
     * @brief Default constructor of an Application object
     */
    Application();

    /** @name Application Menu member-functions*/
    /** @{
    *
    */

    /**
     * @brief Main menu with the following options: File, Passenger, Airplane management, Booking and quit
     */
    void mainMenu();
    /**
     * @brief Menu that allows the user to manage the files
     */
    void filesMenu();
    /**
     * @brief Menu to manage Passengers
     */
    void passengersMenu();
    /**
     * @brief Menu to manage Airplanes
     */
    void airplanesMenu();
    /**
     * @brief Menu to manage the Flights of a certain Airplane passed as parameter with a pointer
     * @param *airplane Airplane *airplane
     */
    void flightsMenu(Airplane *airplane);
    /**
     * @brief Menu to manage bookings
     */
    void bookingsMenu();
    void listsMenu();

    void printListPassengers(vector<Passenger *> passengers, type t);
    void printListAirplane(vector<Airplane *> airplanes, type t);
    void printListFlights(vector<Flight *> flights, type t);




    /** @} end of Application Menu member-functions */

//passenger functions
/** @name Application using Passengers member-functions*/
    /** @{
    *
    */

    /**
     * @brief Selects a menu that allows the user to Update information relative to a Passenger (name, date of birth, job and average number of flights per year)
     */
    void passengerUpdateMenu();

    /** @} end of Application using Passengers member-functions */



    //airplane functions

    void airplaneUpdateMenu();



    void flightUpdateMenu(Airplane * airplane);

    //file functions
    string inputFilePath(string s);
    Airplane * readAirplane(string &a);
    Passenger * readPassenger(string &p);
    Flight * readFlight(string &f);
    void loadPassengerFile();
    void loadFlightFile();
    void loadAirplaneFile();
    void saveAirplaneFile();
    void saveFlightFile();
    void savePassengerFile();
    void saveAllFiles();


};


#endif //AEDA_FEUP_PROJECT_APPLICATION_H
