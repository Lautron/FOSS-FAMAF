# Procesamiento de consultas


## Visión general


### procesar una consulta,

#### SQL
\

#### traducir
\


#### expresión
\

#### álgebra de tablas.
\


#### Luego
\

#### evaluar
\

#### consulta
\

#### evaluación
\


#### términos
\

#### operadores físicos.
\


### expresión

#### varias
\


#### expresiones equivalentes.
\


### consecuencias


#### procesar una consulta
\

#### puede
\


#### evaluar
\

#### consulta equivalente
\


#### consulta C
\

### plan de evaluación


#### expresión E
\

#### equivalente a C
\

#### operadores físicos
\

#### operadores lógicos de E.
\


### máquina de ejecución de consultas

#### toma
\

#### plan de evaluación
\


#### ejecuta
\

#### retorna las respuestas
\


### planes de evaluación


#### diferentes costos.
\


### El SGBD

#### construir
\

#### plan
\

#### minimiza el costo
\


### Optimización de consultas:

#### entre
\

#### planes
\


#### equivalentes
\

#### encontrar
\

#### menor costo.
\


#### costo
\

#### es estimado
\

#### información estadística
\


### un optimizador

#### debe
\


#### conocer
\

#### costo de cada operación.
\


## Árbol binario de ejecución

### Evaluación


#### Materialización:
\


#### Encausamiento:
\


#### Comparando ambos enfoques:
\


### Materialización

## Repaso


### formas alternativas de evaluar una expresión


#### expresiones equivalentes
\

#### diferentes algoritmos
\

#### cada operación
\


### plan de evaluación

#### define
\

#### algoritmo
\

#### usado
\


#### cada operación
\

#### cómo
\

#### se coordina
\

#### ejecución
\

#### operaciones.
\


### diferencia de costo

#### entre planes
\

#### puede ser enorme.
\


## optimización de consultas


### basada en costo:


#### Generar expresiones
\

#### equivalentes
\

#### usando
\


#### reglas de equivalencia.
\


#### Anotar expresiones
\

#### para
\

#### obtener
\

#### planes
\


#### alternativos.
\


#### Elegir
\

#### más económico
\

#### basado en
\

#### costo estimado.
\


### costo estimado

#### se basa en:
\


#### Información estadística
\

#### tablas.
\


#### Estimación estadística
\

#### resultados intermedios.
\


#### Fórmula
\

#### costo
\

#### algoritmos,
\

#### computados
\

#### usando estadísticas.
\


### número de transferencias de bloques

#### es influenciado por:
\


#### operadores lógicos
\

#### tamaño
\

#### resultados intermedios.
\

#### operadores físicos usados
\

#### método para pasar argumentos
\

#### orden de operaciones similares,
\

#### especialmente
\

#### reuniones
\

#### selecciones.
\


## Transformación de expresiones


### equivalentes por igualdad


### equivalentes módulo ordenamiento de registros


### regla de equivalencia


## Reglas de equivalencia


### selección conjuntiva de operaciones


### operaciones de selección son conmutativas:


### Solo la última en una secuencia de operaciones proyección


### Nomenclatura:

### La reunión natural es asociativa:


### parecida a la definición de reunión selectiva:


### expresar una selección de una reunión selectiva


## Optimización Heurística


### Problema:


### heurística


### Solución:


### La mayoría de los optimizadores


### Ejemplo


## Árboles de reunión profunda a la izquierda

## Enfoques híbridos


### combinan