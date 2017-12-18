#ifndef AEDA_FEUP_PROJECT_TECHNICIAN_H
#define AEDA_FEUP_PROJECT_TECHNICIAN_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Technician
{
private:
	string name;
	string model;
	unsigned int avaiability;
public:
	Technician(string name, string model, unsigned int avaiability);
	string getName();
	string getModel();
	unsigned int getAvaiability();

	bool operator<(const Technician &tech1) const;
};

#endif //AEDA_FEUP_PROJECT_TECHNICIAN_H