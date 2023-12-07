#include <iostream>
using namespace std;

bool isLeapYear(int year);

int main() {
	int num;
	do {
		cout << "Enter a year or Q to quit: ";
		cin >> num;

		//CHECKS WHETHER INPUT IS Q OR q
		if (num == 'Q' || num == 'q') {
			break;
		}

		//CHECKS WHETHER INPUT IS A LEAP YEAR
		if (!cin.fail()) {
			bool leapYear = isLeapYear(num);
			if (leapYear == true) {
				cout << num << " is a leap year.\n";
			}
			else {
				cout << num << " is not a leap year.\n";
			}
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