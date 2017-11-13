#ifndef AEDA_FEUP_PROJECT_CARD_H
#define AEDA_FEUP_PROJECT_CARD_H
#include <iostream>
#include <string>

using namespace std;

class Card{

private:
    /** @name Card data-members*/
    /** @{
    *
    */

    /**
     * @brief string Job of the Passenger who holds the card
     */
    string job;
    /**
     * @brief int Average flights the Passenger that holds this card takes per year
     */
    int avgYrFlights;
    /** @} end of Card data-members */

public:
    Card(string job, int nYear);
    string getJob() const;
    int getAvgYrFlights() const;
    void setAvgyrFlights(int nYear);
    void setJob(string job);

};

#endif //AEDA_FEUP_PROJECT_CARD_H
