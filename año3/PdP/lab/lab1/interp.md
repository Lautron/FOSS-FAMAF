# Explicación de la función interpApilar

La función `interpApilar` es una función que toma 7 argumentos y
devuelve un valor de tipo `FloatingPic`. Esta función se encarga de
apilar dos figuras una encima de la otra en una ubicación determinada.

## Argumentos

Los argumentos que recibe la función `interpApilar` son los siguientes:

-   `n`: un valor de tipo `Float` que representa la proporción de tamaño
    que se le dará a la figura superior.
-   `m`: un valor de tipo `Float` que representa la proporción de tamaño
    que se le dará a la figura inferior.
-   `f`: una función de tipo `FloatingPic` que toma tres argumentos: una
    ubicación en forma de vector de tipo `V.Point`, un ancho de tipo
    `Float` y una altura de tipo `Float`. Esta función devuelve una
    figura flotante.
-   `g`: una función de tipo `FloatingPic` que tiene la misma signatura
    que `f`.
-   `x`: un valor de tipo `V.Point` que representa la ubicación donde se
    ubicará la figura inferior.
-   `w`: un valor de tipo `Float` que representa el ancho de la figura.
-   `h`: un valor de tipo `Float` que representa la altura de la figura.

## Cálculo

La función `interpApilar` se encarga de calcular la ubicación y el
tamaño de las dos figuras que se van a apilar. Para ello, utiliza la
fórmula de la interpolación lineal.

En concreto, se calcula el tamaño que se le debe dar a cada figura en
base a los argumentos `n` y `m`. Una figura recibirá una proporción de
tamaño `n/(n+m)` y la otra una proporción de tamaño `m/(n+m)`.

Una vez calculados los tamaños, se calcula la altura de la figura
superior aplicando el operador vectorial `V.*` (producto escalar por un
número) a la altura de la figura total.

Finalmente, se construye la figura flotante utilizando las funciones `f`
y `g`, pasándoles las ubicaciones y tamaños correspondientes.

## Devolución

La función `interpApilar` devuelve una figura flotante, que es la
combinación de las dos figuras apiladas. La función `pictures` se
encarga de combinar las dos figuras en una sola imagen.

# Explicación de la función interpJuntar

La función `interpJuntar` es una función que toma 7 argumentos y
devuelve un valor de tipo `FloatingPic`. Esta función se encarga de
juntar dos figuras una al lado de la otra en una ubicación determinada.

## Argumentos

Los argumentos que recibe la función `interpJuntar` son los siguientes:

-   `n`: un valor de tipo `Float` que representa la proporción de tamaño
    que se le dará a la figura izquierda.
-   `m`: un valor de tipo `Float` que representa la proporción de tamaño
    que se le dará a la figura derecha.
-   `f`: una función de tipo `FloatingPic` que toma tres argumentos: una
    ubicación en forma de vector de tipo `V.Point`, un ancho de tipo
    `Float` y una altura de tipo `Float`. Esta función devuelve una
    figura flotante.
-   `g`: una función de tipo `FloatingPic` que tiene la misma signatura
    que `f`.
-   `x`: un valor de tipo `V.Point` que representa la ubicación donde se
    ubicará la figura izquierda.
-   `w`: un valor de tipo `Float` que representa el ancho de la figura.
-   `h`: un valor de tipo `Float` que representa la altura de la figura.

## Cálculo

La función `interpJuntar` se encarga de calcular la ubicación y el
tamaño de las dos figuras que se van a juntar. Para ello, utiliza la
fórmula de la interpolación lineal.

En concreto, se calcula el tamaño que se le debe dar a cada figura en
base a los argumentos `n` y `m`. Una figura recibirá una proporción de
tamaño `n/(n+m)` y la otra una proporción de tamaño `m/(n+m)`.

Una vez calculados los tamaños, se calcula el ancho de la figura
izquierda aplicando el operador de multiplicación `V.+` (suma de
vectores) a la ubicación de la figura izquierda y el ancho de la figura
total multiplicado por la proporción de tamaño de la figura izquierda.

Finalmente, se construye la figura flotante utilizando las funciones `f`
y `g`, pasándoles las ubicaciones y tamaños correspondientes.

## Devolución

La función `interpJuntar` devuelve una figura flotante, que es la
combinación de las dos figuras juntas. La función

