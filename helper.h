#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <sstream>

using namespace std;
/*! enum class used on the listing menu */
enum type {
    PID = 1,       /*!< Passengers by ID */
    PNAME = 2,     /*!< Passengers by name */
    PAGE = 3,      /*!< Passengers by age */
    PACT = 4,      /*!< Active Passengers*/
    PINC = 5,      /*!< Active Passengers*/
    AID = 6,       /*!< Airplanes by ID */
    FID = 7,       /*!< Flights by ID */
    FPRICEL = 8,   /*!< Flights based on Price(lowest to highest) */
    FPRICEH = 9,   /*!< Flights based on Price(highest to lowest) */
    FDEST = 10,     /*!< Flights by Destination city */
    FTIME = 11      /*!< Flights by the time remaining to the time of the flight */
};

enum date_member_t {
    YEAR = 1,
    MONTH = 2,
    DAY = 3,
    HOUR = 4,
    MINUTE = 5
};

static vector<int> monthdays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
    int hour = 0;
    int minute = 0;
    Date(){};
    Date(int y, int mo, int d, int h, int mn): year(y), month(mo), day(d), hour(h), minute(mn){}
    bool operator<(const Date& d1) const
    {
        return std::tie(year, month, day, hour, minute) < std::tie(d1.year, d1.month, d1.day, hour, minute);
    }
    bool operator==(const Date& d1) const
    {
        return std::tie(year, month, day, hour, minute) == std::tie(d1.year, d1.month, d1.day, hour, minute);
    }
    bool operator>(const Date& d1) const
    {
        return std::tie(year, month, day, hour, minute) > std::tie(d1.year, d1.month, d1.day, hour, minute);
    }
    Date & operator+(const Date & d1){
        Date * d = new Date;
        d->year = this->year + d1.year;
        d->month = this->month + d1.month;
        d->day = this->day + d1.day;
        d->hour = this->hour + d1.hour;
        d->minute = this->minute + d1.minute;
        d->normalize();
        return *d;
    }
    Date & operator-(const Date & d1){
        int m = this->convertToMinutes() - d1.convertToMinutes();
        Date * d = new Date;
        d->minute = abs(m);
        d->normalize();
        return *d;

    }
    Date & operator=(const Date & d1){
        this->year = d1.year;
        this->month = d1.month;
        this->day = d1.day;
        this->hour = d1.hour;
        this->minute = d1.minute;
        this->normalize();
        return *this;
    }
    string print() const{
        stringstream s;
        s << std::right << setfill('0') << setw(2) << to_string(this->day) << "/" << setfill('0') << setw(2)
             << to_string(this->month) << "/" << setfill('0') << setw(4) << to_string(this->year) << resetiosflags(std::ios::showbase) << setfill(' ');
        return s.str();
    }
    string printFullDate() const{
        stringstream s;
        s << std::right << setfill('0') << setw(2) << to_string(this->day) << "/" << setfill('0') << setw(2)
             << to_string(this->month) << "/" << setfill('0') << setw(4) << to_string(this->year) << "-" << setfill('0')
             << setw(2) << to_string(this->hour) << ":" << setfill('0') << setw(2) << to_string(this->minute)
             << resetiosflags(std::ios::showbase) << setfill(' ');
        return s.str();

    }
    string printTime() const{
        stringstream s;
        cout << std::right << setfill('0')
                << setw(2) << to_string(this->hour) << ":" << setfill('0') << setw(2) << to_string(this->minute)
                << resetiosflags(std::ios::showbase) << setfill(' ');
        return s.str();
    }
    void normalize();
    int convertToMinutes() const;
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

bool validFullDate(Date &date);
bool validTime(Date &date);
#endif /* SRC_HELPER_H_ */