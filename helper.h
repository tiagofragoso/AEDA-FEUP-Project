#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
/*! enum class used on the listing menu */
enum type {
    PID = 1,       /*!< Passengers by ID */
    PNAME = 2,     /*!< Passengers by name */
    PAGE = 3,      /*!< Passengers by age */
    AID = 4,       /*!< Airplanes by ID */
    ANM = 5,
    APM = 6,
    FID = 7,       /*!< Flights by ID */
    FPRICEL = 8,   /*!< Flights based on Price(lowest to highest) */
    FPRICEH = 9,   /*!< Flights based on Price(highest to lowest) */
    FDEST = 10,     /*!< Flights by Destination city */
    FTIME = 11      /*!< Flights by the time remaining to the time of the flight */
};

struct Date {
    int day;
    int month;
    int year;
    bool operator<(const Date& d1) const
    {
        return std::tie(year, month, day) < std::tie(d1.year, d1.month, d1.day);
    }
    void print() {
        cout << day << "/" << month << "/" << year;
    }
};

/**
 * @brief checks if input is valid
 * @param variable int &variable
 * @return true if input is valid and false otherwise
 */
bool validArg(int &variable);

/**
 * @brief deletes space characters in the begining and end of the string
 * @param s string &s
 */
void trimString(string &s);

/**
 * @brief waits for user input
 */
void pause();

/**
 * @brief normalizes string
 * @param s string &s
 */
void normalize(string &s);

/**
 * @brief separates string based on the separator
 * @param elem int &elem
 * @param piece string &piece
 * @param separator string separator
 */
void next(int &elem, string &piece, string separator);

/**
 * @brief separates string based on the separator
 * @param piece
 * @param line
 * @param separator
 */
void next(string &piece, string &line, string separator);

/**
 * @brief checks if input is valid
 * @param s string &s
 * @return true if input is valid and false otherwise
 */
bool validString(string &s);
void addTime(Date &date, int days);

#endif /* SRC_HELPER_H_ */