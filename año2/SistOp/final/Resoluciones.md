---
title: Practica Final - Sistemas Operativos
author: Lautaro Bachmann
---

# F1

## Ej1 (CORREGIR)
![](./Resoluciones_figs/fig1.png)

### Temas
- Procesos
- Api procesos

### HowTo
#### fork();
Crea un proceso. Devuelve 0 en caso hijo, >0 en caso padre. El if es para indicar que hace el padre y el hijo en base al return

#### execvp();
Esta funcion recibe como argumento un programa y un array, el array contiene el programa y argumentos.

**IMPORTANTE**: NO CREA UN NUEVO PROCESO, SI NO QUE REEMPLAZA AL QUE SE ESTABA EJECUTANDO

#### FD:
Un file descriptor es un int que sirve para identificar archivos abiertos.

0 STDIN (input) 1 STDOUT (output) 2 STDERR( error) lo

#### close(FD);
Cierra el archivo y FD que le pasamos, sin mas.

#### open(archivo, flag);
Abre en el FD mas chico (numero) el archivo que le pasamos con la flag que le pasemos xdd.
si la flag es 0, entonces **solo tiene permiso de lectura.**

#### read(FD, buffer, cantBytes);
Lee el FD y lo mete en el buffer. La cantBytes vendria a ser el tamaño

#### write(FD, buffer, CantBytes);
Escribe en el FD lo que haya en buffer, la cantBytes seria el tam del buffer

#### argc
Incluye nombre del programa. Osea que si no se pasan argumentos argc es 1

#### Pasos\
Para cada programa:

1. Describir brevemente que hace
2. Calcular cuantas veces se ejecuta `fork()`
3. Determinar que hace el padre
3. Determinar que hacen los hijos

### Resolucion (CORREGIR)

![](./Resoluciones_figs/fig28.png)

### Correcciones
- Hablar de que FDs tiene cada archivo
- Tener en cuenta que si se cierra STRERR (2) otro archivo puede ocupar ese FD
- Tener en cuenta que el **hijo** es el que devuelve 0 en fork()


## Ej2 (DONE)
![](./Resoluciones_figs/fig2.png)

![](./Resoluciones_figs/fig3.png)

### Temas
- Adress spaces
- Adress translation
- Paging

### HowTo
#### Se representa \
(BITS_PAGE_DIR, BITS_PAGE_TABLE, BITS_OFFSET)

#### Pasar de virtual a física \
1. Tomar primeros n bits especificados y ver a que entrada de la page
directory corresponde
2. Ver a que page table apunta la entrada de la page directory
3. Tomar el número de entrada de la page table del segundo grupo de m bits especificados
5. Reemplazar los primeros 5 digitos de la memoria virtual con la direccion del marco
físico de la entrada
6. Revisar demas bits entrada para ver acceso y si está presente

#### Pasar física a virtual
\
Parecido al anterior, solo que hay que ver todos los caminos que llevan a esa direccion física.

1. Ver todas las entradas de las page tables que apuntan al frame (5 primeros bytes)
2. Determinar si estas tablas son accesibles desde la page dir
3. Determinar esquema a utilizar
4. Hallar entrada page dir, entrada page table y bits offset o solo entrada
   page dir y offset segun corresponda.
5. Armar direccion concatenando los datos necesarios

#### Esquema (10, 22)
\
Para este esquema hay que tomar solo primeros 10 bits del frame number y luego concatenar con el offset


### Resolucion
#### A) DONE
\
![](./Resoluciones_figs/fig24.png)


#### B)
\
![](./Resoluciones_figs/fig25.png)


![](./Resoluciones_figs/fig26.png)


![](./Resoluciones_figs/fig27.png)


## Ej3
![](./Resoluciones_figs/fig4.png)

### Temas
- Concurrency and threads
- Semaphores

### HowTo
#### Pasos A
Pensar en el mayor y menor resultado posible.
Determinar números posibles dentro de ese intervalo.

Por ejemplo, si el menor número posible es 100 y el mayor número posible es 200.
Y podes armar números de la forma 2*n + r, con $r \in \{0,1\}$, sabes que podes
llegar a cualquier número entre 100 y 200

#### Pasos B
Usar criterio similar al anterior

#### Pasos C
- Hacer un semaforo por cada progama.
- Hacer que se vayan ejecutando intercaladamente.

### Resolucion

![](./Resoluciones_figs/fig29.png)

### Correccion
Yo lo interprete como que tiene que ir de 1 a 16, pero creo que eso está mal


## Ej4
![](./Resoluciones_figs/fig5.png)

### Temas
### HowTo
1. Buscar camino que haba que ambos programas lleguen a la CS al mismo tiempo
2. Analizar caso anterior para determinar que es lo que hace que funcione mal

### Resolucion

![](./Resoluciones_figs/fig30.png)


## Ej5
![](./Resoluciones_figs/fig6.png)

### Temas
- Hard Disk Drives

### HowTo
#### A)
\

1. Pasar RPM a RPS: `RPM/60`
2. Obtener tiempo una vuelta: `1/RPS`
3. Pasar a Ms: `1/RPS * 1000`

#### B)
\
**IMPORTANTE:** dividir $T_rotation$ en dos porque hay dos cabezales

$T_{seek} =$ tiempo provisto por fabricante

$T_{rotation} = \frac{1}{CantRPM}*60*1000$

**CORRECCION: hay que dividir Trot por 2 otra vez para obtener caso promedio**

$T_{transfer} =$ TamBloque/MaxTransfer

$T_{I/O} = T_{seek} + \frac{T_{rotation}}{2} + T_{transfer}$

$R_{I/O} = TamBloque/T_{I/O}$

#### C)
\
TamCilindro = MaxTransfer * $T_{rotation}$

### Resolucion
![](./Resoluciones_figs/fig31.png)

### Correcciones
Para pasar de MiB/ms a MiB/s hay que multiplicar por 1000


![](./Resoluciones_figs/fig32.png)

Trot hay que dividirlo por 2 para tener el caso promedio, y despues por 2 de nuevo


## Ej6 (CORREGIR)
![](./Resoluciones_figs/fig7.png)

### Temas
- File system implementation

### HowTo
#### a)
\

$indicesPorBloq = \frac{tamBloque}{CantBitsNumBloque}$

$tamMax = tamBloque *(cantBloqDir + indicesPorBloq + indPorBloq^2 + indPorBloq^3)$


#### b)
\
$capMaxDR = tamBloque * 2^{CantBitsNumBloque}$

#### c)
\
Ver que combinacion de tamaño máximo y capacidad data region permite almacenar más.

Es muy probable que por mas que haya un tamaño máximo mayor, este no pueda ser
alocado en la data region.
Tener en cuenta esto.

### Resolucion
#### a)
\
![](./Resoluciones_figs/fig34.png)

#### b)
\
![](./Resoluciones_figs/fig35.png)

### Correcciones
Prestar atencion en no poner resultado en TeraBits en vez de terabytes

# F2
### Ej1
![](./Resoluciones_figs/fig8.png)

### Temas
### HowTo
### Resolucion

## Ej2
![](./Resoluciones_figs/fig9.png)

![](./Resoluciones_figs/fig10.png)

### Temas
### HowTo
### Resolucion

## Ej3
![](./Resoluciones_figs/fig11.png)

### Temas
### HowTo
### Resolucion
![](./Resoluciones_figs/fig36.png)


## Ej4
![](./Resoluciones_figs/fig12.png)

### Temas
### HowTo
### Resolucion
![](./Resoluciones_figs/fig37.png)


## Ej5
![](./Resoluciones_figs/fig13.png)

![](./Resoluciones_figs/fig14.png)

### Temas
### HowTo

\newpage

### Resolucion

#### a)
\
Está decision de diseño posee ciertas ventajas y desventajas.

En cuanto a la velocidad, como uno de los mayores cuellos de botella es la
velocidad del disco. Si los metadatos se guardan en el mismo bloque que se guardan
los datos, podemos obtener tanto los metadatos como los datos del archivo en una sola
lectura. Por lo cual, podemos determinar que esta decision de diseño sería rápida
y eficiente. Aunque quizas se requiera que se utilice un mayor número de instrucciones
para acceder a los 75 bytes de datos.
Uno de los contras de esta idea es que se incrementa la complejidad de los datos,
y como antes mencionamos, seguramente aumenta la cantidad de instrucciones que hace
falta ejecutar para poder acceder a los datos.

Teniendo todo esto en cuenta, como en la figura podemos observar que hay una
gran cantidad de archivos con tamaño menor a $2^10$ creo que se podria conseguir
un aumento en la velocidad significativo al guardar los datos en el mismo bloque
que el inodo.

#### b)
\
Creo que no tendria sentido que los 75 bytes se usen si el tamaño del archivo
supera esta cantidad.
Esto es debido a que se pierde en gran medida la localidad de los datos.
Ya que el inodo puede estar bastante alejado de donde se encuentran los datos.

Aunque tambien se puede utilizar el argumento de que de todas maneras la informacion
del inodo será leida. Por lo cual, daria igual si almacenamos informacion en ese mismo
bloque.

### Correcciones
(Sacado de clase consulta Wolo)

En el A no hay mucha desventaja que digamos.

La desventaja del punto B es que la mayoria de programas leen en bloques.
Entonces tenés que ir calculando tamBloque - 75B y así
Despues tenes que calcular el segundo bloque, y así.
Esto complejiza las cosas.

Los programas que leen de a bloques van a andar un poco peor



## Ej6
![](./Resoluciones_figs/fig23.png)

### Temas
### HowTo
Data region = block pool

### Resolcion

#### a) y b)
\
![](./Resoluciones_figs/fig38.png)

#### c)
Conviene un número de bloque de 32b ya que es el que brinda mayor capacidad
a la block pool y ademas permite que el archivo de mayor tamaño posible llegue a entrar
hasta 4 veces en la block pool.


# F3
## Ej1
![](./Resoluciones_figs/fig15.png)

### Temas
### HowTo
### Resolucion

## Ej2
![](./Resoluciones_figs/fig16.png)

### Temas
### HowTo
- Si el codigo accede a una dir mayor o igual a $base_{code} + bounds_{code}$ da SegFault
- Si se accede a un dato mayor o igual a $base_{data} + bounds_{data}$ da SegFault
- `mov 0x4(%edx), %eax` means that you offset %edx by 4, and you move the content
of that direction into eax
- `$` identifies immediate values
- Si no hay `$` probablemente sea un acceso a memoria
- `jne` jump if not empty (not zero). Reads flag from previos operation

**Correccion:**
Las direcciones deben ser menor estricto que base + bound


### Resolucion
$base_{code} = 0x1000$

$bounds_{code} = 0x100$

$base_{data} = 0x2000$

$bounds_{data} = 0x10$

| linea   | registros            | virtual     | fisica         | SF? |
| :-----: | :------------------: | :-------    | :------        | :-: |
| 0       | edx=0x0              | 0x0         | 0x1000         |     |
| 6       | ecx=0x0              | 0x6, 0x0    | 0x1006, 0x2000 |     |
| 12      | eax=0x4              | 0xC, 0x4    | 0x100C, 0x2004 |     |
| 18      | edx=0x8              | 0x12        | 0x1012         |     |
| 21      | ecx=0x3              | 0x15, 0x8   | 0x1015, 0x2008 |     |
| 23      | edx=0xC              | 0x17        | 0x1017         |     |
| 26      | eax=0x3              | 0x1A        | 0x101A         |     |
|---------|----------------------|-------------|----------------|-----|
| 21      | ecx=0x3+0x7=0xA      | 0x15, 0xC   | 0x1015, 0x200C |     |
| 23      | edx=0x4+0xC = 0x10   | 0x17        | 0x1017         |     |
| 26      | eax=0x2              | 0x1A        | 0x101A         |     |
|---------|----------------------|-------------|----------------|-----|
| 21      | ecx=0xA+0x2=0xC      | 0x15, 0x10  | 0x1015, 0x2010 | SF! |



Así seguiria el programa (lo dejo para que quede registro):

| 23      | edx=0x14             | 0x17        | 0x1017         |     |
|---------|----------------------|-------------|----------------|-----|
| 26 | eax=0x1         | 0x1A        | 0x101A         |     |
|----|-----------------|-------------|----------------|-----|
| 21 | ecx=0xC+0x1=0xD | 0x15,  0x14 | 0x1015, 0x2014 | SF! |
| 23 | edx=0x18        | 0x17        | 0x1017         |     |
| 26 | eax=0x0         | 0x1A        | 0x101A         |     |



### Correccion
Las direcciones deben ser menor estricto que base + bounds


## Ej3
![](./Resoluciones_figs/fig17.png)

### Temas
### HowTo
### Resolucion

## Ej4
![](./Resoluciones_figs/fig18.png)

### Temas
### HowTo
### Resolucion
![](./Resoluciones_figs/fig42.png)


## Ej5
![](./Resoluciones_figs/fig19.png)

### Temas
### HowTo
### Resolucion
![](./Resoluciones_figs/fig41.png)


## Ej6
![](./Resoluciones_figs/fig20.png)

### Temas
### HowTo

\newpage

### Resolucion
![](./Resoluciones_figs/fig39.png)



## Ej7
![](./Resoluciones_figs/fig21.png)

### Temas
### HowTo
### Resolucion
![](./Resoluciones_figs/fig40.png)



# F4
## Ejercicio 1:
un codigo que se ejecutaba como ./a.out ./a.out ./a.out ./a.out ./a.out ./a.out, forkeaba el y el hijo hacia: close(1) y despues read(1, buf,L) //buf era un char[L]

Despues close (0) y write(0,buf,L) creo

El padre hacia execvp(argv[1], argv+1)

## Ejercicio 2
traducir memoria virtual a fisica en paginacion de 3 niveles, despues te daban una fisica y tenias que dar todas las virtuales que apuntaban a esa

## Ejercicio 3
 un loop de sumas en un arreglo en risc-v, tenias que dar la traza de memoria física (traducir direcciones virtuales de instrucciones y algun fetch data que pasaba por ahi) en un punto un elemento del arreglo no tenia una traduccion valida

## Ejercicio 4
 semaforos, 2 loops, 1 pone los elementos del arreglo en 0, el otro en 1, tenias que sincronizarlo para que el arreglo final quede {1,0,1,...,1}

## Ejercicio 5
 tenias que poner read/write secuencialmente en cada una de las estructuras correspondientes a la hora de ejecutar algun comando relacionado con el filesystem

El primero era create /foo/bar y despues 2 write();

# F5 (final Eze)
## Ej3
### Howto
En el a los programas son independientes.

## Ej4
### Howto
Cuando se hace read/write del inodo de bar, es para ver si ya existe
un archivo bar con proteccion de escritura por ejemplo

Osea, primero lo lees para ver si lo podes escribir y recien ahí lo escribis

O puede que justo otro programa haya escrito el inodo

## Ej5
### Howto
Hay que basarse solo en los inodos alocados

Si los bloques de un inodo apuntan todos a cero, probablemente sea un
archivo sin tamaño que se alocó todo por un calloc o similar. Que en vez
de escribir todo a memoria se hace que apunte todo a un mismo bloque que tiene
todo ceros.

Si un archivo lo llenas de ceros, se apuntan todos los bloques a un
mismo bloque lleno de ceros. Es muy similar a paginacion

## Ej tabla create read/writes
### Howto
#### Creacion
\

1. Leer inodo root
2. Leer data root, encontrar foo.
3. Leer inodo foo.
4. Leer data foo
5. Alocar inodo
6. Actualizar data foo
7. Leer inodo bar (ver que no haya sido escrito por otro programa) y escribir bar.
8. Actualizar fecha ultimo acceso foo

#### Escritura
\

1. Lee inodo archivo
2. Aloca data block en d-bitmap
3. Escribe datos en bloque
4. Actualiza metadatos en inodo archivo (tamaño, modify time, etc)

## Ej tabla open read/writes (no tomado, pero lo anoto por las dudas)
### Howto
#### Apertura
\

1. Leer inodo root
2. Leer data root, encontrar foo.
3. Leer inodo foo.
4. Leer data foo
5. Leer inodo bar

#### Lectura
\

1. Lee el inodo de bar
2. Lee el bloque correspondiente
3. Actualiza tiempo de acceso, offset en el inodo bar

# Final 7-12-2023
## Ej6
### Howto
#### Calcular tamaño i-bmap
\
$ibmapSize = \frac{inodeAmount}{2^3}$

Se divide cantidad de inodos por $2^3$ para pasarlo a bytes.

Pasar a una unidad más conveniente

#### Calcular tamaño d-bmap
\
$dbmapSize = \frac{2^{indexSize}}{2^3}$

Se divide cantidad de bloques por $2^3$ para pasarlo a bytes.

Despues se lo pasa a GiB o MiB segun convenga

#### Calcular tamaño inode-table
\
itableSize = inodeSize * inodeAmount

#### Calcular tamaño data-region
\
$DRSize = 2^{indexSize} * blockSize$

# Extra
## Caps final
![](./Resoluciones_figs/fig22.png)

## Notas
Prestar atencion nombres main()

revisar uso fflush()

### ¿Qué es máxima concurrencia?
La definición sería que es posible una ejecución correcta, según la definición
de correcta para este problema en particular, donde se da la mayor cantidad de
interleavings posibles.
 Un solo interleaving, que es así, concurrencia mala.
Dos interleavings, o sea, así y así, está bueno, porque en realidad puede ser
un procesador que termine primero y el otro después, entonces está bueno eso.

