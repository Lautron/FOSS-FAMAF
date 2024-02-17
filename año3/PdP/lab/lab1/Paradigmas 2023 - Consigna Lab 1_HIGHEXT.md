# Laboratorio de programación funcional


## 1. Implementar el lenguaje

Figura
Rotar
Espejar

Rot45
Apilar
Juntar
Encimar


### 1.a. Implementando la sintaxis

tipo Dibujo

su tipo Dibujo también debe terminar con deriving (Eq, Show)


#### Definir los siguientes combinadores.
\

comp

r180
r270

(.-.)

(///)

(^^^)

cuarteto

encimar4

ciclar


#### Definir esquemas para la manipulación de figuras básicas.
\

figura

mapDib

foldDib

figuras


#### definir estas funciones en el archivo Pred.hs:
\

cambiar

anyFig

allFig

andP

orP


### 1.b. La interpretación geométrica

completar o modificar el archivo Interp.hs


## 2. Utilizar el lenguaje


### 2.a. Gráfico de prueba


### 2.b. Grilla

grilla numerada de 8x8,


### 2.c. Escher

reconstruir el gráfico de Escher (con triángulos).

### 2.c. Listar dibujos

si uno pasa --lista imprima en pantalla los nombres de todos los dibujos
Bonus si además pregunta cuál mostrar


## 3. Tests

tests para los módulos Pred y Dibujo.


## 4. Preguntas


### 1.
¿Por qué están separadas las funcionalidades en los módulos indicados? Explicar detalladamente la responsabilidad de cada módulo.


### 2.
¿Por qué las figuras básicas no están incluidas en la definición del lenguaje, y en vez es un parámetro del tipo?


### 3.
¿Qué ventaja tiene utilizar una función de `fold` sobre hacer pattern-matching directo?


## puntos extras

Hacen otra figura interesante, como una imagen fractal,

Extienden el lenguaje para indicar animaciones de figuras.

Agregan
un operador para permitir modificar las proporciones de una imagen.
