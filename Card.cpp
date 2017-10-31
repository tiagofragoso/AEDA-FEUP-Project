#include "Card.h"

int Card::getAvgYrFlights() const {
    return this->avgYrFlights;
}

string Card::getJob() const {
    return this->job;
}

Card::Card(string job, int nYear) {

    this->job = job;
    this->avgYrFlights = nYear;
}