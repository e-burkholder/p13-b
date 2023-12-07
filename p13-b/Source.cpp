#include <iostream>
#include <string>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main() {
	int month, year;
	string monthName;
	do {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;

		//CHECKS WHETHER INPUT IS Q OR q
		if (year == 'Q' || year == 'q') {
			break;
		}

		if (!cin.fail()) {

			//CHECKS THE MONTH NAME
			switch (month) {
			case 1: monthName = "January"; break;
			case 2: monthName = "February"; break;
			case 3: monthName = "March"; break;
			case 4: monthName = "April"; break;
			case 5: monthName = "May"; break;
			case 6: monthName = "June"; break;
			case 7: monthName = "July"; break;
			case 8: monthName = "August"; break;
			case 9: monthName = "September"; break;
			case 10: monthName = "October"; break;
			case 11: monthName = "November"; break;
			case 12: monthName = "December"; break;
			}

			//CHECKS THE AMOUNT OF DAYS IN THE MONTH
			int days = daysInMonth(month, year);
			cout << monthName << " " << year << " has " << days << " days.\n";

		}
	} while (!cin.fail());

	return 0;
}


/*isLeapYear - determines whether a given year is a leap year under the Gregorian calendar.
@param year the year; expected to be >=1582
@return true if the year is a leap year; false otherwise
*/
bool isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}

/*
daysInMonth - determines the number of days in a specified month
@param month the month; expdcted to be in the range (1-12)
@param year the year; expected to be >=1582
@return either 28, 29, 30, or 31, based on month and (leap) year
*/
int daysInMonth(int month, int year) {
	bool leapYearCheck = isLeapYear(year);
	if (month == 2 && leapYearCheck == true) {
		return 29;
	}
	else if (month == 2 && leapYearCheck == false) {
		return 28;
	}
	switch (month) {
	case 1:
		return 31; break;
	case 3:
		return 31;  break;
	case 4:
		return 30;  break;
	case 5:
		return 31;  break;
	case 6:
		return 30;  break;
	case 7:
		return 31; break;
	case 8:
		return 31; break;
	case 9:
		return 30; break;
	case 10:
		return 31;  break;
	case 11:
		return 30; break;
	case 12:
		return 31;  break;
	default: break;
	}

}