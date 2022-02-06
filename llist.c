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
 // sent to NULL
}

struct node *node_alloc(int value)
{
  // allocate a new struct node with value passed in and a next of NULL
  struct node *inserted_node = malloc(sizeof(struct node));
  inserted_node->value = value;
  inserted_node->next = NULL;
  return inserted_node;
}

void node_free(struct node *n)
{
  // free node passed in
  free(n);
}

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
			printf("%s\n", "ih");
    }
    else if(strcmp(argv[position], "it") == 0)
    {
      int val = atoi(argv[++position]);
      struct node *inserted_node = node_alloc(val);
      llist_insert_tail(&head, inserted_node);
			printf("%s\n", "ih");
    }
    else if(strcmp(argv[position], "dh") == 0)
    {
      llist_delete_head(&head);
			printf("%s\n", "dh");
    }
    else if(strcmp(argv[position], "f") == 0)
    {
      llist_free(&head);
			printf("%s\n", "f");
    }
    else if(strcmp(argv[position], "p") == 0)
    {
      llist_print(head);
			printf("%s\n", "p");
    }
    else{

    }

  }
}