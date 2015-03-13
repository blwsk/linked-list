#include "list.h"

int main() {
  char a;
  char *p1;
  a = 'a';
  p1 = &a;
  Node *head = newNode(p1, NULL, NULL);
  List *list = newList(head);

  char b;
  char *p2;
  b = 'b';
  p2 = &b;
  Node *two = newNode(p2, NULL, NULL);
  add(list, two);

  int c;
  int *p3;
  c = 3;
  p3 = &c;
  add(list, newNode(p3, NULL, NULL));

  printList(list);

  return 0;
}

Node * newNode(void *data, Node *prev, Node *next) {
  Node *n;
  n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->prev = prev;
  n->next = next;
  return n;
}

List * newList(Node *head) {
  List *l;
  l = (List *)malloc(sizeof(List *));
  l->head = head;
  return l;
}

/* Adds a new node to the end of the list */
void add(List *list, Node *node) {
  Node *current;
  current = list->head;

  // traverse to the end of the list
  while(current->next != NULL) {
    current = current->next;  // increment
  }

  current->next = node;
  node->prev = current;
  node->next = NULL;
}

/* Prints the data for each node in the list */
void printList(List *list) {
  Node *current;
  current = list->head;

  // traverse to the end of the list
  while(current->next != NULL) {
      printf("%p\n", current->data);
    current = current->next;  // increment
  }
  printf("%p\n", current->data);  // prints the last one
}

















