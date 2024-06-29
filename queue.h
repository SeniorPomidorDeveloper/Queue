#ifndef QUEUE_H
#define QUEUE_H

#include "stddef.h"
#include "stdbool.h"

typedef struct Queue Queue;

int init_Queue(Queue **queue, size_t size); // Инициализировать очередь

size_t get_len_Queue(Queue *queue); // Получить длину очеред

bool is_empty_Queue(Queue *queue); // Проверить, пуста ли очередь

int push_Queue(Queue *queue, void *data); // Добавить элемент в очередь
int get_Queue(Queue *queue, void *data); // Получить элемент из очереди
int erase_Queue(Queue *queue);
int pop_Queue(Queue *queue, void *data); // Удалить элемент из очереди`
void free_Queue(Queue *queue);

#endif // QUEUE_H