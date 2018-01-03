#ifndef AEDA_FEUP_PROJECT_TECHNICIAN_H
#define AEDA_FEUP_PROJECT_TECHNICIAN_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <queue>
#include "helper.h"

using namespace std;

class Technician
{
private:
	unsigned int id;
	string name;
	vector <string> models;
	Date timeWhenAvailable;

public:
    /**
     * @brief Constructor of a Technician object using id, name and a vector of string of models
     * @param id
     * @param name
     * @param model
     */
	Technician(unsigned int id,string name, vector <string> model);
    /**
     * @brief Gets the ID number of a Technician
     * @return unsigned int ID of a Technician
     */
	unsigned int getId() const;
    /**
     * @brief Gets the name of a Technician
     * @return string name of a Technician
     */
	string getName() const;
    /**
     * @brief Gets the models of a Technician
     * @return vector <string> models of a Technician
     */
	vector <string> getModels() const;
    /**
     * @brief Gets the time untill the Technician is available
     * @return Date timeUntilAvailable of a Technician
     */
    Date getTimeWhenAvailable() const;
    /**
     * @brief Sets the id of the Technician object to the passed argument
     * @param id unsigned int id
     */
	void setId(unsigned int id);
    /**
     * @brief Sets the name of the Technician object to the passed argument
     * @param name string name
     */
	void setName(string name);
    /**
     * @brief Sets the models of the Technician object to the passed argument
     * @param model vector <string> model
     */
	void setModels(vector <string> model);
    /**
     * @brief Sets the timeUntilAvailable of the Technician object to the passed argument
     * @param time Date time
     */
	void setTimeWhenAvailable(Date time);
	void setTimeUntilAvailable(int time);
    /**
     * @brief Prints the information about a technician
     */
	void print() const;
    /**
     * @brief Prints the information about a technician
     */
	void printSummary() const;
    /**
     * @brief overload of the operator < to be able to compare them when inserting in the priority queue
     * @param tech1 Technician tech1
     * @return
     */
	bool operator<(const Technician &tech1) const;
    /**
     * @brief overload of the operator = to be able to compare if the Technician objects are equal or not
     * @param tech1 Technician tech1
     * @return true if they are equal or false otherwise
     */
	bool operator=(const Technician &tech1) const;
    /**
     * @brief overload of the operator << for objects of class Technician
     * @param o ostream &o
     * @param p const Technician *p
     * @return ostream
     */
	friend ostream &operator<<(ostream &o, const Technician *t);
};

#endif //AEDA_FEUP_PROJECT_TECHNICIAN_H