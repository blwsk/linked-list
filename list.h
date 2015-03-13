#include <stdlib.h>
#include <stdio.h>


/* Generic doubly linked list node */
typedef struct node {
  void * data;
  struct node *prev;
  struct node *next;
}Node;


/* List structure */
typedef struct list {
  struct node *head;
}List;


/* "Constructors" for Node and List */
Node * newNode(void *data, Node *prev, Node *next);
List * newList(Node *head);

/*
  Interface for doubly linked list functions
    - traverse the list using the next field (forward traversal)
    - traverse the list using the prev field (backward traversal)
    - insert a node at the end of the list
    - delete a node from the list
    - return the item from a particular node in the list
    - etc.
*/


void add(List *list, Node *node);
void printList(List *list);


