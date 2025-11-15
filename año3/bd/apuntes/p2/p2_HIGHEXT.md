# Organización de archivos e índices de bases de datos


## Organización del disco y almacenamiento de datos


### Los discos están estructurados:

#### platos


##### se dividen en pistas,


#### pistas,


##### se segmentan en sectores


#### sectores


##### unidades de datos que se pueden leer/escribir,


##### típicamente 512B).



### Bloques:

##### Secuencias contiguas sectores


#### facilitan


##### transferencia de datos


##### disco


##### memoria



#### cómo se mapean las tablas a los archivos


### Organización de archivos:

##### (archivos separados


##### agrupados)


#### cómo se organizan los registros


##### dentro de los archivos


##### (heap


##### secuencial).



## Enfoques de organización de archivos


#### Simplifican


### Registros de longitud fija:

#### pueden llevar a



### Registros de longitud variable:

#### Acomodan


##### diversos tipos de datos,


#### requieren


##### gestión compleja


#### ejemplo,


##### listas enlazadas para el seguimiento del espacio libre).



#### Ofrece


##### flexibilidad,


#### carece de


##### orden inherente,


### Organización en heap:

#### dificulta


##### búsquedas eficientes.



### Organización secuencial:

#### registros ordenados por


##### clave de búsqueda.



#### Requiere


##### reorganización periódica mantener el orden después de


##### inserciones


##### eliminaciones.



#### Puede ser ineficiente para


##### consultas que involucren uniones,



##### Agrupar tablas relacionadas dentro de un archivo


### Agrupamiento de tablas:

#### puede optimizar


##### ciertas uniones,


#### puede obstaculizar


##### otras.