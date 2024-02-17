#ifndef _QUEUE_HELPERS_H
#define _QUEUE_HELPERS_H

#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

void queue_dump(queue q);
/*
    Write the content of the queue 'q' into stdout.

    PRE: {q --> queue}

    queue_dump(q);
    
    POS: {queue_is_empty(q)}
*/

queue queue_from_file(const char *filepath);
/*
    Each element is read from the file located at 'filepath'.
    The file must exist in disk and must have its contents in the following
    format:

    empty: <empty_flag>
    <elem_1> <elem_2> <elem_3> ... <elem_N>

    The value <empty_flag> indicates with 0 that the saved queue is NOT EMPTY.
    A value greater or smaller than 0 indicates that the saved queue is EMPTY
    therefore is no data in the file (N==0).

    Returns an instance of 'queue' that holds the loaded elements

*/

#endif
