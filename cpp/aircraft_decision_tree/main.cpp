// acdt
// Brandon Montez
// 02/28/2020

#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
using namespace std;

int MenuInput();
void ProgramGreeting();
void Menu();
void DisplayMenu();
void Com();
void Eng();
void Ice();
void Err();
void DeIce(float ice);
bool GetAns();

int main() {
  ProgramGreeting();
  Menu();
  return 0;
}

void ProgramGreeting() {
  cout << "This is just a test,\n"
    << "Do not use in emergency,\n"
    << "Or you might get hurt." << endl;
  cout << "\n~Brandon Montez." << endl;
  cout << "February 28, 2020." << endl;
  cout << "-------------------------\n" << endl;
}

// Specification A3 - One Function
void Menu() {
  DisplayMenu();
  // Specification A2 - Menu Input Validation
  // Specification B1 - Menu Input Validation
  switch(MenuInput()) {
    case 'C': Com(); break;
    case 'E': Eng(); break;
    case 'I': Ice(); break;
    case 'Q': exit(0); break;
    default: Err();
    
  //  switch(MenuInput()) {
  //    case 1: Com(); break;
  //    case 2: Eng(); break;
  //    case 3: Ice(); break;
  //    case 4: exit(0); break;
  //    default: Err();
  }
}

// Specification A1 - Alpha Menu
void DisplayMenu() {
  // Specification B3 - Date
  time_t now = time(0);
  tm * localtm = localtime(&now);
  cout << asctime(localtm) << endl;

  cout << "(C) ommunications Failure" << endl;
  cout << "(E) ngine Failure" << endl;
  cout << "(I) n-Flight Icing" << endl;
  cout << "(Q) uit\n" << endl;

  //  cout << "1. Communications Failure" << endl;
  //  cout << "2. Engine Failure" << endl;
  //  cout << "3. In-Flight Icing" << endl;
  //  cout << "4. Quit\n" << endl;
}

int MenuInput() {
  char input;
  cout << "Select a menu option: ";
  cin >> input;
  cout << endl;
  return toupper(input);
}

void Err() {
  cout << "Error: Invalid selection." << endl;
}

// Specification C1 - Communications Option
void Com() {
  cout << "Switch to Alternate Radio." << endl;
}

// Specification C2 - Engine Failure Option
void Eng() {
  cout << "Answer (y/n)" << endl;
  cout << "Are you airborne?: ";
  if (GetAns()) {
    cout << "Is the electrical system working?: ";
    if (GetAns()) {
      cout << "Has the engine stoped running?: ";
      if (GetAns()) {
        cout << "Are you over the mountains?: ";
        if (GetAns()) {
          cout << "Are you flying at night?: ";
          if (GetAns()) {
            cout << "Turn on the landing light and look out the window.";
            cout << "Do you like what you see?: ";
            if (GetAns())
              cout << "Make emergency landing.";
            else
              // "Do you like what you see?" - No
              cout << "\nTurn off landing light.";
          }
          else
            // "Are you flying at night?" - No
            cout << "\nMake emergency landing.";
        } 
        else {
          // "Are you over the mountains?" - No
          cout << "Are you over water?: ";
          if (GetAns())
            cout << "\nInflate your life vest, make emergency landing.";
          else
            // "Are you over water?" - No
            cout << "\nMake emergency landing on a road.";
        }
      } 
      else {
        // "Has the engine stopped running?" - No 
        cout << "Is the outside air temperature < 32 degrees?: ";
        if (GetAns())
          cout << "\nTurn on Carburator Heat.";
        else
          // "Is the outside air temperature < 32 degrees?" - No
          cout << "\nSwitch to other fuel tank.";
      }
    }
    else
      // "Is the electrical system working?" - No
      cout << "\nTurn on the Master Switch.";
  }
  else
    // "Are you airborne?" - No
    cout << "\nHave a drink and call a mechanic.";
}

// Collect y/n answer from user and return as bool
bool GetAns() {
  bool isTrue = false;
  char ans;
  cin >> ans;
  ans = tolower(ans);
  if (!(ans == 'y' || ans == 'n')) {
    cout << endl;
    Err();
  } else if (ans == 'y')
    isTrue = true;
  return isTrue;
}

// Specification C3 - In-Flight Icing Option
void Ice() {
  float ice = -1.0;
  cout << "Ice on wings in mm (0, 10]: ";
  cin >> ice;
  cout << endl;
  // Specification B2 - Icing Input Validation
  if ((0 < ice && ice <= 10))
    DeIce(ice);
  else
    Err();
}

void DeIce(float ice) {
  if (ice < 1)
    cout << "Set deicing power to 5%." << endl;
  else if (ice <= 5)
    cout << "Set deicing power to 20%." << endl;
  else if (ice <= 9)
    cout << "Set deicing power to 65%." << endl;
  else
    cout << "Set deicing power to 100%." << endl;
}
