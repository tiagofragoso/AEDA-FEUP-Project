#include <iostream>
#include <string>
#include <vector>
#include "Airplane.h"

using namespace std;

#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

bool validArg(int &variable);
bool validArg(int &variable, bool &end);
void trimString(string &s);
void pause();
void normalize(string &s);
Passenger readPassengers(string &p);
Airplane readAirplane(string &a);

#endif /* SRC_HELPER_H_ */
