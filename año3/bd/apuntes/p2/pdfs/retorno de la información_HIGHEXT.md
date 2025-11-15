# Retorno de la información


## Retorno de la información


### es el proceso

##### retornar documentos



##### colección de documentos


##### en respuesta a consulta.



### información no estructurada:


#### No tiene


##### modelo formal bien definido


#### Se basa en


##### comprensión lenguaje natural


#### variedad amplia


##### formatos estándares



### diferencias


##### Datos no estructurados



##### No hay esquemas fijos



##### Modelos de consulta libres de forma



##### Operaciones sobre datos



##### búsquedas retornan lista punteros a documentos.



#### resultados se basan en


##### correspondencia


##### aproximada


##### medidas de efectividad.



#### No trabajan con transacciones



## Lenguajes de consulta


### expresiones de consulta

#### formadas usando


##### palabras clave


##### conectivos proposicionales.



### ejemplos


#### frases:


##### secuencia palabras


#### palabras clave:


##### se escribe palabras clave



##### se asume and entre palabras.



#### Booleanas:


##### involucran


##### términos



##### conectivos booleanos.



#### expresiones regulares:



#### proximidad:


##### expresa cuan cerca deben estar



##### ciertos términos.



#### lenguaje natural:



## Resultados de una consulta


### pueden ser

##### lista



##### identificadores


##### piezas de texto.



### suelen retornarse

##### orden decreciente



##### de relevancia.



### relevancia


#### Frecuencia de términos:


##### frecuencia de ocurrencia



#### Frecuencia inversa de documentos:



##### ocurre en menos documentos


##### más importancia palabra.



#### Enlaces a documentos:


##### más enlaces documento,



##### más importante.



#### palabras ocurren en título,


##### más importancia.



#### primera ocurrencia tarde


##### poca importancia.



#### Proximidad:


##### palabras aparecen cerca


##### más importancia



## Enfoques estadísticos


### Se construye

##### para cada documento


##### estructura que resume que



##### contiene



### En un enfoque estadístico

#### documentos son



##### descompuestos en piezas


#### pueden ser


##### palabras,


##### frases,


##### palabras consecutivas).



#### Cada pieza


##### se


##### cuenta,


##### pesa


##### mide


##### determinar


##### relevancia



##### importancia.



### Modelo Booleano:


#### documentos se representan


##### conjunto de términos.


#### correspondencia exacta.



##### documento sirve


##### o no sirve



#### No hay noción de


##### ordenar por relevancia.



## Modelo de espacio vectorial:


### documento se representa

##### vector de valores


### Cada término es

##### una dimensión.


### Para cada dimensión hay

##### número que puede representar;



##### valor booleano


##### frecuencia del término


##### peso



### Se puede establecer

##### medida de relevancia documento



### consulta se representa

##### vector de términos.


### El vector de una consulta

##### es comparado con vectores documentos



### Las respuestas

##### se ordenan por relevancia.



### Los términos

##### tienen peso en los vectores.


#### opción


##### peso sea frecuencia



##### usar TF-IDF



### función de similitud de vectores.

##### función del coseno del ángulo entre vectores



##### se usa para estimar la similitud.



## Selección de términos relevantes de un documento


### Stopwords

##### palabras que ocurran en 80% o más



##### de documentos



#### Ejemplos:


##### él,


##### la,


##### lo,


##### de,


##### un,


##### y,


##### para,


#### Se deben ignorar



### algoritmo de Martin Porter


##### toma palabra y reduce a su raíz



#### ejemplo:


##### corriendo,


##### corre


##### correr


##### raíz en común ‘corr’.



### sinónimos de un término.


##### usar un término por concepto


##### en lugar de todos los sinónimos.



#### WordNet


##### agrupa palabras en


##### conjuntos de sinónimos



##### llamados synsets.



#### ventajas



##### Mejora de la precisión:



##### Aumento de cobertura: encontrar información que usa diferentes términos



##### Experiencia del usuario optimizada:



### recolectar entidades


#### P.ej:


##### hechos,


##### eventos,


##### lugares,


##### relaciones,


##### nombres



#### muy útil para:



##### Mejorar la precisión en las búsquedas:



##### Agrupar información relacionada:



## Índices invertidos


### Implementación


#### lista invertida de un término


##### puede requerir varios bloques


#### Para eficiencia en el acceso,


##### tener lista invertida



##### conjunto consecutivo bloques.



#### Se puede usar


##### índice de árbol B+


##### mapear término



##### lista invertida asociada.



### Construcción


#### 1.


##### Extraer vocabulario documentos


#### 2.


##### Armar estadísticas documento


#### 3.


##### Invertir stream documentos con términos


##### en


##### stream



##### términos y sus documentos.


#### se puede agregar información adicional



##### frecuencias de términos,


##### posiciones de términos


##### pesos de términos.



## consulta usando índice invertido


### Búsqueda de vocabulario:

##### Cada término se busca en



##### vocabulario.



### Retorno de la información de documentos:

##### retorna información



##### documento para cada término.



### Manipulación de la información retornada:

##### información de cada



##### documento es procesada



## Medición de la relevancia


### Se pueden dar las siguientes situaciones:


#### Falsos negativos:


##### documentos relevantes no retornados.


#### Falsos positivos:


##### documentos irrelevantes retornados.


#### documentos relevantes


##### retornados se llaman verdaderos positivos



#### resultados irrelevantes


##### no retornados se llaman verdaderos negativos.



### Métricas


#### Precisión:


##### ¿qué porcentaje documentos son relevantes



##### consulta?



#### Cobertura:


##### ¿qué porcentaje documentos relevantes



##### son retornados?



### medición F-score

#### combina



##### precisión


##### cobertura



## Lucene


### es

##### máquina de búsqueda


##### indexado


#### popular en


##### industria



##### academia.



### documentos no estructurados

##### pasan proceso indexado



### Un documento

#### se forma de


##### campos;



#### puede ser:


##### binario,


##### numérico


##### texto.



### API de consultas.


#### consultas retornan


##### lista ordenada documentos por rango,



##### usando variante de TF-IDF



#### es configurable:



### usa modelo

##### espacio vectorial