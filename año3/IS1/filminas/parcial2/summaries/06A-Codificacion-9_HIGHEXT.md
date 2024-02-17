# Codiﬁcación


### Objetivo:
- implementar
- diseño
- mejor manera posible


### afecta
- testing
- mantenimiento.

- mantenimiento
- altos


### objetivo NO es
- reducir
- costos
- implementación,
- sino
- de testing
- mantenimiento,


### el código debe
- ser fácil de
- leer
- comprender


## Principios y pautas para la programación


### Objetivo principal del programador:
- escribir
- programas simples

- fáciles de leer
- menor cantidad de errores

- rápidamente


## Programación estructurada


### Objetivo:
- simpliﬁcar
- estructura
- programas

- sea fácil razonar
- sobre ellos.


### estructura estática
- orden
- sentencias

- código
- orden lineal).


### estructura dinámica
- orden
- sentencias

- ejecutan.

### Objetivo de la programación estructurada:
- programas
- estructura
- dinámica
- misma que
- estática,


### simpliﬁca
- ﬂujo
- estructurada de control,

#### son de facilitando

- comprensión

- razonamiento


## Ocultamiento de la información


### soluciones de software
- contienen
- estructuras de datos
- guardan

- información.


### sólo ciertas operaciones
- se realizan
- sobre
- información,


### la información
- sólo quede expuesta

- esas
- operaciones.


### reduce
- acoplamiento.


## El proceso de codiﬁcación


#### comienza

- está disponible
- especiﬁcación
- diseño

- módulos.


#### módulos

- se asignan
- programadores
- individuales.


#### Desarrollo top-down

- módulos
- niveles superiores
- desarrollan

- primero.


#### Desarrollo bottom-up

- módulos
- niveles inferiore
- desarrollan

- primero.


### codiﬁcación incremental


#### Proceso básico:


- Escribir
- código
- módulo.

- Realizar
- test
- unidad.

- Si error:
- arreglar bugs
- repetir tests.

\
![22a](/home/lautarob/Documents/Facultad/año3/IS1/filminas/06A-Codificacion-9/22a.png){ width=250px }


### Desarrollo dirigido por test


#### primero

- escribe
- tests

#### luego


- código
- para que
- pasen
- los
- tests


#### Se realiza

- incrementalmente.


#### se escribe

- código
- suﬁciente
- pasar
- test


#### responsabilidad de asegurar cobertura

- funcionalidad
- radica
- diseño

- test
- no
- codiﬁcación.


#### Ayuda

- asegurar
- código
- testeable.


#### completitud del código

- depende

- toda la cuan exhaustivo
- el test.

#### la funcionalidad código necesitará

- radica en el refactorización

- mejorar
- código

- confuso

\
![26a](/home/lautarob/Documents/Facultad/año3/IS1/filminas/06A-Codificacion-9/26a.png){ width=250px }


### Programación de a pares


#### código se escribe

- dos programadores


#### ambos programadores diseñan

- algoritmos,

- estructuras de datos,
- estrategias,
- etcétera.


#### Una persona

- tipea
- código,

#### la otra

- revisa
- código


#### roles

- alternan
- periodicamente.


#### revisión de código

- continua.

#### Mejor

- diseño
- algoritmos/estructuras de datos/lógica/...

#### más difícil

- escapen
- condiciones particulares.

#### efectividad

- no es
- bien sabida
- (perdida de productividad?)


## Refactorización


### refactorización
- tarea
- permite
- cambios
- programa
- con el

- 

- simpliﬁcarlo
- mejorar
- comprensión
- sin cambiar
- comportamiento observacional


### estructura interna
- cambia.


### comportamiento externo
- permanece igual.


### objetivo básico
- mejorar
- diseño
- plasmado en el
- código


### Conceptos básicos


#### ﬁn


- reducir
- acoplamiento,
- incrementar
- cohesión,
- mejorar
- principio abierto-cerrado.


#### no debe


- cambiar la funcionalidad.


#### no mezclar

- codiﬁcación normal
- refactorización.


#### principal riesgo

- “romper”

- funcionalidad existente.


#### disminuir esta posibilidad:


- Refactorizar
- en
- pequeños pasos.

- tests
- para
- funcionalidad existente.


### Malos olores


#### son

- signos
- indican
- posible
- necesidad
- refactorización.


#### Posibles malos olores:


- Código duplicado:

- Método largo:

- Clase grande:

- Lista larga de parámetros:

- subclase es la misma que la superclase;

- Demasiada comunicación

- Encadenamiento de mensajes:


### Mejoras de métodos


#### Extracción de métodos:


- separar en
- métodos cortos
- cuya
- signatura
- indique
- lo
- que

- hace.


#### Agregar/eliminar parámetros:


- simpliﬁcar
- interfaces


### Mejoras de clases


#### Desplazamiento de métodos:


- método
- actúa demasiado
- objetos
- otra clase.


#### Desplazamiento de atributos:


- atributo
- se usa más
- otra clase,
- moverlo

- Mejora
- cohesión
- acoplamiento.


#### Extracción de clases:


- clase
- agrupa
- múltiples conceptos,

- Mejora cohesión.


#### Remplazar valores de datos por objetos:


- Algunas veces,
- colección de atributos
- transforma
- entidad lógica.

- Separarlos
- como
- clase


### Mejoras de jerarquías


#### Remplazar condicionales con polimorﬁsmos:


- no se está explotando

- OO.

- Reemplazar
- casos
- a través
- jerarquía de clases
- apropiada.


#### Subir métodos / atributos:


- elementos comunes
- pertenecer
- superclase.

- funcionalidad
- atributo
- duplicado
- subclases,
- subirse

- superclase.