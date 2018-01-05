#include "Technician.h"
#include "Application.h"

Technician::Technician(unsigned int id,string name, vector<string> models) {
	this->id = id;
	this->name = name;
	this->models = models;
	this->timeWhenAvailable = Application::currentDate;

}
//get methods

unsigned int Technician::getId() const {
	return this->id;
}

string Technician::getName() const {
	return this->name;
}

vector <string> Technician::getModels() const {
	return this->models;
}

Date Technician::getTimeWhenAvailable() const {
    return this->timeWhenAvailable;
}

//set methods

void Technician::setId(unsigned int id) {
	this->id = id;
}

void Technician::setName(string name) {
	this->name = name;
}

void Technician::setModels(vector <string> models) {
	this->models = models;
}

//Operator overload to sort the priority queue

bool Technician::operator<(const Technician &tech1) const {
	return (timeWhenAvailable < tech1.getTimeWhenAvailable());
}

bool Technician::operator==(const Technician &tech1) const {
	return (id == tech1.getId());
}

ostream &operator<< (ostream &o, const Technician *t) {
	o << to_string(t->id) << "; " << t->name << "; ";
	if (!t->models.empty()) {
		for (int i = 0; i < t->models.size(); i++)
		{
			o << t->models.at(i);
			if (i != t->models.size() - 1) o << ", ";
		}
	} else o << "no_models";
	return o;
}
void Technician::setTimeWhenAvailable(Date date) {
	timeWhenAvailable = date;
}

void Technician::print() const {
	cout << "Id: " << id << endl << "Name: " << name << endl << "Model: ";
	bool first = true;
	for (int i = 0; i < models.size() ; i++)
	{
		if (first) {
			first = false;
			cout << models.at(i);
		}
		else cout << " , " << models.at(i);
	}
	cout << endl;
	cout << "Time Until Available: ";
    if (timeWhenAvailable == Application::currentDate)
        cout << "Available now.\n";
    else cout << timeWhenAvailable.printFullDate() << endl;
}

void Technician::printSummary() const {

	cout << std::left;
	cout << setw(13) << id << setw(3) << " " << setw(30) << name << setw(3) << " ";
    size_t s = this->models.size();
	for (auto const &m: this->models) {
        s--;
        cout << m;
        if (s) cout << ", ";
	}
	cout << endl;
}


