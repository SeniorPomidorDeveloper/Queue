#include "queue.h"

#include <stdlib.h>
#include <string.h>

#include "error_codes.h"

int init_Queue(Queue **queue, const size_t size)
{
    *queue = (Queue *) malloc(sizeof(Queue));
    if (*queue == NULL) return INIT_QUEUE_ERROR;
    (*queue)->size = size;
    (*queue)->len = 0;
    (*queue)->head = NULL;
    (*queue)->tail = NULL;
    return 0;
}

Iter_Queue next_Iter_Queue(const Iter_Queue iter)
{
    return iter->next;
}

Iter_Queue prev_Iter_Queue(const Iter_Queue iter)
{
    return iter->prev;
}

Iter_Queue get_head_Iter_Queue(const Queue *queue)
{
    return queue->head;
}

Iter_Queue get_tail_Iter_Queue(const Queue *queue)
{
    return queue->tail;
}

size_t get_len_Queue(const Queue *queue)
{
    return queue->len;
}

bool is_empty_Queue(const Queue *queue)
{
    return queue->len == 0;
}

Iter_Queue push_Queue(Queue *queue, const void *data)
{
    Node_Queue *new_node = (Node_Queue *) malloc(sizeof(Node_Queue));
    if (new_node == NULL) return NULL;
    new_node->data = (void *) malloc(queue->size);
    if (new_node->data == NULL)
    {
        free(new_node);
        return NULL;
    }
    memcpy(new_node->data, data, queue->size);
    new_node->next = NULL;
    new_node->prev = queue->tail;
    if (queue->tail != NULL) queue->tail->next = new_node;
    queue->tail = new_node;
    if (queue->head == NULL) queue->head = new_node;
    queue->len++;
    return new_node;
}

Iter_Queue get_Queue(const Queue *queue)
{
    if (is_empty_Queue(queue)) return NULL;
    return queue->head;
}

Iter_Queue erase_Queue(Queue *queue)
{
    Node_Queue *old_head = queue->head;
    if (old_head == NULL) return NULL;
    queue->head = old_head->next;
    if (queue->head != NULL) queue->head->prev = NULL;
    free(old_head->data);
    free(old_head);
    queue->len--;
    return get_Queue(queue);
}

Iter_Queue pop_Queue(Queue *queue, Iter_Queue *data_iter)
{
    *data_iter = get_Queue(queue);
    return erase_Queue(queue);
}

void free_Queue(Queue *queue)
{
    while (!is_empty_Queue(queue)) erase_Queue(queue);
    free(queue);
}