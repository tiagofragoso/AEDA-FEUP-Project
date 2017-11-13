//
// Created by Mariana on 10/11/2017.
//

#ifndef AEDA_FEUP_PROJECT_EXCEPTIONS_H
#define AEDA_FEUP_PROJECT_EXCEPTIONS_H

class InvalidFormat {
public:
    InvalidFormat();
};

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

class OverlapingFlight {

public:
    OverlapingFlight();
    void print() const;
};

class ConnectionFlight {

public:
    ConnectionFlight();
    void print() const ;
};

#endif //AEDA_FEUP_PROJECT_EXCEPTIONS_H
