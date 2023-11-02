//Create stack of names(char [ ]) and test it for various functionalities.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 5
#define LENGTH 50

typedef struct stack
{
    char names[SIZE][LENGTH];
    int top;
}stack;

void push(stack *ps, const char *name);
void pop(stack *ps);
void peek(stack *ps);
void init_stack(stack *ps);
bool stack_full(stack *ps);
bool stack_empty(stack *ps);

int main()
{
    stack S;
    init_stack(&S);

    int choice;
    char name[LENGTH];

do{
    printf("0.Exit...\n");
    printf("1.Push Name...\n");
    printf("2.Pop Name...\n");
    printf("3.Peek at the top Name...\n");
    printf("\n...Enter the choice...\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 0: exit(0);
        case 1: 
            printf("Enter a Name:  ");
            scanf("%s", name);
            push(&S, name);
            break;

        case 2:
             pop(&S);
             break;

        case 3:
             peek(&S);
             break;

        default:
             printf("Invalid choice...\n");
    }
}while(choice !=0);
    return 0;
}

void init_stack(stack *ps)
{
    ps->top = 0;
}

bool stack_full(stack *ps)
{
    return ps->top == SIZE-1;
}

bool stack_empty(stack *ps)
{
    return ps->top == -1;
}

void push(stack *ps, const char *name)
{
    stack S;
    init_stack(&S);
    if(stack_full(&S))
       printf("Stack is full ! Unable to push %s\n", name);
    else
    {
        strcpy(ps->names[ps->top],name);
        ps->top++;
    }
}

void pop(stack *ps)
{
    stack S;
    init_stack(&S);
    if(stack_empty(&S))
       printf("Stack is empty ! Unable to pop.\n");
    else
    {
        ps->top--;
        printf("Popped: %s\n", ps->names[ps->top]);
    }
}

void peek(stack *ps)
{
    stack S;
    init_stack(&S);
    if(stack_empty(&S))
       printf("Stack is empty !\n");
    else
    {
        printf("Top name: %s\n", ps->names[ps->top - 1]);
    }
}
