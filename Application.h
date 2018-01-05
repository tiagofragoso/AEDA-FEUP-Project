#ifndef AEDA_FEUP_PROJECT_APPLICATION_H
#define AEDA_FEUP_PROJECT_APPLICATION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include "helper.h"
#include "Company.h"


using namespace std;

class Application {

    typedef void(Company::*companyFunction)();

    typedef void(Application::*appFunction)();

    typedef void(Application::*appFunctionType)(type t);

    typedef void(Application::*appFunctionDate)(date_member_t date_member);

    typedef void(Company::*companyFunctionAirplane)(Airplane *airplane);

    typedef void(Company::*companyFunctionPassenger)(Passenger *passenger);

    typedef void(Company::*companyFunctionTechnician) (Technician *technician);



private:
    Company company;
    string passengersFilepath;
    string airplanesFilepath;
    string flightsFilepath;
    string techniciansFilepath;
    map<string, appFunction> menuMain;
    map<string, appFunction> menuFiles;
    map<string, companyFunction> menuPassengers;
    map<string, companyFunction> menuAirplanes;
    map<string, appFunctionType> menuLists;
    map<string, companyFunctionAirplane> menuFlights;
    map<string, companyFunctionPassenger> menuBookings;
    map<string, companyFunctionAirplane> menuAirplaneUpdate;
    map<string, companyFunctionPassenger> menuPassengersUpdate;
    map<string, companyFunction> menuMaintenance;
    map<string, companyFunction> menuTechnicians;
    map<string, companyFunctionTechnician> menuTechnicianUpdate;
    map<string, appFunctionDate> menuTime;

public:
    static Date currentDate;
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

    /**
     * @brief main Menu
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
     * @brief Menu to manage flights
     */
    void flightsMenu();
    /**
     * @brief Menu to manage Technicians
     */
    void techniciansMenu();
    /**
     * @brief Menu to update a certain Technician
     */
    void technicianUpdateMenu();

    /**
     * @brief Menu to manage bookings
     */
    void bookingsMenu();
    /**
     * @brief Menu to manage Maintenances
     */
    void maintenanceMenu();
    /**
     * @brief Menu to manage time
     */
    void timeMenu();

    /**
    * @brief Menu to manage Lists (sorted information)
    */
    void listsMenu();

    /**
    * @brief Manages the menus and sets them up calling the functions
    */
    void setupMenus();

    /**
    * @brief Menu that allows the user to chose what he wants to update in a specific passenger
    */
    void passengerUpdateMenu();

    /**
    * @brief Menu that allows the user to chose what he wants to update in a specific Airplane
    */
    void airplaneUpdateMenu();

    /**
    * @brief Prints the Main menu
    */
    void printMainMenu() const;

    /**
    * @brief Prints the Files management menu
    */
    void printFilesMenu() const;

    /**
    * @brief Prints the Passenger management menu
    */
    void printPassengersMenu() const;

    /**
    * @brief Prints the Airplanes management menu
    */
    void printAirplanesMenu() const;
    /**
     * @brief Prints Technicians Menu
     */
    void printTechniciansMenu() const;
    /**
     * @brief Prints the menu that allows the user to update a certain Technician passed as paramter
     * @param technician
     */
    void printTechniciansUpdateMenu(Technician * technician) const;

    /**
    * @brief Prints the Sorted Listing menu
    */
    void printListsMenu() const;

    /**
    * @brief Prints the Flights management menu
    */
    void printFlightsMenu() const;

    /**
    * @brief Prints the Booking menu
    */
    void printBookingsMenu() const;
    /**
     * @brief Prints the Maintenances menu
     */
    void printMaintenanceMenu() const;
    /**
     * @brief Prints the Time menu
     */
    void printTimeMenu() const;

    /**
    * @brief Prints the Menu that displays the options for updating the Airplane passed as argument
    * @param airplane Airplane * airplane
    */
    void printAirplaneUpdateMenu(Airplane *airplane) const;

    /**
    * @brief Prints the Menu that displays the options for updating the Passenger passed as argument
    * @param passenger Passenger* passenger
    */
    void printPassengerUpdateMenu(Passenger *passenger) const;

    /**
    * @brief Prints the sorted list of Passenger depending on the type t chosen(id, age, etc)
    * @param t struct type t
    */
    void printListPassengers(type t);

    /**
    * @brief Prints the sorted list of Airplanes depending on the type t chosen
    * @param t struct type t
    */
    void printListAirplane(type t);

    /**
    * @brief Prints the sorted list Flight depending on the type t chosen
    * @param t struct type t
    */
    void printListFlights(type t);

    /** @} end of Application Menu member-functions */

    /** @name Application File management member-functions*/
    /** @{
    *
    */
    /**
    * @brief Returns a string that is the filename with the information of s type (passenger,airplane,flight)
    * @param s string s
    * @return string
    *
    */
    string inputFilePath(string s);

    /**
    * @brief Reads and analyzes the string s taken of the airplane file and returns a pointer to an Airplane object created with the information collected
    * @ param a string &a
    * @return Airplane *
    */
    Airplane *readAirplane(string &a);

    /**
    * @brief Reads and analyzes the string p taken of the passenger file and returns a pointer to an Passenger object created with the information collected
    * @ param p string &p
    * @return Passenger *
    */
    Passenger *readPassenger(string &p);

    /**
    * @brief Reads and analyzes the string f taken of the flights file and returns a pointer to an Flight object created with the information collected
    * @ param f string &f
    * @return Flight *
    */
    Flight *readFlight(string &f);

    /**
    *@brief Loads all the lines from a flight file if the filepath is correct
    */
    void loadFlightFile();

    /**
    *@brief Loads all the lines from a airplane file if the filepath is correct
    */
    void loadAirplaneFile();

    /**
    *@brief Loads all the lines from a passenger file if the filepath is correct
    */
    void loadPassengerFile();
    /**
    *@ brief Saves all the changes made in the execution of the program to the files
    */
    void saveAllFiles();
    /**
     * @brief Saves the fleet on the airplane File
     * @param path
     * @param fleet
     */
    void saveFile(string &path, AirplanesSet fleet);
    /**
     * @brief Saves the technicians info in the techs file
     * @param path
     * @param techs
     */
	void saveFile(string &path, techniciansPriorityQueue techs);

    /**
    *@ brief Manages saving of the changes in a file, informing the user if changes were made
    */
    void saveChanges();

    /**
    *@ brief Exits the menu in which the user is currently on
    */
    void exitMenu();

    /**
    @brief template function that saves the class T object in the file
    */
    template<class T>
    void saveFile(string &path, vector<T> objects) {
        ofstream file(path);

        if (!file) throw InvalidFilePath("fail");
        for (size_t i = 0; i < objects.size(); i++) {
            file << objects.at(i);
            if (i != objects.size() - 1) file << endl;
        }
        file.close();
    }

    /** @} end of Application Menu member-functions */

	//2 projeto

    /**
     * @brief Analyzes a string p that represents a technician from a file and creates a Technician * from it
     * @param p string &p
     * @return Technician *
     */
	Technician* readTechnician(string &p);
    /**
     * @brief Load the Technician file to get the data to the program
     */
    void loadTechnicianFile();
    /**
     * @brief Function to manage system's dynamic time
     * @param d Date d
     */
    static void advanceTime(Date d);
    /**
     * @brief Helper function that resets the changed Flags
     */
    void resetFlags();
    /**
     * @brief Function that manages the time in the program
     * @param date_member date_member_t date_member
     */
    void manageTime(date_member_t date_member);

};


#endif //AEDA_FEUP_PROJECT_APPLICATION_H