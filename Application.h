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
#include "Company.h"



using namespace std;

class Application {

private:
    /**
     * @brief Company company
     */
    Company company;
    /**
     * @brief bool passengersChanged is true when Passengers vector has changed and false otherwise
     */
    bool passengersChanged;
    /**
     * @brief bool airplanesChanged is true when Airplanes vector has changed and false otherwise
     */
    bool airplanesChanged;
    /**
     * @brief bool flightsChanged is true when Flights vector has changed and false otherwise
     */
    bool flightsChanged;
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
     * @brief Constructor of an "empty" Application object
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

    /** @} end of Application Menu member-functions */

//passenger functions
/** @name Application using Passengers member-functions*/
    /** @{
    *
    */

    /**
    * @brief Prints the total information of a desired Passenger
    */
    void passengerShow();
    /**
     * @brief Creates a new Passenger and adds it to the Company vector passengers after validating the information
     */
    void passengerCreate();
    /**
     * @brief Deletes the pretended Passenger from the Company vector containing the passengers
     */
    void passengerDelete();
    /**
     * @brief Selects a menu that allows the user to Update information relative to a Passenger (name, date of birth, job and average number of flights per year)
     */
    void passengerUpdateMenu();
    /**
     * @brief Prints a summary of a Passenger object
     */
    void printSummaryPassenger();
    /**
     * @brief Searches the passengers vector for the id inserted by the user and returns the pretended Passenger
     * @return Passenger*
     */
    Passenger * choosePassenger();
    /**
     * @brief Checks if the id is in the vector of passengers, if it is an exception is thrown
     * @param id int id
     */
    void validPassenger(int id);
    /**
     * @brief Updates the name of the passenger passed as parameter to the one inserted by the user
     * @param *passenger Passenger *passenger
     */
    void passengerUpdateName(Passenger * passenger);
    /**
     * @brief Updates the date of birth of the passenger passed as parameter to the one inserted by the user
     * @param *passenger Passenger *passenger
     */
    void passengerUpdateDateOfBirth(Passenger * passenger);
    /**
     * @brief Updates the job of the passenger passed as parameter to the one inserted by the user
     * @param *passenger Passenger *passenger
     */
    void passengerUpdateJob(Passenger * passenger);
    /**
     * @brief Updates the average number of flights per year of the passenger passed as parameter to the one inserted by the user
     * @param *passenger Passenger *passenger
     */
    void passengerUpdateNYear(Passenger * passenger);

    /** @} end of Application using Passengers member-functions */

    

    //airplane functions
    void airplaneShow();
    void airplaneCreate();
    void airplaneDelete();
    void airplaneUpdateMenu();
    void printSummaryAirplane();
    Airplane * chooseAirplane();
    void validAirplane(int id);
    void airplaneUpdateModel(Airplane * airplane);
    void airplaneUpdateCapacity(Airplane * airplane);

	void showAllFlights(Passenger *p);
    void flightShow(Airplane * airplane);
    void flightCreate(Airplane * airplane);
    void flightDelete(Airplane * airplane);
    void flightUpdateMenu(Airplane * airplane);
    void printSummaryFlight(Airplane * airplane);
    Flight * chooseFlight(Airplane * airplane);
    void validFlight(int id);
    void flightUpdatePrice(Flight * flight);
    void flightAddPassenger(Flight * flight);
    void flightDeletePassenger(Flight * flight);
    void flightUpdateBuyer(Flight * flight);
	PassengerMap::iterator chooseSeat(Flight *flight);
	Passenger * newCustomer();

    //file functions
    string inputFilePath(string s);
    Airplane * readAirplane(string &a);
    Passenger * readPassenger(string &p);
    Flight * readFlight(string &f);
    void loadPassengerFile();
    void loadFlightFile();
    void loadAirplaneFile();
    void saveFiles();


};


#endif //AEDA_FEUP_PROJECT_APPLICATION_H
