
#ifndef queue_h
#define queue_h

#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

typedef struct queue
{
    int arr[SIZE];
    int rear;
    int front;
}queue;

void init_queue(queue *pq);
void enqueue(queue *pq, int data);
void dequeue(queue *pq);
int queue_full(queue *pq);
int queue_empty(queue *pq);
int get_front(queue *pq);

#endif
