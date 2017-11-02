#include <iostream>
#include <string>

using namespace std;

#ifndef AEDA_FEUP_PROJECT_CARD_H
#define AEDA_FEUP_PROJECT_CARD_H


class Card{

private:
    string job;
    int avgYrFlights;

public:
    Card(string job, int nYear);
    string getJob() const;
    int getAvgYrFlights() const;
    void setAvgyrFlights(int nYear);
    void setJob(string job);

};

#endif //AEDA_FEUP_PROJECT_CARD_H
