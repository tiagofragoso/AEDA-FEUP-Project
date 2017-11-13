#ifndef AEDA_FEUP_PROJECT_COMPANY_H
#define AEDA_FEUP_PROJECT_COMPANY_H
/**
* @{
*
* Company class declaration
*/

#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"

using namespace std;

/**
*	The Company class is the one that countains all the passengers, airplanes and flights information
*/
class Company {

private:
	/** @name Company data-members*/
	/** @{ 
	*
	*/

	/**
	* @brief string name of the company object
	*/
	string name;  
	/**
	* @brief vector <Airplane> fleet fleet with all the Airplanes of the company 
	*/
	vector <Airplane> fleet; 
	/**
	* @brief vector with pointers to all the Passengers of the company
	*/
	vector <Passenger*> passengers; 
	/** @} end of Company data-members */



public:

	/**
	 * @brief Constructor of an empty Company object
	 */
    Company();  
	/**
	 * @brief Constructor of a Company object with all of its data members
	 * @param name
	 * @param fleet
	 * @param passengers
	 */
	Company(string name, vector <Airplane> fleet, vector <Passenger*> passengers); 
	/**
	 * @brief Constructor of a Company object only defining its name
	 * @param name
	 */
    Company(string name); 


	
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
	*@brief Adds the passed pointer to a Passenger to the data member passengers
	*@param *passenger Passenger *passenger pointer to the Passenger object to be added
	*/
	void addPassenger(Passenger *passenger);
	/**
	*@brief Removes the Passenger from the data member passengers
	*@param *passenger Passenger *passenger pointer to the Passenger object to be removed
	*/
	void removePassenger(Passenger *passenger);
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
	* @brief Removes the passed Airplane of the company fleet
	* @param airplane Airplane airplane that indicates which Airplane to remove from the data member fleet of the company
	*/
	void removeAirplane(Airplane airplane);
	/**
	* @brief Replaces the Airplane with the same id as the passed Airplane to the one passed 
	* @param newairplane Airplane newairplane it will be included in the data member fleet of the company
	*/
    void setAirplane(Airplane newairplane);

};

#endif //AEDA_FEUP_PROJECT_COMPANY_H
