//
// Created by Tiago Fragoso on 17/10/2017.
//

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
    string getJob() const;
    int getAvgYrFlights() const;

};

#endif //AEDA_FEUP_PROJECT_CARD_H
