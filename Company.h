#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"
#include "Card.h"
#include "Flight.h"
#include "Passenger.h"
#include "helper.h"

using namespace std;

#ifndef AEDA_FEUP_PROJECT_COMPANY_H
#define AEDA_FEUP_PROJECT_COMPANY_H
/**
*	The Company class contains 3 data members:
*   string name
*	vector <Airplane> fleet
*   vector <Passenger*> passengers
*/
class Company {

private:
	string name;  /// Name of the company  
	vector <Airplane> fleet; /// Fleet of the company 
	vector <Passenger*> passengers; /// All the passengers of the company 

public:
    Company();  /// Constructor of an empty company object
	Company(string name, vector <Airplane> fleet, vector <Passenger*> passengers); /// Constructor of a company object with all of its data members
    Company(string name); ///Constructor of a company object only defining its name


	
	//get methods
	/**
	* @brief Used to get the name of a company
	* @return string name of a company
	*/
	string getName() const; 
	/**
	* @brief Gets the fleet of the company
	* @return vector <Airplane> with the Airplanes of the company
	*/
	vector <Airplane> getFleet() const;
	/**
	* @brief Gets a vector of pointers to the passengers of the company
	* @return vector <Passenger*> with the pointers to the Passengers of the company
	*/
	vector <Passenger*> getPassangers() const;

	//set methods
	/**
	* @brief Sets the name of the company to the passed parameter name
	* @param name string name
	*/
	void setName(string name);
	/**
	* @brief Sets the fleet of the company to the passed parameter vector <Airplane> fleet
	* @param fleet vector <Airplane> fleet
	*/
	void setFleet(vector <Airplane> fleet);
	/**
	* @brief Sets the pointers of the Passengers of the company to the passed parameter vector <Passanger*> passengers
	* @param passengers vector <Passenger*> passengers
	*/
	void setPassengers(vector <Passenger*> passengers);

	//Management methods
	//Airplane
	/**
	* @brief Adds the passed parameter airplane to the data member fleet of the company
	* @param airplane Airplane airplane
	*/
	void addAirplane(Airplane airplane);
	/**
	* @brief Removes the Airplane with the index aIndex of the company fleet
	* @param aIndex int aIndex that indicates which Airplane to remove from the data member fleet of the company
	*/
	void removeAirplane(Airplane airplane);
    void setAirplane(Airplane newairplane);



	//Passenger
	void addPassanger(Passenger *passenger);
	void removePassenger(Passenger *passenger);




};

#endif //AEDA_FEUP_PROJECT_COMPANY_H
