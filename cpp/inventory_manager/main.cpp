// InvInq.cpp
// 10/10/21
// Brandon Montez

#include <iostream>
#include <sstream>
#include <string>
#include <ctime>  // not needed
using namespace std;


// Specification B1 - Date class
class Date {
  private:
    int moon, sun, cycle;  // month, day, year
  public:
    // Date() { moon = tm_mon; sun = tm_mday; cycle = tm_year; }
    Date() { moon = 9; sun = 9; cycle = 99; }
    Date(int mm, int ss, int cc) { moon = mm; sun = ss; cycle = cc; }
    void Display() { cout << moon << "/" << sun << "/" << cycle << endl; }

    // Specification B2 - ComponentTest method in Date
    // need to instantiate the class within itself to be a proper class test?
    void ClassTest() {
      cout << "Testing Date Class..." << endl;
      cout << "Date default value is: 9/9/99" << endl;
      cout << "Current value is: ";
      Display();
      cout << "Setting date to: 1/18/96" << endl;
      moon = 1;
      sun = 18;
      cycle = 96;
      cout << "Current value is: ";
      Display();
      cout << endl;
    }
};


class Item { 
  private:
    int item_id, quantity, whole_cost;
    Date date;
    
  public:
    friend ostream &operator<<(ostream &output, Item a);
    friend istream &operator>>(istream &input, Item &a);

    // used in overloaded istream operator
    void setFeatures(int id, int q, int wc) {
      item_id = id;
      quantity = q;
      whole_cost = wc;
    }

    // setters
    void setID(int id) { item_id = id; }
    void setQuant(int q) { quantity = q; }
    void setWcost(int wc) { whole_cost = wc; }

    // getters
    int getID() { return item_id; }
    int getQuant() { return quantity; }
    int getWcost() { return whole_cost; }
    int getRcost() { return whole_cost * 2; }
    void showDate() { date.Display(); }

    void ClassTest() {
      Item test;
      cout << "Testing Item Class..." << endl;
      cout << "Sending 1, 10, 100, to setFeatures." << endl;
      test.setFeatures(1, 10, 100);
      cout << "Getting item features -> ";
      cout << "ID: " << test.getID() << ", Quantity: " << test.getQuant() << ", Whole Cost: "
          << test.getWcost() << endl;
      cout << "Testing Rcost calculator (should be 200): ";
      cout << test.getRcost() << endl;
      cout << "Testing date display (should be 9/9/99): ";
      test.showDate();
      cout << endl;
    }
};


void ProgramGreeting();
void ShowMenu();
void UnitTest();
Item* AddItem(Item*, int);
Item* SubtractItem(Item*, int);
Item* EditBag(Item*, int);
void SpillBag(Item*, int);


int main() {
  string inp;
  char c_inp;
  bool valid_inp = 0;
  const int SLOTS = 1;
  int count = 0;

  // Specification C2 - Dynamic Array
  Item* bag = new Item[SLOTS];

  ProgramGreeting();

  // Specification A4 - UnitTest() method in main()
  UnitTest();

  // start program
  do {
    // get valid menu selection from user
    do {
      ShowMenu();
      getline(cin, inp);
      cout << endl;

      // Specification B3 - Menu Input Validation
      if ((inp != "a") & (inp != "A") & (inp != "d") & (inp != "D") & (inp != "e") &
          (inp != "E") & (inp != "s") & (inp != "S") & (inp != "q") & (inp != "Q"))
        cout << "Please select a valid menu option.\n" << endl;
      else
        valid_inp = 1;

    } while (valid_inp == 0);

    c_inp = toupper(inp[0]);

    // c_inp should now be a valid menu selection

    switch(c_inp) {
      case 'A': {
        // Specification C3 - Resize Array - add to end
        bag = AddItem(bag, count);
        count++;
        break;
      }
      case 'D': {
        // Specification C4 - Resize Array - subtract from end
        bag = SubtractItem(bag, count);
        if (count != 0)
          count --;
        break;
      }
      case 'E': {
        // Specification A1 - Edit Inventory
        bag = EditBag(bag, count);
        break;
      }
      case 'S': {
        // show inventory contents
        SpillBag(bag, count);
        break;
      }
      case 'Q': {
        cout << "Have a nice day.\n";
        break;
      }
    }
  } while (c_inp != 'Q');

  delete [] bag;
  bag = nullptr;

  return 0;
}


void ProgramGreeting() {
  cout << "\nWelcome to my program.\n";
  cout << "Here you will be able to manage an inventory of items.\n";
  cout << "Please don't break anything.\n";
  cout << "~Brandon Montez\n";
  cout << "-October 10, 2021\n" << endl;
}


// Specification A3 - Overload operator»
istream &operator>>(istream &input, Item &a) {
  int id, quant, cost;
  bool bad_id = true;

  // Specification B4 - Inventory Entry Input Validation
  do {
    cout << "Please input the item ID: ";
    input >> id;
    if (5 < to_string(id).length()) 
      cout << "Error, ID must be 5 digits or less." << endl;
    else 
      bad_id = false;
  } while (bad_id);
  
  cout << "Please input the quantity: ";
  input >> quant;
  cout << "Please input the wholesale cost: ";
  input >> cost;
  cout << endl;

  // modify the object with the data
  a.setFeatures(id, quant, cost);

  cin.clear();
  cin.ignore();
  return input;
}


// Specification A2 - Overload operator«
ostream &operator<<(ostream &output, Item a) {
  output << "\nID Number: " << a.getID() << "\nQuantity: " << a.getQuant() << "\nWholesale Cost: "
        << a.getWcost() << "\nRetail Cost: " << a.getRcost() << "\nDate: ";
  a.showDate();

  return output;
}


// Specification C1 - Alpha Menu
void ShowMenu() {
  cout << "Main Menu.\n<A>dd Item\n<D>elete Item\n<E>dit Item\n"
          "<S>how Inventory\n<Q>uit Program\n" << endl;
}


Item* AddItem(Item* bag, int count) {
  if (count == 0)
    cin >> bag[0];
  else {
    Item* bigbag = new Item[count + 1];
    // fill new bag with previous contents
    for (int i = 0; i < count; i++)
      bigbag[i] = bag[i];

    // insert new item
    cin >> bigbag[count];

    delete [] bag;
    bag = bigbag;
    bigbag = nullptr;
  }
  return bag;
}


Item* SubtractItem(Item* bag, int count) {
  if (count == 0)
    cout << "No more items to remove.\n" << endl;
  else if (count == 1) {
    bag[0].setFeatures(0, 0, 0);  // default feature values are 0
    cout << "Removed the last item from bag.\n" << endl;
    count--;
  }
  else {
    Item* smallbag = new Item[count - 1];
    for (int i = 0; i < count - 1; i++)
      smallbag[i] = bag[i];

    delete [] bag;
    bag = smallbag;
    smallbag = nullptr;

    cout << "Removed item from bag.\n" << endl;
    count--;
  }
  return bag;
}


Item* EditBag(Item* bag, int count) {
  int i, s, id, qu, wc;

  do {
    cout << "Please enter the index of the item to edit:" << endl;
    cin >> i;
    if (count <= i)
      cout << "Error: Index out of bounds.\n" << endl;
  } while (count <= i);

  do {
    cout << "\nWhich would you like to edit?" << endl;
    cout << "  1. Item ID\n  2. Quantity\n  3. Wholesale Cost\n" << endl;
    cin >> s;
    if (s < 1 || 3 < s) 
      cout << "Error: Select either 1, 2 or 3." << endl;
  } while (s < 1 || 3 < s);
  
  cout << endl;
  
  if (s == 1) {
    cout << "Enter updated Item ID value: " << endl;
    cin >> id;
    bag[i].setID(id);
  }
  else if (s == 2) {
    cout << "Enter updated Quantity: " << endl;
    cin >> qu;
    bag[i].setQuant(qu);
  }
  else if (s == 3) {
    cout << "Enter updated Wholesale Cost:" << endl;
    cin >> wc;
    bag[i].setWcost(wc);
  }
  else {
    cout << "Unknown error in Inventory Edit.\n" << endl;
  }
  cin.clear();
  cin.ignore();
  cout << endl;

  return bag;
}


void SpillBag(Item* bag, int count) {
  cout << "Showing " << count << " items...\n" << endl;
  for (int i = 0; i < count; i++)
    cout << "Index: " << i << bag[i] << endl;
}


void UnitTest() {
  // check date class
  Date dcheck;
  dcheck.ClassTest();

  // check item class
  Item icheck;
  icheck.ClassTest();
}