#ifndef AEDA_FEUP_PROJECT_CARD_H
#define AEDA_FEUP_PROJECT_CARD_H
#include <iostream>
#include <string>

using namespace std;

class Card{

private:
    /**
     * @brief string Job of the Passenger who holds the card
     */
    string job;
    /**
     * @brief int Average flights the Passenger that holds this card takes per year
     */
    int avgYrFlights = 0;

public:
    /**
     * @brief Default Constructor of a Card object
     */
	Card() {}
    /**
     * @brief Constructor of a Card object using the job and the average number of Flights per year
     * @param job
     * @param nYear
     */
    Card(string job, int nYear = 0);
    /**
     * @brief Gets the job of the Card object
     * @return string job listed in the Card
     */
    string getJob() const;
    /**
     * @brief Gets the Average number of Flights per year in the Card
     * @return int avgYrFlights
     */
    int getAvgYrFlights() const;
    /**
     * @brief Sets the avgYrFlights of the Card to the passed parameter
     * @param nYear int nYear
     */
    void setAvgyrFlights(int nYear);
    /**
     * @brief Sets the job of the Card object to the passed parameter
     * @param job string job
     */
    void setJob(string job);

};

#endif //AEDA_FEUP_PROJECT_CARD_H
