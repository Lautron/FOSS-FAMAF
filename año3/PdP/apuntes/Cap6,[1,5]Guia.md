# Control de la ejecución


## Pasaje de parámetros

**Los nombres de los parámetros**
**cuando se declara una función se llaman parámetros formales.**
**Cuando se llama a una función, se usan los llamados parámetros reales,**
que son los valores efectivos de los parámetros formales en una llamada concreta a la función.

Los distintos mecanismos de pasaje de parámetros se diferencian por el momento en el que se evalúa el parámetro real
(evaluación estricta, en el momento de pasar el parámetro, o perezosa, cuando se necesita)
y por la ubicación de memoria donde se almacena el valor

del parámetro
(la misma ubicación del bloque que hace la llamada a función o una nueva ubicación especíﬁca de la función).
La mayoría de los lenguajes de programación actuales evalúan los parámetros reales de forma estricta, no perezosa,
Entre los mecanismos
los más comunes son el pasaje por referencia y el pasaje por valor.
se diferencian entre ellos por la ubicación de memoria donde se almacena el valor del parámetro.
El pasaje por referencia
por
por referencia pasa el L-valor, es decir, la ubicación en memoria,
del parámetro real, mientras que el pasaje por valor pasa el R-valor,
es decir, el valor que hay en la ubicación de memoria.
es importante
por varias razones:

**Efectos secundarios**
Las asignaciones de valor en el interior del cuerpo de la función pueden tener diferentes efectos.

**Aliasing**
el aliasing ocurre cuando dos identiﬁcadores de variable se reﬁeren al mismo objeto o ubicación.

**Eﬁciencia**
Pasar por valor puede ser ineﬁcaz para grandes estructuras de datos, si hay que copiar ese valor. Pasar por referencia puede ser menos eﬁciente que pasar por valor peque˜nas estructuras que se adapten bien en la pila, porque cuando los parámetros se pasan por referencia, debemos resolver la referencia de un puntero para obtener su valor.

dos formas de describir la semántica del pasaje de parámetros: con diagramas de la memoria y la pila que muestren si la pila contiene una copia del parámetro real o una referencia.
Otra
es
traducir el código a un lenguaje que distinga entre R-valores y L-valores,


## Semántica de pasaje por valor (call-by-value)

pasaje por valor es la estrategia de evaluación más común en los lenguajes de programación. Es una forma estricta de pasaje de parámetros,
el argumento se evalúa, y el valor que se obtiene (su R-valor) se liga a una variable local de la función, en general copiando el valor a una nueva ubicación de memoria en el activation record de la llamada a función. El valor que se encuentra en el activation record que llama a la función no es modiﬁcado en ningún momento.

## Semántica de pasaje por referencia call-by-reference

En pasaje por referencia se liga el L-valor del parámetro real al parámetro formal. En este caso se tiene un único valor referenciado (o apuntado) desde dos puntos diferentes, el programa principal y la función a la que se le pasa el argumento, por lo que cualquier acción sobre el parámetro se realiza sobre la misma posición de memoria (aliasing).
Esto signiﬁca que la función que es llamada puede modiﬁcar la variable con efecto en el bloque que llama a la función.


### Sutilezas entre pasaje por valor y pasaje por referencia

En lenguajes puramente funcionales típicamente no hay diferencia semántica entre pasaje por valor y pasaje por referencia, porque sus estructuras de datos son inmutables, por lo que es imposible que una función pueda modiﬁcar sus argumentos.
normalmente se describen como de pasaje por valor, a pesar de que las implementaciones utilizan normalmente pasaje por referencia internamente porque es más eﬁciente.
En algunos casos de pasaje por valor el valor que se pasa
es
una referencia a una ubicación de memoria.
sintácticamente parece llamada por valor
puede terminar teniendo los efectos de un pasaje por referencia.
Lenguajes como C y ML utilizan esta técnica.

varias razones por las que se puede pasar una referencia. Una razón puede ser que el lenguaje no permita el pasaje por valor de estructuras de datos complejas, y se pase una referencia para preservar esa estructura. También se usa de forma sistemática en lenguajes con orientación a objetos, lo que se suele llamar call-by-sharing, call-by-object o call-by-object-sharing.
**call-by-sharing, el pasaje de parámetros es por valor, pero se pasa una referencia a un objeto. Por lo tanto, se hace una copia local del argumento que se pasa, pero esa copia es una referencia a un objeto que es visible tanto desde la función llamada como desde la función que llama.**
La semántica
diﬁere del pasaje por referencia en que las asignaciones a los argumentos dentro de la función no son visibles a la función que llama,
si se pasa una variable, no es posible simular una asignación en esa variable en el alcance de la función que llama. Por lo tanto, no se pueden hacer cambios a la referencia que se ha pasado por valor.
a través de esa referencia de la que la función llamada ha hecho una copia, ambas funciones, la llamada y la que llama, tienen acceso al mismo objeto, no se hace ninguna copia. Si ese objeto es mutable, los cambios que se hagan al objeto dentro de la función llamada son visibles para la función que llama, a diferencia del pasaje por valor.
el término call-by-sharing no se usa
no se usa mucho, se usan diferentes términos en los diferentes lenguajes y documentaciones.


## Semántica de pasaje por valor-resultado

Es un tipo de pasaje de parámetros con evaluación estricta (no perezosa) poco usado en los lenguajes de programación actuales. Se basa en que dentro de la función se trabaja como si los argumentos hubieran sido pasados por valor, pero al acabar la función los valores que tengan los argumentos serán copiados a la ubicación de memoria en la que se ubicaba el valor copiado inicialmente.


## Pasaje de parámetros no estricto (perezoso)

En la evaluación perezosa, los argumentos de una función no se evalúan a menos que se utilicen efectivamente en la evaluación del cuerpo de la función.


### Pasaje por nombre call-by-name

En el pasaje call-by-name, los argumentos de una función no se evalúan antes de la llamada a la función, sino que se sustituyen sus nombres directamente en el cuerpo de la función y luego se dejan para ser evaluados cada vez que aparecen en la función. Si un argumento no se utiliza en el cuerpo de la función, el argumento no se evalúa; si se utiliza varias veces, se re-evalúa cada vez que aparece.
En algunas ocasiones, call-by-name tiene ventajas sobre pasaje por valor,
por ejemplo,
si el argumento no siempre se usa, porque nos ahorramos la evaluación del argumento. Si el argumento es un cálculo no termina, la ventaja es enorme.


### Pasaje por necesidad call-by-need

El pasaje por necesidad call-by-need es una versión memoizada de pasaje por nombre donde, si se evalúa el argumento de la función, ese valor se almacena para usos posteriores. En un entorno de ”puro”(sin
efectos secundarios), esto produce los mismos
esto produce los mismos resultados que el pasaje por nombre; cuando el argumento de la función se utiliza dos o más veces, el pasaje por necesidad es casi siempre más rápido.

## Alcance estático vs. alcance dinámico

Si un identiﬁcador x aparece en el cuerpo de una función, pero x no se declara dentro de la función, entonces el valor de x depende de alguna declaración fuera de la función.
la ubicación de x está fuera del registro de activación para la función y es una variable libre o variable global respecto a esa función.
Debido a que x ha sido declarada en otro bloque,
Hay dos políticas principales para buscar la declaración adecuada de un identiﬁcador de variable libre:

**alcance estático**

****

**léxico)**

****

Un identiﬁcador global se reﬁere al identiﬁcador con ese nombre que se encuentre en el bloque contenedor más cercano en el texto del programa.

**alcance dinámico**
Un identiﬁcador global se reﬁere al identiﬁcador que se encuentre en el registro de activación más reciente en la pila de ejecución.

la búsqueda de una declaración usando la política de alcance estático utiliza la relación estática e inmutable entre bloques en el texto del programa. Por el contrario, el alcance dinámico utiliza la secuencia efectiva de las llamadas que se ejecutan en la ejecución del programa, que es dinámica y puede cambiar.

## Naturalidad y overhead del alcance estático

El alcance estático es la semántica más intuitiva
los lenguajes de programación proveen los mecanismos necesarios para poder mantener esta semántica.
Hay diferentes opciones para hacerlo.
La opción más sencilla es prohibir los contextos en los que el alcance estático daría un resultado distinto al alcance dinámico.

Sin embargo, en la mayoría de lenguajes se usan access links para mantener la semántica de alcance estático.
**Un access link es una dirección de memoria que se guarda en el activation record de una función y que apunta al activation record del bloque más cercano que lo contiene en el texto**

**del programa.**
Para los bloques anidados in-line esta dirección de memoria es redundante con el control link, ya que el bloque más cercano que lo contiene siempre se corresponde con el activation record que se ha apilado inmediatamente antes.
Para las funciones,
el bloque más cercano que la contiene viene determinado por el lugar donde se declara la función. Debido a que el punto de declaración a menudo es diferente del punto en el que se llama a una función, el access link generalmente apunta a un registro de activación diferente al enlace de control.


## Recursión a la cola

optimización del compilador que se llama eliminación de la recursión a la cola. Para las funciones recursivas a la cola, que describimos a continuación, se puede reutilizar un activation record para una llamada recursiva a la función. Esto reduce la cantidad de espacio de la pila que usa una función recursiva, y

evita llegar a problemas por límites de hardware como el llamado stack overﬂow, en el que la ejecución de un programa requiere más espacio del que hay disponible en la pila.

**Una función f es recursiva de cola si todas las llamadas recursivas en el cuerpo de f son llamadas a la cola a f.**

La ventaja de la recursión de cola es que podemos utilizar el mismo activation record para todas las llamadas recursivas.


## Alto orden


### Funciones de primera clase

Un lenguaje tiene funciones de primera clase si las funciones pueden ser

declaradas dentro de cualquier alcance,

pasadas como argumentos a otras funciones y,

devueltas como resultado de funciones.

En un lenguaje con funciones de primera clase y con alcance estático, un valor de función se representa generalmente por una clausura, un par formado por un puntero al código del cuerpo de una función y otro puntero a un activation record, con una semántica prácticamente equivalente a un access link.


### Pasar Funciones a otras Funciones

Vamos a ver que cuando una función f se pasa a una función g, es posible que tengamos que pasar también la clausura de f, que contiene un puntero a su activation record. Cuando f se llama dentro del cuerpo de g, el puntero de entorno de la clausura se utiliza para determinar cuál es el access link que tiene que guardarse en el activation record de la llamada a f. La necesidad de clausuras en este contexto se conoce como el problema de downward funarg, porque sucede cuando se pasan funciones como argumentos hacia abajo en alcances anidados.

La solución estándar para mantener el alcance estático cuando las funciones se pasan como argumentos a otras funciones o se devuelven como resultados es utilizar una estructura de datos llamada clausura. La clausura es un par formado por un puntero a la parte de la memoria donde se guarda el código de la función y otro puntero a un activation record. Debido a que cada activation record contiene un access link se˜nalando al activation record del bloque del texto del programa más cercano que lo contiene, un puntero al alcance en el que se declara una función también proporciona enlaces al activation record del bloque que la contiene.