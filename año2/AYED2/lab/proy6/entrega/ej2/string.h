#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stdio.h>

typedef struct _s_string* string;

/* Creates a new string copying the characters
 * of the given [word].
 */
string string_create(const char *word);

/* Returns the length of the given string [str]
 */
unsigned int string_length(string str);

/* Returns true if [str1] is alphabetically before than [str2] (strictly), or
 * false otherwise.
 */
bool string_less(string str1, string str2);

/* Returns true if [str1] is equal to [str2], or false otherwise. */
bool string_eq(string str1, string str2);

/* Retuns a clone of the string [str] */
string string_clone(string str);

/* Destroys the string, freeing all the allocated resources */
string string_destroy(string str);

/* Returns a reference to the string, as a pointer to a constant sequence
 * of characters. 
*/
const char* string_ref(string str);

/* Prints the string in the given [file] */
void string_dump(string str, FILE *file);

#endif
