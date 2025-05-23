// hokeemon.cpp
// Brandon Montez
// 11/28/21

// https://drive.google.com/file/d/1Wbzot211InwXqRErWJc1nFH6ku_ywKsP/view

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// Specification C2 - Creature class
class Creature {
  protected:
    int hunger, boredom;
    bool dead = false, catatonic = false;
    string name = "Hokeemon";

  public:
    Creature() {
      hunger = rand() % 6;
      boredom = rand() % 6;
    }

    // setters
    void set_dead(bool b) { dead = b; }
    void set_catatonic(bool b) { catatonic = b; }
    void set_name(string s) { name = s; }

    // getters
    bool get_dead() { return dead; }
    string get_name() { return name; }

    void listen() {
      if (not dead && not catatonic) {
        cout << name << ": My hunger level is: " << hunger << endl;
        cout << name << ": My boredom level is: " << boredom << endl;
        // check health status
        cout << *this;
      }
    }

    void play() {
      if (not dead && not catatonic) {
        int play = rand() % 5 + 4;
        boredom -= play;
        cout << "You play with " << name << " for " << play << " hours." << endl;
        // check health status
        cout << *this;
      }
    }

    void feed() {
      if (not dead && not catatonic) {
        int food = rand() % 4 + 3;
        hunger += food;
        cout << "You reach into your sack and give " << food << " food items to " << name << endl;
        // check health status
        cout << *this;
      }
    }

    // Specification C1 - PassTime()
    void turn() {
      if (not dead && not catatonic) {
        hunger -= 1;
        boredom += 1;
      }
      // check health status
      cout << *this;
    }

    void Component_Test() {
      cout << "Testing Creature class..." << endl;
      cout << "Displaying expected status levels." << endl;
      cout << "Hokeemon: My hunger level is: (0-5)\nHokeemon: My boredom level is: (0-5)" << endl;
      cout << "Displaying current status levels." << endl;
      this -> listen();
      cout << "Setting hunger below 0." << endl;
      cout << "Expecting dead status..." << endl;
      hunger = -100;
      cout << *this;
      cout << "\nEnd of Creature testing.\n" << endl;
    }

    friend ostream &operator<<(ostream &output, Creature &c);
};


// Specification B1 - Child Class
class Tezmon : public Creature {
  private:
  public:
    void Component_Test() {
      cout << "Testing Tezmon class..." << endl;
      cout << "Displaying expected status levels." << endl;
      cout << "Hokeemon: My hunger level is: (0-5)\nHokeemon: My boredom level is: (0-5)" << endl;
      cout << "Displaying current status levels." << endl;
      this -> listen();
      cout << "Setting hunger below 0." << endl;
      cout << "Expecting dead status..." << endl;
      hunger = -100;
      cout << *this;
      cout << "\nEnd of Tezmon testing.\n" << endl;
    }
};


// Specification A3 - Second Child Class
class Sadmon : public Creature {
  private:
  public:
    void Component_Test() {
      cout << "Testing Sadmon class..." << endl;
      cout << "Displaying expected status levels." << endl;
      cout << "Hokeemon: My hunger level is: (0-5)\nHokeemon: My boredom level is: (0-5)" << endl;
      cout << "Displaying current status levels." << endl;
      this -> listen();
      cout << "Setting hunger below 0." << endl;
      cout << "Expecting dead status..." << endl;
      hunger = -100;
      cout << *this;
      cout << "\nEnd of Sadmon testing.\n" << endl;
    }
};


void ComponentTesting();
void ProgramGreeting();
char Menu_Selection();


int main() {
  char sel;
  bool extinction = false;
  string name;

  srand(time(0));

  ProgramGreeting();
  ComponentTesting();

  Tezmon c;

  // Specification A1 - Critter Name
  cout << "Please name your Hokeemon: ";
  getline(cin, name);
  c.set_name(name);

  do {
    switch (sel = Menu_Selection()) {
      case 'L': {
        cout << endl;
        c.listen();
        c.turn();
        break;
      }
      case 'P': {
        cout << endl;
        c.play();
        c.turn();
        break;
      }
      case 'F': {
        cout << endl;
        c.feed();
        c.turn();
        break;
      }
      case 'Q': {
        cout << "\nKlling " << c.get_name() << " and then quitting..." << endl;
        extinction = true;
        break;
      }
    }
    if (c.get_dead()) {
      cout << "\nYou were a bad handler, " << c.get_name() << " will haunt you forever." << endl;
      extinction = true;
    }
  } while (extinction == false);

  cout << "\nThanks for playing!" << endl;
} 


char Menu_Selection() {
  string inp;
  char i;
  bool bad_inp = true;
  // Specification C3 - Validate Input
  while (bad_inp) {
    cout << "\nSelect\n<L>isten\n<P>lay\n<F>eed\n<Q>uit\n" << endl;
    getline(cin,inp);
    i = toupper(inp[0]);
    if (i == 'L' || i == 'P' || i == 'F' || i == 'Q') {
      bad_inp = false;
    }
    else {
      cout << "\nPlease select a valid menu option." << endl;
    }
  }
  return i;
}


// Specification C4 - Overload «
ostream &operator<<(ostream &output, Creature &c) {
  if (c.catatonic) {
    output << endl << c.name << " is catatonic." << endl;
  }
  else if (20 < c.boredom) {
    c.set_catatonic(true);
    output << endl << c.name << " has become catatonic." << endl;
  }
  if (c.dead) {
    output << endl << c.name << " is dead." << endl;
  }
  else if (c.hunger < 0) {
    c.set_dead(true);
    output << endl << c.name << " has died." << endl;
  }
  return output;
}


void ProgramGreeting() {
  time_t now = time(0);
  tm *today = localtime(&now);

  cout << "Welcome to my program, here you can take care of your Hokeemon." << endl;
  cout << "Today's date: " << 1 + today->tm_mon << "/" << today->tm_mday << "/" << 1900 + today->tm_year << endl;
  cout << "-Brandon Montez.\n" << endl;
}


void ComponentTesting() {
  Creature test;
  test.Component_Test();
  Tezmon test1;
  test1.Component_Test();
  Sadmon test2;
  test2.Component_Test();
}
