#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
  char value;
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
        printf("%c ", x -> value);
        printf("\n");
    }
}



bool evaluacion(char *parentesis) {
  int i = 0;
  while (parentesis[i] != 0) {
    if(parentesis[i] == ')') {
      char c = pop();
      if ( c != '(') return false;
    } else
        push(parentesis[i]);
      i++;
  }
  if (!isempty()) return false;
  return true;
}

int main(int argc, char *argv[]) {
  printf("%s\n", evaluacion(argv[1]) ? "Si esta" : "No, no esta balanceado BURROOOOOOO");
  return 0;
}
