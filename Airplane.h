#ifndef AEDA_FEUP_PROJECT_AIRPLANE_H
#define AEDA_FEUP_PROJECT_AIRPLANE_H
#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"

using namespace std;


class Airplane {

private:
	/**
	 * @brief string model of the Airplane
	 */
	string model;
	/**
	 * @brief unsigned int id number of the Airplane
	 */
	unsigned int id;
	/**
	 * @brief int capacity of the Airplane
	 */
	int capacity;
	/**
	 * @brief vector <Flight*> vector with the pointer to the Flights of the Airplane
	 */
	vector < Flight * > flights;

public:
	/**
	 * @brief Default Constructor of an Airplane object
	 */
	Airplane();
	/**
	 * @brief Constructor of an Airplane object with all of its data members
	 * @param id
	 * @param name
	 * @param capacity
	 * @param flights
	 */
	Airplane(unsigned int id, string name, int capacity, vector <Flight *> flights);
	/**
	 * @brief Constructor of an Airplane object with no flights
	 * @param id
	 * @param name
	 * @param capacity
	 */
    Airplane(unsigned int id, string name, int capacity);

	//get Methods
	/**
	 * @brief  Used to get the Model of the Airplane
	 * @return string model of the Airplane
	 */
	string getModel() const;
	/**
	 * @brief Used to get the ID of the Airplane
	 * @return unsigned int ID of the Airplanes
	 */
	unsigned int getId() const;
	/**
	 * @brief Used to get the capacity of the Airplane
	 * @return unsigned int capacity of the Airplane
	 */
	unsigned int getCapacity() const;
	/**
	 * @brief Used to get the vector with the pointers to all the flights of an Airplane
	 * @return vector <Flight *> pointers to the flights of an Airplane
	 */
	vector <Flight *> getFlights() const;

	//set Methods
	/**
	 * @brief Sets the Airplane's model to the one passed as parameter
	 * @param model string model
	 */
	void setModel(string model);
	/**
	 * @brief Sets the Airplane's ID to the one passed as parameter
	 * @param id unsigned int id
	 */
	void setId(unsigned int id);
	/**
	 * @brief Sets the Airplane's capacity to the one passed as parameter
	 * @param model string model
	 */
	void setCapacity(unsigned int capacity);
	/**
	 * @brief Sets the Airplane's flights vector to the one passed as parameter
	 * @param flights vector <Flight *> flights
	 */
	void setFlights(vector <Flight *> flights);
	/**
 	* @brief Prints the id of the Airplane
 	*/
    void printSummary();
	/**
	 * @brief Prints the id, model and capacity of an Airplane object
	 */
    void print();
	/**
	 * @brief overload of the operator == to match Airplane objects
	 * @param a1 const Airplane &a1
	 * @return true upon sucess matching the 2 Airplane objects ids and false otherwise
	 */
	bool operator==(const Airplane &a1);
	/**
	 * @brief Removes the flight pointed by the parameter from the Airplane's data-member flights
	 * @param flight Flight * flight
	 */
    void removeFlight(Flight * flight);

    /**
     * @brief Adds the flight passed as argument
     * @param flight Flight * flight
     */
    void addFlight(Flight * flight);

	friend ostream & operator<<(ostream & o, const Airplane * a);
};

#endif //AEDA_FEUP_PROJECT_AIRPLANE_H
