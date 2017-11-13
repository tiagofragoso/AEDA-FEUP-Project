#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Passenger.h"
#include "Airplane.h"
using namespace std;
/** @name Date Struct*/
/** @{
 *
 * Struct that saves the information about a Passenger year, month and day of birth
 */
struct Date{
    unsigned int day = 0;
    unsigned int month = 0;
    unsigned int year = 0;

    string print();
    Date();
    Date(string s);
};
/** @} end of Date Struct */

typedef std::map<string, Passenger* > PassengerMap;

bool validArg(int &variable);
bool validArg(int &variable, bool &end);
void trimString(string &s);
void pause();
void normalize(string &s);
Passenger readPassengers(string &p);
Airplane readAirplane(string &a);
//lolada

#endif /* SRC_HELPER_H_ */
