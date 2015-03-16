#include "list.h"

int main() {

  List l;
  l = newList();

  char a = 'a';
  char b = 'b';
  char c = 'c';
  add(l, &a);
  add(l, &b);
  add(l, &c);

  return 0;
}


List newList(void) {
  List new;
  new = (List)malloc(sizeof(List));

  Node_t *head;
  head->data = NULL;
  head->next = NULL;
  head->prev = NULL;

  new->head = head;
  return new;
}


/* Adds a new node to the end of the list */
void add(List list, void *item) {
  
  Node_t *new;
  new = (Node_t *)malloc(sizeof(Node_t));
  new->data = item;
  
  Node_t *current;
  current = list->head;

  while(next(current) != NULL) {
    current = current->next;
  }

  current->next = new;
  new->next = NULL;
  new->prev = current;

}


/* Returns the number of nodes in the list */
int length(List list) {
  int count;
  count = 0;

  Node_t *current;
  current = list->head;

  while(current->next != NULL) {
    count++;
    current = current->next;
  }

  return count;
}


/*
  The following functions traverse the list forwards (next) 
  and backwards (prev)
*/
Node_t * next(Node_t *node) {
  return node->next;
}

Node_t * prev(Node_t *node) {
  return node->prev;
}


/*
  Deletes the node from its list
*/
void del(Node_t *node) {
  Node_t *tempPrev;
  Node_t *tempNext;

  assert(prev(node) != NULL);
  assert(next(node) != NULL);

  tempPrev = prev(node);
  tempNext = next(node);

  free(node);

  tempPrev->next = tempNext;
  tempNext->prev = tempPrev;
}

/*
  Returns the data payload for node
*/
void * data(Node_t *node) {
  assert(node != NULL);

  return (void *)node->data;
}























