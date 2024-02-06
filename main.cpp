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

// The Linked List class defines the linked list and its functions
class LinkedList {

    // Create an empty list
    Node* head; // A node with no inserted data but points to the head of the list

    // This function checks if the linked list is empty so that my other functions are more readable
    bool isEmpty() { // it returns true or false
        return head == nullptr; // if the head pointer is pointing to nullptr that means that there are no nodes and the list is empty
    }

    // This function checks if the value inserted is a positive integer or 0
    // Linked lists do not have negative positions, they start from 0 until n, increasing by 1
    bool isValid(int position) {
        return position >= 0; // return true if position is an integer bigger or equal to 0
    }   

};