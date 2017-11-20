#include "Card.h"

int Card::getAvgYrFlights() const {
    return this->avgYrFlights;
}

string Card::getJob() const {

    return job;
}

Card::Card(string job, int nYear = 0) {

    this->job = job;
    this->avgYrFlights = nYear;
}

void Card::setAvgyrFlights(int nYear) {

    avgYrFlights = nYear;
}

void Card::setJob(string job) {

    this->job = job;

}