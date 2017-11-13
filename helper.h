#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>


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
    Date(string &s);
};
/** @} end of Date Struct */



bool validArg(int &variable);
bool validArg(int &variable, bool &end);
void trimString(string &s);
void pause();
void normalize(string &s);
void next(int &elem, string &piece, string separator);
void next(string &piece, string &line, string separator);


#endif /* SRC_HELPER_H_ */
