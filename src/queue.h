#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>

#include "structs.h"

typedef struct Queue Queue;

int init_Queue(Queue **queue, const size_t size); // Инициализировать очередь

Iter_Queue next_Iter_Queue(const Iter_Queue iter);
Iter_Queue prev_Iter_Queue(const Iter_Queue iter);
Iter_Queue get_head_Iter_Queue(const Queue *queue);
Iter_Queue get_tail_Iter_Queue(const Queue *queue);

size_t get_len_Queue(const Queue *queue); // Получить длину очеред

bool is_empty_Queue(const Queue *queue); // Проверить, пуста ли очередь

Iter_Queue push_Queue(Queue *queue, const void *data); // Добавить элемент в очередь
Iter_Queue get_Queue(const Queue *queue); // Получить элемент из очереди
Iter_Queue erase_Queue(Queue *queue); // Удалить последний элемент из очереди
Iter_Queue pop_Queue(Queue *queue, Iter_Queue *data_iter); // Получить и удалить последний элемент из очереди
void free_Queue(Queue *queue); // Освободить память, занятую очередью

#endif // QUEUE_H