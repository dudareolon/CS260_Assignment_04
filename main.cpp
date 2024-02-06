// CS260 - Winter 2024 - Assignment 04 - Arbitrary list operations
// Author: Eduarda (Duda) Reolon
// Description: This program creates a linked-list that can insert and remove a value into a given position of the list.
// This program can also return the value that is stored at a given position on the linked list without removing the value. 


#include <iostream>

// The node struct defines what a 'data structure' node is
struct Node {
    int data; // a node is formed of a slot for the data
    Node* next; // and a slot for the address of the next node
};