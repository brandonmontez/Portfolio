/* 
Insert 10 values into a min-heap from a file. 
Display the data, level by level. 
Then delete 5 items.
After each delete, display the heap, level by level.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void add(int[], int&, int);
void del(int[], int&); 
void swap(int[], int, int);
void dispHeap(int[], int);
void sd(int[], int, int);
void su(int[], int);

ifstream input("input.txt");


int main() {
  int data;
  int heap[10];
  int heap_size = 0;

  //add items to heap
  while(input.good() && input >> data)
    add(heap, heap_size, data);
  
  //display heap
  dispHeap(heap, heap_size);

  //delete from heap
  cout << "\n\tStarting delete...";
  for (int i = 0; i < 5; i++) {
    cout << "\n\n\t(" << i + 1
      << ")------------------------------------";
    del(heap, heap_size);
    dispHeap(heap, heap_size);
  }
  input.close();
  return 0;
}


void add(int heap[], int &size, int dat) {
  heap[size] = dat;
  su(heap, size);
  size++;
}

void del(int heap[], int &size) {
  if (size) {
    size--;
    heap[0] = heap[size];
    heap[size] = 0;
    sd(heap, size, 0);
  }
}

void swap(int arr[], int a, int b) {
  int c = arr[a];
  arr[a] = arr[b];
  arr[b] = c;
}

//shift-up
void su(int heap[], int pos) {
  int parent = (pos - 1) / 2;
  if (pos && heap[pos] < heap[parent]) {
    swap(heap, pos, parent);
    su(heap, parent);
  }
}

//shift-down
void sd(int heap[], int size, int parent) {
  int min;
  int lchild = parent * 2 + 1;
  int rchild = parent * 2 + 2;
  if (lchild < size) {
      if (lchild == size - 1)
        min = lchild;
      else {
        if (heap[lchild] < heap[rchild])
          min = lchild;
        else
          min = rchild;
      }
  }
  if (heap[min] < heap[parent]) {
    swap(heap, min, parent);
    sd(heap, size, min);
  }
}

void dispHeap(int heap[], int size) {
  cout << endl;
  for (int i = 0; i < size; i++) {
    string t = "\t\t\t\t\t\t";
    if (i == 1 || i == 3 || i == 7)
      cout << endl;
    if (i == 1 || i == 2)
      t = "\t\t\t\t";
    else if (3 <= i && i < 7)
      t = "\t\t ";
    else if (7 <= i && i <= 10)
      t = "\t ";
    cout << t << heap[i];
  }
  cout << endl;
}