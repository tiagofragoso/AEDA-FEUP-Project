#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

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

/**
 * @brief checks if input is valid
 * @param variable
 * @return returns true if input is valid and false otherwise
 */
bool validArg(int &variable);

/**
 * @brief deletes space caracters in the begining and end of the string
 * @param s string
 */
void trimString(string &s);

/**
 * @brief waits for user input
 */
void pause();

/**
 * @brief normalizes string
 * @param s string
 */
void normalize(string &s);

/**
 * @param elem
 * @param piece
 * @param separator
 */
void next(int &elem, string &piece, string separator);

/**
 *
 * @param piece
 * @param line
 * @param separator
 */
void next(string &piece, string &line, string separator);

/**
 * @brief checks if input is valid
 * @param s string
 * @return returns true if input is valid and false otherwise
 */
bool validString(string &s);

#endif /* SRC_HELPER_H_ */