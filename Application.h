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

    typedef void(Company::*companyFunction)(void);
    typedef void(Application::*appFunction)(void);
    typedef void(Application::*appFunctionType)(type t);
    typedef void(Company::*companyFunctionAirplane)(Airplane * airplane);
    typedef void(Company::*companyFunctionPassenger)(Passenger * passenger);
    typedef void(Company::*companyFunctionFlight)(Flight * flight);

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
    map<string, appFunction> menuMain;
    map<string, appFunction> menuFiles;
    map<string, companyFunction> menuPassengers;
    map<string, companyFunction> menuAirplanes;
    map<string, appFunctionType> menuLists;
    map<string, companyFunctionAirplane> menuFlights;
    map<string, companyFunctionPassenger> menuBookings;
    map<string, companyFunctionAirplane> menuAirplaneUpdate;
    map<string, companyFunctionFlight> menuFlightsUpdate;
    map<string, companyFunctionPassenger> menuPassengersUpdate;


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

    static const string AIRPLANE_IDENTIFIER;
    static const string FLIGHT_IDENTIFIER;
    static const string PASSENGER_IDENTIFIER;

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
    void flightsMenu();
    /**
     * @brief Menu to manage bookings
     */
    void bookingsMenu();
    void listsMenu();
    void setupMenus();
    void passengerUpdateMenu();
    void airplaneUpdateMenu();
    void flightUpdateMenu(Airplane * airplane);
    void printMainMenu();
    void printFilesMenu();
    void printPassengersMenu();
    void printAirplanesMenu();
    void printListsMenu();
    void printFlightsMenu();
    void printBookingsMenu();
    void printAirplaneUpdateMenu(Airplane * airplane);
    void printFlightUpdateMenu(Flight * flight);
    void printPassengerUpdateMenu(Passenger * passenger);

    void printListPassengers(type t);
    void printListAirplane(type t);
    void printListFlights(type t);




    /** @} end of Application Menu member-functions */



    /** @} end of Application using Passengers member-functions */



    //airplane functions


    //file functions
    string inputFilePath(string s);
    Airplane * readAirplane(string &a);
    Passenger * readPassenger(string &p);
    Flight * readFlight(string &f);
    void loadPassengerFile();
    void loadFlightFile();
    void loadAirplaneFile();
    void saveAllFiles();
    void saveChanges();
    void exitMenu();

    template <class T>
    void saveFile(string &path, vector<T>objects){
        ofstream file(path);

        if (!file) throw InvalidFilePath("fail");
        for (size_t i = 0; i < objects.size(); i++) {
            file << objects.at(i);
            if (i != objects.size() - 1) file << endl;
        }
        file.close();
    }
};


#endif //AEDA_FEUP_PROJECT_APPLICATION_H
