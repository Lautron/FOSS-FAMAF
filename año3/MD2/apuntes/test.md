# Grafos
<!-- from 01_Grafos_shortened_HIGHEXT.md -->


## Definicion
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
### Definicion
es un par ordenado G = (V, E) donde

**V**
es un conjunto cualquiera.

En esta materia siempre supondremos V ﬁnito.

**E**
es un subconjunto del conjunto de subconjuntos de 2 elementos de V.

es decir E  $\subseteq$  {A  $\subseteq$  V : |A| = 2}


## Notaciones
<!-- from 01_Grafos_shortened_HIGHEXT.md -->


### elementos de V
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
se llaman
**vértices**
o nodos. Usaremos preferentemente el primer nombre.


### elementos de E
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
se llaman
**lados**
o aristas. Usaremos preferentemente el primer nombre.


### cantidad de elementos de V,
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
salvo que digamos otra cosa, se denotará por default como n.


### cantidad de elementos de E,
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
salvo que digamos otra cosa, se denotará por default como m.


### Un elemento {x, y}  $\in$  E
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
será abreviado como xy.

x e y se llamarán los extremos del lado xy.


## Subgrafos
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

### Definicion
Dado un grafo G = (V, E), un
**subgrafo**
de G es un
**grafo**
H = (W, F) tal que W  $\subseteq$  V y F  $\subseteq$  E.

Observemos que pedimos que H sea en si mismo un grafo.
No cualquier par (W, F) con W  $\subseteq$  V y F  $\subseteq$  E será un subgrafo


## Vecinos de un vértice
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

### Definicion
Dado x  $\in$  V,
los vértices que forman un lado con x se llaman los
**vécinos**
$\in$  de x.

El conjunto de vécinos se llama el

### “vecindario”
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
y se denota por  $\Gamma$ (x).

Es decir  $\Gamma$ (x) = {y  $\in$  V : xy  $\in$  E}


## Grado de un vértice
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

### Definicion
La cardinalidad de  $\Gamma$ (x) se llama el
**grado**
de x,
y la denotaremos por d(x) (o $d_G(x)$)


### WARNING:
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
en algunos libros se denota usando la letra griega delta:  $\delta$ (x)

### El menor de todos los grados
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
de un grafo lo denotaremos por  $\delta$

$\delta$  = Min{d(x) : x  $\in$  V}

### mayor de todos los grados
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
de un grafo lo denotaremos por
por  $\Delta$ .

Min{d(x)  $\in$  V}  $\Delta$  = Max{d(x) : x  $\in$  V}


### grafo regular.
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
Un grafo que tenga  $\delta$  =  $\Delta$  (es decir, todos los grados iguales) se llamará un grafo regular

o  $\Delta$ -regular si queremos especiﬁcar el grado común a todos los vértices.


## Cíclicos y completos
<!-- from 01_Grafos_shortened_HIGHEXT.md -->


### grafo cíclico
#### Definicion
\
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
en n vértices, (n > 3) denotado por $C_n$, es el grafo:

$\{X_{1},...,X_{n}\}$ y lados $\{X_{1}X_{2},\,X_{2}X_{3},...,X_{n-1}X_{n},X_{n}X_{1}\}\}).$

#### Vertices
\
Tiene n vertices

#### Lados
\
Tiene n lados

#### Grado
\
$d_{C_{n}}(X)=2$
para todo vértice de $C_{n}$

Es 2-regular

#### Origen del nombre
\

$C_{n}$ se llaman cíclicos porque su representación gráﬁca es un ciclo de n puntos.


### grafo completo
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\

#### Definicion
\
en n vértices, denotado por $K_{n}$ , es el grafo:

$\{X_{1}\,,\,...,\,X_{n}\}$ y lados $\{X_{i}X_{j}\,:\,i,j\in\{\,1\,,2,\,...,n\}\,,i\,<j\})$

#### Vertices
\
Tiene n vertices

#### Lados
\
Tiene 
${\binom{n}{2}}={\frac{n(n-1)}{2}}$
lados.

#### Grado
\
${d}_{K_{n}}(X)=n-1$
para todo vértice de $K_{n}$




Por lo tanto ambos son grafos regulares.

Es $(n-1)$-regular


## camino
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

### Definicion
Un camino entre 2 vertices x,y es una sucesion de vertices
$X_{1},...,X_{r}$
tales que:

1. $x_{1}=X$
2. $\textstyle x_{r}=y$
3. $x_{i}x_{i+1}\in E\ \forall i\in\{1,2,...,r-1\}$

### Notacion
x  $\sim$  y 

sii existe un camino entre x e y

### Componentes conexas
"$\sim$" es una relación de equivalencia.

por lo tanto el grafo G se parte en clases de equivalencia de esa relación de equivalencia.

Esas partes se llaman las componentes conexas de G.

## Grafos conexos
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

Un grafo se dice conexo si tiene una sola componente conexa.

$C_{n}$ y $K_{n}$ son conexos.


### arbol
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
es un grafo conexo sin ciclos.


## Determinación de las componentes conexas
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

El algoritmo básico de DFS o BFS lo que hace es, dado un vértice x, encontrar todos los vértices de la componente conexa de x.


### algoritmo
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\

(abajo en vez de BFS puede usarse DFS)

#. Tomar W =  $\varnothing$ , i = 1.
#. Tomar un vértice cualquiera x de V.
#. Correr BFS(x).
#. LLamarle Ci a la componente conexa que encuentra BFS(x).
#. Hacer W = W $\cup$  (vértices de Ci).
#. Si W = V, return C1, C2, ..., Ci.
#. Si no, hacer i = i + 1, tomar un vértice x $\notin$  W y repetir [3].


## DFS y BFS
<!-- from 01_Grafos_shortened_HIGHEXT.md -->


### breve repaso
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\

a partir de un vértice raiz, los algoritmos van buscando nuevos vértices, buscando vecinos de vértices que ya han sido agregados.

### Diferencia
DFS agrega de a un vécino por vez y usa una pila.

BFS agrega todos los vecinos juntos y usa una cola.


### BFS(x):
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

\begin{tabular}{ l l l }
& Crear una cola con x como único elemento.\\
& Tomar C = {x}.\\
& WHILE (la cola no sea vacia)\\
& \quad \quad Tomar p=el primer elemento de la cola.\\
& \quad \quad Borrar p de la cola.\\
& \quad \quad IF existen vértices de\quad $\Gamma$ (p) que no esten en C:\\
& \quad \quad \quad \quad Agregar todos los elementos de\quad $\Gamma$ (p) que no estén en C a la cola y a C.\\
& ENDWHILE\\
& return C.\\
\end{tabular}


### DFS(x):
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

\begin{tabular}{ l l l }
& Crear una pila con x como único elemento.\\
& Tomar C = {x}.\\
& WHILE (la pila no sea vacia)\\
& \quad \quad Tomar p=el primer elemento de la pila.\\
& \quad \quad IF existe algún vértice de\quad $\Gamma$ (p) que no esté en C:\\
& \quad \quad \quad \quad Tomar un q\quad $\in$\quad  $\Gamma$ (p)\quad $-$\quad C.\\
& \quad \quad \quad \quad $\in$\quad  $-$\quad Hacer C = C\quad $\cup$\quad {q}.\\
& \quad \quad \quad \quad $\cup$\quad {q}. Agregar q a la pila.\\
& \quad \quad ELSE:\\
& \quad \quad \quad \quad Borrar p de la pila.\\
& ENDWHILE\\
& return C.\\
\end{tabular}


### Complejidad
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

la complejidad tanto de DFS como de BFS es O(m).


## Coloreos propios
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
### Coloreo
Un coloreo (de los vértices) es una función cualquiera c : V → S donde S es un conjunto ﬁnito.


### Cantidad de colores
Si la cardinalidad de S es k diremos que el coloreo tiene k colores.
En general usaremos S = {0, 1, ..., k  $-$  1} para denotar los colores.

### Coloreo propio
Un coloreo es propio si xy  $\in$  E  $\Rightarrow$  c(x) $\neq$  c(y) (extremos con distinto color)

Un grafo que tiene un coloreo propio con k colores se dice k-coloreable.


# Número cromático
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

## Definicion
$\chi$ (G) = min{k :  $\exists$  un coloreo propio con k colores de G}


## Calculando  $\chi$ (G)
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

Si uno dice que  $\chi$ (G) = k, por la deﬁnición misma de este número, hay que hacer dos cosas para probarlo:

1. Dar un coloreo propio de G con k colores. (y obviamente probar que es propio).
    - Esto prueba la parte del “ $\exists$  un coloreo propio con k colores de G”
\
2. Probar que no existe ningún coloreo propio con k  $-$  1 colores de G.
    - Esto prueba que k es el mínimo.


## probar que no existe ningun coloreo propio con k-1 colores
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

### Propiedad util
Si H es un subgrafo de G, entonces  $\chi$ (H)  $\leq$   $\chi$ (G).

Entonces si encontramos un subgrafo H de G para el cual sepamos que  $\chi$ (H) = k habremos probado que no existe ningun colore propio con k-1 colores


### prueba por contradicción:
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\
se asume que existe un coloreo propio con k  $-$  1 colores y deduciendo cosas, se llega a un absurdo.

Hay 2 problemas

1. Llegar al absurdo puede ser bastante diﬁcil, teniendo que contemplar varios casos, pej.
2. Para poder hacer la prueba por contradicción, hay que asumir que existe un coloreo propio con k  $-$  1 colores.
    - Eso signiﬁca que uds. NO TIENEN CONTROL sobre ese coloreo.
    - Sólo saben que hay uno, y deben deducir cosas sobre ese coloreo a partir de la estructura del grafo.


##  $\chi$ (G) para algunos grafos
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

### Valor "maximo" para el numero cromatico
\
En general, dado que para cualquier grafo G podemos darle un color distinto a todos los vértices, tenemos la desigualdad  $\chi$ (G)  $\leq$  n.

### Grafo completo
\
$\chi$ ($K_{n}$) = n

si quieren probar que r  $\leq$   $\chi$ (G) basta con ver que existe un $K_{r}$ subgrafo de G.

### Grafos con mas de un lado
\
$\chi$ (G) = 1 si y solo si E =  $\varnothing$  asi que para cualquier grafo que tenga al menos un lado,  

$\chi$ (G)$\geq$  2.

### Ciclos pares
$\chi(C_{2r})=2$
pues podemos colorear c(i) = (i mod 2)

### Ciclos impares
Si tenemos en cuenta a $\chi(C_{2r+1})$
tendriamos que 2r + 1 y 1 tendrían color 1, absurdo pues forman lado.

Podemos colorear: c(i) = (i mod 2) si i < 2r + 1 y c(2r + 1) = 2.

Por lo tanto, los ciclos impares tienen número cromático igual a 3.

cualquier grafo que tenga como subgrafo a un ciclo impar debe tener número cromático mayor o igual que 3.


## Algoritmo de fuerza bruta
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

### Algoritmo
simplemente tomar todos los coloreos posibles con los colores {0, 1, ..., n  $-$  1} y calcular cuales {0,  $-$  1} de esos coloreo son propios, y ver de entre esos quien tiene la menor cantidad de colores.

### Desventajas
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

Este algoritmo calcula  $\chi$ (G) pero:
Hay $n^{n}$ posibles coloreos.
Chequear que un coloreo es propio es O(m).

el algoritmo tiene complejidad O($n^n$m) asi que no es útil salvo para n muy chicos.


## Algoritmo Greedy
<!-- from 01_Grafos_shortened_HIGHEXT.md -->

El algoritmo Greedy requiere como input no sólo un grafo G sino un
**orden**
de los vértices.

para extraer el mayor beneﬁcio posible de Greedy conviene poder llamarlo varias veces cambiando el orden.


### Idea de Greedy
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\

La idea de Greedy consiste de dos partes:

1. Ir coloreando los vértices de G uno por uno, en el orden dado, manteniendo siempre el invariante que el coloreo parcial que se va obteniendo es propio.

2. Darle a cada vértice al momento de colorearlo el menor color posible que se le pueda dar manteniendo el invariante de que el coloreo es propio.


### Greedy
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\

Input: Grafo G y orden de los vértices $X_{1}\,,\,X_{2},\,\cdots,\,X_{7}.$

- $c(X_{1})=0$
- Para i > 1, asumiendo que los vértices $X_{1},\,X_{2},\,\cdot\,\cdot\,\cdot\,\cdot\,,\,X_{i-1}$ ya han sido coloreados, colorear $x_{i}$ con:
    - $c(x_{i})=\operatorname*{min}\{K\geq0:K\not\in\,c\left(\{x_{1},\,\ldots\,\cdot x_{i-1}\}\cap\Gamma(x_{i})\right)\}$

**Comentario: **

estamos usando la notación usual de c(A) = {c(a) : a  $\in$  A}.

Es decir, $x_{i}$ recibe el menor color que sea distinto del color de todos los vecinos anteriores a $x_{i}$


### Complejidad de Greedy
<!-- from 01_Grafos_shortened_HIGHEXT.md -->
\

la complejidad de Greedy es
$O( d(x_{1})+d(x_{2})+\cdot\cdot\cdot+d(x_{n})).$



Por el lema del apretón de manos que vieron en Discreta I, la suma de todos los grados es igual a 2m.

Por lo tanto la complejidad de greedy es O(2m) = O(m), osea, es polinomial
## Teoremas greedy

### Cotas para Greedy
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->
$\chi$ (G)  $\leq$   $\Delta$  + 1


### Teorema de Brooks
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

#### Definicion

Si G es conexo, entonces  $\chi$ (G)  $\leq$   $\Delta$ , a menos que G sea un ciclo impar o un grafo completo.


#### Propiedad
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

Si G es conexo, entonces existe un ordenamiento de los vértices tal que Greeedy colorea todos los vértices, salvo uno, con  $\Delta$  colores o menos.


## VIT
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->


### Very Important Theorem
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

Sea G = (V, E) un grafo cuyos vértices estan coloreados con un coloreo propio c con r colores {0, 1, ..., r  $-$  1}.

Sea  $\pi$  una permutación de los números 0, 1, ..., r  $-$  1, es decir, 

$\pi  : \{0, 1, ..., r  -  1\} \mapsto$ \{0, 1, ..., r  -  1\} es una biyección.

Sea $V_{i}$ = {x  $\in$  V : c(x) = i}, i = 0, 1, ..., r  $-$  1.

Ordenemos los vértices poniendo primero los vértices de $V_{\pi(0)}$ luego los de $V_{\pi(1)}$,etc, hasta $V_{\pi(r-1)}$

(el orden interno de los vértices dentro de cada $V_{\pi(i)}$ es irrelevante)

Entonces Greedy en ese orden coloreará G con r colores o menos.


### Corolario
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->
Existe un ordenamiento de los vértices de G tal que Greedy colorea G con  $\chi$ (G) colores.

### Consecuencia
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

si no podemos obtener  $\chi$ (G) polinomialmente, usaremos el VIT para tratar de obtener una aproximación a  $\chi$ (G).

No siempre se puede,
pero en la practica suele funcionar bastante bien, dependiendo de cuales permutaciones  $\pi$  se usen.


## Grafos bipartitos
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

### Definicion
Un grafo se dice bipartito si  $\chi$ (G) = 2.

Es decir, si G = (V, E) entonces existen X, Y  $\subseteq$  V tales que:

1. V = X  $\cup$  Y.
2. X  $\cap$  Y =  $\varnothing$
3. wv  $\in$  E  $\Rightarrow$  (w  $\in$  X, v  $\in$  Y)  $\lor$  (w  $\in$  Y, v  $\in$  X)


## El problema 2COLOR
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

### Definicion
Dado un grafo G, ¿es  $\chi$ (G)  $\leq$  2?


### Teorema
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

2COLOR es polinomial


### Algoritmo 2COLOR para G conexo.
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

#### Algoritmo

1. Elegir un vértice x cualquiera.
2. Correr BFS(x), creando un arbol.
3. Para cada vértice z, sea N(z) el nivel de z en el arbol BFS(x).
4. Colorear c(z) = (N(z) mod 2).
5. Chequear si el colorario dado en [4] es propio.
6. Si lo es, retornar “ $\chi$ (G)  $\leq$  2”
7. Si no lo es, retornar “ $\chi$ (G) > 2”


#### Complejidad
\
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

la complejidad total es O(m) + O(m) = O(m).


#### Corolario
\
<!-- from 02_Clase2Greedyreorden2COLORB_v2_HIGHEXT.md -->

Sea G un grafo con  $\chi$ (G)  $\geq$  3.

Como  $\chi$ (G)  $\geq$  3, el coloreo de 2 colores dado en el algoritmo no  $\geq$  puede ser propio.

**Conclusión:**
$\chi(G) \ge 3$ si y solo si existe un ciclo impar en G


