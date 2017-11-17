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

enum type {
    PID = 1,
    PNAME = 2,
    PAGE = 3,
    AID = 4,
    ACAP = 5,
    FID = 6,
    FPRICEL = 7,
    FPRICEH = 8,
    FDEST = 9,
    FTIME = 10
};

struct Date{
    unsigned int day = 0;
    unsigned int month = 0;
    unsigned int year = 0;

    string print();
    Date();
    Date(string &s);
};
/** @} end of Date Struct */

template <class T> struct less : binary_function <T,T,bool> {
    bool operator() (const T& x, const T& y) const {
        if( x.length() < y.length()) {
            return true;
        } else if (x.length() > y.length()) {
            return false;
        }else return (x < y);
    }
};



bool validArg(int &variable);
bool validArg(int &variable, bool &end);
void trimString(string &s);
void pause();
void normalize(string &s);
void next(int &elem, string &piece, string separator);
void next(string &piece, string &line, string separator);




#endif /* SRC_HELPER_H_ */
