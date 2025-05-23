// TODO.cpp
// 11/07/21
// Brandon Montez

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <cctype>
#include <cstdlib>

using namespace std;

class Todo {
  private:
    string task, date;

  public:
    Todo() {
      task = "Do something.";
      date = "99/99/9999";
    }

    // Specification A4 - Overload Constructor
    Todo(string inp) {
      task = inp;
      CreateDate();  // is it bad to call a function in the constructor? 
    }

    // Specification A1 - Overload Copy Constructor
    Todo(const Todo &t) {
      task = t.GetTask();
      date = t.GetDate();
    }

    void SetTask(string inp) {
      task = inp;
    }

    string GetTask() const {
      return task;
    }

    void CreateDate() {
      int mo, da, ye;

      // Specification A3 - System Date.
      time_t now = time(0);
      tm *today = localtime(&now);

      mo = 1 + today->tm_mon;
      da = today->tm_mday;
      ye = 1900 + today->tm_year;

      stringstream ss;
      ss << mo << "/" << da << "/" << ye;

      date = ss.str();
    }

    void SetDate(string d) {
      date = d;
    }

    string GetDate() const {
      return date;
    }

    friend ostream &operator<<(ostream &output, Todo &a);
    friend istream &operator>>(istream &input, Todo &a);

    // Specification A2 - Overload Assignment Operator
    

    // Specification C3 - Test TODO’s
    void ComponentTest () {
      cout << "Testing Todo class...\n" << endl;

      cout << "Testing default contructor:" << endl;
      Todo testing1;
      cout << "  Expected\n    Task: Do something.\n    Date: 99/99/9999" << endl;
      cout << "  Outcome\n" << "    Task: " << testing1.GetTask() << "\n    Date: " << testing1.GetDate() << endl << endl;

      cout << "Testing overloaded constructor:" << endl;
      Todo testing2("Overloaded constructor");
      cout << "  Expected\n    Task: Overloaded contructor\n    Date: (Today's date, given by the system)" << endl;
      cout << "  Outcome\n" << "    Task: " << testing2.GetTask() << "\n    Date: " << testing2.GetDate() << endl << endl;

      cout << "Testing SetTask function:" << endl;
      Todo testing3;
      testing3.SetTask("SetTask working");
      cout << "  Expected\n    Task: SetTask working\n    Date: 99/99/9999" << endl;
      cout << "  Outcome\n" << "    Task: " << testing3.GetTask() << "\n    Date: " << testing3.GetDate() << endl << endl;

      cout << "Testing CreateDate function:" << endl;
      Todo testing4;
      testing4.CreateDate();
      cout << "  Expected\n    Task: Do something.\n    Date: (Today's date, given by the system)" << endl;
      cout << "  Outcome\n" << "    Task: " << testing4.GetTask() << "\n    Date: " << testing4.GetDate() << endl << endl;

      cout << "Testing SetTask and CreateDate functions simultaneously:" << endl;
      Todo testing5;
      testing5.SetTask("SetTask and CreateDate");
      testing5.CreateDate();
      cout << "  Expected\n    Task: SetTask and CreateDate\n    Date: (Today's date, given by the system)" << endl;
      cout << "  Outcome\n" << "    Task: " << testing5.GetTask() << "\n    Date: " << testing5.GetDate() << endl << endl;

      cout << "Ending test on Todo class...\n\n" << endl;
    }
};


Todo* AddTask(Todo*, int, string);
Todo* DelTask(Todo*, int, int);
Todo MakeTodo(string);
Todo* MakeList(int);
void ShowTasks(Todo*, int);
void ProgramGreeting();
void ComponentTesting();


int main() {
  int size = 0;  // start size count at 0.
  int inv = 0;
  int list_count = 0;
  const int CAPACITY = 999;

  bool is_int = true;
  bool keep_going = true;

  string userinp;
  string task_or_invnumb;
  string read_task;
  string read_date;
  
  ProgramGreeting();
  ComponentTesting();

  // set dummy array to large size for transfering files
  // note this means we can only transfer lists of size CAPACITY or smaller
  Todo* dummy_list = new Todo[CAPACITY];  
  
  // Specification B4 - Persistence
  ifstream in_file("mytodolist.txt");
  if (in_file.is_open()) {
    string line;

    while (getline(in_file, line, '\n')) {
      // cout << "Line: " << line << endl;  // debugging

      stringstream ss(line);
      string read_task, read_date;

      getline(ss, read_task, ',');

      // cout << "Read task: " << read_task << endl;  // debugging
      dummy_list[list_count].SetTask(read_task);

      getline(ss, read_date, '\n');
      // cout << "Read date: " << read_date << endl;  // debugging
      dummy_list[list_count].SetDate(read_date);

      list_count++;
    }
    size = list_count;
  }
  
  // Specification C4 - TODO array
  Todo *list = MakeList(list_count);

  for (int i = 0; i < list_count; i++)
    list[i] = dummy_list[i];

  // delete the dummy list
  delete [] dummy_list;
  dummy_list = nullptr;

  do {
    cout << "Please input your task without any commas ('\\' to quit)." << endl;
    getline(cin, userinp);
    cout << endl;

    task_or_invnumb = userinp;
    task_or_invnumb.erase(0, 2);

    switch (userinp[0]) {
      // Specification B1 - + Symbol
      case '+': {
        list = AddTask(list, size, task_or_invnumb);
        size++;
        break;
      }
      // Specification B3 - - symbol
      case '-': {
        for (unsigned int i = 0; i < task_or_invnumb.length(); i++) {
          if (isdigit(task_or_invnumb[i]) == false) {
            is_int = false;
          }
        }

        if (is_int) {
          inv = stoi(task_or_invnumb);
          list = DelTask(list, size, inv);

          if ((size != 0) && (0 <= inv && inv < size)) {
            size--;
          }
          else {
            break;
          }
        }
        else {
          cout << "Error, input is not a number.\n" << endl;
        }

        // reset is_int
        is_int = true;
        break;
      }
      // Specification B2 - ? Symbol
      case '?': {
        ShowTasks(list, size);
        break;
      }
      // end program
      case '\\': {
        keep_going = false;
        break;
      }
      // unknown error
      default: {
        cout << "Error while interpreting user input.\n" << endl;
        break;
      }
    }
  } while (keep_going);

  // store records in a text file before exiting
  ofstream out_file("mytodolist.txt");
  if (out_file.is_open()) {
    for (int i = 0; i < size; i++) {
      out_file << list[i].GetTask() << "," << list[i].GetDate() << endl;
    }
  }
  else {
    cout << "Error opening file." << endl;
  }
  out_file.close();

  return 0;
} 


Todo* AddTask(Todo* list, int size, string task) {
  if (size == 0) {
    list[0].SetTask(task);
    list[0].CreateDate();
  }
  else {
    Todo* biglist = new Todo[size + 1];

    for (int i = 0; i < size; i++) {
      biglist[i] = list[i];
    }

    Todo t = MakeTodo(task);

    biglist[size] = t;  // add new object to the end of biglist

    delete [] list;
    list = biglist;
    biglist = nullptr;
  }

  cout << "Added task.\n" << endl;

  return list;
}

Todo* MakeList(int len) {
  if (len) {
    Todo* list = new Todo[len];
    return list;
  }
  else {
    Todo* list = new Todo[1];
    return list;
  }
}


Todo MakeTodo(string task) {
  if (task == " ")
    return Todo();
  else
    return Todo(task);
}


Todo* DelTask(Todo* list, int size, int id) {

  bool removed_id = false;

  if (size == 0) {
    cout << "No tasks to remove.\n" << endl;
  }
  else if (size <= id || id < 0) {
    cout << "Invalid ID number.\n" << endl;
  }
  else if (size == 1) {
    list[id].SetTask("Nothing to do.\n");
    list[id].CreateDate();
  }
  else {
    Todo* small_list = new Todo[size - 1];
    for (int i = 0; i < size - 1; i++) {
      if ((i != id) && (removed_id == false)) {
        small_list[i] = list[i];
      }
      else {
        small_list[i] = list[i + 1];
        removed_id = true;
      }
    }

    delete [] list;
    list = small_list;
    small_list = nullptr;

    cout << "Removed task #" << id << endl << endl;
  }
  return list;
}


void ShowTasks(Todo* list, int size) {
  for (int i = 0; i < size; i++) {
    cout << i << ". " << list[i] << endl;
  }
  cout << endl;
}


void ComponentTesting() {
  Todo test;
  test.ComponentTest();
}


// Specification C2 - Overload »
// not used
istream &operator>>(istream &input, Todo &a) {
  string userstr = "";
  string task = "";

  cout << "Please input the task." << endl;
  input >> userstr;

  task = userstr;
  task.erase(0, 2);

  a.SetTask(task);
  a.CreateDate();

  return input;
}


// Specification C1 - Overload «
// used in ShowTasks() function.
ostream &operator<<(ostream &output, Todo &a) {
  output << a.GetDate() << " - " << a.GetTask();
  return output;
}


void ProgramGreeting() {
  time_t now = time(0);
  tm *today = localtime(&now);

  cout << "Welcome to my program, here you can create a todo list." << endl;
  cout << "Today's date: " << 1 + today->tm_mon << "/" << today->tm_mday << "/" << 1900 + today->tm_year << endl;
  cout << "-Brandon Montez.\n" << endl;
}