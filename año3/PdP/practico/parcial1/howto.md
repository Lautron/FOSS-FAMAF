# Parcial 1 2022-06-23.pdf
## 1) Es caracteristica del codigo espaghetti?
### General
Para identificar codigo espaghetti hay que ver si el salto que se produce es arbitrario y no depende del bloque actual ni de los bloques anteriores.

### break
En el caso de break, no es una característica del codigo espaghetti, ya que no se salta a una ubicacion arbitraria si no que solo
se sale del bloque actual, el cual pertenece a un bucle.

## 2) Escribir pseudocodigo
### a) componente determinista con efectos secundarios
Un procedimiento que modifique el estado pero sin que su comportamiento dependa de el.

O que siempre produzca el mismo cambio para determinado argumento.

### a) componente no determinista sin efectos secundarios
Un componente que dependa del estado pero no lo modifique.

#### Ejemplo
Una funcion que le sume a un parametro una variable global.

## 3) Como se usa la vtable en C++
Saberse bien las caracteristicas de los metodos virtuales en C++

## 4) Comportamiento de un programa en alcance estatico vs alcance dinamico
### Alcance dinamico
El alcance dinámico se refiere a que una variable o función se puede acceder dentro de una función y también dentro de cualquier función que se llame desde esa función

El valor de la variable es el valor de la ultima vez que apareció en la pila.

### Alcance estatico
El alcance estático se refiere a que una variable o función se puede acceder solo dentro de la función en la que se define o dentro de una función anidada dentro de esa función

El valor de la variable es el valor mas cercano a la definicion de la funcion

## 5) Determinar valores de variables al final de la ejecucion
### a) Por valor
Evaluar manualmente teniendo en cuenta que las asignaciones dentro de las funciones no cambian el estado.

### b) Por referencia
Evaluar manualmente teniendo en cuenta que las asignaciones dentro de las funciones cambian el estado.

### b) Por valor resultado
Evaluar manualmente teniendo en cuenta que las asignaciones dentro de las funciones cambian el estado al final de la ejecucion de las mismas

## 6) Explicar ejecucion de excepciones
Tener en cuenta que los finally siempre se ejecutan.

Prestar atencion de no manejar una excepcion mas de una vez.

# Parcial 1 2022-05-03.pdf
## 1)
1) Asignar tipo a hojas
2) Asignar tipo a los nodos internos
3) Resolver por sustitucion

## 2)
- break produce que se termine la ejecucion del bucle abruptamente

# Parcial 1 2019-06-18.pdf
# Parcial 1 2019-04-25.pdf
# Parcial 1 2018-06-19.pdf
# Parcial 1 2018-04-19.pdf
