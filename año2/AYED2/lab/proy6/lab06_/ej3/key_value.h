#ifndef _KEY_VALUE_H
#define _KEY_VALUE_H

#include <stdbool.h>
#include <stdio.h>
#include "string.h"

/* Key and value, both of type string */
typedef string key_t;
typedef string value_t;

/* Rename operations */
#define key_destroy string_destroy
#define key_eq string_eq
#define value_eq string_eq
#define key_less string_less
#define key_dump string_dump
#define value_destroy string_destroy
#define value_dump string_dump

#endif
