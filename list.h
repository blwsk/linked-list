#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/*
  Generic doubly linked list node
*/
typedef struct node {
  void * data;
  struct node *prev;
  struct node *next;
}Node_t;

/*
  Generic doubly linked list structure
*/
typedef struct list {
  Node_t *head;
}List_t;

typedef List_t * List;


/*
  Returns a new list
*/
List newList(void);

/*
  Adds a new node to the list with payload item
*/
void add(List list, void *item);

/*
  Returns the number of nodes in the list
*/
int length(List list);

/*
  The following functions traverse the list forwards (next) 
  and backwards (prev)
*/
Node_t * next(Node_t *node);
Node_t * prev(Node_t *node);

/*
  Deletes the node from its list
*/
void del(Node_t *node);

/*
  Returns the data payload for node
*/
void * data(Node_t *node);

