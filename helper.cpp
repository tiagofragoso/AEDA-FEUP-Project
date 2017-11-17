#include "helper.h"
#include "Airplane.h"
#include "exceptions.h"
#include "Company.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
// Input tester
bool validArg(int & variable) {
	size_t index = 0;
	bool success = true;
	string input;
	getline(cin, input);
	if (input == "") {
		success = false;
	}
	else {
		trimString(input);

		try {
			variable = stoi(input, &index);
		}

		catch (const std::invalid_argument& ia) {
			success = false;
		}

		if (index != input.length()) success = false;

		if (variable <= 0) success = false;
	}

	if (!success) cout << "Invalid input. Reenter.\n";
	return success;
}

// Input tester with end bool
bool validArg(int &variable, bool &end) {
	size_t index = 0;
	bool success = true;
	string input;
	getline(cin, input);
	if (input == "") {
		end = true;
		success = false;
		return success;
	}
	trimString(input);

	try {
		variable = stoi(input, &index);

	}
	catch (const std::invalid_argument& ia) {
		success = false;
	}

	if (index != input.length()) success = false;

	if (variable <= 0) success = false;

	if (!success) cout << "Invalid input. Reenter.\n";
	return success;
}

// Helpers for string processing
void trimString(string &s) {
	s = s.substr(s.find_first_not_of(" "));
	s = s.substr(0, s.find_last_not_of(" ") + 1);
}

// Function to wait for next menu input
void pause() {
	string foo;
	cout << "Press enter to continue.";
	getline(cin, foo);
}

void normalize(string &s){
    for (int i = 0; i < s.size(); i++) {
        s.at(i) = tolower(s.at(i));
    }
    trimString(s);
}

void next(string &piece, string &line, string separator){
	int temp = line.find_first_of(separator);
	if(temp == string::npos){
		piece = line;
		line = "";
	}else{
		piece = line.substr(0,temp);
		line=line.substr(temp+1, line.length() - 1);
	}
	trimString(piece);
}

void next(int &elem, string &piece, string separator){
	string elemstring;
	size_t i;
	bool err = false;
	next(elemstring,piece,separator);
	try {

		elem = stoi(elemstring, &i);

	} catch (std::invalid_argument){
		err = true;
	}

	if (i != elemstring.length() || err) throw InvalidFormat();
}

Date::Date(string &s) {
	int temp;
	try {
		next(temp, s, "/");
	} catch (InvalidFormat) {
		cout << "Please insert the correct date.\n";
	}
	this->day = temp;
	temp = 0;
	try {
		next(temp, s, "/");
	} catch (InvalidFormat) {
		cout << "Please insert the correct date.\n";
	}
	this->month = temp;
	temp = 0;
	try {
		next(temp, s, "/");
	} catch (InvalidFormat) {
		cout << "Please insert the correct date.\n";
	}
	this->year = temp;
}