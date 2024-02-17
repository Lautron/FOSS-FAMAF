#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

typedef struct _s_queue * queue;

typedef char queue_elem;

queue queue_empty(void);

queue queue_enqueue(queue q, queue_elem e);

bool queue_is_empty(queue q);

unsigned int queue_size(queue q);

queue_elem queue_first(queue q);

queue queue_dequeue(queue q);

queue queue_destroy(queue q);

#endif
