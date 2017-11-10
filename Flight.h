#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Passenger.h"

using namespace std;

#ifndef AEDA_FEUP_PROJECT_FLIGHT_H
#define AEDA_FEUP_PROJECT_FLIGHT_H

class Flight {

private:
    unsigned int id;
    string departure;
    string destination;
    unsigned int time_to_flight;
    unsigned int basePrice;
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

    //set Methods
    void setDeparture(string departure);
    void setDestination(string destination);
    void setTime_to_flight(unsigned int time_to_flight);
    void setBasePrice(unsigned int basePrice);
    void setDuration(unsigned int duration);

    void printSummary();
    virtual void print() = 0;

    bool operator==(const Flight &f);


};

class RentedFlight : public Flight {

private:
    Passenger * buyer;

public:
    RentedFlight(unsigned int id, string departure, string destination,unsigned  int time_to_flight,unsigned  int basePrice,unsigned  int duration, Passenger *buyer);

    //get Methods
    Passenger * getBuyer() const;

    //set Methods
    void setBuyer(Passenger * buyer);

    void print();

};

class ComercialFlight : public Flight {

private:
    map<string, Passenger * > passengers;

public:
    ComercialFlight(unsigned int id, string departure, string destination, unsigned int time_to_flight, unsigned int basePrice, unsigned int duration, map<string, Passenger *> passengers);

    //get methods
    map<string, Passenger * > getPassengers() const;

    //set methods
    void setPassengers(map<string, Passenger * > passengers);

    void print();
};
#endif //AEDA_FEUP_PROJECT_FLIGHT_H
