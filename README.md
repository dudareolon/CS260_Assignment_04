# CS260_Assignment_04
Eduarda Reolon - Arbitrary list operations

Description: This program creates a linked-list that can insert and remove a value into a given position of the list. This program can also return the value that is stored at a given position on the linked list without removing the value. 

---------------------------------------------------------------------------------------------------

Design: 

1- Create a struct for the Node description. This is a Node:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/0559feee-1f6b-4e2a-8a97-62877bec0c27)

Figure 1

A node has a slot for the data stored and a slot for the adress of the next node (or nullptr if there is not a next node).

2- Make the linked list class. This is a linked list:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/c0daa417-4969-4db2-83c6-c2f76aa93582)

Figure 2

To initialize the linked list, I will need to create a variable of the type Node pointer, in other words, use the pointer part of the Node struct and not the data part yet (the node will start empty). Then set this node to point to nullptr since there is nothing else on the linked list. After this point the linked list will look like this:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/41a0a5e8-25f1-4ad8-b22c-5d443edb784a)

Figure 3

As we add more nodes to the linked list the head node will not be pointing to nullptr anymore. On figure 2, node 1 represents the Head Node. 

Big picture desing of the class:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/b1140f76-70ad-4cd3-90c9-107afb92391f)

Figure 4

Design of the add function:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/0e7222ae-b8e1-4527-be30-dd72b369570a)

Figure 5

Desing of the remove function:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/1f7712c2-16e0-414c-a199-43067472d129)

Figure 6

Design of the get function:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/10b8e1b4-f1ae-4813-87e9-7ed2c0c0314a)

Figure 7

The get function could have been as short as three lines long, if it was not for the user input checks that I did.

---------------------------------------------------------------------------------------------------

The parts of the code where I meet each one of the requirements are the following:

Requirement 1: an add function that takes a value and inserts it into a given position into the list:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/b391c4eb-5583-44ed-b861-5e4c99ccf0cf)

Figure 8

Requirement 2: a remove function that takes a position and removes the value stored at that position of the list and returns it:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/1605c6cc-4ac8-4e97-a1ac-a56085278f9d)

Figure 9

Requirement 3: a get function that takes a position and returns that value without removing it:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/68dff05b-e0c7-4cf3-b5be-ed26133d4979)

Figure 10



