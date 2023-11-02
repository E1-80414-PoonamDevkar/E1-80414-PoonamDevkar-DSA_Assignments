// Create stack of books(name, author, price and pages) and test various functionalities.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define SIZE 5
#define book_name_LENGTH 50
#define author_name_LENGH 50

typedef struct book
{
    char name[book_name_LENGTH];
    char author[author_name_LENGH];
    float price;
    int pages;
}Book;

typedef struct stack
{
  Book books[SIZE];
  int top;
}stack;

void init_stack(stack *ps);
bool stack_full(stack *ps);
bool stack_empty(stack *ps);
void push(stack *ps, const char *name,const char *author, float price, int pages);
void pop(stack *ps);
void peek(stack *ps);


int main()
{
    stack S;
    init_stack(&S);

    int choice;
    char name[book_name_LENGTH];
    char author[author_name_LENGH];
    float price;
    int pages;
    Book newBook;

do{
    printf("\n-----Welcome-----\n");
    printf("1.Push a book.\n");
    printf("2.Pop a book.\n");
    printf("3.Peek at the top book.\n");
    printf("0.Exit.\n");
    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 0:exit(0);
        case 1:
            printf("---Enter details of Book---\n");
            printf("Name: ");
            scanf("%s", newBook.name);
            printf("Author: ");
            scanf("%s", newBook.author);
            printf("Price: ");
            scanf("%f", &newBook.price);
            printf("Pages: ");
            scanf("%d", &newBook.pages);
            push(&S, name, author, price, pages);
            break;

        case 2:
            pop(&S);
            break;

        case 3:
            peek(&S);
            break;

        default:
            printf("Invalid choice.\n");
    }
}while(choice !=0);
        return 0;
}


void init_stack(stack *ps)
{
    ps->top =0;
}

bool stack_full(stack *ps)
{
    return ps->top = SIZE;
}

bool stack_empty(stack *ps)
{
    return ps->top = 0;
}

void push(stack *ps, const char *name,const char *author, float price, int pages)
{
    stack S;
    init_stack(&S);
    if(stack_full(ps))
    {
        printf("Stack is full ! \n");
    }
    else
    {
        Book book;
        strcpy(book.name,name);
        strcpy(book.author,author);
        book.price = price;
        book.pages = pages;
        ps->books[ps->top]= book;
        ps->top++;
        printf("Pushed book: %s by %s\n", name , author);
    }
}

void pop(stack *ps)
{
    stack S;
    init_stack(&S);
    if(stack_empty(ps))
    {
        printf("stack is empty !\n");
    }
    else
    {
        ps->top--;
        Book book = ps->books[ps->top];
        printf("Popped book: %s by %s \n", ps->books[ps->top].name, ps->books[ps->top].author);
        
    }
}

void peek(stack *ps)
{
    stack S;
    init_stack(&S);
    if(stack_empty(ps))
    {
        printf("Stack is empty !\n");
    }
    else
    {
        Book book = ps->books[ps->top -1];
        printf("Top book: %s by %s, Price: %.2f, Pages: %d\n", book.name, book.author, book.price, book.pages);      
    }
}