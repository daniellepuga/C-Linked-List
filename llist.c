#include "llist.h"

void llist_insert_head(struct node **head, struct node *n)
{
  // insert node n at the head of the list. this node should have
  // previously allocated with node_alloc()
}

struct node *llist_delete_head(struct node **head)
{
  // remove a node from the head of the list and return a pointer
  // to it. return NULL if list is empty. this function will not
  // free the node; just uncouples it from the list
}

void llist_insert_tail(struct node **head, struct node *n)
{
  // insert node n at the tail of the list. this node should have
  // previously been allocated with node_alloc()
}

void llist_print(struct node *head)
{
  // prints a list to standard output in this form:
  // 1 -> 12 -> 3490 -> 7
  // with no trailing or leading spaces on the line. 
  // if the list is empty, the string
  // [empty]
  // (including square brackets), should be printed
}

void llist_free(struct node **head)
{
 // call node_free() for every node in the list. head will be
 // sent to NULL
}

struct node *node_alloc(int value)
{
  // allocate a new struct node with value 3490 and a next of NULL
}

void node_free(struct node *n)
{
  // free a node previously allocated with node_alloc().
}