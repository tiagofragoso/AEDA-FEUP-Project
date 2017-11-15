#ifndef AEDA_FEUP_PROJECT_FLIGHT_H
#define AEDA_FEUP_PROJECT_FLIGHT_H

#include "Passenger.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef std::map<string, Passenger*, std::less<string> > PassengerMap;


class Flight {

private:
    /**
     * @brief unsigned int id of the Flight
     */
    unsigned int id;
    /**
     * @brief string departure location
     */
    string departure;
    /**
     * @brief string destination location
     */
    string destination;
    /**
     * @brief unsigned int time_to_flight time until the Flight takes off
     */
    unsigned int time_to_flight;
    /**
     * @brief unsigned int basePrice of the Flight object
     */
    unsigned int basePrice;
    /**
     * @brief unsigned int duration of the Flight
     */
    unsigned int duration;

public:
	/**
	 * @brief Constructor of a Flight object with all of its data members
	 * @param id
	 * @param departure
	 * @param destination
	 * @param time_to_flight
	 * @param basePrice
	 * @param duration
	 */
    Flight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration);

    //get Methods
    /**
     * @brief Gets the ID of the Flight object
     * @return unsigned int id of the Flight
     */
    unsigned int getId() const;
    /**
     * @brief Gets the departure location of the Flight object
     * @return string departure location of the Flight
     */
    string getDeparture() const;
    /**
     * @brief Gets the destination location of the Flight object
     * @return string destination location of the Flight
     */
    string getDestination() const;
    /**
     * @brief Gets the time remaining until the Flight object
     * @return unsigned int time_to_flight
     */
    unsigned int getTime_to_flight() const;
    /**
     * @brief Gets the base price of the Flight object
     * @return  unsigned int base price of the Flight
     */
    unsigned int getBasePrice() const;
    /**
     * @brief Gets the duration of the Flight object
     * @return unsigned int duration of the Flight
     */
    unsigned int getDuration() const;
    /**
     * @brief Purely Virtual function that gets the type of the Flight, "c" if commercial and "r" if rented
     * @return string
     */
    virtual string getType() const = 0;

    //set Methods
    /**
     * @brief Sets the departure of the Flight to the one passed as parameter
     * @param departure string departure
     */
    void setDeparture(string departure);
    /**
     * @brief Sets the destination of the Flight to the one passed as parameter
     * @param destination string destination
     */
    void setDestination(string destination);
    /**
     * @brief Sets the time_to_flight of the Flight to the one passed as parameter
     * @param time_to_flight unsigned int time_to_flight
     */
    void setTime_to_flight(unsigned int time_to_flight);
    /**
     * @brief Sets the basePrice of the Flight to the one passed as parameter
     * @param basePrice unsigned int basePrice
     */
    void setBasePrice(unsigned int basePrice);
    /**
     * @brief Sets the duration of the Flight to the one passed as parameter
     * @param duration unsigned int duration
     */
    void setDuration(unsigned int duration);
    /**
     * @brief Sets the ID of the Flight to the one passed as parameter
     * @param id  unsigned int id
     */
    void setId(unsigned int id);

    /**
     * @brief Prints a summary of a Flight object
     */
    void printSummary();
    /**
     * @brief Purely virtual function used in both of the subclasses
     */
    virtual void print() = 0;
    /**
     * @brief Purely virtual function redefined in the Rented Flight subclass
     * @return Passenger* Pointer to a Passenger object
     */
    virtual Passenger * getBuyer() const = 0;
    /**
     * @brief Purely virtual function redefined in the Commercial Flight subclass
     * @return PassengerMap & (reference to a PassengerMap)
     */
    virtual PassengerMap & getPassengers() = 0;
    /**
     * @brief Purely virtual function redefined in the Rented Flight subclass
     * @param passenger Passenger* passenger
     */
    virtual void setBuyer(Passenger * passenger) = 0;
    /**
     * @brief Purely virtual function redefined in the Commercial Flight subclass
     * @param passengers  PassengerMap passengers
     */
    virtual void setPassengers(PassengerMap passengers) = 0;
    /**
     * @brief Purely virtual function redefined in the Commercial Flight subclass
     * @param seat
     * @param passenger
     */
    virtual void addPassenger(string seat, Passenger * passenger) = 0;
/** @name Flight functions to overload operators*/
    /** @{
    *
    */
    /**
     * @brief Overload of the operator == for the Flight Class. It allows comparing 2 Flight objects to see if they are the same(by ID)
     * @param f Flight &f
     * @return true upon sucess comparing if the Flight objects are the same or false otherwise
     */
    bool operator==(const Flight &f);
    /**
     * @brief Overload of the operator < for the Flight Class. It allows comparing 2 Flight objects by time_to_flight
     * @param f Flight &f
     * @return true if the Flight's time_to_flight is smaller than the passed parameter's time_to_flight and false otherwise
     */
    bool operator<(const Flight &f);
    /**
     * @brief Overload of the operator << for the Flight Class. It allows sending the Flight object to the stream on the file's format
     * @param o ostream &o
     * @param f  Flight *f
     * @return
     */
    friend ostream & operator<<(ostream & o, Flight * f);
    /** @} end of Flight functions to overload operators */
};

class RentedFlight : public Flight {

private:
    /**
     * @brief Pointer to the Passenger object that is the buyer of the RentedFlight
     */
    Passenger * buyer;

public:
    /**
     * @brief Default constructor of a Rented Flight object
     */
    RentedFlight();
    /**
     * @brief Constructor of a RentedFlight object with all the data-members of the superclass plus the data-member of the subclass Rented Flight
     * @param id
     * @param departure
     * @param destination
     * @param time_to_flight
     * @param basePrice
     * @param duration
     * @param buyer
     */
    RentedFlight(unsigned int id, string departure, string destination,unsigned  int time_to_flight,unsigned  int basePrice,unsigned  int duration, Passenger *buyer);

    //get Methods
    /**
     * @brief Gets a pointer to the buyer of the RentedFlight
     * @return Passenger* pointer to a Passenger object
     */
    Passenger * getBuyer() const;
    /**
     * @brief Inherited from the superclass to be used in CommercialFlight
     * @return PassengerMap& (reference to a PassengerMap)
     */
    PassengerMap & getPassengers();
    /**
     * @brief Used to know if a Flight object is Rented or Commercial
     * @return "r" string "r"
     */
    string getType() const { return "r"; }

    //set Methods
    /**
     * @brief Sets the buyer of a RentedFlight to the one passed as a parameter
     * @param buyer  Passenger* buyer
     */
    void setBuyer(Passenger * buyer);

   /**
    * @brief Inherited from the superclass to be used in CommercialFlight
    * @param passengers PassengerMap passengers
    */
    void setPassengers(PassengerMap passengers);
    /**
     * @brief Prints the Information of the RentedFlight. Data-members inherited from the Flight class and the buyer from this one
     */
    void print();
    /**
     * @brief Inherited from the superclass to be used in CommercialFlight
     * @param seat
     * @param passenger
     */
    void addPassenger(string seat, Passenger * passenger) {}

};

class ComercialFlight : public Flight {

private:
    /**
     * @brief passengers PassengerMap with all the Passengers in the Flight
     */
    PassengerMap passengers;

public:
    /**
     * @brief Default Constructor of a CommercialFlight object
     */
    ComercialFlight();
    /**
     * @brief Constructor of a CommercialFlight object with the Data-members of the superclass
     * @param id
     * @param departure
     * @param destination
     * @param time_to_flight
     * @param basePrice
     * @param duration
     */
    ComercialFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration);
    /**
     * @brief Constructor of a CommercialFlight object with the Data-members inherited from the superclass plus the PassengerMap from this CommercialFlight class
     * @param id
     * @param departure
     * @param destination
     * @param time_to_flight
     * @param basePrice
     * @param duration
     * @param passengers
     */
    ComercialFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration, PassengerMap passengers);

    //get methods
    /**
     * @brief Inherited from the superclass used in RentedFlight
     * @return Passenger*
     */
    Passenger * getBuyer() const;
    /**
     * @ Gets the PassengerMap(map with the seats and the passengers) of a CommercialFlight
     * @return PassengerMap PassengerMap&
     */
    PassengerMap & getPassengers();
    /**
      * @brief Used to know if a Flight object is Rented or Commercial
      * @return "c" string "c"
      */
    string getType() const { return "c"; }
    //set methods
    /**
    * @brief Inherited from the super class used in RentedFlight class
    * @param buyer Passenger *buyer
    */
    void setBuyer(Passenger * buyer);
    /**
     * @brief Sets the PassengersMap data member of a Commercial Flight to the map passed as parameter
     * @param passengers  PassengerMap passengers
     */
    void setPassengers(PassengerMap passengers);
    /**
     * @brief Adds the passenger passed as parameter to the map on seat passed as parameter
     * @param seat
     * @param passenger
     */
    void addPassenger(string seat, Passenger * passenger);
    /**
     * @brief Prints the Information of the RentedFlight. Data-members inherited from the Flight class and the passengers from the PassengerMap
     */
    void print();
};
#endif //AEDA_FEUP_PROJECT_FLIGHT_H
