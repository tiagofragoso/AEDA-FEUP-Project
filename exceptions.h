//
// Created by Mariana on 10/11/2017.
//

#ifndef AEDA_FEUP_PROJECT_EXCEPTIONS_H
#define AEDA_FEUP_PROJECT_EXCEPTIONS_H

class InvalidPassenger {

private:
    unsigned int id;

public:
    InvalidPassenger(unsigned int id);
    void print() const;
    void printDuplicate() const;

};

class InvalidAirplane {

private:
    unsigned int id;

public:
    InvalidAirplane(unsigned int id);
    void print() const;
    void printDuplicate() const;

};

class InvalidFlight {

private:
    unsigned int id;

public:
    InvalidFlight(unsigned int id);
    void print() const;
    void printDuplicate() const;

};

#endif //AEDA_FEUP_PROJECT_EXCEPTIONS_H
