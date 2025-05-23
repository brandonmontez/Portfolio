//  ccctc
//  Brandon Montez
//  03/28/20

#include <cctype>
#include <iostream>
#include <limits>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
void ProgramGreeting(), toCelsius(float temp), toKelvin(float temp),
  toNewton(float temp), toRankine(float temp);
bool validateObject(string obj), tempCheck(float temp, float lp, float hp),
	validateConvertMenu(int choice), playOn();
int convertMenu();
float collectTemp(string obj);
string tolowerString(string some_str), objInput();

int main() {
	bool replay;
	float temp = 0.0;
	int conversion_type;
	ProgramGreeting();
	temp = collectTemp(objInput());
	do {
		conversion_type = convertMenu();
		switch (conversion_type) {
		case 1:
			toCelsius(temp);
			break;
		case 2:
			toRankine(temp);
			break;
		case 3:
			toKelvin(temp);
			break;
		case 4:
			toNewton(temp);
			break;
		case 5:
			toCelsius(temp);
			toRankine(temp);
			toKelvin(temp);
			toNewton(temp);
			break;
		}
		if (conversion_type != 6)
			replay = playOn();
	} while (conversion_type != 6 && replay == true);
}

bool playOn() {
	char inp;
	bool go_again = false;
	do {
		cout << "\nWould you like to go again? (y/n):" << endl;
		cin >> inp;
		inp = tolower(inp);
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (inp != 'n' && inp != 'y')
			cout << "(Error - Please enter 'y' or 'n'.)" << endl;
	} while (inp != 'n' && inp != 'y');
	if (inp == 'y')
		go_again = true;
	return go_again;
}

void toCelsius(float temp) {
	temp = (temp - 32) * 0.55556;
	cout << "Temperature in Celsius: " << temp << "°C" << endl;
}

void toRankine(float temp) {
	temp = temp + 459.67;
	cout << "Temperature in Rankine: " << temp << "°R" << endl;
}

void toKelvin(float temp) {
	temp = (temp + 459.67) * 0.55556;
	cout << "Temperature in Kelvin: " << temp << "K" << endl;
}

// Specification A3 – Another Temperature Scale
void toNewton(float temp) {
	temp = (temp - 32) * 0.18333;
	cout << "Temperature in Newton: " << temp << "°N" << endl;
}

string objInput() {
	string input = "";
	do {
		cout << "Please enter which object you would like to measure: "
				"'cot', 'cat', 'cap', 'cow':" << endl;
		cin >> input;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		input = tolowerString(input);
	} while (validateObject(input) == false);
	cout << endl;
	return input;
}

// Specification C1 – Only Valid Words
bool validateObject(string obj) {
	// Specification B3 - Auto Variable Type
	auto status = true;
	if (3 < obj.length()) {
		cout << "(Error - Invalid entry. Too many characters.)\n" << endl;
		status = false;
	} else if (obj != "cot" && obj != "cat" && obj != "cap" && obj != "cow") {
		cout << "(Error - Invalid entry. Selection must be either: "
				"'cot', 'cat', 'cap', or 'cow'.)\n" << endl;
		status = false;
	}
	return status;
}

// Specification A1 – Sophisticated Word Check
string tolowerString(string some_str) {
	string mutabl = "";
	for (int i = 0; i < some_str.length(); i++)
		mutabl += tolower(some_str[i]);
	return mutabl;
}

float collectTemp(string obj) {
	// Specification B1 – Floats for Temps
	float temp = 0.0, low_param = 0.0, high_param = 0.0;

	if (obj == "cat") {
		low_param = 86;
		high_param = 102;
	} else if (obj == "cot") {
		low_param = 54;
		high_param = 80;
	} else if (obj == "cap") {
		low_param = 72;
		high_param = 88;
		// Specification A2 – Another Thing
	} else if (obj == "cow") {
		low_param = 61;
		high_param = 90;
	} else
		cout << "(Error - How did you get here?)" << endl;
	do {
		cout << "Please enter a temperature in °F betweeen (" << low_param
			 << " - " << high_param << "):" << endl;
		cin >> temp;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (tempCheck(temp, low_param, high_param) == false);
	return temp;
}

// Specification B2 – Valid Temps Only
bool tempCheck(float temp, float lp, float hp) {
	bool status = true;
	float err_mgn = 0.2;
	if (temp < lp - err_mgn) {
		cout << "(Error - Invalid entry. Temperature too low. Must be above "
			 << lp << "°F)\n" << endl;
		status = false;
	} else if (hp + err_mgn < temp) {
		cout << "(Error - Invalid entry. Temperature too high. Must be below "
			 << hp << "°F)\n" << endl;
		status = false;
	}
	return status;
}

// Specification C2 – Temp Scale Menu
int convertMenu() {
	int choice = 0;
	do {
		cout << "\nTemperature Conversion Menu:\n"
				"1. To Celsius\n"
				"2. To Rankine\n"
				"3. To Kelvin\n"
				"4. To Newton\n"
				"5. Calculate all\n"
				"6. End program\n"
				"\nMenu selection: ";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (validateConvertMenu(choice) == false);
	cout << endl;
	return choice;
}

// Specification C3 – Valid Scale Menu Check
bool validateConvertMenu(int choice) {
	bool status = true;
	if (choice < 1 || 6 < choice) {
		cout << "(Error - Invalid entry. Out of bounds. Must be an integer "
				"between (1 - 6).)\n";
		status = false;
	}
	return status;
}

void ProgramGreeting() {
	cout << "Hello! This program is mostly useless. Sorry!\n"
			"Brandon Montez\n"
			"03-28-20\n" << endl;
}