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
    FID = 5,
    FPRICEL = 6,
    FPRICEH = 7,
    FDEST = 8,
    FTIME = 9
};

struct Date {
    unsigned int day = 0;
    unsigned int month = 0;
    unsigned int year = 0;

    string print();

    Date();

    Date(string &s);
};

/** @} end of Date Struct */

template<class T>
struct less : binary_function<T, T, bool> {
    bool operator()(const T &x, const T &y) const {
        if (x.length() < y.length()) {
            return true;
        } else if (x.length() > y.length()) {
            return false;
        } else return (x < y);
    }
};


bool validArg(int &variable);

bool validArg(int &variable, bool &end);

void trimString(string &s);

void pause();

void normalize(string &s);

void next(int &elem, string &piece, string separator);

void next(string &piece, string &line, string separator);

template<class T>
T binary_search_ptr(const vector<T> &v, T x, bool comp(T t1, T t2)) {
    int left = 0, right = v.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (comp(v[middle], x)) left = middle + 1;
        else if (comp(x, v[middle])) right = middle - 1;
        else return v[middle];
    }
    return nullptr;
}


#endif /* SRC_HELPER_H_ */
