// gpa.cpp
// 09/26/21
// Brandon Montez


#include <iostream>
#include <string>
#include <cstdlib> // might not need
using namespace std;


// Specification A1 - Date class
class Date {
private:
  int month, day, year;
public:
  // CAN CHANGE TO CONSTRUCTOR
  void SetDate(int mon, int da, int ye) {
    month = mon; day = da; year = ye;
  }

  void Print() {
    cout << month << "/" << day << "/" << year << endl;
  }

  string GetDate() {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
  }

  // Specification A3 - Component Test Method in Date
  void ComponentTest() {
    Date comp_test;
    comp_test.SetDate(2,18,1958);
    if (comp_test.GetDate() == "2/18/1958")
      cout << "Date component test passed" << endl;
    else
      cout << "Date component test failed" << endl;
  }
};


void UnitTest();
void ProgramGreeting();
void MainMenu();
string GetInput();
double GetScore();
char CalcGrade(double);


int main() {
  int count = 0,  // tracks the amount of user input values
      player_select;

  double* scores = nullptr;

  // Specification B1 - Dynamic Array
  scores = new double[1];

  ProgramGreeting();

  do {
    // get verified user input
    player_select = stoi(GetInput());

    switch (player_select) {
      // input score
      case 1: {
        // for the first input value
        if (count == 0)
          scores[0] = GetScore();
        // for all else
        else {
          // create new pointer for a new array
          double* bigarr = nullptr;
          // Specification B2 - Add Elements
          // create new array, add element
          bigarr = new double[count + 1];

          // transfer values in scores[] to new array
          for (int i = 0; i < count; i++)
            bigarr[i] = scores[i];
          
          // insert new value into new array
          bigarr[count] = GetScore(); 

          // set original pointer to the new array
          delete [] scores;
          scores = bigarr;
          bigarr = nullptr;
        }
        // increment count of input scores
        count++;
        break;
      }
      // Specification C2 - Print Scores
      case 2: {
        cout << "Display all scores" << endl;
        cout << "-------------------" << endl;

        for (int i = 0; i < count; i++) {
          cout << scores[i] << " ";
          // Specification C3 - Letter Grades
          cout << CalcGrade(scores[i]) << endl;
        }

        cout << endl;
        break;
      }
      // Specification C4 - Compute GPA
      case 3: {
        double tot = 0.0,
                avg = 0.0;

        cout << "Process grade" << endl;
        cout << "--------------" << endl;
        for (int i = 0; i < count; i++) 
          tot += scores[i];
        avg = tot / count;

        cout << "Your average score is: " << avg << endl;
        // Specification B4 - Print Letter Grade
        cout << "Your grade is: " << CalcGrade(avg) << endl << endl;
        break;
      }
      // quit
      case 4: {
        break;
      }
    }
  } while (player_select != 4);
  
  delete [] scores;
  scores = nullptr;

  Date date;
  // Specification A2 - External date initialization
  // CAN CHANGE TO CONSTRUCTOR
  date.SetDate(9,30,2021);
  date.Print();

  // unit testing
  UnitTest();

  return 0;
}


// Specification C1 - Program Greeting Function
void ProgramGreeting() {
  cout << "Welcome to my program.\nIn this program you can calculate gpa.\nDue Date: September 26, 2021\n-Brandon Montez\n" << endl;
}


// Specification A4 - Component Test Grade Conversion
void UnitTest() {
  Date test_day;
  Date test_day_2;
  test_day.ComponentTest();
  test_day_2.ComponentTest();

  cout << "\nUnit testing Grade Calculator..." << endl;
  for (int i = -10; i < 120; i += 10) {
    cout << "Input value: " << i << endl;
    cout << "Output from Grade Caculator: " << CalcGrade(i) << endl;
  }
}


void MainMenu() {
  cout << "Main Menu.\n"
"1. Add Score.\n"
"2. Display All Scores.\n"
"3. Process Grade.\n"
"4. Quit Program.\n" << endl;
}


// Specification B3 - Menu Input Validation
string GetInput() { 
  string selection = "";

  do {
    MainMenu();
    getline(cin, selection);

    if (selection != "1" && selection != "2" && selection != "3" && selection != "4")
      cout << "\nError in user selection\n" << endl;
  } while (selection != "1" && selection != "2" && selection != "3" && selection != "4");
  cout << endl;

  return selection;
}


double GetScore() {
  string input;
  double score;

  do {
    cout << "Please enter your score for this test. " << endl;
    cout << "---------------------------------------" << endl;
    cin >> input;
    cin.clear();
    cin.ignore();

    score = stod(input);  // error on character input

    if (score < 0 || 100 < score)
      cout << "\nError inputting score. Requires values between (0, 100)\n" << endl;
  } while (score < 0 || 100 < score);
  cout << endl;

  return score;
}


char CalcGrade(double perc) {
  char grd = '0';

  if (perc < 0)
    cout << "Input below minimum value (0)." << endl;
  else if (perc < 60)
    grd = 'F';
  else if (perc < 70)
    grd = 'D';
  else if (perc < 80)
    grd = 'C';
  else if (perc < 90)
    grd = 'B';
  else if (perc <= 100)
    grd = 'A';
  else if (100 <= perc)
    cout << "Input above maximum value (100)." << endl;
  else
    cout << "Invalid input in CalcGrade. Unknown error." << endl;

  return grd;
}
