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
#include <iomanip>
#include "helper.h"
#include "exceptions.h"
#include "Airplane.h"
#include <cmath>

using namespace std;

/**
*	The Company class is the one that countains all the passengers, airplanes and flights information
*/
class Company {

	typedef void(Company::*Menu)(void);

private:
	/**
	* @brief string name of the company object
	*/
	string name;
	/**
	* @brief vector <Airplane> fleet fleet with all the Airplanes of the company 
	*/
	vector <Airplane*> fleet;
	/**
	* @brief vector with pointers to all the Passengers of the company
	*/
	vector <Passenger*> passengers;
	/**
	 * @brief vector with pointers to all the Flights of the company
	 */
    vector<Flight*> flights;

	/**
* @brief bool passengersChanged is true when Passengers vector has changed and false otherwise
*/
	static bool passengersChanged;
/**
 * @brief bool airplanesChanged is true when Airplanes vector has changed and false otherwise
 */
	static bool airplanesChanged;
/**
 * @brief bool flightsChanged is true when Flights vector has changed and false otherwise
 */
	static bool flightsChanged;


public:

	/**
	 * @brief Default Constructor of a Company object
	 */
    Company();  
	/**
	 * @brief Constructor of a Company object with all of its data members
	 * @param name
	 * @param fleet
	 * @param passengers
	 * @param flights
	 */
	Company(string name, vector <Airplane*> fleet, vector <Passenger*> passengers);
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
	vector <Airplane*> getFleet() const;
	/**
	* @brief Gets a vector of pointers to the passengers of the company
	* @return vector <Passenger*> with the pointers to the Passengers of the company
	*/
	vector <Passenger*> getPassengers() const;
	bool getPassengersChanged() const;
	bool getAirplanesChanged() const;
	bool getFlightsChanged() const;

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
	void setFleet(vector <Airplane*> fleet);
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
	void addAirplane(Airplane *airplane);
	/**
	* @brief Removes the passed Airplane of the company fleet
	* @param airplane Airplane airplane that indicates which Airplane to remove from the data member fleet of the company
	*/
	void removeAirplane(Airplane *airplane);
	/**
	* @brief Replaces the Airplane with the same id as the passed Airplane to the one passed 
	* @param newairplane Airplane newairplane it will be included in the data member fleet of the company
	*/

	void addFlight(Flight * f);

	Flight * flightById(unsigned int id);

    Passenger * passengerById(unsigned int id);

	vector<Flight *> getFlights(){return flights;}

	//Management menus

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


	void airplaneShow();
	void airplaneCreate();
	void airplaneDelete();
	void printSummaryAirplane();
	Airplane * chooseAirplane();
	void validAirplane(int id);
	void airplaneUpdateModel(Airplane * airplane);
	void airplaneUpdateCapacity(Airplane * airplane);

	void showAllTickets(Passenger * passenger);
	void flightShow(Airplane * airplane);
	void flightCreate(Airplane * airplane);
	void flightDelete(Airplane * airplane);

	void printSummaryFlight(Airplane * airplane);
	Flight * chooseFlight(Airplane * airplane);
	void validFlight(int id);
	void flightUpdatePrice(Flight * flight);
	void flightAddPassenger(Flight * flight, Passenger* passenger);
	void flightDeletePassenger(Flight * flight);
	void flightUpdateBuyer(Flight * flight);
	PassengerMap::iterator chooseSeat(Flight *flight);
	string chooseSeat(vector<string> seats);
	Passenger * newCustomer();
	vector<string> availableSeats(Flight * flight, unsigned int capacity);
	void printSeats(unsigned int capacity, vector<string> seats);
	void returnTicket(Passenger *p);
	vector< pair<string, Flight*> > getTickets(Passenger *p);
	void bookFlight(Passenger *p);
	void bookFlightWithType(Passenger *p, string type);
	void printAllFlightsWithType( Passenger *p , string type);
	Flight* chooseFlight(unsigned int id, string type);
	float ticketPrice(Passenger *p, Flight *f, string type);
    vector<Flight *> getFlightsWithType(string type);

};

#endif //AEDA_FEUP_PROJECT_COMPANY_H
