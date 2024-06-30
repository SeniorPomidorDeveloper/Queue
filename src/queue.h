#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>
#include <stdbool.h>

#include "structs.h"

typedef struct Queue Queue;

int init_Queue(Queue **queue, const size_t size); // Инициализировать очередь

Iter_Queue next_Iter_Queue(const Iter_Queue iter); // Следующий итератор
Iter_Queue prev_Iter_Queue(const Iter_Queue iter); // Предыдущий итератор
Iter_Queue get_head_Iter_Queue(const Queue *queue); // Получить итератор головного элемента очереди
Iter_Queue get_tail_Iter_Queue(const Queue *queue); // Получить заднего элемента очереди
void *get_data_Iter_Queue(const Iter_Queue iter); // Получить данные из итератора
Iter_Queue set_data_Iter_Queue(Queue *queue, Iter_Queue iter, const void *data); // Установить данные в итераторе

size_t get_len_Queue(const Queue *queue); // Получить длину очеред

bool is_empty_Queue(const Queue *queue); // Проверить, пуста ли очередь

Iter_Queue push_Queue(Queue *queue, const void *data); // Добавить элемент в очередь
Iter_Queue get_Queue(const Queue *queue); // Получить элемент из очереди
Iter_Queue erase_Queue(Queue *queue); // Удалить элемент из очереди
Iter_Queue pop_Queue(Queue *queue, void **data); // Получить и удалить элемент из очереди
void free_Queue(Queue *queue); // Освободить память, занятую очередью

#endif // QUEUE_H