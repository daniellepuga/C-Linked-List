#include "llist.h"

int main(int argc, char** argv)
{
  // initialize head of new linked list as NULL
  struct node *head = NULL;

  // for loop checking each individual argv for a match to
  // each function and then executing each function
  for(int position = 1; position < argc; position++)
  {
    if(strcmp(argv[position], "ih") == 0)
    {
      int val = atoi(argv[++position]);
      struct node *inserted_node = node_alloc(val);
      llist_insert_head(&head, inserted_node);
    }
    else if(strcmp(argv[position], "it") == 0)
    {
      int val = atoi(argv[++position]);
      struct node *inserted_node = node_alloc(val);
      llist_insert_tail(&head, inserted_node);
    }
    else if(strcmp(argv[position], "dh") == 0)
    {
      llist_delete_head(&head);
    }
    else if(strcmp(argv[position], "f") == 0)
    {
      llist_free(&head);
    }
    else if(strcmp(argv[position], "p") == 0)
    {
      llist_print(head);
    }
    else{
      printf("please enter one of the following commands followed by numeric values.\n 'ih', 'it', 'dh', 'f', 'p'\n");
      exit(0);
    }
  }
}

void llist_insert_head(struct node **head, struct node *n)
{
  // insert node n at the head of the list. this node should have
  // previously allocated with node_alloc()
  n->next = *head;
  *head = n;
}

struct node *llist_delete_head(struct node **head)
{
  // remove a node from the head of the list and return a pointer
  // to it. return NULL if list is empty. this function will not
  // free the node; just uncouples it from the list
  if(*head == NULL)
  {
    return NULL;
  }
  else 
  {
    // store the head in a temp value
    struct node *temp = *head;
    // change head pointer to next node
    *head = (*head)->next;
    // return the temp
    return temp;
  }
}

void llist_insert_tail(struct node **head, struct node *n)
{
  // insert node n at the tail of the list. this node should have
  // previously been allocated with node_alloc()

  // if the list is empty then this new node is the head

  // structure help from 
  // https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/
  if(*head == NULL)
  {
    *head = n;
  }

  // we make a new node
  else
  {
    struct node *tail_node = *head;

    // traverse until last node
    while (tail_node->next != NULL)
    {
      tail_node = tail_node->next;
    }
    // change the next of the last node
    tail_node->next = n;
  }
}

void llist_print(struct node *head)
{
  // prints a list to standard output in this form:
  // 1 -> 12 -> 3490 -> 7
  // if the list is empty, the string
  // [empty]
  // (including square brackets), should be printed

  // https://www.geeksforgeeks.org/doubly-linked-list/ used for help on
  // how to set up a print function with pointers.
  if(head == NULL)
  {
    printf("[empty]");
  }
  else 
  {
    // we need this statement since should not have a -> in front
    printf("%d", head->value);

    // and then update pointer
    struct node *next_node = head->next;

    // then loop with -> in front of values we want to display
    while(next_node != NULL)
    {
      printf(" -> %d", next_node->value);
      next_node = next_node->next;
    }
  }
  printf("\n");
}

void llist_free(struct node **head)
{
 // call node_free() for every node in the list. head will be
 // sent to NULL. if the list is free then our job is already done!
 // delete all the nodes.

  if(*head == NULL)
  {
    return;
  }
  else 
  {
    // get to the real head
    struct node *current_node = *head;
    struct node *next_node = current_node->next;

    // loop through all nodes and free each one
    while(next_node != NULL)
    {
      next_node = current_node->next;
      free(current_node);
      current_node = next_node;
    }
    // dereference head to effect the real head back in the caller
    *head = NULL;
  }
}

struct node *node_alloc(int value)
{
  // allocate a new struct node with value passed in and a next of NULL
  struct node *inserted_node = malloc(sizeof(struct node));
  // adding value to our newly inserted node
  inserted_node->value = value;
  // making the next value NULL by default
  inserted_node->next = NULL;
  return inserted_node;
}

void node_free(struct node *n)
{
  // free node passed in
  free(n);
}
