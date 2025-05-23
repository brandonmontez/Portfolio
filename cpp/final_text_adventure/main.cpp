// text_adventure.cpp
// Brandon Montez
// CISP 360
// 05/19/2021

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Specification B3 - A Class of Monsters
class Monster {
  public:
    Monster() {
      key = rand() % 5;
    }

    void setPlayerName(string name) {
      player_name = name;
    }
    
    void getDescription() {
    cout << "\nRoom number: 2" << endl;
      switch(key){
        case 0:
          troll();
          break;
        case 1:
          ice_queen();
          break;
        case 2:
          cowboy();
          break;
        case 3:
          cat();
          break;
        case 4:
          dragon();
          break;
      }
    }

    void getNewDescription() {
    cout << "\nRoom number: 2" << endl;
      switch(key){
        case 0:
          troll2();
          break;
        case 1:
          ice_queen2();
          break;
        case 2:
          cowboy2();
          break;
        case 3:
          cat2();
          break;
        case 4:
          dragon2();
          break;
      }
    }

    void troll() {
      cout << "You enter the room to find a troll sitting around a campfire. He has his back turned to you and seems to be fervently picking at something near his feet. Just before you turn around the troll calls your name, '" << player_name << "? Is that you?' Oh I've been waiting for your arrival. Come here, and take this present to room 6 for me. I need it delivered today.' He hands you a sealed box with a stench like no other. You wonder what could possibly be inside.\n" << endl;
    }

    // Specification B2 - Dynamic Rooms
    void troll2() {
      cout << "The room is empty, yet the stench remains. You pull the box out of your bag and are reminded of that disgusting troll.\n" << endl;
    }

    void ice_queen() {
      cout << "You enter a room with below freezing temperatures and ice sheets across the floor. A woman eats her dinner at a table in the middle of the room. She calls to you, '" << player_name << ", come here.' You tell the lady to get lost, for you have no interest in anything other than mom's spaghetti.\n" << endl;
    }

    void ice_queen2() {
      cout << "The room is no longer cold. The table still remains in the middle of the room, but the woman appears to have finished her meal. 'Good riddance, old hag.' You think." << endl;
    }

    void cowboy() {
      cout << "The room is arid and immediately you feel parched for thirst. The floor is covered in dust or sand, and your nose is getting filled with updraft. A man rides by on a horse at high speeds. You wonder if you can stop him, but then you realize you'd rather not get in his way.\n" << endl;
    }
    
    void cowboy2() {
      cout << "The cowboy has left. The sand is starting to blow away, exposing a metal flooring underneath. A shotgun sits in the middle of the room. You decide to leave it there.\n" << endl;
    }

    void cat() {
      cout << "You enter the room and to your surpise, it is filled with kittens upon kittens. Layers of pillows fill the floors, and cats, cats everywhere, cuddling and hugging each other, 'oh how wonderful!' You think. A kitten comes by and rubs on your legs as you stand in amazement. You feel a strong urge to lie down with the kittens and rest there forever.\n" << endl;
    }

    void cat2() {
      cout << "Excitement rushes through your veins as you slowly reopened the door to kitty-heaven. But inside, there were no kittens. Large tigers, and lions parade the room, which now has outgrowths of vines and bushes. On the ceiling, a monkey hangs down from a treebranch, looking like he feels sorry for you.\n" << endl;
    }

    // Specification B1 - More Monsters
    void dragon() {
      cout << "You enter the room and immediately feel a blast of heat overcomes your body. In the middle of the room rests a dragon with her eggs nestled between her tail. Behind her, in the corner of the room, appears to be a large abyss, leading to who knows where. You wonder why she's resting in front of the hole.\n" << endl;
    }

    void dragon2() {
      cout << "The dragon is no longer in the room. The hole that was in the corner remains unprotected. Part of you wants to go inside, but your body just won't move in that direction.\n" << endl;
    }

    int key;
    string player_name;
};

void ProgramGreeting();
char getInput();
bool validate(int r, char i);
int changeRooms(int r, char i);
void getNewDescription();
void getDescription(int num, string name);
char getSelection(int room, int visits, string name, Monster monst);

int main() {
  srand(time(0));
  ProgramGreeting();
  
  // Specification C2 - Player Name
  string name;
  cout << "Please enter your name:" << endl;
  getline(cin, name);
  cout << endl;

  int room = 0;
  char input;
  int visits[6] = {1,0,0,0,0,0};

  Monster monster;
  monster.setPlayerName(name);

  cout << "Room number: 0" << endl;
  cout << "You are in strange room that is 20 feet in length all around. Moss and ivy cover the Western wall and part of the Southern wall. The Northern wall is faced with a large ivory door, and the Eastern wall appears to be solid concrete. Your knees are weak, and you wish you had your mom's spaghetti.\n" << endl;

  do {
    input = getSelection(room, visits[room], name, monster);

    room = changeRooms(room, input);
    visits[room] += 1;

    // Specification C4 – Abbreviated Room Description
    if (visits[room] <= 1) {
      if (room == 2) {
        monster.getDescription();
        }
      else {
        getDescription(room, name);
      }
    }
    else if (room == 2) {
      monster.getNewDescription();
    }
    else if (room == 5) {
      getNewDescription();
    }
    else {
      cout << "\nRoom number: " << room << endl;
    }

  } while (room < 6);

  cout << "You are subsumed by a shining aura and dissolve into stardust." << endl;

  return 0;
}

char getSelection(int room, int visits, string name, Monster monst) {
  char input;
  bool valid = false;

  do {
    input = getInput();

    if (input == 'L') {

      // Specification C5 - Detailed Look
      if (room == 2) {
        if (visits > 1) {
          monst.getNewDescription();
        }
        else {
        monst.getDescription();
        }
      } else if (room == 5 && visits > 1) {
        getNewDescription();
      }
      else {
        getDescription(room, name);
      }
    }

    else {
      valid = validate(room, input);
      if (!(valid)) {
        cout << "\nBonk! You've ran into a wall! Congrats, now look for the exit.\n" << endl;
      }
    }
  } while (!(valid));

  return input;
}


int changeRooms(int r, char i) {
  int next = 0;

  switch (r) {
    case 0:
      if (i=='N')
        next = 1;
      break;
    case 1:
      if (i=='W')
        next = 2;
      else if (i=='S')
        next = 0;
      else if (i=='N')
        next = 3;
      break;
    case 2:
      if (i=='E')
        next = 1;
      break;
    case 3:
      if (i=='W')
        next = 4;
      else if (i=='N')
        next = 5;
      else if (i=='S')
        next = 1;
      break;
    // Specification C1 - Five Rooms
    case 4:
      if (i=='N')
        next = 6;
      else if (i=='E')
        next = 3;
      break;
    // Specification A3 - More Rooms
    case 5:
      if (i=='W')
        next = 6;
      else if (i=='S')
        next = 3;
      break;
  }

  return next;
}

// Specification C3 - Input Validation
bool validate(int r, char i) {
  bool valid_move = false;

  switch (r) {
    case 0:
      if (i == 'N') {
        valid_move = true;
      }
      break;
    case 1:
      if (i == 'N' || i == 'S' || i == 'W') {
        valid_move = true;
      }
      break;
    case 2:
      if (i == 'E') {
        valid_move = true;
      }
      break;
    case 3:
      if (i == 'N' || i == 'S' || i == 'W') {
        valid_move = true;
      }
      break;
    case 4:
      if (i == 'N' || i == 'E') {
        valid_move = true;
      }
      break;
    case 5:
      if (i == 'S' || i == 'W') {
        valid_move = true;
      }
      break;
  }
  return valid_move;
}

char getInput() {
  string direc;
  cout << "Which way to go? (N/W/E/S or L for a description)" << endl;
  getline(cin, direc);
  direc[0] = toupper(direc[0]);
  while (direc[0] != 'W' && direc[0] != 'E' && direc[0] != 'N' && direc[0] != 'S' && direc[0] != 'L') {
    cout << "Error: Please enter a valid direction." << endl;
    cin >> direc[0];
  }
  return direc[0];
}

void getDescription(int num, string name) {
  cout << "\nRoom number: " << num << endl;
  if (num == 0) {
    cout << "You are in strange room that is 20 feet in length all around. Moss and ivy cover the Western wall and part of the Southern wall. The Northern wall is faced with a large ivory door, and the Eastern wall appears to be solid concrete. Your knees are weak, and you wish you had your mom's spaghetti.\n" << endl;
  }
  if (num == 1) {
    cout << "This room has a large entrance on the Western wall barriered by a golden door. The Eastern wall is made of smooth granite with no entrances. The Northern wall has a wooden door with a shining purple light above it. The Southern wall retains a large ivory door.\n" << endl;
  }
  if (num == 3) {
    cout << "You are in a very bright room, illuminated by thousands of different light fixtures. It looks like the world's largest antique light fixture store. It's difficult to see, but because the lights are so high to the ceiling you can still make out what's in front of you. You wonder, who would buy all these lights, and why are they in here?\nThe North wall has a door with a sign that simply reads 'Come In.' The Eastern wall is all wooden slats, and shrieks can be heard behind the Western door. The Southern wall has a door with a small green light illuminated above it.\n" << endl;
  }
  if (num == 4) {
    cout << "A woman with a large mouth sits in a chair facing the door as you enter. She opens her wide mouth and shows you a devilish grin. 'Move now, " << name << " The North is your home. Mother waits.\n" << endl;
  }
  if (num == 5) {
    cout << "The room is almost entirely pitch black. Some eminence brings a shade of light into the centre of the room. All around are masked spirits in tattered Native American garb. A voice cries in the darkness, repeating the same lines over and over, '" << name << ", Father is angry. You should've came home. Don't go West. Don't go West.\n" << endl;
  }
}
void getNewDescription() {
  cout << "\nThe voices have calmed down. The light has grown such that you can make out the edges of the room. All the walls are bare except for the Western wall, which offers a door with a golden handle.\n" << endl;
}
void ProgramGreeting() {
  cout << "Welcome to your final demise!\nBrandon Montez\nMay 19, 2021\n" << endl;
}