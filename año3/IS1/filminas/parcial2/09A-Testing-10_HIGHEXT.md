# Testing

## Conceptos


### Defecto y desperfecto


#### Desperfecto:

- ocurre si
- el comportamiento
- es distinto
- del esperado/especiﬁcado.


#### Defecto:

- es lo que causa
- el desperfecto.

- Defecto = bug
- desperfecto implica
- presencia del defecto.
- existencia del defecto
- no implica
- ocurrencia
- desperfecto.
- Qué cosa es considerada un desperfecto
- depende del proyecto


### Rol del testing:


#### Las revisiones


- no pueden encontrar todos los defectos.


#### En consecuencia

- habrá defectos


#### tienen que identiﬁcarse

- por medio del testing.


#### rol crítico

- garantizar calidad.


#### detectar los defectos

- debemos causar
- desperfectos
- durante el testing.

#### identiﬁcar el defecto real

- recurrir al

- debugging. 


### Oráculos de tests


#### veriﬁcar la ocurrencia de un desperfecto


- necesitamos conocer
- comportamiento correcto
- necesitamos un
- oráculo de test.


#### pretendemos que el oráculo

- siempre dé el resultado correcto.

- Muchas veces el oráculo es
- humano
- propenso a cometer errores.


#### El oráculo humano

- usa la especiﬁcación

- decidir el “comportamiento correcto”.


#### Las mismas especiﬁcaciones

- pueden contener errores.


### Casos de test y criterios de selección


#### Idealmente:


- conjunto de
- test
- tal que
- ejecución satisfactoria

- implique
- ausencia de defectos.

- como el testing es costoso,
- deseamos que sea
- conjunto reducido.


#### El criterio de selección

- especiﬁca
- condiciones
- conjunto
- de test

- debe satisfacer
- con respecto
- al programa
- y/o a la especiﬁcación.


### propiedades fundamentales


#### Conﬁabilidad:

- todos los conjuntos de
- test
- que satisfacen el criterio
- detectan los mismos errores.


#### Validez:

- para cualquier error
- hay un conjunto de
- test
- que satisfagan tal criterio
- detecten el error.


#### prácticamente imposible

- obtener
- criterio
- conﬁable
- válido

- al mismo tiempo,


### testing


#### debe

- revelar los defectos

- ser “destructivos”.


## Testing de caja negra


### diseñar los casos de test,

#### se utiliza

- comportamiento esperado
- sistema.

- test se seleccionan
- sólo a partir
- especiﬁcación.


#### No se utiliza

- estructura interna del código.


### Premisa:
- el comportamiento esperado
- está especiﬁcado.


### Para el testing de módulos:
- especﬁciﬁcación
- diseño
- deﬁne

- comportamiento esperado.


### Para el testing del sistema:
- la SRS deﬁne el comportamiento esperado.


### exhaustivo:

- Testear
- con todos los elementos
- espacio de entrada.

- No es viable:


### Particionado por clase de equivalencia


#### Dividir el espacio de entrada

- en clases de equivalencias.


#### idea:

- Si el software funciona para un
- test en una clase

- muy probablemente funcione
- para todos los elementos de la misma clase.


#### Base lógica:

- especiﬁcación requiere
- mismo comportamiento
- todos los elementos

- una misma clase.

- Es muy probable que
- falle para todos
- o para ninguno.


#### Cada condición especiﬁcada como entrada

- es una clase de equivalencia.

#### Para lograr robustez,

- armar clases de equivalencias

- entradas inválidas.
- especiﬁca el rango 0  $\leq$  x  $\leq$  MAX.

#### Ej.:


- rango [0..MAX] forma una clase,

- x < 0
- deﬁne una clase inválida,

- x > MAX
- deﬁne otra clase inválida.


#### También se deben considerar

- clases de equivalencia de
- datos de salida.


#### Una vez elegidas las clases de equivalencia,

- seleccionar los casos de test:

- 1. Seleccionar
- test
- cubriendo tantas clases
- como sea posible.

- 2. O dar un
- test
- cubra a lo sumo
- una clase válida por cada entrada.


### Análisis de valores límites


#### Los programas generalmente fallan

- sobre valores especiales.

- se encuentran en
- los límites

- clases de equivalencia.


#### test de valores límites

- conjunto de datos de entrada

- que se encuentra en
- el borde de las clases de equivalencias
- entrada
- salida.


#### Para cada clase de equivalencia:


- Elegir valores
- en los límites de la clase.

- justo fuera
- dentro
- de los límites.

- Considerar las salidas
- producir
- test
- generen salidas

- sobre los límites.


#### caso de múltiples entradas


- Ejecutar todas las combinaciones posibles

- Seleccionar
- casos límites
- una variable
- mantener las otras en casos
- normales


### Comparación

### Grafo de causa-efecto


#### Para manipular las entradas

- distintas combinaciones
- clases de equivalencia

- deben ser ejecutadas.

- cantidad de combinaciones
- puede ser grande:


#### ayuda a

- seleccionar
- combinaciones

- como condiciones de entrada.


#### Identiﬁcar

- causas y efectos en el sistema


#### Causa:

- distintas condiciones
- entrada
- verdaderas
- falsas.

#### Efecto:

- distintas condiciones
- salidas
- (V/F también).

- cuáles causas pueden
- producir qué efectos;


#### Causas y efectos son

- nodos en el grafo.

#### Las aristas

- determinan dependencia:
- hay aristas
- “positivas”
- “negativas”.

#### Existen nodos

- “and”
- “or”
- combinar la causalidad.


#### A partir del grafo

- se puede armar
- una tabla de decisión.

- Lista
- combinaciones de condiciones
- hacen efectivo cada efecto.


#### La tabla de decisión

- usarse
- armar
- casos de test.


### Testing de a pares


#### Usualmente muchos parámetros

- determinan
- comportamiento del sistema.


#### Los defectos de modo simple

- pueden detectarse
- veriﬁcando distintos valores

- de los distintos parámetros.


#### Los defectos de modo múltiple

- se revelan con
- test

- que contemplen las combinaciones apropiadas.

- Esto se denomina
- test combinatorio.


#### test combinatorio no es factible:


- n parámetros / m valores
- nm casos de test.

- nm = 3125.


#### mayoría de tales defectos

- se revelan
- interacción de

- pares de valores.


#### Para modo doble

- necesitamos ejercitar cada par
- =>
- se denomina testing de a pares.


#### En testing de a pares,

- todos los pares de valores
- deben ser ejercitados.

#### n parámetros / m valores,


- m2 * n * (n-1) / 2


#### generación del conjunto de casos de test más chico


- que provea cobertura completa de los pares no es trivial.


#### Existen algoritmos eﬁcientes

- para generación de
- test

- pueden reducir el esfuerzo de testing considerablemente.


#### es un enfoque

- práctico
- muy utilizado en la industria.


### Testing basado en estados


#### En muchos sistemas,

- comportamiento depende
- estado del sistema,

- misma entrada,
- comportamiento podría diferir


#### testing basado en estado

- está dirigido a tales sistemas.


#### Un sistema puede modelarse

- como una máquina de estados.


#### El espacio de estados

- puede particionarse
- pocos estados,
- cada uno

- representando
- estado lógico de interés


#### componentes:


- conjunto de estados:
- estados lógicos representando

- impacto acumulativo del sistema.

- conjunto de transiciones:
- cambio de estado

- en respuesta a algún evento de entrada.

- conjunto de eventos:
- entradas al sistema.

- conjunto de acciones:
- salidas producidas
- en respuesta a
- los eventos

- de acuerdo al estado actual.


#### el modelo de estado se construye a partir

- especiﬁcaciones

- o los requerimientos.


#### El desafío más importante es,

- partir de la especiﬁcación/requerimientos,

- identiﬁcar
- conjunto de estados
- captura las propiedades claves
- pero es
- suﬁcientemente pequeño


#### Los casos de test

- se seleccionan con el modelo de estado


#### criterios para generar los casos de test.


- Cobertura de transiciones:

- asegurar que toda transición sea ejecutada.

- Cobertura de par de transiciones:

- ejecutar todo par de transiciones adyacentes

- Cobertura de árbol de transiciones:
- ejecutar todos los caminos simples


#### El test basado en estados

- se enfoca en
- testing de
- estados
- transiciones.


#### El modelo de estado se realiza

- luego de que

- información de diseño
- se hace disponible.


## Testing de caja blanca


### se enfoca en
- el código:


### objetivo
- ejecutar
- estructuras del programa

- descubrir errores.


### test se derivan
- del código.

### Se denomina también
- testing estructural.


### Tipos

#### Criterio basado en el ﬂujo de control.


- Observa
- cobertura del grafo de ﬂujo de control.


#### Criterio basado en el ﬂujo de datos.


- Observa
- cobertura
- relación deﬁnición-uso
- en las variables.


#### Criterio basado en mutación.


- Observa
- mutantes del programa original.

- (¡el tercero lo leen del libro!)


### Criterio basado en ﬂujo de control


#### Considerar al programa como un grafo de ﬂujo de control.


- Los nodos
- representan bloques de código,

- Una arista (i, j)
- representa
- posible transferencia de control
- del nodo i al j.

- Suponemos la existencia de
- nodo inicial
- nodo ﬁnal.


#### Criterio de cobertura de sentencia


- Cada sentencia
- se ejecuta al menos una vez
- durante el testing.


#### Criterio de cobertura de ramiﬁcaciones


- cada decisión debe ejercitarse como
- verdadera
- falsa
- durante el testing.

- implica
- cobertura de sentencias.


#### Criterio de cobertura de caminos


- Todos los posibles caminos
- estado inicial
- al ﬁnal
- deben ser ejercitados.

- implica
- cobertura de bifurcación.

- Problema:
- cantidad
- caminos
- inﬁnita

- caminos
- no
- realizables.


#### Ninguno es suﬁciente para

- detectar todos los tipos de defectos


#### Proveen alguna idea cuantitativa

- de la “amplitud” del conjunto
- de test.


### Criterio basado en ﬂujo de datos


#### construye un grafo de deﬁnición-uso


- etiquetando apropiadamente el grafo de ﬂujo de control.


#### tipos:


- def:

- var está a la izquierda de la asignación).

- uso-c:
- variable se usa para cómputo.

- uso-p:
- variable se utiliza en un predicado

- transferencia de control.


#### grafo de def-uso se construye


- asociando variables a nodos y aristas del grafo de ﬂujo de control:

- Por cada nodo i,
- def(i)
- conjunto de variables

- hay una deﬁnición en i.

- c-use(i)
- conjunto de variables
- hay un uso-c.

- Para una arista (i,j),
- p-use(i,j)
- conjunto de variables

- hay un uso-p.


#### Un camino de i a j

- se dice libre de deﬁniciones
- con respecto a una var x

- si no hay deﬁniciones de x
- en todos los nodos intermedios.


#### Criterios:


- todas las deﬁniciones:
- por cada nodo i
- cada x en def(i)

- hay un camino libre de deﬁniciones
- con respecto a x
- hasta un uso-c o uso-p de x.

- todos los usos-p:
- todos los usos-p de todas las deﬁniciones deben testearse.

- otros criterios:
- todos los usos-c,
- algunos usos-p,
- algunos usos-c.


## El proceso de testing


### Testing incremental


#### Testing incremental:

- agregar partes no testeadas
- incrementalmente

- a la parte ya testeada.


#### esencial para


- ayuda a encontrar más defectos

- ayuda a la identiﬁcación
- eliminación.


#### El testing de grandes sistemas

- siempre de manera incremental.


### Niveles de testing


#### se utilizan distintos niveles de testing


- para revelar los distintos tipos de defectos.


#### Testing de unidad:

- distintos módulos del programa

- se testean separadamente contra el diseño,

- Se enfoca en
- defectos inyectados durante la codiﬁcación.

- objetivo
- testear
- lógica interna de los módulos.

- programador
- realiza el test


#### Testing de integración:

- Se enfoca en
- interacción
- módulos

- énfasis en
- testing de las interfaces


#### Testing del sistema:

- El sistema
- completo es testeado.
- veriﬁcar si
- software implementa
- requerimientos.
- etapa ﬁnal del testing
- antes de que el software sea entregado.
- realizado por
- personal independiente.

- fase de testing que
- consume mas tiempo.


#### Testing de aceptación:


- veriﬁcar
- software satisfaga
- necesidades
- usuario.

- se realiza por
- usuario/cliente

- después de que el testing de aceptación resulte satisfactorio,

- software es puesto en ejecución (“deployed”).

- El plan del test de aceptación
- se basa en
- criterio del test de aceptación

- SRS.


#### Otras formas

- Testing de desempeño:

- Requiere de herramientas
- medir el desempeño.

- Testing de estrés

- sistema se sobre carga al máximo;

- Testing de regresión:

- funcionalidades previas continúen funcionando


### Especiﬁcación de los casos de test


#### realizar separadamente


- cada unidad.


#### Por cada unidad de test

- se determinan
- test
- de acuerdo
- plan

- (enfoques, características, etc.).


#### cada caso de test se especiﬁca:


- entradas a utilizar,

- condiciones que éste testeará,

- resultado esperado.


#### efectividad y costo del testing

- dependen
- conjunto de

- test seleccionado.


#### determinar si un conjunto de casos de test es bueno?


- No existe una manera


#### Para cada testeo,

- se desarrolla
- especiﬁcación de
- test

- que se revisa y se ejecuta.


#### preparación de la especiﬁcación


- tarea exigente y que demanda tiempo:

- Se pueden utilizar
- criterios para casos de test.

- casos especiales y escenarios.


### Ejecución de los casos de test y análisis


#### puede requerir de

- “drivers”
- “stubs”.
- módulos extras para preparar el entorno

- acorde a las condiciones establecidas en la especiﬁcación


#### Algunos test

- pueden automatizarse,
- otros necesitan ser manuales:


### Registro de defectos y seguimiento


#### Los defectos encontrados

- se registran en

- sistema seguidor de defectos (“tracking”)
- permite rastrearlos hasta que se “cierren”.


#### ciclo de vida;


- Alguien lo encuentra
- y lo registra

- Se asigna la tarea de corrección;

- veriﬁca que el defecto fue

- corregido


#### severidad del defecto


- Crítico:
- puede demorar el proceso;
- afecta a muchos usuarios.

- Mayor:
- mucho impacto
- posee soluciones provisorias;

- requiere de mucho esfuerzo
- tiene menor impacto en el cronograma.

- Menor:
- se maniﬁesta raramente
- tiene poco impacto.

- Cosmético:
- pequeños errores
- sin impacto en el funcionamiento