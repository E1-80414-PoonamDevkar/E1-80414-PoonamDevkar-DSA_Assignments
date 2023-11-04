#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int *arr;  
    int rear;
    int front;
    int size;  
} queue;

void init_queue(queue *pq, int size);
void enqueue(queue *pq, int data);
void dequeue(queue *pq);
int queue_full(queue *pq);
int queue_empty(queue *pq);
int get_front(queue *pq);

int main()
{
    int choice, data, size;
    queue Q;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    if (size <= 0) 
    {
        printf("Invalid size...\n");
        return 1;
    }

    Q.size = size;
    Q.arr = (int *)malloc(size * sizeof(int));

    if (Q.arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    init_queue(&Q, size);

    do {
        printf("0. Exit...\n");
        printf("1. Enqueue...\n");
        printf("2. Dequeue...\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 0:
                free(Q.arr); 
                exit(0);
            case 1: 
                if (queue_full(&Q))
                    printf("Queue is Full!\n");
                else 
                {
                    printf("Enter the element to insert: ");
                    scanf("%d", &data);
                    enqueue(&Q, data);
                    printf("Element inserted!\n");
                }
                break;
            case 2: // Dequeue
                if (queue_empty(&Q))
                    printf("Queue is Empty!\n");
                else {
                    int ele = get_front(&Q);
                    dequeue(&Q);
                    printf("Element Deleted = %d\n", ele);
                }
                break;
            default:
                printf("Enter a valid choice!\n");
        }
    } while (choice != 0);

    free(Q.arr);
    return 0;
}

void init_queue(queue *pq, int size) 
{
    pq->rear = -1;
    pq->front = -1;
    pq->size = size;  
}

void enqueue(queue *pq, int data) 
{
    if (pq->rear == pq->size - 1) 
    {
        printf("Queue is Full!\n");
        return;
    }
    
    pq->rear++;
    pq->arr[pq->rear] = data;
    
    if (pq->front == -1)
        pq->front = 0;
}

void dequeue(queue *pq)
 {
    if (pq->front > pq->rear)
    {
        printf("Queue is Empty!\n");
        return;
    }
    
    pq->arr[pq->front] = 0;
    pq->front++;
}

int queue_full(queue *pq) 
{
    return (pq->rear == pq->size - 1);
}

int queue_empty(queue *pq) 
{
    return (pq->front > pq->rear);
}

int get_front(queue *pq) 
{
    return pq->arr[pq->front];
}
