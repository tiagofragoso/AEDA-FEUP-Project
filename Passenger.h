#ifndef AEDA_FEUP_PROJECT_PASSENGER_H
#define AEDA_FEUP_PROJECT_PASSENGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "helper.h"

using namespace std;

class Passenger {

private:
	/** @name Passenger data-members*/
	/** @{
    *
    */
	/**
	 * @brief int ID of the Passenger
	 */
	int id;
	/**
	 * @brief string Name of the Passenger
	 */
	string name;
	/**
	 * @brief Date Struct Date of birth of the Passenger
	 */
	string dateOfBirth;
	/** @} end of Passenger data-members */

public:
    Passenger();

	/**
	 * @brief Constructor of a PassengerWithCard object using ID, name, Date of birth, job and the number of Flights per year
	 * @param id
	 * @param name
	 * @param dateOfBirth
	 */
	Passenger(unsigned int id, string name, string dateOfBirth);

	//get Methods
	/**
	 * @brief Gets the ID number of a Passenger
	 * @return unsigned int ID of a Passenger
	 */
	unsigned int getId() const;
	/**
	 * @brief Gets the name of a Passenger
	 * @return string name of a Passenger
	 */
	string getName() const;
	/**
	 * @brief Gets the Date of birth of a Passenger
	 * @return Date Date struct countaining the Date of birth of a Passenger
	 */
	string getDateOfBirth() const;

	//set Methods
	/**
	 * @brief Sets the ID of the Passenger object to the passed parameter
	 * @param id unsigned int id
	 */
	void setId(unsigned int id);
	/**
	 * @brief Sets the name of the Passenger object to the passed parameter
	 * @param name string name
	 */
	void setName(string name);
	/**
	 * @brief Sets the Date of Birth of the Passenger object to the passed parameter
	 * @param dateofBirth Date struct dateofBirth
	 */
	void setDateOfBirth(string dateOfBirth);
	/**
 	* @brief Prints the id  and the name of the Passenger
 	*/
    void printSummary();
	/**
	 * @brief Prints the id, name and the date of birth of a Passenger object
	 */
//TODO: CHECK HOW TO DOCUMENT VIRTUAL FUNCTIONS
    virtual void print();
    virtual string getType();
    virtual Card *  getCard() const;
    virtual void setCard(Card * card);
	/**
	 * @brief overload of the operator == to match Passenger objects
	 * @param p const Passenger &p
	 * @return true upon sucess matching the 2 Passenger objects ids and false otherwise
	 */
	bool operator==(const Passenger &p);
};

class PassengerWithCard: public Passenger {

private:
	/** @name PassengerWithCard data-members*/
	/** @{
    *
    */
	/**
	 * @brief Card pointer to a Card object of a Passenger
	 */
	Card *card;
	/** @} end of PassengerWithCard data-members */

public:

    PassengerWithCard();

	/**
	 * @brief Constructor of a PassengerWithCard object using ID, name, Date of birth and a card object
	 * @param id
	 * @param name
	 * @param dateOfBirth
	 * @param card
	 */
	PassengerWithCard(unsigned int id, string name, string dateOfBirth, Card *card);
	/**
	 * @brief Constructor of a PassengerWithCard object using ID, name, Date of birth, job and the number of Flights per year
	 * @param id
	 * @param name
	 * @param dateOfBirth
	 * @param job
	 * @param nYear
	 */
	PassengerWithCard(unsigned int id, string name, string dateOfBirth, string job, int nYear);


	//get Methods
	/**
	 * @brief Gets the card of a PassengerWithCard object
	 * @return pointer to a Card object
	 */
	Card* getCard() const;

	//Set Methods
	/**
	 * @brief Sets the card of a PassengerWithCard object to the passed parameter
	 * @param *card Card *card
	 */
	void setCard(Card * card);
	/**
 	* @brief Prints the ID, name, Date of birth, job and the average number of flights per year of a PassengerWithCard
 	*/
    void print();
	//TODO: IMPORTANT, CHECK THIS PART WHIS SPOLIS
	/**
	 * @brief Checks if the PassengerWithCard holds a card object
	 * @return string "c" if the Passenger really has a card
	 */
    string getType();

};

#endif //AEDA_FEUP_PROJECT_PASSENGER_H
