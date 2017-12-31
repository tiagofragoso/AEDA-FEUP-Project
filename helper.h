#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

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

static vector<int> monthdays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date {
    int day = 0;
    int month = 0;
    int year = 0;
    int hour = 0;
    int minute = 0;
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
    void print() {
        cout << std::right << setfill('0') << setw(2) << to_string(this->day) << "/" << setfill('0') << setw(2)
             << to_string(this->month) << "/" << setfill('0') << setw(4) << to_string(this->year) << resetiosflags(std::ios::showbase) << setfill(' ');
    }
    void printFullDate(){
        cout << std::right << setfill('0') << setw(2) << to_string(this->day) << "/" << setfill('0') << setw(2)
             << to_string(this->month) << "/" << setfill('0') << setw(4) << to_string(this->year) << "-" << setfill('0')
             << setw(2) << to_string(this->hour) << ":" << setfill('0') << setw(2) << to_string(this->minute)
             << resetiosflags(std::ios::showbase) << setfill(' ');

    }
    void printTime(){
        cout << std::right << setfill('0')
                << setw(2) << to_string(this->hour) << ":" << setfill('0') << setw(2) << to_string(this->minute)
                << resetiosflags(std::ios::showbase) << setfill(' ');
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
void addTime(Date &date, int days);

#endif /* SRC_HELPER_H_ */