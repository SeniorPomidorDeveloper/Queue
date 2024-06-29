#ifndef STRUCTS_H
#define STRUCTS_H

#include <stddef.h>

typedef struct Node_Queue
{
    void *data;
    struct Node_Queue *next;
    struct Node_Queue *prev;
} Node_Queue;

typedef struct Queue
{
    size_t size;
    size_t len;
    Node_Queue *head;
    Node_Queue *tail;
} Queue;

typedef Node_Queue * Iter_Queue;

#endif // STRUCTS_H