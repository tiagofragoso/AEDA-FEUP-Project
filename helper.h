#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"

using namespace std;

struct Date{
    unsigned int day;
    unsigned int month;
    unsigned int year;

    string print();

    Date(string s);

};

typedef map<string, Passenger * > PassengerMap;

bool validArg(int &variable);
bool validArg(int &variable, bool &end);
void trimString(string &s);
void pause();
void normalize(string &s);
Passenger readPassengers(string &p);
Airplane readAirplane(string &a);
//lolada

#endif /* SRC_HELPER_H_ */
