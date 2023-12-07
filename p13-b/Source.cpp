#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getNumberOfDays(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int getMonthNumber(const string& month) {
    if (month == "January") return 1;
    if (month == "February") return 2;
    if (month == "March") return 3;
    if (month == "April") return 4;
    if (month == "May") return 5;
    if (month == "June") return 6;
    if (month == "July") return 7;
    if (month == "August") return 8;
    if (month == "September") return 9;
    if (month == "October") return 10;
    if (month == "November") return 11;
    if (month == "December") return 12;
    return -1; // Invalid month
}

void displayCalendar(int month, int year) {
    cout << "   --- " << month << "/" << year << " ---" << endl;
    cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;

    // Get the day of the week for the first day of the month
    int startDay = getNumberOfDays(1, year);
    startDay = (startDay + 1) % 7; // 0 for Sunday, 1 for Monday, ...

    int daysInMonth = getNumberOfDays(month, year);
    int day = 1;

    // Print spaces for the days before the start of the month
    for (int i = 0; i < startDay; ++i) {
        cout << setw(4) << " ";
    }

    // Print the days of the month
    for (int i = startDay; i < 7; ++i) {
        cout << setw(4) << day;
        day++;
    }
    cout << endl;

    for (int i = 2; i <= daysInMonth / 7 + 1; ++i) {
        for (int j = 0; j < 7 && day <= daysInMonth; ++j) {
            cout << setw(4) << day;
            day++;
        }
        cout << endl;
    }
}

void displayCalendar(int month, int year, ofstream& outputFile) {
    outputFile << "   --- " << month << "/" << year << " ---" << endl;
    outputFile << " Sun Mon Tue Wed Thu Fri Sat" << endl;

    // Get the day of the week for the first day of the month
    int startDay = getNumberOfDays(1, year);
    startDay = (startDay + 1) % 7; // 0 for Sunday, 1 for Monday, ...

    int daysInMonth = getNumberOfDays(month, year);
    int day = 1;

    // Print spaces for the days before the start of the month
    for (int i = 0; i < startDay; ++i) {
        outputFile << setw(4) << " ";
    }

    // Print the days of the month
    for (int i = startDay; i < 7; ++i) {
        outputFile << setw(4) << day;
        day++;
    }
    outputFile << std::endl;

    for (int i = 2; i <= daysInMonth / 7 + 1; ++i) {
        for (int j = 0; j < 7 && day <= daysInMonth; ++j) {
            outputFile << setw(4) << day;
            day++;
        }
        outputFile << endl;
    }
}

int main() {
    string inputMonth;
    int year;

    cout << "Enter the full name of the month: ";
    cin >> inputMonth;

    cout << "Enter the year: ";
    cin >> year;

    int month = getMonthNumber(inputMonth);

    if (month == -1 || year < 0) {
        cout << "Invalid month or year entered.\n";
        return 1;
    }

    ofstream outputFile("calendar_output.txt");
    if (!outputFile.is_open()) {
        cout << "Unable to open the output file.\n";
        return 1;
    }

    displayCalendar(month, year);
    displayCalendar(month, year, outputFile);

    outputFile.close();
    cout << "Calendar has been saved to 'calendar_output.txt'." << endl;

    return 0;
}
