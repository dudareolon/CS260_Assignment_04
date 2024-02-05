# CS260_Assignment_04
Eduarda Reolon - Arbitrary list operations

Description: This program creates a linked-list that can insert and remove a value into a given position of the list. This program can also return the value that is stored at a given position on the linked list without removing the value. 

---------------------------------------------------------------------------------------------------

Design: 

1- Create a struct for the Node description. This is a Node:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/0559feee-1f6b-4e2a-8a97-62877bec0c27)

A node has a slot for the data stored and a slot for the adress of the next node (or nullptr if there is not a next node).

2- Make the linked list class. This is a linked list:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/c0daa417-4969-4db2-83c6-c2f76aa93582)

To initialize the linked list, I will need to create a variable of the type Node pointer, in other words, use the pointer part of the Node struct and not the data part yet (the node will start empty). Then set this node to point to nullptr since there is nothing else on the linked list. After this point the linked list will look like this:

![image](https://github.com/dudareolon/CS260_Assignment_04/assets/102680672/41a0a5e8-25f1-4ad8-b22c-5d443edb784a)

As we add more nodes to the linked list the head node will not be pointing to nullptr anymore.






