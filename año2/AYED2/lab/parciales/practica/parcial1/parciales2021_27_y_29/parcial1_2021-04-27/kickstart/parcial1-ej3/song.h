#ifndef _SONG_H
#define _SONG_H

#include <stdbool.h>

#define MAX_NAME_LENGTH 100u
#define MAX_ARTIST_LENGTH 100u

typedef struct s_song_t {
    char song_name[MAX_NAME_LENGTH + 1u];      // Nombre de la cancion
    char artist_name[MAX_ARTIST_LENGTH + 1u];  // Interprete de la canción
    unsigned int year;                         // Año del copyright
    unsigned int seconds;                      // Cantidad de segundos que dura
} song_t;


#endif
