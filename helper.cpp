#include <iostream>
#include <iomanip>
#include <string>
#include "helper.h"

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
/*
Airplane readAirplane(string &a) {
 


}
*/

