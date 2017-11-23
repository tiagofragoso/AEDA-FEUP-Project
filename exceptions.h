#ifndef AEDA_FEUP_PROJECT_EXCEPTIONS_H
#define AEDA_FEUP_PROJECT_EXCEPTIONS_H

#include <string>
using namespace std;

class InvalidFormat {
public:
	/**
	 * @brief default constructor for exception InvalidFormat
	 */
    InvalidFormat();
};

class InvalidFilePath {
private:
    std::string type;

public:
	/**
	 * @brief default constructor for exception InvalidPath
	 */
    InvalidFilePath();
	/**
	 * @brief constructor for exception InvalidPath
	 * @param type file type
	 */
    InvalidFilePath(std::string type);
	/**
	 * @brief prints exception message
	 */
    void print();
};

class InvalidPassenger {

private:
    unsigned int id;

public:
	/**
	 * @brief constructor for exception InvalidPassenger
	 * @param id
	 */
    InvalidPassenger(unsigned int id);
	/**
	 * @brief prints exception message (invalid passenger id)
	 */
    void print() const;
	/**
	 * @brief prints exception message (duplicate passenger id)
	 */
    void printDuplicate() const;

};

class InvalidAirplane {

private:
    unsigned int id;

public:
	/**
	 * @brief constructor for exception InvalidAirplane
	 * @param id
	 */
    InvalidAirplane(unsigned int id);
	/**
	 * @brief prints exception message (invalid airplane id)
	 */
    void print() const;
	/**
	 * @brief prints exception message (duplicate airplane id)
	 */
    void printDuplicate() const;

};

class InvalidFlight {

private:
    unsigned int id;

public:
	/**
	 * @brief constructor for exception InvalidFlight
	 * @param id
	 */
    InvalidFlight(unsigned int id);
	/**
	 * @brief prints exception message (invalid flight id)
	 */
    void print() const;
	/**
	 * @brief prints exception message (duplicate flight id)
	 */
    void printDuplicate() const;

};

class InvalidSeat {

private:
	string seat;

public:
	/**
	 * @brief constructor for exception InvalidSeat
	 * @param seat
	 */
	InvalidSeat(string seat);
	/**
	 * @brief prints exception message (invalid seat)
	 */
	void print() const;
};

class OverlapingFlight {

public:
	/**
	 * @brief constructor for exception OverlapingFlight
	 */
    OverlapingFlight();
	/**
	 * @brief prints exception message (overlaping flight)
	 */
    void print() const;
};

class ConnectionFlight {

public:
	/**
	 * @brief constructor for exception ConnectionFlight
	 */
    ConnectionFlight();
	/**
	 * @brief  prints exception message
	 */
    void print() const ;
};

#endif //AEDA_FEUP_PROJECT_EXCEPTIONS_H
