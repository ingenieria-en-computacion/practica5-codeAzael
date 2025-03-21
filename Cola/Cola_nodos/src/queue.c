#include "queue.h"
#include "node.h"
#include <stdlib.h>
#include <stdbool.h>

Queue* queue_create() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void queue_enqueue(Queue* q, Data d) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = d;
    new_node->next = NULL;

    if (q->tail == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

Data queue_dequeue(Queue* q) {
    if (queue_is_empty(q)) {
        return (Data)0; 
    }

    Node* temp = q->head;
    Data d = temp->data;

    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(temp);
    return d;
}

bool queue_is_empty(Queue* q){
    return q->head == NULL;
}

Data queue_front(Queue* q) {
    if (queue_is_empty(q)) {
        return (Data)0;
    }
    return q->head->data;
}

void queue_empty(Queue* q) {
    while (!queue_is_empty(q)) {
        queue_dequeue(q);
    }
}

void queue_delete(Queue* q) {
    queue_empty(q);
    free(q);
}