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

    public:
    // Create an empty list
    Node* head; // A node with no inserted data but points to the head of the list

    // A constructor (ctor) is a special type of function called to create an object, it prepares the new object for use, such as letting it receive input arguments
    LinkedList() : head(nullptr) {} // constructed a Linked List that has the pointer head with the address of nullptr

    // This function checks if the linked list is empty so that my other functions are more readable
    bool isEmpty()const { // it returns true or false
        return head == nullptr; // if the head pointer is pointing to nullptr that means that there are no nodes and the list is empty
    }

    // This function checks if the value inserted is a positive integer or 0
    // Linked lists do not have negative positions, they start from 0 until n, increasing by 1
    bool isValid(int position) const {
        return position >= 0; // return true if position is an integer bigger or equal to 0
    }   

    // This function prints the linked list and it is mostly used for testing
    void printList() const{
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
            Node* iteration_ptr = head; // creates another pointer for the iteration that will start pointing at the head node

            // for loop to check if the inserted position is actually a positing in the list
            for (int i = 0; i < position - 1; ++i) { // only needs to go to position-1 because we will be iterating on the nodes 'next' addresses and the address of the 
                                                     // node on the inserted position is stored on the node that comes before it
                                                     // we need the address of the node in the position in order to change its data and its next address
                if (iteration_ptr->next == nullptr) { // if position-1 points to nullptr, aka is the last node of the list
                    cout << "The position you entered is too big for this list" << endl;
                    return;
                }
                iteration_ptr = iteration_ptr->next;
            }


            // After the for loop iteration_ptr_2 has the address of the node that comes before the node in the inserted position 
            // the node at position-1 points ('next') to the node at the position
            // the new node 'next' address then becomes the position-1 'next' address, so the new node now points at node that was at this position 
            ptr_newNode->next = iteration_ptr->next;
            // and the node at position-1 is updated to point at the new node
            iteration_ptr->next = ptr_newNode;
        }
    }

    // This function removes the value at a given location
    int remove(int position) { 
        if (!isValid(position) || isEmpty()) { //check if input is no valid or if the list is empty
            cout << "the position you entered is not a positive integer or 0, or the list is empty" << endl;
            return 0;
        }

        int removedValue; // variable that will store the deleted value to be returned

        // check if the position inserted is 0
        // If position==0 then the node that needs to be removed is the node head is pointing to
        if (position == 0) {
            Node* ptr_removedNode = head; // now ptr_removedNode has the address of the head pointer
            head = head->next; // head is updated to store the address of the next node
            removedValue = ptr_removedNode->data; // data of removed node is stored in the variable that will be returned


        } else {
            Node* iteration_ptr_2 = head; // same iteration as the add function for the same reasons
            for (int i = 0; i < position - 1; ++i) {

                if (iteration_ptr_2->next == nullptr) { // if position-1 points to nullptr, aka is the last node of the list
                    cout << "The position you entered is too big for this list" << endl;
                    return 0;
                }

                iteration_ptr_2 = iteration_ptr_2->next; 
            }

            // at the end of the loop, the iteration pointer has the address of position - 1 

            Node* ptr_removedNode = iteration_ptr_2->next; // create a pointer that stores the value of the node to be removed
            iteration_ptr_2->next = ptr_removedNode->next; // Update the nodes so that position -1 node's 'next' value is the 'next' value of the node removed. 
            removedValue = ptr_removedNode->data; 
        }

        return removedValue;
    }

    // This function gets the value at a specific input location without removing it
    int get(int position) const { 
        if (!isValid(position) || isEmpty()) { // this if check is the same as the one in the remove function
            cout << "the position you entered is not a positive integer or 0, or the list is empty" << endl;
            return 0; 
        }

        Node* iteration_ptr_3 = head; // iteration pointer is initialized with the address of head, which is the first node in the list
        for (int i = 0; i < position; ++i) {
            // this iteration goes from 0 until the inserted position, different than the one used on the add and on the remove functions
                if (iteration_ptr_3->next == nullptr) { 
                cout << "The position you entered is too big for this list" << endl;
                return 0;
            }
            iteration_ptr_3 = iteration_ptr_3->next;
        }

        // at the end of the for loop the iteration pointer has the address of the node we want to get
        // return the data of this node
        return iteration_ptr_3->data;
    }


};

int main() {
    // create a list under the linked list class
    LinkedList myList;

    // Test 1:
    // test if the add function is working properly:
    myList.add(10, 0);
    myList.add(20, 1);
    myList.add(30, 1); // this will shift 20 to the right and 30 will be stored in the spot 1
    cout << "List after initial adds: ";
    myList.printList();
    cout << endl;
    // Output:
    // List after initial adds: 10 30 20 
    // Correct 


    // Test 2:
    // test if the remove function works properly
    int removedValue = myList.remove(2);
    cout << "Removed value: " << removedValue << endl; // the value on the slot number 2 must be removed and the list that had 3 elements will now have 2
    cout << "List after removing the value: ";
    myList.printList();
    cout << endl;
    // Output:
    // Removed value: 20
    // List after removing the value: 10 30 
    // Correct


    // Test 3:
    // test if the get function works
    int getValue = myList.get(1);
    cout << "The value in the linked list at the position you entered is: " << getValue << endl;
    // Output:
    // The value in the linked list at the position you entered is: 30
    // Correct

    // Test 4:
    // test if the functions display error messages correctly
    myList.get(6);
    myList.get(-6);
    myList.add(20, 15);
    myList.add(20, -15);
    myList.remove(300);
    myList.remove(-300);
    // Output:
    // The position you entered is too big for this list
    // the position you entered is not a positive integer or 0, or the list is empty
    // The position you entered is too big for this list
    // The position you inserted is not a positive integer, therefore is invalid and the value can't be added
    // The position you entered is too big for this list
    // the position you entered is not a positive integer or 0, or the list is empty
    // Correct

    return 0;
}