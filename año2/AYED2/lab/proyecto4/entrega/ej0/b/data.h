#ifndef _DATA_H_
#define _DATA_H_

#define NAME_SIZE 30

typedef char name_t [NAME_SIZE];

typedef struct _s_data {
    name_t name;
    unsigned int age;
    unsigned int height;
} data_t;


#endif

