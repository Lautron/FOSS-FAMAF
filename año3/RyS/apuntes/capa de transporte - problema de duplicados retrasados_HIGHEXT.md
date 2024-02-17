# Problemas de tener segmentos duplicados retrasados y su resolución


## Comparación de segmentos

Sí, por ejemplo, cuando se pierde un ack y un segmento se retransmite.

También cuando por congestión un segmento se demora, expira su temporizador y el segmento se retransmite.

**No se pueden entregar segmentos duplicados a la capa de aplicación.**

**¿Cómo hacer para saber eficientemente si dos segmentos son diferentes o no?**
Ineficiente es comparar los segmentos bit a bit,
**Idea: Numerar los segmentos con números de secuencia.**

Entonces paquetes con n° de secuencia diferentes son distintos.

Esta idea funcionaría bien si tenemos n° de secuencia de tamaño arbitrario.

**¿Los números de secuencia pueden ser de tamaño arbitrario?**

No, porque queremos que los segmentos tengan longitud máxima.

Por lo tanto el espacio de números de secuencia es finito;

**¿La idea de solo usar espacio de secuencia finito y numerar segmentos con n° de secuencia funciona bien?**

no

Porque números de secuencia alcanzan el máximo y vuelven a reiniciarse y aumentan hasta alcanzar el x de nuevo.

**¿por qué sucede eso?**

El espacio de secuencia no es suficientemente grande.

El duplicado retrasado permanece demasiado en la red.


## Duplicados retrasados

**Sucede la siguiente situación: un segmento S con n° de secuencia x queda demorado debido a que la red está congestionada.**

El temporizador de retransmisiones asociado a S expira y se retransmite S.

El protocolo de enrutamiento cambia las rutas y la retransmisión de S llega rápido a destino.

Pero aun quedó en la red un duplicado retrasado de S (de n° de secuencia x).

Ese duplicado retrasado de S más adelante llega a destino generando problemas.

• Este tipo de problemas es tan serio que debe ser evitado.


## ¿Cómo encarar problemas de duplicados retrasados?

Idea: Asegurar que ningún paquete viva más allá de T sec. (tiempo de vida de paquete) – Esto se refiere a paquetes de datos, retransmisiones de ellos y a confirmaciones de recepción. – Eliminar paquetes viejos que andan dando vueltas por ahí.

**¿Cómo resolver el problema de duplicados retrasados dentro de una conexión?**

Asumiendo que T es el tiempo de vida de paquete, el origen etiqueta los segmentos con n° de secuencia que no van a reutilizarse dentro de T sec.


## 


## ¿Cómo evitar que duplicado retrasado que pasa de una conexión a otra genere problema?


## 

**Como al establecer una conexión se usan segmentos, una conexión debería tener un N° inicial de secuencia con el que comienza a operar.**

En los dos ejemplos últimos sucede lo siguiente:

Hay conexión nueva que rápidamente llega a n° de secuencia x para la cual hay duplicado retrasado que genera problemas.

Idea de solución: hay que escoger como número inicial de secuencia de la conexión nueva un n° de secuencia que haga imposible o improbable que el duplicado retrasado de n° de secuencia x genere problemas.

Además se mantiene dentro de una conexión que el origen etiqueta los segmentos con n° de secuencia que no van a reutilizarse dentro de T sec (tiempo de vida del paquete).

**Implementación 1**

al crear una nueva conexión cada extremo genera un n° de secuencia de 32 bits aleatorio que pasa a ser el número inicial de secuencia para los datos enviados. – Alguna implementación de TCP usa esta solución.

**¿Por qué tiende a funcionar?**

La probabilidad de que un paquete duplicado retrasado genere problemas en una conexión siguiente es baja debido a la elección aleatoria del número inicial de secuencia de la conexión siguiente.

**vincular n° de secuencia de algún modo al tiempo y para medir el tiempo usar un reloj.**
Cada host tiene un reloj de hora del día.
Los relojes de los hosts no necesitan ser sincronizados;

se supone que cada reloj es un contador binario que se incrementa a si mismo en intervalos uniformes.

El reloj continua operando aun ante la caída del host

Cuando se establece una conexión los k bits de orden mayor del reloj = número inicial de secuencia.