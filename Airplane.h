#ifndef AEDA_FEUP_PROJECT_AIRPLANE_H
#define AEDA_FEUP_PROJECT_AIRPLANE_H

#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"
#include "exceptions.h"

using namespace std;


class Airplane {

private:
    string model;
    unsigned int id;
    unsigned int capacity;
    vector<Flight *> flights;

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
    Airplane(unsigned int id, string name, unsigned int capacity, vector<Flight *> flights);

    /**
     * @brief Constructor of an Airplane object with no flights
     * @param id
     * @param name
     * @param capacity
     */
    Airplane(unsigned int id, string name, unsigned int capacity);

    /**
     * @brief  Gets the Model of the Airplane
     * @return string model of the Airplane
     */
    string getModel() const;

    /**
     * @brief Gets the ID of the Airplane
     * @return unsigned int ID of the Airplanes
     */
    unsigned int getId() const;

    /**
     * @brief Gets the capacity of the Airplane
     * @return unsigned int capacity of the Airplane
     */
    unsigned int getCapacity() const;

    /**
     * @brief Gets the vector with the pointers to all the flights of an Airplane
     * @return vector <Flight *> pointers to the flights of an Airplane
     */
    vector<Flight *> getFlights() const;

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
     * @param capacity unsigned int capacity
     */
    void setCapacity(unsigned int capacity);

    /**
     * @brief Sets the Airplane's flights vector to the one passed as parameter
     * @param flights vector <Flight *> flights
     */
    void setFlights(vector<Flight *> flights);

    /**
     * @brief Prints the id of the Airplane
     */
    void printSummary() const;

    /**
     * @brief Prints the id, model and capacity of an Airplane object
     */
    void print() const;

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
    void removeFlight(Flight *flight);

    /**
     * @brief Adds the flight passed as argument
     * @param flight Flight * flight
     */
    void addFlight(Flight *flight);

    /**
     * @brief overload of the operator << for obejcts of class Airplane
     * @param o ostream o&
     * @param a Airplane * a
     * @return ostream&
     */
    friend ostream &operator<<(ostream &o, const Airplane *a);
};

/**
 * @brief Compares two objects of class Airplane based on their id
 * @param a1 Airplane * a1
 * @param a2 Airplane * a2
 * @return returns true if a1's id is less than a2's id
 */
bool compAId(Airplane *a1, Airplane *a2);

#endif //AEDA_FEUP_PROJECT_AIRPLANE_H