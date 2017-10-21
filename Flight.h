//
// Created by Tiago Fragoso on 17/10/2017.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef AEDA_FEUP_PROJECT_FLIGHT_H
#define AEDA_FEUP_PROJECT_FLIGHT_H

class Flight {

private:
	string departure;
	string destination;
	int time_to_flight;
	int basePrice;
	int duration;

public:
	Flight(string departure, string destination, int time_to_flight, int basePrice, int duration);

	//get Methods
	string getDeparture();
	string getDestination();
	int getTime_to_flight();
	int getBasePrice();
	int getDuration();

	//set Methods
	void setDeparture(string departure);
	void setDestination(string destination);
	void setTime_to_flight(int time_to_flight);
	void setBasePrice(int basePrice);
	void setDuration(int duration);







};

class RentedFlight : public Flight {




};
#endif //AEDA_FEUP_PROJECT_FLIGHT_H
