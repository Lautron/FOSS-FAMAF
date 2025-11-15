# Operadores sobre tablas y su implementación


## Visión general


### tabla álgebra de tablas.


### procesar una consulta,


### operadores lógicos.


### operador físico


### evaluación de una expresión


### medir el costo accesos a bloques: costos de todos los algoritmos físicos


### Cuando presentamos estimaciones de costos,


## Tablas y esquemas Proyección


###  Пf1,…,fn = map (\t’ -> (f1(t’),…,fn(t’)))


### Operador físico


## Selección Selección Operadores físicos para selección


### búsqueda lineal


#### Escanear cada bloque


##### y testear todos los registros



#### Estimación de costo


##### + 1 acceso a bloque br transferencias de bloques



##### número bloques conteniendo registros de la tabla


##### br denota



### índice primario árbol B+ igualdad


### clave candidata


#### Recorrer altura del árbol


##### más una E/S para recoger el registro.



#### costo


##### (hi + 1) transferencias de bloque


##### (hi + 1) accesos a bloque;



##### denota altura índice.


#### hi 



### índice primario árbol B+ igualdad


### no clave candidata


#### acceso a bloque


##### cada nivel del árbol acceso a bloque



##### primer bloque.



#### registros van a estar


##### bloques consecutivos.



#### costo



##### hi transferencias de bloque y hi accesos a bloque para recorrer el árbol B+.



##### hi es la altura del árbol B+.



##### acceso a bloque para buscar los registros


##### total de b transferencias de bloque


##### acceder registros con clave de búsqueda.



### índice secundario árbol B+, igualdad en clave


### candidata


#### es similar al


##### índice primario y (hi + 1) transferencias de bloque (hi + 1) accesos a bloque. denota la altura del índice.


#### hi 



### índice secundario árbol B+,


### igualdad en no clave


#### costo recorrido índice


##### es el mismo.


#### cada registro



##### puede estar bloque diferente,


##### requiriendo


##### un acceso por registro.



#### Sea n


##### número registros recogidos.


#### costo


##### (hi + n) transferencias de bloque y (hi + n) accesos a bloque.



### Selecciones involucrando comparaciones


#### Algoritmo para índice primario:



#### Algoritmo para índice secundario



### Tamaño de resultado de operador físico de selección Factor de selectividad


#### Regla 1:



#### Regla 2:



#### Regla 3:



#### Regla 4:



#### Regla 5:



#### Regla 6:



#### Regla 7:



## Producto cartesiano


### [] x s = []


### (t:r) x s = (juntar t s) ++ q


## Concatenación de tuplas Anexar


### juntar t [] = []


### juntar t (u : s) = (t ; u) : (juntar t s)


## Ordenamiento


### ordenamiento ascendente


####  Oa1,…,aN ([]) = []  Oa1,…,aN (x:r) = inserta1,…,aN (x, Oa1,…,aN (r))



### ordenamiento descendente


#### O> a1,…,aN (r) = reverse (Oa1,…,aN(r))



#### Reverse [] = []



#### Reverse (x : xs) = reverse xs ++ [x]



### Operadores físicos

#### Ordenamiento externo


## Reunión selectiva Reunión natural

### Operadores físicos Tamaño de resultado Factor de selectividad

## Remover duplicados

### Operador físico

## Concatenación de tablas Concatenación Resta


### Algoritmo:


### Costo:


## Intersección


### Algoritmo:


### Costo: