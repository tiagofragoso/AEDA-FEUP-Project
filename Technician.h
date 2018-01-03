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
	Technician(unsigned int id,string name, vector <string> model);
	unsigned int getId() const;
	string getName() const;
	vector <string> getModels() const;
    Date getTimeWhenAvailable() const;

	void setId(unsigned int id);
	void setName(string name);
	void setModels(vector <string> model);
	void setTimeWhenAvailable(Date time);
	void print() const;
	void printSummary() const;

	bool operator<(const Technician &tech1) const;
	bool operator=(const Technician &tech1) const;
	friend ostream &operator<<(ostream &o, const Technician *t);
};

#endif //AEDA_FEUP_PROJECT_TECHNICIAN_H