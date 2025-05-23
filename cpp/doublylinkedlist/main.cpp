#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ifstream input("input.txt");
ofstream output("output.txt");

// this program recieves a text file (input.txt) formatted as a list with newlines between each element.
// you can delete an item from the list with a <delete [item name]> command in the input text. 
// input assumes everything is lower case.
// this program outputs a text file (output.txt) of the final list in first ascending and then descending order.

struct Node {
  Node *prev = NULL;
  Node *next = NULL;
  string name = "";
};

void add(Node *&, Node *&, string);
void remove(Node *&, Node *&, string);

int main() {
  string word;

  Node *head = NULL;
  Node *tail = NULL;
  
  while(input.good() && input >> word) {
    if (word == "delete") {
      input >> word;  // move to next word
      remove(head, tail, word);
    }
    else {
      add(head, tail, word);
    }
  }

  // traverse and output to file
  Node *curr = NULL;

  // forwards
  curr = head;
  while(curr) {
    output << curr->name << endl;
    curr = curr->next;
  }

  // formatting 
  output << "================" << endl;

  // backwards
  curr = tail;
  while(curr) {
    output << curr->name << endl;
    curr = curr->prev;
  }

  input.close();
  output.close();
}

void add(Node*&head, Node*&tail, string word) {
  Node *curr = head;
  Node *nn = new Node;
  nn->name = word;
  
  if(!head) {
    head = nn;
    tail = nn;
  }
  else if (word <= head->name) {  // if smaller than head
    // add word to head
    nn->next = head;
    nn->prev = head->prev;  // redundant since head prev is null and all nodes default to null
    head->prev = nn;
    head = nn;
  }
  else if (word > tail->name) {  // if greater than tail
    // add word to tail
    nn->prev = tail;
    nn->next = tail->next;  // redundant
    tail->next = nn;
    tail = nn;
  }
  else {
    // find the location to insert
    while(word > curr->name) {
      curr = curr->next;
    }
    nn->prev = curr->prev;
    nn->next = curr;
    curr->prev->next = nn;
    curr->prev = nn;
  }
}

void remove(Node*&head, Node*&tail, string word) {
  Node *curr = head;

  while(curr->name < word && curr->next) {
    curr = curr->next;
  }

  // check if we found word or reached end of list
  if (curr->name == word) {
    // check if deleting head
    if(curr->prev)  // not head
      curr->prev->next = curr->next;
    else  // is head
      head = curr->next;
    
    // check if deleting tail
    if(curr->next)  // not tail
      curr->next->prev = curr->prev;
    else  // is tail
      tail = curr->prev;
  }
  else {
    // reached end of list and no match so do nothing
  }
}