//3. Do necessory changes in code of stack if top is initialized to 0.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct stack
{
    int arr[SIZE];
    int top;
}stack;

int peek(stack *ps);
void init_stack(stack *ps);
void push(stack *ps, int data);
void pop(stack *ps);
int stack_full(stack *ps);
int stack_empty(stack *ps);

int main()
{
    stack S;
    init_stack(&S);
    
    int choice;
do{
    printf("\n Enter choice: \n");
    printf("0.Exit...\n");
    printf("1.Push...\n");
    printf("2.Pop...\n");
    printf("3.Peek...\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 0:exit(0);
        case 1:
               if(stack_full(&S))
                  printf("Stack is Full!!\n");
               else
                {
                    int data;
                    printf("Enter the element to insert..");
                    scanf("%d", &data);
                    push(&S, data);
                    printf("Element inserted =%d", data);
                }
                break;
        case 2:
            if(stack_empty(&S))
               printf("Stack EMpty!!!");
            else
            {
                int ele = peek(&S);
                pop(&S);
                printf("Element popped=%d", ele);
            }
            break;
        case 3:
            if(stack_empty(&S))
               printf("Stack empty!! Peek not possible..");
            else
            {
                int ele =peek(&S);
                printf("Topmost element= %d\n", ele);
            }
            break;
        default:
           printf("Invalid choice! Kindly enter valid choice...\n");
    }
}while(choice != 0);

    return 0;
}


void init_stack(stack *ps)
{
    ps->top = 0;
}

void push(stack *ps, int data)
{
    ps->arr[ps->top]=data;
    ps->top++;
}

void pop(stack *ps)
    {
    if (ps->top > 0) 
    {  // Check if the stack is not empty
        ps->top--;
        ps->arr[ps->top] = 0;
    }
}  


int stack_full(stack *ps)
{
    return ps->top == SIZE-1;
}

int stack_empty(stack *ps)
{
    return ps->top ==0;
}

int peek(stack *ps)
{
    return ps->arr[ps->top];
}