#ifndef _MOVIE_H_
#define _MOVIE_H_

#define MAX_NAME_LENGTH 150
#define MAX_DIRECTOR_LENGTH 100

typedef struct s_movie_t {
  char name[MAX_NAME_LENGTH + 1u];          // Nombre de la película
  char director[MAX_DIRECTOR_LENGTH + 1u];  // Nombre del director
  unsigned int runtime;                     // Duración en minutos
  float avg_rating;                         // Rating promedio
  float n_votes;                            // Cantidad de votos
} movie_t;

#endif

