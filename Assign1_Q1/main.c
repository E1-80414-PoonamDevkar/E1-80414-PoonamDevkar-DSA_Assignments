
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main() 
{
    int choice, data;
    queue Q;
    init_queue(&Q);

    do {
        printf("0. Exit...\n");
        printf("1.Enqueue...\n");
        printf("2.Dequeue...\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 0:
                exit(0);
            case 1: 
                if (queue_full(&Q))
                    printf("Queue is Full!!!\n");
                else 
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &data);
                    enqueue(&Q, data);
                    printf("Element inserted successfully!!\n");
                }
                break;
            case 2: 
                if (queue_empty(&Q))
                    printf("Queue is Empty!!\n");
                else 
                {
                    int ele;
                    ele = get_front(&Q);
                    dequeue(&Q);
                    printf("Element Deleted = %d\n", ele);
                }
                break;
            default:
                printf("Invalid choice!!\n");
        }
    } while (choice != 0);

    return 0;
}
