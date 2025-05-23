// pig.cpp
// 08/29/21
// Brandon Montez

#include <iostream>
#include <string>
using namespace std;

// Funciton Prototype
void ProgramGreeting();
void playGame(int* hi, int* lo);
int getPlayerSelection();
int playerChoice(int player);
string getStudentName();
int RandomNumber(int hi, int lo);
int d6();


int main() {
  ProgramGreeting();
  // Specification C1 - Fixed Seed
  srand(47);

  // Specification B3 - Hi Score on Heap
  int *hi_score = new int;
  int *lo_score = new int;
  
  // play game until winner
  playGame(hi_score, lo_score);

  // Specification B4 – Display High Score
  cout << "The high score was: " << *hi_score << endl;

  // note this will usually return an error because (100 < hi_score)
  cout << "\nHere's a random number between the high (" << *hi_score << ") and low ("
      << *lo_score << ") scores: " << RandomNumber(*hi_score, *lo_score) << endl;

  // delete the dynamic memory
  delete hi_score;
  delete lo_score;

  return 0;
}


void ProgramGreeting() {
  //Specification B2 - Display Due Date
  cout << "Welcome to my program.\nIn this program you will play a dice game.\nDue Date: 08/29/21\n-Brandon Montez" << endl;
}


void playGame(int *hi, int *lo) {
  // grand points
  int p1_gp,
      p2_gp;

  const int GOAL = 100,
            // human
            P1 = 0,
            // computer
            P2 = 1;

  int winner = -1,
      player = -1;

  // Specification C2 - Student Name
  string name = getStudentName();

  // introduction message
  cout << "\nThe game will now begin." << endl;

  while (winner == -1) {

    int turn_value = 0,
        roll_value = 0,
        pc;

    // change player
    player = (player + 1) % 2;

    if (player == 0) {
      cout << "\n" << name << "'s turn." << endl;
    } else {
      cout << "\nComputer's turn." << endl;
    }

    // get player choice
    do {
      pc = playerChoice(player);
      if (pc == 1) {
        roll_value = d6();
        if (roll_value == 1) {
          turn_value = 0;
          pc = 0;
          cout << "\nYou rolled a 1. Turn ended." << endl;
        } else {
          // Specification B1 - Display Turn Stats
          turn_value += roll_value;
          cout << "\nYour turn points: " << turn_value << endl;
        }
      }
    } while (pc == 1);

    if (pc ==2) {
      cout << "\nYou selected hold." << endl;
    }
    
    // add grand points
    if (player == P1) {
      p1_gp += turn_value;
      cout << "\n" << name << "'s grand points: " << p1_gp << endl;
    } else {
      p2_gp += turn_value;
      cout << "\nComputer grand points: " << p2_gp << endl;
    }

    // check for winner
    if (p1_gp >= GOAL) {
      winner = P1;
      *hi = p1_gp;
      *lo = p2_gp;
    } else if (p2_gp >= GOAL) {
      winner = P2;
      *hi = p2_gp;
      *lo = p1_gp;
    }
  }
}


string getStudentName() {
  string name;
  cout << "\nPlease enter your name: " << endl;
  getline(cin, name);
  cout << "Your name is: " << name << endl;
  return name;
}


int playerChoice(int player) {
  if (player == 0) {
    return getPlayerSelection();
  } else {
    return ((rand() % 2) + 1);
  }
}


int getPlayerSelection() { 
  int selection;

  // Specification C4 - Bulletproof Menu
  do {
    // Specification C3 - Numeric Menu
    cout << "\nWould you like to:\n"
            "1. Roll\n"
            "2. Hold\n" << endl;
    cin >> selection;
    cin.clear();
    cin.ignore();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (selection != 1 && selection != 2)
      cout << "Error in user selection" << endl;
  }
  while (selection != 1 && selection != 2);

  return selection;
}


// Specification A1 - D6() function
int d6() {
  return ((rand() % 6) + 1);
}


// Specification A2 - RandomNumber() function
int RandomNumber(int hi, int lo) {
  int return_value;
  int random_num;

  // Specification A3 - Protect RandomNumber() input
  if (hi < lo || lo < 1 || 100 < hi) {
    cout << "\nProtect RandomNumber input error." << endl;
    return_value = -1;
  } else {
    do {
      random_num = (rand() % hi);
    } while (random_num <= lo);
    return_value = random_num;
  }

  // Specification A4 - Protect RandomNumber() output
  if (100 < return_value) {
    return_value = -2;
  }

  return return_value;
}