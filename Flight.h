#ifndef AEDA_FEUP_PROJECT_FLIGHT_H
#define AEDA_FEUP_PROJECT_FLIGHT_H

#include "Passenger.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef std::map<string, Passenger* > PassengerMap;


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
    Flight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration);

    //get Methods
    unsigned int getId() const;
    string getDeparture() const;
    string getDestination() const;
    unsigned int getTime_to_flight() const;
    unsigned int getBasePrice() const;
    unsigned int getDuration() const;
    virtual string getType() const = 0;

    //set Methods
    void setDeparture(string departure);
    void setDestination(string destination);
    void setTime_to_flight(unsigned int time_to_flight);
    void setBasePrice(unsigned int basePrice);
    void setDuration(unsigned int duration);
    void setId(unsigned int id);

    void printSummary();
    virtual void print() = 0;
    virtual Passenger * getBuyer() const = 0;
    virtual PassengerMap & getPassengers() = 0;
    virtual void setBuyer(Passenger * passenger) = 0;
    virtual void setPassengers(PassengerMap passengers) = 0;
    virtual void addPassenger(string seat, Passenger * passenger) = 0;

    bool operator==(const Flight &f);
    bool operator<(const Flight &f);
    friend ostream & operator<<(ostream & o, Flight * f);


};

class RentedFlight : public Flight {

private:
    Passenger * buyer;

public:
    RentedFlight();
    RentedFlight(unsigned int id, string departure, string destination,unsigned  int time_to_flight,unsigned  int basePrice,unsigned  int duration, Passenger *buyer);

    //get Methods
    Passenger * getBuyer() const;
    PassengerMap & getPassengers();
    string getType() const { return "r"; }

    //set Methods
    void setBuyer(Passenger * buyer);
    void setPassengers(PassengerMap passengers);
    void print();
    void addPassenger(string seat, Passenger * passenger) {}

};

class ComercialFlight : public Flight {

private:
    PassengerMap passengers;

public:
    ComercialFlight();
    ComercialFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration);
    ComercialFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration, PassengerMap passengers);

    //get methods
    Passenger * getBuyer() const;
    PassengerMap & getPassengers();
    string getType() const { return "c"; }

    //set methods
    void setBuyer(Passenger * buyer);
    void setPassengers(PassengerMap passengers);
    void addPassenger(string seat, Passenger * passenger);

    void print();
};
#endif //AEDA_FEUP_PROJECT_FLIGHT_H
