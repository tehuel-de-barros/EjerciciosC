#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node {
  int value;
  struct node *next;
}node;
//

node *stack = NULL;

void push(int item) {
  node *t = stack;
  stack = malloc(sizeof(node));
  stack -> value = item;
  stack -> next = t;
}
bool isempty(void) {
  return stack == NULL ? true : false;
}

int pop ( void ) {
  if (isempty()) {
    printf("Pila vacia\n");
    return -127;
  }
  int val = stack -> value;
  node *t = stack;
  stack = stack->next;
  free(t);
  return val;
}



void printsatck (void) {

    for (node *x = stack; x != NULL; x = x->next) {
        printf("%d ", x -> value);
        printf("\n");
    }
}


int main(int argc, char const *argv[]) {
  push(1);
  push(1);
  push(1);
  push(1);
  push(1);
  push(9);
  pop();
  printsatck();
  return 0;
}
