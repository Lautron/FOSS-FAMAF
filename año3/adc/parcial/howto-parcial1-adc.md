# TP3
## ERR
### Cual es el registro de sistema de ERR?
S2_0_C0_C0_0

### Para que sirve?
Guarda la direccion de memoria de la siguiente instruccion que debe ser ejecutada

### La siguiente instruccion a ejecutar solo se guarda si se hace un BR?
No, se guarda siempre

![](./howto-parcial1-adc_figs/fig1.png)


## ELR
### Cual es el registro de sistema de ELR?
S2_0_C1_C0_0

### Para que sirve?
Guarda la direccion de la instruccion que causó la excepcion

## ESR
### Cual es el registro de sistema de ESR?
S2_0_C2_C0_0

### Para que sirve?
Guarda informacion sobre el tipo de excepcion que sucedio

## Que hace ERET?
Hace un salto incondicional a la direccion almacenada en ERR

## Como interpretar valor de ESR en vector de excepciones?
Generalmente en un parcial nos van a dar la tablita de significados

Si no, ver el comportamiento en base al circuito del datapath.

No basarse en las filminas que dicen que 0 es opcode invalido y 1 es overflow

### Como funciona en nuestro procesador?
- 0010: Opcode invalido
- 0001: Interrupcion externa

## Que pasa si sucede una excepcion dentro del vector de excepciones?
Se levanta una excepcion y se vuelve al vector de excepciones.

Es como si hubiese habido una excepcion en cualquier otro codigo, no cambia nada
porque sea el vector de excepciones.

# TP4
## Cual es el periodo de clock entre instrucciones en procesador con pipeline?
1 periodo

Esto se da porque primero se ejecuta la primer instruccion, y despues en cada clock se van
ejecutando nuevas instrucciones

![](./howto-parcial1_figs/fig1.png)

Como vemos en la figura, una vez se termina la primer instruccion, se van terminando
instrucciones durante cada periodo de clock.

## Como determinar latencia total procesador sin pipeline?
Sumar todas las latencias


## Conversion unidades de tiempo
| Unidad          | Equivalente en segundos       |
|-----------------|-------------------------------|
| 1 nanosegundo   | $1 * 10^{-9}$                     |
| 1 picosegundo   | $1 * 10^{-12}$                    |

## Conversión de unidades de frecuencia
| Unidad          | Equivalente en hercios       |
|-----------------|-------------------------------|
| 1 hertzio       | $1$                           |
| 1 kilohertzio   | $1 * 10^{3}$                 |
| 1 megahertzio   | $1 * 10^{6}$                 |
| 1 gigahertzio   | $1 * 10^{9}$                 |
| 1 terahertzio   | $1 * 10^{12}$                |

## Como calcular la velocidad del clock?
Hay que expresarlo en Mhz.
Siendo $T$ el periodo del clock, la velocidad se calcula de la siguiente forma:
$$f = \frac{1}{T}$$

Ahora, debemos pasar este resultado a Mhz, para ello convertimos la unidad de tiempo
a segundos y resolvemos

## Calcular velocidad de ejecucion de una instruccion con pipeline
Siendo $T$ el periodo del clock
$$T * \text{ cantEtapas }$$

### Ejemplo
$$
1 \text{ ns} = 10^{-9} \text{ s}
$$
Por lo tanto:
$$
T = 40 \text{ ns} = 40 \times 10^{-9} \text{ s} = 4 \times 10^{-8} \text{ s}
$$
3. **Calcular la frecuencia en hertz**: Sustituyendo el valor del periodo en la fórmula de frecuencia:
$$
f = \frac{1}{T} = \frac{1}{4 \times 10^{-8} \text{ s}} = 25 \times 10^{6} \text{ Hz} = 25 \text{ MHz}
$$

## Calcular ganancia pipeline
Sea T el periodo de clock:

$$\text{ ganancia N instrucciones } = \frac{\text{ tiempoTotalSinPipe } * N }{T * \text{ cantEtapas } + (N-1) * T}$$

La primer parte de la formula tiene en cuenta la primer instruccion que se ejecuta.
La segunda parte tiene en cuenta que una vez finaliza la primer instruccion, se terminan
de ejecutar instrucciones en cada periodo de clock que pasa.

## Cuales son las etapas con pipeline?
Son las mismas que un procesador normal.

1. IF (Instruction Fetch)
2. ID ( Instruction Decode )
3. EX (Execute, donde está la ALU)
4. MEM (Memory)
5. Wb (Writeback)

## Dependencias de datos
Suceden cuando necesitamos un dato calculado en una instruccion anterior, la cual
aun no termina de ejecutarse.

![](./howto-parcial1_figs/fig2.png)

## Que es el stall?
Esperar a que los datos necesarios esten listos y se escriban en los registros adecuados

Para ello se demora una instruccion hasta que se cumpla con los requisitos

NO elimina contenido de los registros, a diferencia de un flush

![](./howto-parcial1_figs/fig3.png)


## Como funciona el forwarding?
En vez de esperar al writeback, los datos se pasan antes.

![](./howto-parcial1_figs/fig4.png)

## Reglas forwarding
Solo se pueden pasar datos de la siguiente forma:
- De EX a EX
- De Mem a EX

- Siempre se pasan "para adelante"
- Si no se dan las condiciones es necesario hacer un stall
- Si una instruccion lee de la memoria no puede pasar sus datos en EX

## Cuando podemos usar datos normalmente?
Supongamos que tenemos dos intrucciones, A y B.
B depende de A.

Podemos usar los datos generados por A normalmente una vez pasa su etapa de Wb.
Es decir, si tenemos la etapa de ID de la instruccion B, en la misma columba que el
Wb de la instruccion A, no es necesario hacer forwarding para acceder a esos datos.

### Ejemplo

![](./howto-parcial1_figs/fig6.png)

En este caso, los datos generados por el SUB, pueden ser usados por el ADD con normalidad


## Hazard de control
Sucede cuando hay algun tipo de branch

### Tecnicas de prediccion
#### Taken\
El procesador siempre asume que el salto se toma y carga la instruccion del salto.

Para ello tiene que esperar a que se ejecute Mem de la instruccion que hace el branch

#### Not Taken\
El procesador siempre asume que el salto no se toma y carga la siguiente instruccion al salto

### Que es un flush?
Sucede cuando fuimos por un camino que no era, entonces hay que
eliminar las instrucciones que procesamos e irnos por otro lado.

Este proceso de eliminar lo que hicimos consiste en setear las
señales de control en 0 y poner los registros usados en 0

## Como se marcan las dependencias?

![](./howto-parcial1_figs/fig5.png)

1. Se pone que es dependencia de Datos y se pone el registro afectado
2. Se pone que es de Control
3. Si sucede una dependencia de datos dada por un salto, se agrega "(cond)"

## Procesador optimizado para saltos
### Que cambia?
Se lleva el calculo de direccion y la comparacion con 0 a la etapa
de ID

### Donde se da cuenta el procesador que tiene que saltar?
En el ID de la instruccion de salto, sin embargo, esto se aplica
recien en el Execute.

Osea, recien puedo saltar, cuando la instruccion de salto esta pasando
por la etapa de execute

# Dibujar circuito resultante
## 1)
\
![1a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/1a.png)

## 2)
\
![1a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/1a.png)

## Howto
### Como representar asignacion no concurrente

![](./howto-parcial1-adc_figs/fig3.png)

### Como representar asignacion en paralelo

![](./howto-parcial1-adc_figs/fig4.png)

### Reglas generales
- Cada variable cuyo valor se guarda va a necesitar un flopr

# Completar tabla en base a test bench
\
![1b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/1b.png)

\
![2a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/2a.png)

## Howto
### Que significa "#n;"
Que se esperan n ps antes de continuar.

La unidad de tiempo puede llegar a cambiar

### Como se comportan los always?
Se ejecutan todo el rato y en paralelo

### Pasar de ns a ps
Multiplicar por 1000 ($10^3$)

#### Ejemplo\

![](./howto-parcial1-adc_figs/fig2.png)

1. a = '0
2. (espera 10 ps)
3. a = 8'b111
4. (espera 20 ps)
5. a = '0
6. (espera 10 ps)
7. a = 8'b111
8. ...

### Como se comporta el initial?
Se ejecuta una vez al inicio

# Completar test bench en base a señales
\
![1b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/1b.png)

# Procesador con pipeline
## 1)
\
![2b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/2b.png)
\
![3a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/3a.png)

## 2)
\
![2a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/2a.png)
\
![2b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/2b.png)

## Howto
### Señales
#### Reg2Loc
Selecciona la ubicacion del Reg2
**Etapa de ejecución:** ID

#### ALUSrc
Indica si el segundo operando es un inmediato.
**Etapa de ejecución:** EX

#### MemToReg
Decide si el dato a escribir en el registro proviene de la memoria o de la ALU.
**Etapa de ejecución:** WB (Write Back)

#### RegWrite
Habilita la escritura en el registro destino.
**Etapa de ejecución:** WB

#### MemRead
Permite la lectura de datos de la memoria.
**Etapa de ejecución:** Mem

#### MemWrite
Permite la escritura de datos en la memoria.
**Etapa de ejecución:** Mem

#### Branch
Controla si se hace un salto o no
**Etapa de ejecución:** Mem


# Latencia pipeline
\
![3b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/3b.png)

# Excepciones
\
![3c](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/3c.png)
\
![4a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/4a.png)
\
![4b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/4b.png)

## Howto
### Que hace la instruccion BL?
Salta a la instruccion de la label especificada y guarda en X30 el PC + 4

![](./howto-parcial1-adc_figs/fig5.png)

### A que es equivalente SUBIS XZR?

```
SUBIS xzr, x9, 0x01
==
CMP x9, 0x01
```

### Que hace B.LS?
Chequea flags para ver si es menor o igual

### Esquema de vector unico? (CHEQUEAR)
Que usa un unico vector para el manejo de todas las excepciones

## 2)
\
![3a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/3a.png)
\
![3b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/3b.png)

# Dependencias funcionales
## 1)
\
![5a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/5a.png)

## 2)
\
![4b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/4b.png)

# Completar con dependencias

\
![2c](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/2c.png)
\
![4a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/4a.png)


