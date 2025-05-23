// ttt.cpp
// Brandon Montez
// CISP 360
// 05/02/2021

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class ttt {
  public:
    ttt() {
      makeBoard();
      coinFlip();
    }

    // Specification C1 - Random Start
    void coinFlip () {
      srand((unsigned int)time(NULL));
      player = rand() % 2;
      cout << "\n" << player_names[player] << " will start the game." << endl;
    }

    void makeBoard() {
      for (int i = 0; i < 9; i++) {
        board[i] = ' ';
      }
    }

    // Specification C2 - Simple Display
    void displayBoard() {
      cout << endl;
      for (int i = 0; i < 9; i+=3) {
        for (int j = 0; j < 3; j++) {
          cout << board[i+j] << ",";
        }
      cout << endl;
      }
      cout << endl;
    }

    void changePlayer() {
      player = (player + 1) % 2;
    }

    void getMove() {
      cout << player_names[player] << "'s move: ";

      if (player == 0) {
        move = getHumanMove();
      }
      else {
        move = getCompMove();
        cout << move << endl;
      }
    }

    int getHumanMove() {
      string user_move;

      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // BUGGY

      cin >> user_move; 

      while (validateHumanMove(user_move) == false) {
        cout << player_names[player] << "'s move: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // BUGGY

        cin >> user_move; 
      }

      return stoi(user_move); // should return an int between 0-8.
    }

    // Specification B3 – Valid Move
    // uvm -> string containing unvalidated move
    bool validateHumanMove (string uvm) {
      bool valid = true;
      int digit;

      if (uvm.length() != 1) {
        cout << "Error: Cannot read input. Please enter a digit between 0-8." << endl;
        valid = false;
      }

      else if (isdigit(uvm[0]) == 0) {
        cout << "Error: Input must be an integer." << endl;
        valid = false;
      }

      else {

        digit = stoi(uvm); // convert string to int for easier validation

        if (moveRange(digit) == false) {
          cout << "Error: Out of Range. Please enter a digit between 0-8." << endl;
          valid = false;
        }
        else if (freeSpace(digit) == false) {
          cout << "Error: That tile is occupied." << endl;
          valid = false;
        }
      }
      return valid;
    }

    bool moveRange(int test_move) {
      bool in_range = false;
      if (0 <= test_move && test_move <= 8) {
        in_range = true;
      }
      return in_range;
    }

    bool freeSpace(int test_move) {
      bool free = true;
      if (board[test_move] != ' ') {
        free = false;
      }
      return free;
    }

    // Specification C3 - AI
    int getCompMove() {
      int comp_move = rand() % 9;
      while (freeSpace(comp_move) == false) {
        comp_move = rand() % 9;
      }
      return comp_move;
    }

    void playMove() {
      board[move] = player_marks[player];
      move_count += 1;
    }

    void evalBoard() {
      // horizontal
      if (player_marks[player] == board[0] && board[0] == board[1] && board[1] == board[2]) {
        winner = player;
      } else if (player_marks[player] == board[3] && board[3] == board[4] && board[4] == board[5]) {
        winner = player;
      } else if (player_marks[player] == board[6] && board[6] == board[7] && board[7] == board[8]) {
        winner = player;
      //vertical
      } else if (player_marks[player] == board[0] && board[0] == board[3] && board[3] == board[6]) {
        winner = player;
      } else if (player_marks[player] == board[1] && board[1] == board[4] && board[4] == board[7]) {
        winner = player;
      } else if (player_marks[player] == board[2] && board[2] == board[5] && board[5] == board[8]) {
        winner = player;
      // diagonal
      } else if (player_marks[player] == board[0] && board[0] == board[4] && board[4] == board[8]) {
        winner = player;
      } else if (player_marks[player] == board[2] && board[2] == board[4] && board[4] == board[6]) {
        winner = player;
      }
    }

    bool gameOver() {
      bool gameover = false;
      if (winner != -1) {
        gameover = true;
      } else if (move_count >= 9){
        gameover = true;
      }
      return gameover;
    }

    void displayWinner() {
      if (winner == -1) {
        cout << "Game Over: Tie!" << endl;
      }
      else {
        cout << player_names[winner] << " Wins!" << endl;
      }
    }

  private:
    int player, move, move_count = 0, winner = -1;
        
    // Specification A3 - Array Data Type
    char board[9],
         player_marks[2] = {'X', 'O'};
         
    string player_names[2] = {"Human", "Computer"};
};

// Specification A2 - Simple Prompt
bool keepPlaying() {
  bool go_again = false;
  char inp;

  cout << "\nWould you like to play again? (y/n)" << endl;

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cin >> inp;

  while (inp != 'n' && inp != 'y') {
    cout << "Error: Invalid Input. Enter y or n." << endl;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin >> inp;
  }
  if (inp == 'y') {
    go_again = true;
  }
  return go_again;
}

void displayBoardRules() {
  string key;
  int temp_board[9];

  cout << "\nThe board is numbered 0-8 in reading order from top left to bottom right.\n" << endl;

  for (int i = 0; i < 9; i++) {
    temp_board[i] = i;
    cout << temp_board[i] << ",";
    if (i == 2 || i == 5)
      cout << endl;
  }

  cout << "\n\nEnter any key to return." << endl;

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cin >> key;

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // LOL

  cout << endl;
}

// Specification B1 - Start Menu
void displayMenu() {
  cout << "1. Explain Game\n2. Play Game\n3. Quit\n";
}

//Specification B2 - Valid Menu Choices
int getMenuInput() {
  int input;

  cout << "\nMenu choice: ";
  cin >> input;
  
  while (input < 1 || 3 < input) {
    cout << "Error: Invalid Input. Please choose an option between 1-3.\n\nMenu choice: ";

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cin >> input;
  }
  return input;
}

void ProgramGreeting() {
  cout << "Welcome to Tic-Tac-Toe.\nEnjoy pummeling this stupid computer to death!\nBrandon Montez\nMay 2nd, 2021.\n" << endl;
}

void playGame() {
  ttt game;

  do {
    game.displayBoard();
    game.getMove();
    game.playMove();
    game.evalBoard();
    game.changePlayer();
  } while (game.gameOver() == false);

  game.displayBoard();
  game.displayWinner();
}

int main() {
  int input;
  ProgramGreeting();

  displayMenu();
  input = getMenuInput();

  if (input == 1) {
    displayBoardRules();
    main();
  }

  // Specification A1 - Main Game Loop
  else if (input == 2) {
    do {
      playGame();
    } while (keepPlaying());
  }

  return 0;
}