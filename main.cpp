// CS260 - Winter 2024 - Assignment 04 - Arbitrary list operations
// Author: Eduarda (Duda) Reolon
// Description: This program creates a linked-list that can insert and remove a value into a given position of the list.
// This program can also return the value that is stored at a given position on the linked list without removing the value. 


#include <iostream>

using std::cout;
using std::endl;

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

    // This function prints the linked list and it is mostly used for testing
    void printList() {
        Node* iteration_ptr = head; //creates a pointer for the iteration, initially it stores the address of the head of the list
        // repeats while the iteration_ptr is not pointing to the last node of the list
        while (iteration_ptr != nullptr) { // the last node on the list points to nullptr as we defined on the add function
            cout << iteration_ptr->data << " "; // display the data of each node in the list
            iteration_ptr = iteration_ptr->next; // update the iteration pointer to point to the next node
        }
    }

    // This function adds a given value at a specific given position in the list
    void add(int value, int position) {
        // Test if the position given is a positive integer
        if (!isValid(position)) { // ! means 'is not'
            cout << "The position you inserted is not a positive integer, therefore is invalid and the value can't be added" << endl;
            return; // leave the function after sending error message
        }

        // Create the new node
        Node* ptr_newNode = new Node; // "new Node" allocates a memory location on the heap for an instance of a Node object
                                      // "Node* ptr_newNode" creates a pointer that stores the address of the "new Node" 
        ptr_newNode->data = value; // in the address of the new Node the data slot becomes the value
        ptr_newNode->next = nullptr; // and in that same address, the next slot becomes nullptr
        // The new node needs to point to something when initialized otherwise the system will point it to garbage data
        // since we do not know yet where this node will be in the list, point it to nullptr
        // ptr_newNode = address of the new node

        // check if the 
        if (position == 0 || isEmpty()) { // check if the position inserted is 0 or if the list is empty
            ptr_newNode->next = head; // then the new node will point to the head 
            head = ptr_newNode; // and the head pointer is updated to point to to new node address

        } else {
            Node* iteration_ptr_2 = head; // creates another pointer for the iteration that will start pointing at the head node

            // for loop to check if the inserted position is actually a positing in the list
            for (int i = 0; i < position - 1; ++i) { // only needs to go to position-1 because we will be iterating on the nodes 'next' addresses and the address of the 
                                                     // node on the inserted position is stored on the node that comes before it
                                                     // we need the address of the node in the position in order to change its data and its next address
                if (iteration_ptr_2->next == nullptr) { // if position-1 points to nullptr, aka is the last node of the list
                    cout << "The position you entered is too big for this list" << endl;
                    return;
                }
                iteration_ptr_2 = iteration_ptr_2->next;
            }


            // After the for loop iteration_ptr_2 has the address of the node that comes before the node in the inserted position 
            // the node at position-1 points ('next') to the node at the position
            // the new node 'next' address then becomes the position-1 'next' address, so the new node now points at node that was at this position 
            ptr_newNode->next = iteration_ptr_2->next;
            // and the node at position-1 is updated to point at the new node
            iteration_ptr_2->next = ptr_newNode;
        }
    }

};