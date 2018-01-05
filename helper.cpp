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

bool validFullDate(Date &date){
    string input;
    getline(cin, input);
    bool success = true;
    if (input.length() < 9 || input.length() > 16) success = false;
    else {
        trimString(input);
        try {
            next(date.day, input, "/");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
        try {
            next(date.month, input, "/");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
        try {
            next(date.year, input, "-");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
        try {
            next(date.hour, input, ":");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
        try {
            next(date.minute, input, "/");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
    }
    end:

    Date copyDate = date;
    copyDate.normalize();
    if (!(date == copyDate)) success = false;

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

bool validTime(Date &date) {
    string input;
    getline(cin, input);
    bool success = true;
    if (input.length() < 3 || input.length() > 5) success = false;
    else {
        trimString(input);
        try {
            next(date.hour, input, ":");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
        try {
            next(date.minute, input, "/");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
    }
    end:
    date.normalize();
    if (!success) cout << "Invalid input. Reenter.\n";
    return success;
}

bool validDate(Date &date) {
    string input;
    getline(cin, input);
    bool success = true;
    if (input.length() < 4 || input.length() > 10) success = false;
    else {
        trimString(input);
        try {
            next(date.day, input, "/");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
        try {
            next(date.month, input, "/");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
        try {
            next(date.year, input, "/");
        } catch (InvalidFormat &i) {
            success = false;
            goto end;
        }
    }
    end:

    Date copyDate = date;
    copyDate.normalize();
    if (!(date == copyDate)) success = false;

    if (!success) cout << "Invalid input. Reenter.\n";
    return success;
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
    while (this->month > 12) {
        this->month -= 12;
        this->year++;
    }
    while (this->day > monthdays[this->month]) {
        this->day -= monthdays[this->month];
        this->month++;
        if (this->month > 12) {
            this->month -= 12;
            this->year++;
        }
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
