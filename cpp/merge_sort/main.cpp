// Brandon Montez
// merge_sort.cpp
// 3/20/22

#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node *next = NULL;
};

// function headers
void split(Node *head, Node *&a, Node *&b);
Node *merge(Node *a, Node *b);
Node *mergeSort(Node *head);
void push(Node **head_ref, int new_data);
void printList(Node *node);

int main()
{
    // make test list
    Node *list = NULL;
    push(&list, 50);
    push(&list, 12);
    push(&list, 6);
    push(&list, 1);
    push(&list, 13);
    push(&list, 120);
    push(&list, -71);
    push(&list, 0);

    // print test list
    cout << "\nOriginal Linked List is: \n";
    printList(list);
    cout << endl
         << endl;

    // sort list
    list = mergeSort(list);

    // print sorted list
    cout << "\nSorted Linked List is: \n";
    printList(list);
    cout << endl;

    return 0;
}

Node *mergeSort(Node *head)
{
    Node *a;
    Node *b;
    Node *c;

    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;

    split(head, a, b);

    a = mergeSort(a);
    b = mergeSort(b);
    c = merge(a, b);
    return c;
}

Node *merge(Node *a, Node *b)
{
    Node *c;

    // intitilaize first value
    if (a->data <= b->data)
    {
        c = a;
        a = a->next;
    }
    else
    {
        c = b;
        b = b->next;
    }

    Node *curr = c;

    // loop until one list terminates
    while (a && b)
    {
        if (a->data <= b->data)
        {
            curr->next = a;
            curr = curr->next;
            a = a->next;
        }
        else
        {
            curr->next = b;
            curr = curr->next;
            b = b->next;
        }
    }

    // now append the remaining list
    while (a)
    {
        curr->next = a;
        curr = curr->next;
        a = a->next;
    }
    while (b)
    {
        curr->next = b;
        curr = curr->next;
        b = b->next;
    }

    return c;
}

// split linked list into two
// pass split lists back by reference
void split(Node *head, Node *&a, Node *&b)
{
    Node *fast;
    Node *slow;
    slow = head;
    fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    a = head;
    b = slow->next;
    slow->next = NULL;
}

// print linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

// push linked list
void push(Node **head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head);
    (*head) = new_node;
}