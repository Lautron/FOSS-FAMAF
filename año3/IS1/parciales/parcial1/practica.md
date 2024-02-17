# Desafios
## Desafios general
### Escala
**(considerar escala)**
El desafio de la escala tiene que ver con que no es lo mismo tratar con un
problema pequeño que uno grande.
**(soluciones a pequeños problemas no siempre escalan)**

Los metodos deben escalar en teniendo en cuenta el tamaño del problema.
**(tambien deben escalar con el problema)**
Las dimensiones a considerar con respecto a los metodos de ingenieria y a la
administracion del proyecto no son los mismo para un sistema pequeño que para uno
grande.
Para un sistema pequeño podemos usar metodos mas informales. Sin embargo, para
un sistema grande debemos formalizarlos.

Un ejemplo de la diferencia de metodos que puede haber segun la escala de un problema
se da con contar personas. No es lo mismo contar la cantidad de alumnos en un aula
que realizar un censo nacional.

### Productividad
El desafio de la productividad está motivado por el costo y el cronograma.
Tanto una solucion que demore mucho como una que sea barata pero de mala calidad
son inaceptables.
La productividad es fundamental, ya que el principal factor que influye en el costo
es el gasto en mano de obra. Por ende, si aumentamos la productividad tambien
disminuimos el costo.
Otro factor importante a considerar es el "time to market". Nos interesa disminuirlo
lo máximo posible ya que juega un papel fundamental en el contexto de negocios.

El objetivo **(enfoque)** de la IS es buscar generar una alta productividad con el fin
de reducir tanto el costo total como el tiempo que lleva desarrollar un sistema.

Como analogia para el "time to market" podemos tomar el ejemplo de una taza de cafe que toma 2hs en producir
cafe una vez iniciada la máquina. Por mas que el café producido sea el mejor del mundo,
no nos sirve si nos lo da 2hs tarde.

Como dato adicional podemos agregar que el costo se mide en Persona/Mes, y la productividad
se mide en KLOC/PM.

### Calidad
Una de las motivaciones principales de la IS es la calidad.
Uno de los objetivos fundamentales es producir software de alta calidad.
Por lo cual el enfoque de la IS se centra justamente en eso.

A diferencia del tiempo y el costo, medir la calidad es complicado.

Una de las formas que tenemos para juzgar la calidad es el estandar ISO de calidad,
el cual se compone de los siguientes aspectos:
- Funcionalidad
- Confiabilidad
- Usabilidad
- Eficiencia
- Mantenibilidad
- Portabilidad

El concepto de calidad varia segun el proyecto. Hay proyectos para que le brindan
mas importancia a la confiabilidad o a la usabilidad por ejemplo.
El concepto de calidad de cada proyecto es algo que debe definirse de antemano.
El concepto de calidad es justamente lo que buscamos cumplir al desarrollar el software.

Por otro lado, podemos definir de manera resumida la Calidad como la densidad de
defectos que posee el codigo, es decir: calidad = defectos/KLOC

Generalmente buscamos que haya menos de un defecto por cada mil lineas de código.

### Consistencia y Repetitividad
Uno de los desafios clave de la ingenieria de software es el podes repetir
exitos anteriores con el fin de mantener cierta consistencia en la calidad y la productividad
**(asegurar exito repetible)**

Por esto es que uno de los objetivos de la IS es el sucesivo desarrollo de sistemas
con alta productividad y calidad

Una de las cosas que permite la consistencia es predecir el resultado de un
proyecto de manera **(con certeza)** razonable. Ademas de que si no hubiese consistencia, el estimar
los costos **(del proyecto)** seria sumamente complicado.

### Cambios
Las empresas e instituciones estan cambiando continuamente, por lo cual el software
debe adaptarse a dichos cambios.
Uno de los objetivos de la ingenieria de software es el producir software que
se adapte fácilmente a cambios.
Algo importante a tener en cuenta es que los metodos que no soportan cambios son poco utiles,
por mas que generen alta calidad y productividad.

### Describir exhaustivamente calidad

# SRS
## Caracteristicas srs
Correctitud: cada requerimiento expresa una característica deseada por el cliente **(sistema final)**
Completitud: Todos las características deseadas por el cliente se encuentran expresadas en la SRS
Es dificil de lograr.
Se relaciona mucho a la correctitud.

No ambiguedad: para cada requerimiento existe un único significado **(esencial verificabilidad)**
Consistencia: Que los requerimientos no se contradigan entre si
Verificabilidad: Que para cada requerimiento exista un proceso **(efectivo)** que permita verificar
que el sistema final cumple con el requerimiento
Rastreabilidad: **(origen req)** que para cada requerimiento pueda determinarse como se relaciona con los
elementos de codigo o diseño. **(elementos de software)**
    Para adelante: por cada requerimiento debe poderse encontrar el elemento de diseño o software que lo atiende **(que impacta)**
    Para atras: por cada elemento de codigo o diseño se debe poder encontrar el requerimiento de software que atiende.
Modificabilidad:
Que la estructura y estilo de la SRS permita realizar cambios **(facilmente)** de manera tal que se preserve
la completitud y consistencia
**(estorbo redundancia)**

Ordenada en aspectos de importancia y estabilidad:
**(req criticos, esenciales, deseables)**
**(req esenciales, propensos a cambiar)**
Que los requerimientos esten ordenados en base a su importancia y su probabilidad
de cambio con el fin de minimizar el riesgo de los cambios de requerimientos.
Es decir, se ponen primero los requerimientos mas importantes o que es menos probable que cambien
**(orden prioridad construccion)**

## Punto funcion
## Actividades proceso requerimientos

# Arquitectura
## Estilos arquitectonicos
## ATAM

# Diseño
## Criterios evaluacion
## Acoplamiento funcion
## Acoplamiento Objetos
## Metricas OO
## Principios
## Cohesion Funcion
