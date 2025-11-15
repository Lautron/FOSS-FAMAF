# TP3
## ERR
### Cual es el registro de sistema de ERR?
S2_0_C0_C0_0

### Para que sirve?
Guarda la direccion de memoria de la siguiente instruccion que debe ser ejecutada

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
El procesador siempre asume que el salto se toma y carga la instruccion del salto

#### Not Taken\
El procesador siempre asume que el salto no se toma y carga la siguiente instruccion al salto

## Como se marcan las dependencias?

![](./howto-parcial1_figs/fig5.png)

1. Se pone que es dependencia de Datos y se pone el registro afectado
2. Se pone que es de Control
3. Si sucede una dependencia de datos dada por un salto, se agrega "(cond)"


# Dibujar circuito resultante
## 1)
\
![1a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/1a.png)

## 2)
\
![1a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2022-09-23 (Tema A)/1a.png)

# Completar tabla en base a test bench
\
![1b](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/1b.png)

\
![2a](/home/lautarob/Documents/Facultad/a3/adc/parcial/viejos/Parcial 1 2023/2a.png)

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


