#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define STACK_MAX_SIZE 20

typedef struct Stack_tag {
    char data[STACK_MAX_SIZE];
    size_t size;
} Stack_t;

void push(Stack_t* stack, const char value) {
    if (stack->size >= STACK_MAX_SIZE) {
        exit(STACK_OVERFLOW);
    }
    stack->data[stack->size] = value;
    stack->size++;
}

char pop(Stack_t* stack) {
    if (stack->size == 0) {
        exit(STACK_UNDERFLOW);
    }
    stack->size--;
    return stack->data[stack->size];
}

char peek(const Stack_t* stack) {
    if (stack->size <= 0) {
        exit(STACK_UNDERFLOW);
    }
    return stack->data[stack->size - 1];
}


void printStackValue(const char value) {
    printf("%c", value);
}

void printStack(const Stack_t* stack, void (*printStackValue)(const char)) {
    int i;
    int len = stack->size - 1;
    printf("stack %d > ", stack->size);
    for (i = 0; i < len; i++) {
        printStackValue(stack->data[i]);
        printf(" | ");
    }
    if (stack->size != 0) {
        printStackValue(stack->data[i]);
    }
    printf("\n");
}

int main()
{
    char nazv_sh[20];
    fgets(nazv_sh, 20, stdin);
    int eq = 0;
    Stack_t stack;
    stack.size = 0;
    for (int i = 0; i < 20; i++) {
        if (nazv_sh[i] == '\0' || nazv_sh[i] == '\n') break;
        if (nazv_sh[i] != '.' && nazv_sh[i] != ',' && nazv_sh[i] != ':' && nazv_sh[i] != ';' && nazv_sh[i] != '!' && nazv_sh[i] != '?' && nazv_sh[i] != ' ' && nazv_sh[i] != '\0')
            push(&stack, nazv_sh[i]);
    }
    printStack(&stack, printStackValue);
    for (int i = 0; i < 20; i++) {
       if (nazv_sh[i] == '\0' || nazv_sh[i] == '\n') break;
       if (nazv_sh[i] != '.' && nazv_sh[i] != ',' && nazv_sh[i] != ':' && nazv_sh[i] != ';' && nazv_sh[i] != '!' && nazv_sh[i] != '?' && nazv_sh[i] != ' ' && nazv_sh[i] != '\0')
           if (nazv_sh[i] != pop(&stack)) eq = 1;

    }
    if (eq == 0) printf("palindrom +");
    else printf("palindrom -");
    getch();

    return 0;
}