#include "helper.h"
#include "Airplane.h"
#include "Company.h"

using namespace std;

// Input tester
bool validArg(int &variable) {
    size_t index = 0;
    bool success = true;
    string input;
    getline(cin, input);
    if (input == "") {
        success = false;
    } else {
        trimString(input);

        try {
            variable = stoi(input, &index);
        }

        catch (const std::invalid_argument &ia) {
            success = false;
        }

        if (index != input.length()) success = false;

        if (variable <= 0) success = false;
    }

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

void normalize(string &s) {
    for (auto &c: s) {
        c = tolower(c);
    }
    trimString(s);
}

void next(string &piece, string &line, string separator) {
    int temp = line.find_first_of(separator);
    if (temp == string::npos) {
        piece = line;
        line = "";
    } else {
        piece = line.substr(0, temp);
        line = line.substr(temp + 1, line.length() - 1);
    }
    trimString(piece);
}

void next(int &elem, string &piece, string separator) {
    string elemstring;
    size_t i;
    bool err = false;
    next(elemstring, piece, separator);
    try {

        elem = stoi(elemstring, &i);

    } catch (std::invalid_argument &i) {
        err = true;
    }

    if (i != elemstring.length() || err) throw InvalidFormat();
}

bool validString(string &s) {

    getline(cin, s);

    if (s == "") {
        cout << "Invalid input. Reenter.\n";
        return false;
    }

    return true;
}

void addTime(Date &date, int days) {

    date.day += days;

    while(true) {

        switch(date.month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (date.day <= 31) return;
                date.day -= 31;
                date.month++;
                break;
            case 2:
                if (date.day <= 28) return;
                date.day -= 28;
                date.month++;
                break;
            case 4: case 6: case 9: case 11:
                if (date.day <= 30) return;
                date.day -= 30;
                date.month++;
                break;
            default:
                date.month -= 12;
                date.year++;
                break;
        }
    }
}


void Date::normalize() {
    while (this->minute > 59) {
        this->minute -= 60;
        this->hour++;
    }
    while (this->hour > 23) {
        this->hour -= 24;
        this->day++;
    }
    while (this->day > monthdays[this->month]) {
        this->day -= monthdays[this->month];
        this->month++;
    }
    while (this->month > 12){
        this->month -= 12;
        this->year++;
    }

}

int Date::convertToMinutes() const{
    int t = this->minute;
    t += this->hour*60;
    t += this->day *24*60;
    for (int i = 1; i <= this->month; i++) t += monthdays[i]*24*60;
    t += this->year * 525600;
    return t;

}
