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
    FID = 5,       /*!< Flights by ID */
    FPRICEL = 6,   /*!< Flights based on Price(lowest to highest) */
    FPRICEH = 7,   /*!< Flights based on Price(highest to lowest) */
    FDEST = 8,     /*!< Flights by Destination city */
    FTIME = 9      /*!< Flights by the time remaining to the time of the flight */
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

#endif /* SRC_HELPER_H_ */