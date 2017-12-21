#ifndef AEDA_FEUP_PROJECT_TECHNICIAN_H
#define AEDA_FEUP_PROJECT_TECHNICIAN_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <queue>

using namespace std;

class Technician
{
private:
	unsigned int id;
	string name;
	vector <string> models;
	priority_queue <unsigned int> maintenances;

public:
	Technician(unsigned int id,string name, vector <string> model);
	unsigned int getId();
	string getName();
	vector <string> getModels();

	void setId(unsigned int id);
	void setName(string name);
	void setModels(vector <string> model);

	bool operator<(const Technician &tech1) const;
};

#endif //AEDA_FEUP_PROJECT_TECHNICIAN_H